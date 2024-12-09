from bs4 import BeautifulSoup
# HTML 파일 읽기
with open('MyTest.html', 'r', encoding='utf-8') as file:
    html_content = file.read()
# BeautifulSoup 객체 생성
soup = BeautifulSoup(html_content, 'html.parser')
# class가 green인 부분 추출
green_texts = soup.find_all(class_='red')
# 추출한 내용 출력
for text in green_texts:
    print(text.get_text())
