import os, sys
k = os.listdir("GAMELOGS")
print k

for dirname in k:
	#print k[1:]
	if dirname == ".DS_Store" or dirname == "." or dirname == "..":
		continue
	with open("./GAMELOGS/" + dirname + "/PathLog.txt") as f:
		print "./GAMELOGS/" + dirname + "/PathLog.txt"
		content = f.readlines()
		content = [x.strip() for x in content]

		fp = open("./GAMELOGS/" + dirname + "/Cleaned_PathLog.txt", "w+")

		for x in content:
			if len(x.split(" ")) == 2 and x.split(" ")[1] != '':
				fp.writelines(str(x) + "\n")
			else:
				continue

		fp.close()

# you may also want to remove whitespace characters like `\n` at the end of each line
