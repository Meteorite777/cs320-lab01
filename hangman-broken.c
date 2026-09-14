#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LIVES 6
#define WORD_COUNT 5
#define MAX_WORD_LENGTH 7

// Function to draw the text-based hangman state
void drawHangman(int livesLeft) {
    printf("\n");
    printf(" +---+\n");
    printf(" | |\n");
    printf(" | %c\n", (livesLeft < 6) ? 'O' : ' ');
    printf(" | %c%c%c\n", (livesLeft < 4) ? '/' : ' ', (livesLeft < 5) ? '|' : ' ', (livesLeft < 3) ? '\\' : ' ');
    printf(" | %c %c\n", (livesLeft < 5) ? '/' : ' ', (livesLeft < 1) ? '\\' : ' ');
    printf(" === \n\n");
}

int main() {
    // A predefined list of secret words
    char wordBank[WORD_COUNT][MAX_WORD_LENGTH] = {
        "prograMming",
        "computer",
        "developer",
        "Software",
        "science"	
    };

    // Seed the random number generator to pick a different word every run
    srand((unsigned int)time(NULL));
    int randomIndex = rand() % WORD_COUNT;
    
    // Declare a pointer to a single character, instantiate it with a randomIndex from wordBank[].
    // This saves the memory location of the first character of the word in wordBank[] to secretWord.
    // When you printf() a pointer to a character, printf() goes through memory starting at that
    // memory location and prints what it finds until it hits a null terminator character '/0'
    // When you instantiate a character array or string with a string literal such as
    // "developer" it appends the null terminator character '/0' automatically.
    char *secretWord = wordBank[2];
    printf("wordBank[2] char: %c\n", *secretWord);
    printf("wordBank[2] string: %s\n", secretWord);
    int wordLength = strlen(secretWord);
    printf("Wordlen: %d\n", wordLength);

    // Track the puzzle's visible state (e.g., "_ _ o _ _ ")
    // Declare a new character array 'guessedWord' of size 'MAX_WORD_LENGTH' and fill it with '_' characters.
    char guessedWord[MAX_WORD_LENGTH];
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0'; // Null-terminate the string at the end of 'guessedWord'

    int lives = MAX_LIVES;
    bool guessedCorrectly = false;

    printf("Welcome to Hangman!\n");

    // Main game loop
    while (lives > 0 && !guessedCorrectly) {
        drawHangman(lives);
        
        // Print out the guessed word representation
        printf("Word: ");
        for (int i = 0; i < wordLength; i++) {
            printf("%c ", guessedWord[i]);
        }
        printf("\nLives left: %d\n", lives);

        // Fetch a letter from the user
        char guess;
        printf("Guess a letter: ");
        // Note the leading space before %c: it skips leftover whitespace/newlines from previous inputs
        if (scanf(" %c", &guess) != 1) {
            continue;
        }

        bool foundLetter = false;
        // Verify if the character matches any letter in the secret word
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                if (guessedWord[i] != guess) {
                    guessedWord[i] = guess;
                    foundLetter = true;
                } else {
                    // Letter was already revealed
                    foundLetter = true; 
                }
            }
        }

        if (!foundLetter) {
            printf("\nWrong guess! '%c' is not in the word.\n", guess);
            lives--;
        } else {
            printf("\nGood job!\n");
        }

        // Check if the entire word has been revealed
        if (strcmp(secretWord, guessedWord) == 0) {
            guessedCorrectly = true;
        }
    }

    // End game resolution
    drawHangman(lives);
    if (guessedCorrectly) {
        printf("🎉 Congratulations! You guessed the word: %s\n", secretWord);
    } else {
        printf("💀 Game Over! You ran out of lives. The word was: %s\n", secretWord);
    }

    return 0;
}
