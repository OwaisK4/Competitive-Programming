from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    n, m = list(map(int, input().split()))
    if n >= m:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        solve()
        t -= 1
