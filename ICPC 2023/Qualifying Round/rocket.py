def f(a, l, r, sum, n):
    if l == r:
        return 0
    if (r - l + 1) == 2:
        sum += a[l] + a[r]
        return sum
    left = 0
    right = 0
    x = 1e18
    for k in range(l, r):
        left = f(a, l, k, sum + a[l] + a[r], n)
        right = f(a, k + 1, r, sum + a[l] + a[r], n)
        x = min(x, left + right)
    return x


def solve():
    a = [int(i) for i in input().split()]
    n = len(a)
    # print(a)
    answer = f(a, 0, n - 1, 0, n)
    print(answer)


t = int(input())
for i in range(t):
    solve()
