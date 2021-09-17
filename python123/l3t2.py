'''#实例4：文本进度条 多行
import time 
s = '*' * 10
print (s)
scale = 10
for i in range (scale + 1):
    a = '*' * i
    b = '.' * (scale - i)
    c = (i / scale) * 100
    print("\r{:^3.0f}%[{}->{}]".format(c,a,b),end='')
    time.sleep(0.1)
print("")'''
#实例4：文本进度条 单行动态刷新 /r
'''
import time
for i in range(101):
    print("\r{:3}%".format(i),end='')
    time.sleep(0.1)
'''
import time
scale = 50
print("执行开始".center(scale//2,'-'))
start = time.perf_counter()
for i in range(51):
    a = '*' * i
    b = '.' * (scale - i)
    c = (i / scale) * 100
    der = time.perf_counter() - start
    print("\r{:^3.0f}%[{}->{}]{:.2f}s".format(c,a,b,der),end='')
    time .sleep(0.1)
print("\n"+"执行结束".center(scale // 2, "-") )