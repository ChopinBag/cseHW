txtFile = open("/Users/imseung-u/Documents/GitHub/cseHW/Practice/Intro_to_Computer&Program/240514/songs.txt", 'r')
lines = txtFile.read()
print(lines)

def process(w):
    output = ""
    for ch in w:
        if (ch.isalpha()):
            output += ch
    return output.lower()
words = {}

txtFile.close()
