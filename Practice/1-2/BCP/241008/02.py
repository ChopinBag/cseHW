#%%
morse_dict = { "A" : ".-", "B" : "-...", "C" : "-.-.", 
              "D" : "-..", "E" : ".", "F" : "..-.", "G" : "--.",
              "H" : "....", "I" : "..", "J" : ".---", "K" : "-.-",
              "L" : ".-..", "M" : "--", "N" : "-.", "O" : "---", 
              "P" : ".--.", "Q" : "--.-", "R" : ".-.", "S" : "...",
              "T" : "-", "U" : "..-", "V" : "...-", "W" : ".--", 
              "X" : "-..-", "Y" : "-.--", "Z" : "--.."} 
userInput = input()
morse = ""
for i in range(len(userInput)):
    morse += morse_dict[userInput[i]]
print(morse)
# %%