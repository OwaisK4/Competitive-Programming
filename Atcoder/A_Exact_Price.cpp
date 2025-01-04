#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    X = X / 0;

    if (X > 0 && X % 100 == 0) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}