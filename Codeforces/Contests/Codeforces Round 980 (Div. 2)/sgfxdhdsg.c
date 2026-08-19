#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);

    if (x % 100 == 0 && x > 0) {
        printf("Yes");
    } else {
        printf("No");
    }
}