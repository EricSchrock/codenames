#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE (3)

// https://man7.org/linux/man-pages/man5/terminal-colors.d.5.html
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

typedef enum {
    TILE_BLANK,
    TILE_X,
    TILE_O,
} TILE_E;

static TILE_E board[BOARD_SIZE][BOARD_SIZE];

static void render(void);
static void update(bool x_is_next);
static bool check_win_conditions(bool x_is_next);
static bool check_tie_conditions(void);

int main()
{
    int return_code;
    bool x_is_next = true;

    render(); // Initial render so players can see the board on their first play

    // Game loop
    while (true) {
        update(x_is_next); // Combined process input and update steps
        render();

        if (check_win_conditions(x_is_next)) { //todo: Move into state logic
            printf("%s wins!\n\n", x_is_next ? "X" : "O");
            break;
        }

        if (check_tie_conditions()) { //todo: Move into state logic
            printf("Nobody wins!\n\n");
            break;
        }

        x_is_next = !x_is_next; // Switch players //todo: Move into state logic
    }

    return return_code;
}

static void render(void)
{
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == TILE_BLANK) {
                printf(" %d ", (j + 1) + (i * BOARD_SIZE));
            } else if (board[i][j] == TILE_X) {
                printf(ANSI_COLOR_RED " x " ANSI_COLOR_RESET);
            } else if (board[i][j] == TILE_O) {
                printf(ANSI_COLOR_GREEN " o " ANSI_COLOR_RESET);
            }

            if (j < (BOARD_SIZE - 1)) {
                printf("|");
            }
        }

        printf("\n");

        if (i < (BOARD_SIZE - 1)) {
            for (int j = 0; j < (BOARD_SIZE * 4) - 1; j ++) {
                printf("-");
            }

            printf("\n");
        }
    }

    printf("\n");
}

static void update(bool x_is_next)
{
    int slot;

    while (true) {
        // Game loop: Process input
        printf("%s's turn\n", x_is_next ? "X" : "O");
        printf("Enter slot to place: ");
        scanf("%d", &slot);

        if (slot <= 0) {
            printf("Slot must be greater than 0\n");
            continue;
        } else if (slot > (BOARD_SIZE * BOARD_SIZE)) {
            printf("Slot must be smaller than %d\n", (BOARD_SIZE * BOARD_SIZE) + 1);
            continue;
        }

        int i = (slot - 1) / BOARD_SIZE;
        int j = (slot - 1) % BOARD_SIZE;

        if (board[i][j] != TILE_BLANK) {
            printf("Slot must be empty\n");
            continue;
        }

        // Game loop: Update
        board[i][j] = x_is_next ? TILE_X : TILE_O;
        break;
    }
}

static bool check_win_conditions(bool x_is_next)
{
    TILE_E check = x_is_next ? TILE_X : TILE_O;

    // Check rows
    bool row;
    for (int i = 0; i < BOARD_SIZE; i++) {
        row = true;

        for (int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] != check) {
                row = false;
            }
        }

        if (row) {
            break;
        }
    }

    // Check columns
    bool column;
    for (int j = 0; j < BOARD_SIZE; j++) {
        column = true;

        for (int i = 0; i < BOARD_SIZE; i++){
            if (board[i][j] != check) {
                column = false;
            }
        }

        if (column) {
            break;
        }
    }

    // Check diagonals
    bool right_sloping = true;
    bool left_sloping = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] != check) {
            right_sloping = false;
        }

        if (board[i][BOARD_SIZE - 1 - i] != check) {
            left_sloping = false;
        }
    }

    return row || column || right_sloping || left_sloping;
}

static bool check_tie_conditions(void)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == TILE_BLANK) {
                return false;
            }
        }
    }

    return true;
}
