from urllib.request import urlopen
from bs4 import BeautifulSoup

html = urlopen('https://entertain.daum.net/ranking/popular')
soup = BeautifulSoup(html, 'html.parser')

ol = soup.select_one('.ranking_list')
li = ol.find_all('li')

for dt in li:
    m_rank = dt.find('em').text
    m_title = dt.select_one('.link_txt').text
    print(m_rank, m_title)
