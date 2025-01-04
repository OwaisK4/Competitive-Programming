#include <math.h>
#include <stdio.h>
int main() {
    int a, b, x;
    scanf("%d %d", &a, &b);
    if (a > b || a == b) {
        x = a - b;
        printf("%d", (int)pow(32, x));
    }
}
