<<<<<<< HEAD
# Greedy..?
# 한 줄로 들어온 수식을 적절히 괄호를 쳐서 최소로 만들려면, 
# -가 나온 이후부터는 모든 수들을 음수로 만들면 된다.

def sol(raw_data: str) -> int:
    temp = str()
    ans = 0
    trigger = 0

    for i in range(len(raw_data)):
        if raw_data[i].isdigit():
            temp += raw_data[i]
        else:
            if trigger == 1:
                ans -= int(temp) 
                temp = str()
            else:
                if raw_data[i] == '-':
                    trigger = 1
                ans += int(temp)
                temp = str()

    if trigger == 1: ans -= int(temp)
    else: ans += int(temp)
    
    return ans

raw_data = input()
=======
# Greedy..?
# 한 줄로 들어온 수식을 적절히 괄호를 쳐서 최소로 만들려면, 
# -가 나온 이후부터는 모든 수들을 음수로 만들면 된다.

def sol(raw_data: str) -> int:
    temp = str()
    ans = 0
    trigger = 0

    for i in range(len(raw_data)):
        if raw_data[i].isdigit():
            temp += raw_data[i]
        else:
            if trigger == 1:
                ans -= int(temp) 
                temp = str()
            else:
                if raw_data[i] == '-':
                    trigger = 1
                ans += int(temp)
                temp = str()

    if trigger == 1: ans -= int(temp)
    else: ans += int(temp)
    
    return ans

raw_data = input()
>>>>>>> 36d2869ec230063a227952956cdf2a73c80ddf42
print(sol(raw_data))