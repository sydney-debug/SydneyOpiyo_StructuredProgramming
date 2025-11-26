#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int length;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline if present
    str[strcspn(str, "\n")] = 0;

    length = strlen(str);

    printf("You entered: %s\n", str);
    printf("Length of the string: %d\n", length);

    printf("Press Enter to exit...");
    getchar(); // wait for user input
    return 0;
}
