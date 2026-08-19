import re

topics = []
lines = []
while True:
    line = input()
    if line == "</Thesaurus>":
        break
    elif line == "<Thesaurus>":
        continue
    lines.append(line)
top = [[] for i in range(len(lines))]

i = 0
for line in lines:
    T = re.search(r"(<T>.*</T>)", line)
    top_level = T.group(0)
    top_level = top_level[3 : len(top_level) - 4].lower()
    # print(top_level)
    top[i].append(top_level)

    T = re.search(r"(<NT>.*</NT>)", line)
    if T is not None:
        NTs = T.groups()
        for nt in NTs:
            nt = nt[4 : len(nt) - 5].lower()
            print(nt)
            top[i].append(nt)

    T = re.search(r"(<UF>.*</UF>)", line)
    if T is not None:
        UFs = T.groups()
        for uf in UFs:
            uf = uf[4 : len(uf) - 5].lower()
            print(uf)
            top[i].append(uf)
    i += 1

for i in range(len(top)):
    print(top[i])
