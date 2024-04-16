#include <stdio.h>
#include <string.h>

// Function to encrypt a message using Caesar Cipher
void encrypt(char *message, int shift) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        // Shift only alphabetic characters
        if (isalpha(message[i])) {
            // Shift uppercase letters
            if (isupper(message[i])) {
                message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
            }
            // Shift lowercase letters
            else if (islower(message[i])) {
                message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
            }
        }
    }
}

// Function to decrypt a message using Caesar Cipher
void decrypt(char *message, int shift) {
    // Decrypting is essentially encrypting with the negative shift
    encrypt(message, -shift);
}

int main() {
    char message[100];
    int shift;

    // Secret key (shift value)
    shift = 3;

    printf("Enter the encrypted message: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character
    if ((strlen(message) > 0) && (message[strlen (message) - 1] == '\n'))
        message[strlen (message) - 1] = '\0';

    // Decrypt the message
    decrypt(message, shift);

    printf("Decrypted message: %s\n", message);

    return 0;
}

