#include <stdio.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int head = 0;
int count = 0;

void insert(int value) {
    buffer[head] = value;
    head = (head + 1) % BUFFER_SIZE;
    if (count < BUFFER_SIZE)
        count++;
}

void printBuffer() {
    int i;
    int index = (head + BUFFER_SIZE - count) % BUFFER_SIZE;

    printf("Stored values (oldest to newest): ");
    for (i = 0; i < count; i++) {
        printf("%d ", buffer[(index + i) % BUFFER_SIZE]);
    }
    printf("\n");
}

int main() {
    int value, choice;

    while (1) {
        printf("\n1. Insert Data\n2. Print Data\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter sensor value: ");
            scanf("%d", &value);
            insert(value);
        } else if (choice == 2) {
            printBuffer();
        } else if (choice == 3) {
            break;
        }
    }

    system ("pause");
    return 0;
}
