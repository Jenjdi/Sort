import requests
from bs4 import BeautifulSoup
import jieba
from wordcloud import WordCloud
import matplotlib.pyplot as plt
import os

new_directory = 'd:\\C++\\ciyun'
os.chdir(new_directory)
# 豆瓣影评URL（示例）
url = 'https://movie.douban.com/subject/1292052/comments?status=P'

# 发送HTTP请求
response = requests.get(url)
response.encoding = 'utf-8'

# 解析HTML
soup = BeautifulSoup(response.text, 'html.parser')
comments = soup.find_all('span', class_='short')

# 提取影评内容
text = ' '.join([comment.get_text() for comment in comments])

# 中文分词
seg_list = jieba.cut(text, cut_all=False)
words = ' '.join(seg_list)

# 生成词云
wordcloud = WordCloud(font_path='simhei.ttf', width=800, height=400, background_color='white').generate(words)

# 显示词云
plt.figure(figsize=(10, 5))
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis('off')
plt.show()
