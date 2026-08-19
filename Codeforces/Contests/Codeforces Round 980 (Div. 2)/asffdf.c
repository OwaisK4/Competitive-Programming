#include <stdio.h>
int main() {
    int n, ans;
    scanf("%d", &n);

    ans = n % 100;

    if (ans == 0 && n != 0) {
        printf("Yes");
    } else
        printf("No");

    return 0;
}