import requests
str = input()
response = requests.get(str)
response.encoding = 'utf-8'
print(response.text)