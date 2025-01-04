#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    int diff = A - B;
    int answer = 1;
    while (diff > 0) {
        answer = answer * 32;
        diff = diff - 1;
    }
    printf("%d", answer);
}