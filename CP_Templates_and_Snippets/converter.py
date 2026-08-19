import os, json, re

infilepath = os.path.join(os.path.dirname(__file__), "code.cpp")
outfilepath = os.path.join(os.path.dirname(__file__), "snippet.json")

outfile = open(outfilepath, "w")
# obj = {
#     "LCA_snippet": [
#         {
#             "scope": "cpp",
#             "prefix": "lca_cp_snippet",
#             "body": [
#                 "class DSU {",
#                 "    public:",
#                 "    int n;",
#                 "    vector<int> parent, size;",
#                 "",
#             ],
#         }
#     ]
# }

# json.dump(obj, outfile)

snippets = {"top-level": []}

# """
with open(infilepath, "r") as infile:
    cnt = 0
    buffer = []
    for line in infile:
        line = line.rstrip()
        # line = re.sub('"', r"\"", line)
        if line.startswith("//"):
            cnt += 1
        if cnt > 1:
            obj = {
                f"{buffer[0][3:]}_snippet": {
                    "scope": "cpp",
                    "prefix": f"{re.sub(' ', '_', buffer[0][3:]).lower()}",
                    "body": buffer[1:],
                }
            }
            snippets["top-level"].append(obj)
            # outfile.write(buffer[0][3:] + "\n")
            # for b in buffer:
            #     outfile.write(b + "\n")
            cnt -= 1
            buffer = [line]
        else:
            buffer.append(line)
# """
json.dump(snippets, outfile)
outfile.close()
