#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numberToGuess, userGuess, attempts = 0;
    int maxAttempts = 5;
    srand(time(NULL)); // Seed for random number generator

    // Generate a random number between 1 and 100
    numberToGuess = rand() % 100 + 1;

    printf("Welcome to the Guess the Number game!\n");
    printf("I have selected a number between 1 and 100. You have %d attempts to guess it.\n", maxAttempts);

    do {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);

        attempts++;

        if (userGuess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else if (userGuess > numberToGuess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d correctly in %d attempts.\n", numberToGuess, attempts);
            break;
        }

        if (attempts == maxAttempts) {
            printf("Sorry, you've run out of attempts. The correct number was %d.\n", numberToGuess);
            break;
        }
    } while (1);

    return 0;
}
