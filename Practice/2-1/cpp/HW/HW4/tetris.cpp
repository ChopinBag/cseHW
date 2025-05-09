#include "tetris.h"
#include <vector>
#include <cstdlib>
#include <ctime>
// --- 게임 초기화 ---
void init_game(GameState& state) {
    srand(888);
    state.board = std::vector<std::vector<char>>(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, '.'));
    state.current_block = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
    state.tetrominoes = {
        // I-tetromino (2 rotations)
        {
            {
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 0}
            }
        },
        // O-tetromino (1 rotation)
        {
            {
                {0, 1, 1, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }
        },
        // T-tetromino (4 rotations)
        {
            {
                {0, 1, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            }
        },
        // S-tetromino (2 rotations)
        {
            {
                {0, 1, 1, 0},
                {1, 1, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }
        },
        // Z-tetromino (2 rotations)
        {
            {
                {1, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 1, 0},
                {0, 1, 1, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            }
        },
        // J-tetromino (4 rotations)
        {
            {
                {1, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 1, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {0, 0, 0, 0}
            }
        },
        // L-tetromino (4 rotations)
        {
            {
                {0, 0, 1, 0},
                {1, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {1, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {1, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            }
        }
    };

    state.current_tetromino = 0;
    state.current_rotation = 0;
    state.block_x = 0;
    state.block_y = 0;
    state.score = 0;
    state.level = 1;
    state.lines_cleared = 0;
    state.high_score = 2200; // 필요시 파일에서 불러오는 함수 구현
    state.running = true;
    state.next_tetromino = rand() % state.tetrominoes.size();
    state.fall_timer = 0;
    state.fall_interval = 10 - (state.level - 1);
    if (state.fall_interval < 1) state.fall_interval = 1;
    spawn_new_block(state);
}

void handle_game_action(GameState& state, int action) {
    switch (action) {
        case ACTION_QUIT:
            state.running = false;
            break;
        case ACTION_LEFT:
            move_block(state, -1, 0);
            break;
        case ACTION_RIGHT:
            move_block(state, 1, 0);
            break;
        case ACTION_DOWN:
            move_block(state, 0, 1);
            break;
        case ACTION_ROTATE:
            rotate_block(state);
            break;
        case ACTION_DROP:
            drop_block_to_bottom(state);
            break;
        default:
            break;
    }
}

// --- 블록 충돌 검사 ---
bool is_valid_position(const std::vector<std::vector<int>>& block, int x, int y, const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (block[i][j]) {
                int bx = x + j;
                int by = y + i;
                if (bx < 0 || bx >= BOARD_WIDTH || by < 0 || by >= BOARD_HEIGHT)
                    return false;
                if (board[by][bx] != '.')
                    return false;
            }
        }
    }
    return true;
}

// --- 블록 회전 ---
void rotate_block(GameState& state) {
    int total_rot = state.tetrominoes[state.current_tetromino].size();
    int next_rot = (state.current_rotation + 1) % total_rot;
    const auto& next_block = state.tetrominoes[state.current_tetromino][next_rot];
    if (is_valid_position(next_block, state.block_x, state.block_y, state.board)) {
        state.current_rotation = next_rot;
        state.current_block = next_block;
    }
    // 벽치기 미지원: 회전 불가시 아무 동작 없음
}

// --- 블록 이동 ---
bool move_block(GameState& state, int dx, int dy) {
    int nx = state.block_x + dx;
    int ny = state.block_y + dy;
    if (is_valid_position(state.current_block, nx, ny, state.board)) {
        state.block_x = nx;
        state.block_y = ny;
        return true;
    }
    return false;
}

// --- 블록 착지 ---
void land_block(GameState& state) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (state.current_block[i][j]) {
                int bx = state.block_x + j;
                int by = state.block_y + i;
                if (by >= 0 && by < BOARD_HEIGHT && bx >= 0 && bx < BOARD_WIDTH)
                    state.board[by][bx] = '#';
            }
        }
    }
}

// --- 라인 클리어 및 점수/레벨 처리 ---
void check_lines(GameState& state) {
    int lines = 0;
    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool full = true;
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            if (state.board[y][x] == '.') {
                full = false;
                break;
            }
        }
        if (full) {
            for (int ty = y; ty > 0; --ty)
                state.board[ty] = state.board[ty - 1];
            state.board[0] = std::vector<char>(BOARD_WIDTH, '.');
            ++lines;
            ++state.lines_cleared;
            ++y; // 같은 줄 다시 검사(내려온 줄)
        }
    }
    if (lines > 0) {
        state.score += 100 * state.level * lines;
        if (state.lines_cleared / 10 + 1 > state.level) {
            state.level = state.lines_cleared / 10 + 1;
            state.fall_interval = 10 - (state.level - 1);
            if (state.fall_interval < 1) state.fall_interval = 1;
        }
    }
}

// --- 새로운 블록 생성 ---
void spawn_new_block(GameState& state) {
    state.current_tetromino = state.next_tetromino;
    state.current_rotation = 0;
    state.current_block = state.tetrominoes[state.current_tetromino][0];
    state.block_x = BOARD_WIDTH / 2 - 2;
    state.block_y = 0;
    // 다음 블록 미리 선택
    state.next_tetromino = rand() % state.tetrominoes.size();
    // 스폰 위치 불가 = 게임 오버
    if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) {
        state.running = false;
    }
}

// --- 하드 드롭 ---
void drop_block_to_bottom(GameState& state) {
    while (move_block(state, 0, 1)) {}
    land_block(state);
    check_lines(state);
    spawn_new_block(state);
}

// --- 게임 상태 갱신(중력) ---
void update_game(GameState& state) {
    if (!state.running) return;
    state.fall_timer++;
    if (state.fall_timer >= state.fall_interval) {
        if (!move_block(state, 0, 1)) {
            land_block(state);
            check_lines(state);
            spawn_new_block(state);
        }
        state.fall_timer = 0;
    }
}

