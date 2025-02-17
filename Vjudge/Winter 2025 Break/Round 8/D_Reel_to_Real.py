from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    n, t = list(map(int, input().split()))
    a = list(map(int, input().split()))
    reels = 0
    i = 0
    while i < n and reels + a[i] <= t:
        reels += a[i]
        i += 1
    print(i)


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        solve()
        t -= 1
