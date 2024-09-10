import random
def getPass():
    string = "qwertyuiopasdfghjklzxcvbnm1234567890"
    password = ""

    for i in range(6):
        index = random.randrange(len(string))
        password += string[index]

    return password

print(getPass())