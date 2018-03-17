import os, sys
k = os.listdir("GAMELOGS")
print k

for dirname in k:
	if dirname == ".DS_Store" or dirname == "." or dirname == "..":
		continue
	fname = "./GAMELOGS/" + dirname + "/Cleaned_PathLog.txt"
	with open(fname) as f:
		content = f.readlines()
		content = [x.strip() for x in content]
		
		l = content[0::10]
		fp = open("./GAMELOGS/" + dirname + "/saaf.txt", "w+")
		for x in l:
			if len(x.split(" ")) == 2 and x.split(" ")[1] != '':
				fp.writelines(str(x) + "\n")
			else:
				continue
		fp.close()
# you may also want to remove whitespace characters like `\n` at the end of each line
