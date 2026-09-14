#include <stdio.h>

// Define a simple struct
struct Player {
    int id;
    int score;
};

int main() {
    // 1. Create a regular struct variable
    struct Player player1 = {101, 450};

    // 2. Create a pointer to a struct Player and assign player1's address to it
    struct Player *ptr = &player1;

    // 3. Read values using the pointer (arrow operator)
    printf("Original ID: %d\n", ptr->id);
    printf("Original Score: %d\n", ptr->score);

    // 4. Modify values using the pointer
    ptr->score = 500;

    // Verify that the original struct variable was updated
    printf("Updated Score (via variable): %d\n", player1.score);
    printf("Updated Score (via pointer): %d\n", ptr->score);

    return 0;
}
