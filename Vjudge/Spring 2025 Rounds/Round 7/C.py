import math

LINF = float("inf")


def solve():
    n = int(input())
    x = input()
    indexes = []
    i = n // 2
    while i >= 0 and x[i] == "0":
        i -= 1
    if i >= 0:
        indexes.append(i)
        i -= 1
    while i >= 0 and x[i] == "0":
        i -= 1
    if i >= 0:
        indexes.append(i)

    i = n // 2 + 1
    while i < n and x[i] == "0":
        i += 1
    if i < n:
        indexes.append(i)
        i += 1
    while i < n and x[i] == "0":
        i += 1
    if i < n:
        indexes.append(i)

    # print(indexes)

    sum_result = LINF
    for j in indexes:
        s1 = x[:j]
        s2 = x[j:]

        current = 0
        mul = 1
        if len(s1) < len(s2):
            s1, s2 = s2, s1
        s1 = s1[::-1]
        s2 = s2[::-1]
        s3 = ""
        carry = 0
        for i in range(min(len(s1), len(s2))):
            z = int(s1[i]) + int(s2[i]) + carry
            if z > 9:
                carry = 1
                z -= 10
            else:
                carry = 0
            # s1 = s1[:i] + str(z) + s1[i + 1 :]
            s3 += str(z)
        for i in range(min(len(s1), len(s2)), len(s1)):
            z = int(s1[i]) + carry
            if z > 9:
                carry = 1
                z -= 10
            else:
                carry = 0
            # s1 = s1[:i] + str(z) + s1[i + 1 :]
            s3 += str(z)

        s1 = s1[::-1]
        s3 = s3[::-1]
        # print(s3)
        sum_result = min(sum_result, int(s3))

    print(sum_result)


if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
