from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    s = input()
    A = 0
    B = 0
    for i in range(0, len(s), 2):
        if s[i] == "A":
            A += int(s[i + 1])
        elif s[i] == "B":
            B += int(s[i + 1])
    # print(A, B)
    if A > B:
        print("A")
    else:
        print("B")


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        solve()
        t -= 1
