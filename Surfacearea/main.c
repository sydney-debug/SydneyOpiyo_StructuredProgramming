#include <stdio.h>

int main() {
    float r, area;
    const float PI = 3.14159;

    printf("Enter radius: ");
    scanf("%f", &r);

    area = 4 * PI * r * r;

    printf("Surface area = %.2f\n", area);

    printf("Press Enter to exit...");
    getchar(); // to capture leftover newline
    getchar(); // waits for user input
    return 0;
}
