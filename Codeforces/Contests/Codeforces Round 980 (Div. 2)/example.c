#include <stdio.h>
int main() {
    int input, part1, part2;
    scanf("%d", &input);
    part1 = input - 2;
    part2 = 2;

    if (part1 != 0 && part1 % 2 == 0) {
        printf("YES");
    }

    else {
        printf("NO");
    }
}