# -*-encoding: utf-8 -*-

#문제 요구사항을 잘 참고하면 -가 한번이라도 나온다면 그 이후의
#숫자들은 전부 뺄 수 있음.
#따라서 -가 처음 나온 위치를 찾아 그 뒤 수들을 다 빼면됨
import sys
 
exp = list(sys.stdin.readline())
hyphenLocation = 0                  #-의 위치
isHypgen = 0                        #-가 한번이라도 나왔는지 확인

for i in range(len(exp)) :          #문자열에서 +,- 를 체크하고 .으로 바꿔 저장
    if exp[i] == '+':
        exp[i] = '.'
        if isHypgen :
            continue
        hyphenLocation += 1
    elif exp[i] == '-':
        exp[i] = '.'
        if isHypgen :
            continue
        hyphenLocation += 1
        isHypgen = 1
        
exp = ''.join(exp)                  #배열을 문자열로 변환
expList = exp.split('.')            #문자열을 .을 기준으로 분리
answer = 0                          #정답을 담을 변수

for i in range(len(expList)) :
    if hyphenLocation <= i and isHypgen == 1:   #-가 있고, 그 첫 위치를 참조하면
        answer -= int(expList[i])               #뺄셈
    else : answer += int(expList[i])            #예외 경우는 덧셈

print(answer)

#파싱을 하는 과정의 간소화 가능?
#첫 위치를 파악한 이후에는 불필요한 if문을 어찌할까...