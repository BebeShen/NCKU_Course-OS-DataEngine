# generateInput.py:用來產生input測資
#   使用說明:file_path改成你要產生的檔案的名字
#           seed 是隨機生成字串用的
#           which 用來隨機產生 GET PUT SCAN -> 0~10自己調機率
#           迴圈數字就是測資數量，1000000筆 大概是 140 MB

import random
import time
import sys

random.seed(time.time())

# Set ENV
maxValue = pow(2,31)-1 # 2^31-1
minValue = 0
number_input = 10000000
# file_path = "small_" + str(number_input)+'.input'
file_path = "all_put_1GB.input"
method = ['PUT','GET','SCAN']
seed = "0123456789qazxswedcvfrtgbnhyujmkiolp"

with open(file_path,'w') as f:
    instrs = []
    for i in range(number_input):
        which = random.randint(1,7)
        if which <= 7:
            # PUT
            s = []
            for _ in range(128):
                s.append(random.choice(seed))
            # instr = "PUT" + " " + str(random.randint(minValue,maxValue)) + " " + ''.join(s)
            instr = "PUT" + " " + str(random.randint(0,4000*5-1)) + " " + ''.join(s)
            # print(instr)
            instrs.append(instr+"\n")
        elif which <= 9:
            # GET
            # instr = "GET" + " " + str(random.randint(minValue,maxValue))
            instr = "GET" + " " + str(random.randint(0,7999))
            # print(instr)
            instrs.append(instr+"\n")
        elif which == 10:
            # SCAN
            # k1 = random.randint(minValue,(int)((maxValue / 4) * 3) )
            k1 = random.randint(0,6999)
            k2 = k1 + random.randint(100,1000)
            instr = "SCAN" + " " + str(k1) + " " + str(k2)
            # print(instr)
            instrs.append(instr+"\n")
    f.writelines(instrs)