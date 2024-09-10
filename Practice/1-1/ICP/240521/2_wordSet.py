txtFile = open("/Users/imseung-u/Documents/GitHub/cseHW/Practice/Intro_to_Computer&Program/240514/songs.txt", 'r')
lines = txtFile.read()

table = dict()
for i in txtFile:
    words = i.split()
    for word in words:
        if word not in table:
            table[word] = 1
        else:
            table[word] += 1

print(table)