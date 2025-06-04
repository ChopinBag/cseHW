/*
 * csim.c - Cache Simulator
 * 이름: 임승우
 * 학번 : 202455376
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include "cachelab.h"

typedef struct {
    int valid;
    unsigned long tag;
    unsigned long lru_counter;
} cache_line_t;

typedef struct {
    int S;
    int E;
    int B;
    cache_line_t **lines;
} cache_t;

int s = 0, E = 0, b = 0;
char *tracefile = NULL;
int verbose = 0;

int hit_count = 0;
int miss_count = 0;
int eviction_count = 0;

cache_t cache;
static unsigned long timestamp = 1;

void initCache();
void freeCache();
void accessData(unsigned long address);
void printUsage(char *argv[]);

int main(int argc, char *argv[]) {
    char opt;
    FILE *fp;

    while ((opt = getopt(argc, argv, "s:E:b:t:vh")) != -1) {
        switch (opt) {
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                tracefile = optarg;
                break;
            case 'v':
                verbose = 1;
                break;
            case 'h':
                printUsage(argv);
                exit(0);
            default:
                printUsage(argv);
                exit(1);
        }
    }

    if (s == 0 || E == 0 || b == 0 || tracefile == NULL) {
        fprintf(stderr, "Missing required command line argument\n");
        printUsage(argv);
        exit(1);
    }

    initCache();

    fp = fopen(tracefile, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening trace file: %s\n", tracefile);
        freeCache();
        exit(1);
    }

    char buf[100];
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        char op;
        unsigned long addr;
        int size;

        if (buf[0] == 'I')
            continue;

        sscanf(buf, " %c %lx,%d", &op, &addr, &size);

        if (verbose) {
            printf("%c %lx,%d ", op, addr, size);
        }

        switch (op) {
            case 'L':
                accessData(addr);
                break;
            case 'S':
                accessData(addr);
                break;
            case 'M':
                accessData(addr);
                accessData(addr);
                break;
            default:
                break;
        }

        if (verbose) {
            printf("\n");
        }
    }

    fclose(fp);
    freeCache();
    printSummary(hit_count, miss_count, eviction_count);

    return 0;
}

void initCache() {
    int S = 1 << s;
    cache.S = S;
    cache.E = E;
    cache.B = 1 << b;

    cache.lines = (cache_line_t **)malloc(S * sizeof(cache_line_t *));
    for (int i = 0; i < S; i++) {
        cache.lines[i] = (cache_line_t *)malloc(E * sizeof(cache_line_t));
        for (int j = 0; j < E; j++) {
            cache.lines[i][j].valid = 0;
            cache.lines[i][j].tag = 0;
            cache.lines[i][j].lru_counter = 0;
        }
    }
}

void freeCache() {
    for (int i = 0; i < cache.S; i++) {
        free(cache.lines[i]);
    }
    free(cache.lines);
}

void accessData(unsigned long address) {
    unsigned long set_index = (address >> b) & ((1 << s) - 1);
    unsigned long tag = address >> (s + b);
    cache_line_t *set = cache.lines[set_index];

    int hit_line = -1;
    for (int i = 0; i < E; i++) {
        if (set[i].valid && set[i].tag == tag) {
            hit_line = i;
            break;
        }
    }

    if (hit_line != -1) {
        hit_count++;
        set[hit_line].lru_counter = timestamp++;
        if (verbose) printf("hit ");
    } else {
        miss_count++;
        int empty_line = -1;
        for (int i = 0; i < E; i++) {
            if (!set[i].valid) {
                empty_line = i;
                break;
            }
        }

        if (empty_line != -1) {
            set[empty_line].valid = 1;
            set[empty_line].tag = tag;
            set[empty_line].lru_counter = timestamp++;
            if (verbose) printf("miss ");
        } else {
            int lru_line = 0;
            unsigned long min_ts = set[0].lru_counter;
            for (int i = 1; i < E; i++) {
                if (set[i].lru_counter < min_ts) {
                    min_ts = set[i].lru_counter;
                    lru_line = i;
                }
            }
            eviction_count++;
            set[lru_line].tag = tag;
            set[lru_line].lru_counter = timestamp++;
            if (verbose) printf("miss eviction ");
        }
    }
}

void printUsage(char *argv[]) {
    printf("Usage: %s [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n", argv[0]);
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <s>     Number of set index bits.\n");
    printf("  -E <E>     Number of lines per set (associativity).\n");
    printf("  -b <b>     Number of block bits.\n");
    printf("  -t <file>  Trace file.\n");
}
