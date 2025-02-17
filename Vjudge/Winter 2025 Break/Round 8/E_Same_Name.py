from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    n = int(input())
    d = defaultdict(int)
    for i in range(n):
        s = input()
        d[s] += 1
        if d[s] > 1:
            print("Yes")
            return
    print("No")


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        solve()
        t -= 1
