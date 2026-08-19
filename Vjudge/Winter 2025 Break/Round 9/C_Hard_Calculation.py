from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():

    s, t = list(map(int, input().split()))
    s = str(s)
    t = str(t)
    s = s[::-1]
    t = t[::-1]

    for i in range(min(len(s), len(t))):
        d1, d2 = int(s[i]), int(t[i])
        if d1 + d2 > 9:
            print("Hard")
            return
    print("Easy")


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        solve()
        t -= 1
