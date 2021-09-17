#天天向上的力量
def dayup(df):
    ddu = 1
    for i in range(365) :
        if i % 7 in[0,6] :
            ddu = ddu * (1 - 0.01)
        else :
            ddu = (1 + df) * ddu
    return ddu
du = 1
for i in range(365):
    du *= 1.01
df = 0.01
while dayup(df) < du:
    df += 0.001
print ("{:.3f}".format(df))