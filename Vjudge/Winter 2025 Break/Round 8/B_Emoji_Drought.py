from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    s = input()
    happy = 0
    sad = 0
    for i in range(0, len(s) - 3):
        if s[i : i + 3] == ":-)":
            happy += 1
        elif s[i : i + 3] == ":-(":
            sad += 1
    if happy == 0 and sad == 0:
        print("none")
    elif happy == sad:
        print("unsure")
    elif happy > sad:
        print("happy")
    elif happy < sad:
        print("sad")


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        solve()
        t -= 1
