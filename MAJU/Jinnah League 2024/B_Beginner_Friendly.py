from collections import defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(0)
        return
    mp = defaultdict(int)
    # maximum = 0
    for i in a:
        mp[i] += 1
    answer = 0
    for k, v in mp.items():
        answer = max(answer, min(len(mp) - 1, v))
        answer = max(answer, min(len(mp), v - 1))
    print(answer)
    # print(mp)


if __name__ == "__main__":
    t = int(input())
    while t:
        solve()
        t -= 1
