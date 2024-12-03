import jieba
import re
import os
from collections import defaultdict

# 读取文件内容
def read_files(file_paths):
    text = ''
    for file_path in file_paths:
        with open(file_path, 'r', encoding='utf-8') as file:
            text += file.read()
    return text

# 分词并统计词频
def word_frequency(text):
    words = jieba.lcut(text)
    freq_dict = defaultdict(int)
    for word in words:
        freq_dict[word] += 1
    return freq_dict

# 修正统计结果，提取人物名称（简单示例，可以根据具体情况优化）
def filter_and_correct_names(freq_dict):
    # 假设人物名称为两个或三个字的名词
    name_pattern = re.compile(r'[\u4e00-\u9fa5]{2,3}')
    corrected_dict = defaultdict(int)
    for word, freq in freq_dict.items():
        if name_pattern.match(word):
            corrected_dict[word] += freq
    return corrected_dict

# 找出出现次数最多的10个人物
def top_n_names(name_dict, n=10):
    sorted_names = sorted(name_dict.items(), key=lambda x: x[1], reverse=True)
    return sorted_names[:n]

# 主函数
def main():
    os.chdir('D:\C++\字符统计')
    file_paths = ['三国演义.txt']
    text = read_files(file_paths)
    freq_dict = word_frequency(text)
    name_dict = filter_and_correct_names(freq_dict)
    top_names = top_n_names(name_dict)
    
    print("出现次数最多的10个人物：")
    for name, freq in top_names:
        print(f"{name}: {freq}")

if __name__ == "__main__":
    main()