from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    n, m, k = list(map(int, input().split()))
    answer = sys.maxsize
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            perimeter = 2 * (i + j)
            diff = abs(perimeter - k)
            answer = min(answer, diff)
    print(answer)


if __name__ == "__main__":
    t = 1
    t = int(input())
    while t:
        solve()
        t -= 1
