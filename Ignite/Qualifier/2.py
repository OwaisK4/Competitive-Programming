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
        if s[j] == "?" or c[i + j] == "?":
            continue
        elif c[i + j].lower() == s[j].lower():
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
