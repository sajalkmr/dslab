#include <stdio.h>

void hanoi(int n, char source, char aux, char target) {
    if (n > 0) {
        hanoi(n - 1, source, target, aux);
        printf("Move %c to %c using %c\n", source, target, aux);
        hanoi(n - 1, aux, source, target);
    }
}

int main() {
    int n;
    printf("Enter the number of towers: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}
