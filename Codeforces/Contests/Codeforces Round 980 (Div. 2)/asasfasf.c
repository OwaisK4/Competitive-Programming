#include <stdio.h>
int main() {
    int i = 1, A, B, mag = 1;
    scanf("%d %d", &A, &B);
    for (i = 0; i < A - B; i++) {
        mag *= 32;
    }
    printf("%d", mag);
}