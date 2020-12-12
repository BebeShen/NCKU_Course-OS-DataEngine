import random
import time
import sys

random.seed(time.time())

# Set ENV
maxValue = pow(2,31)-1
minValue = 0
number_input = 10000
# file_path = "small_" + str(number_input)+'.input'
file_path = "all_PUT_1001000.input"
method = ['PUT','GET','SCAN']
seed = "0123456789qazxswedcvfrtgbnhyujmkiolp"

with open(file_path,'w') as f:
    instrs = []
    for i in range(1001000):
        which = random.randint(1,7)
        if which <= 7:
            # PUT
            s = []
            for _ in range(128):
                s.append(random.choice(seed))
            instr = "PUT" + " " + str(random.randint(minValue,maxValue)) + " " + ''.join(s)
            # print(instr)
            instrs.append(instr+"\n")
        elif which <= 9:
            # GET
            instr = "GET" + " " + str(random.randint(minValue,maxValue))
            # print(instr)
            instrs.append(instr+"\n")
        elif which == 10:
            # SCAN
            k1 = random.randint(minValue,(int)((maxValue / 4) * 3) )
            k2 = k1 + random.randint(250,5000)
            instr = "SCAN" + " " + str(k1) + " " + str(k2)
            # print(instr)
            instrs.append(instr+"\n")
    f.writelines(instrs)