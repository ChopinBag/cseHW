from bs4 import BeautifulSoup

with open('MyTest.html','r',encoding='utf-8') as file:
    html_content = file.read()
    
    soup = BeautifulSoup(html_content, 'html.parser')
    green_txt = soup.find_all(class_ = 'red')
    for txt in green_txt:
        print(txt.get_text())
        
    div = soup.find(id = 'text')
    for _ in div:
        print(div.get_text())