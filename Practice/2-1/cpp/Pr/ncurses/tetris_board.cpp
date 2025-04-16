#include <ncurses.h>

int main() {
    initscr();
    curs_set(0);  // 커서 숨기기

    // 보드 테두리 그리기
    mvhline(1, 1, '-', 10);         // 상단
    mvhline(6, 1, '-', 10);         // 하단
    for (int y = 2; y < 6; y++) {   // 좌우
        mvaddch(y, 1, '|');
        mvaddch(y, 11, '|');
    }
    mvaddch(1, 1, '+'); mvaddch(1, 11, '+');  // 모서리
    mvaddch(6, 1, '+'); mvaddch(6, 11, '+');

    // 블록 띄우기
    mvaddch(3, 5, '#');  // 가운데 블록 하나

    refresh();
    getch();
    endwin();
    return 0;
}