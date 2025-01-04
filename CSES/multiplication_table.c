#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int iRow, iColumn, iTableValue, n;
    printf_s("\nEnter Multiplication Table Size: ");
    scanf_s("%d", &n);
    printf_s("\n   ");

    for (iColumn = 1; iColumn <= n; iColumn++)
        printf_s(" %3d", iColumn);
        
    for (iRow = 1; iRow <= n; iRow++) {
        printf_s("\n %2d", iRow);
        for (iColumn = 1; iColumn <= n; iColumn++) {
            iTableValue = iRow * iColumn;
            printf_s(" %3d", iTableValue);
        }
    }

    return 0;
}