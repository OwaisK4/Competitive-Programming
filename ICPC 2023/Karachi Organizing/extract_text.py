import pypdf

filename = "Scoreboard ICPC_Online_23 - DOMjudge.pdf"
f = open(filename, "rb")
output = open("output", "a")

pdf = pypdf.PdfReader(f)
# text = pdf.pages[0].extract_text()
# print(text)
pages = pdf.pages
# for page in pages:
#     output.write(page.extract_text())
for i in range(2):
    output.write(pages[i].extract_text())

f.close()
output.close()
