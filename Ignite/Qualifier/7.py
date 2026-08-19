n = int(input())
m = list(map(int, input().split()))
a = list(map(int, input().split()))
tm1 = list(map(int, input().split()))
ta = list(map(int, input().split()))
m0, a0, dm, da = map(int, input().split())

dp = [[-1 for _ in range(2)] for _ in range(n)]


def f(index, team):
    if index == n:
        return dm if team == 0 else da
    if dp[index][team] != -1:
        return dp[index][team]
    answer = float("inf")
    if team == 0:
        answer = min(answer, f(index + 1, 0) + m[index])
        answer = min(answer, f(index + 1, 1) + m[index] + tm1[index])
    else:
        answer = min(answer, f(index + 1, 1) + a[index])
        answer = min(answer, f(index + 1, 0) + a[index] + ta[index])
    dp[index][team] = answer
    return answer


answer = min(m0 + min(f(0, 0), f(0, 1) + tm1[0]), a0 + min(f(0, 1), f(0, 0) + ta[0]))
print(answer)
