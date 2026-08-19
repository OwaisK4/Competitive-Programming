from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    s = input()
    s = s[:-2] + "i"
    print(s)


if __name__ == "__main__":
    t = 1
    t = int(input())
    while t:
        solve()
        t -= 1
