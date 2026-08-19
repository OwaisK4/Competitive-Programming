from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    s = input()
    t = ""
    if s[0] == s[2]:
        t = s[0] + "=" + s[2]
    elif s[0] < s[2]:
        t = s[0] + "<" + s[2]
    else:
        t = s[0] + ">" + s[2]
    print(t)


if __name__ == "__main__":
    t = 1
    t = int(input())
    while t:
        solve()
        t -= 1
