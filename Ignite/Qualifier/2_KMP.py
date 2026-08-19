c = input()
s = input()

# print(c)
# print(s)

n = len(c)
m = len(s)

answers = []

for i in range(n - m + 1):
    valid = True
    for j in range(m):
        if c[i + j] == "?" or s[j] == "?":
            continue
        elif c[i + j] == s[j]:
            continue
        else:
            valid = False
            break
    if valid:
        answers.append(str(i))

print(len(answers))
if len(answers) == 0:
    print()
else:
    # print(" ".join(answers))
    for i in answers:
        print(i, end=" ")
