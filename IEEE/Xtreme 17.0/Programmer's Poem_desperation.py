n, m = [int(i) for i in input().split()]

sets = []

for i in range(n):
    a = [i.lower() for i in input().split()]
    A = set(a)
    sets.append(A)

indexes = ["X" for i in range(m)]

current = 0
text = input()
words = []

for i in range(m):
    text = input()
    words.append(text.split()[-1].lower())

for i in range(m):
    if indexes[i] != "X":
        continue
    found = False
    for j in range(n):
        if words[i] in sets[j]:
            found = True
            break
    if not found:
        continue

    found = False
    for j in range(i + 1, m):
        for k in range(n):
            if words[i] in sets[k] and words[j] in sets[k]:
                # print("Here", i, j)
                found = True
                indexes[i] = chr(current + ord("A"))
                indexes[j] = chr(current + ord("A"))

    if found:
        current += 1
    else:
        pass
        # indexes[i] = "X"

# print(words)
print("".join(indexes))
