import os, re

for dir, subdirs, files in os.walk("."):
    for file in files:
        # print(file)
        if not file.endswith(".cpp"):
            continue
        f = open(os.path.join(dir, file), "r")
        # print(f)
        text = f.read()
        dfsSearch = re.compile(r"dfs")
        mo = dfsSearch.search(text)
        if mo == None:
            continue
        else:
            print("DFS string found in " + os.path.join(dir, file))