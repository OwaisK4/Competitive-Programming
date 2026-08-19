n, m = [int(i) for i in input().split()]

sets = []

for i in range(n):
    a = [i.lower() for i in input().split()]
    A = set(a)
    sets.append(A)

# print(A)
indexes = [-1 for i in range(200)]

answer = ""
text = input()
j = 0
for i in range(0, m // 2):
    text = input()
    word1 = text.split()[-1].lower()
    text = input()
    word2 = text.split()[-1].lower()
    found = False
    for s in range(len(sets)):
        if word1 in sets[s] and word2 in sets[s]:
            if indexes[s] == -1:
                indexes[s] = j
                if chr(indexes[s] + ord("A")) == "X":
                    j += 1
                    indexes[s] = j
                j += 1
            answer += chr(indexes[s] + ord("A")) * 2
            found = True
            break
    if not found:
        answer += "XX"

if m % 2 != 0:
    answer += "X"

print(answer)
