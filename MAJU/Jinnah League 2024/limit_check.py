f0 = "What are you doing at the end of the world? Are you busy? Will you save us?"
x = 'What are you doing while sending "'
y = '"? Are you busy? Will you send "'
z = '"?'

dp = [-1 for i in range(pow(10, 5))]


def f(n):
    if n == 0:
        return len(f0)
    if dp[n] != -1:
        return dp[n]

    total = len(x) + len(y) + len(z) + 2 * f(n - 1)
    dp[n] = total
    return dp[n]


lim = pow(10, 18)
print(lim)
val = len(x) + len(y) + len(z) + 2 * f(51)
print(val < lim)
# print(lim - f(52))


i = 0
while True:
    value = f(i)
    if value > lim:
        break
    print(i, value)
    i += 1
