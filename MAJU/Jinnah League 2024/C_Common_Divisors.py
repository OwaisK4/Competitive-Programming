from collections import defaultdict
import sys
from math import gcd, inf

from cv2 import INTER_MAX

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    g = max(a)
    for i in a:
        g = gcd(g, i)
    i = 1
    cnt = 0
    while i * i <= g:
        if g % i == 0:
            cnt += 1
        i += 1
    print(cnt)


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        solve()
        t -= 1
