from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    n, a, b, c = list(map(int, input().split()))
    divisor = a + b + c
    days = n // divisor * 3
    n %= divisor
    if n == 0:
        print(days)
    elif n <= a:
        print(days + 1)
        return
    elif n <= a + b:
        print(days + 2)
        return
    else:
        print(days + 3)
        return


if __name__ == "__main__":
    t = 1
    t = int(input())
    while t:
        solve()
        t -= 1
