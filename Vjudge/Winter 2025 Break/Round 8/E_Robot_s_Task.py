from collections import OrderedDict, defaultdict
import sys

# input = sys.stdin.readline
# print = sys.stdout.write


def solve():
    n = int(input())
    a = list(map(int, input().split()))

    nums = a[:]
    index, cnt = 0, 0
    valid = True
    while True:
        for i in range(0, len(a)):
            if a[i] <= index and nums[i] != -1:
                nums[i] = -1
                index += 1
        if index == n:
            break

        cnt += 1
        for i in range(len(a) - 1, -1, -1):
            if a[i] <= index and nums[i] != -1:
                nums[i] = -1
                index += 1
        if index == n:
            break

        cnt += 1
    print(cnt)


if __name__ == "__main__":
    t = 1
    # t = int(input())
    while t:
        solve()
        t -= 1
