#include <string>
#include <vector>

using namespace std;

enum type{
    R,
    T,
    F,
    C,
    M,
    J,
    A,
    N,
}; // 열거형: RTFCMJAN 01234567

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int arr[8];
    // 설문조사 문항은 최대 1000개
    for(int i=0; i < survey.size(); i++)
    {
        // survey[i][0] i+1번째 질문 비동의 0번째 인덱스에 해당하는 성격유형 점수 1~3점 증가
        // survey[i][1] i+1번째 질문 동의, 1번째 인덱스에 해당하는 성격유형 점수 1~3점 증가
        // choice[i] i+1 번째 질문의 선택지
        int select = 4 - choices[i];
        // 321은 비동의, 0, -1-2-3은 동의
        
        if(survey[i] == "RT"){
            if(select > 0) // 비동의, 인덱스 0에 해당하는 R 성향 점수 증가
                arr[R] += select;
            else // 동의, 인덱스 1에 해당하는 T 성향 점수 증가
                arr[T] += -select;               
        } else if(survey[i] == "TR"){
            if(select > 0)
                arr[T] += select;
            else
                arr[R] += -select; 
        } else if(survey[i] == "FC"){
            if(select > 0)
                arr[F] += select;
            else
                arr[C] += -select; 
        } else if(survey[i] == "CF"){
            if(select > 0)
                arr[C] += select;
            else
                arr[F] += -select; 
        } else if(survey[i] == "MJ"){
             if(select > 0)
                arr[M] += select;
            else
                arr[J] += -select; 
        } else if(survey[i] == "JM"){
            if(select > 0)
                arr[J] += select;
            else
                arr[M] += -select; 
        } else if(survey[i] == "AN"){
            if(select > 0)
                arr[A] += select;
            else
                arr[N] += -select; 
        } else{
            if(select > 0)
                arr[N] += select;
            else
                arr[A] += -select; 
        }
    }
    answer += arr[R] >= arr[T] ? "R" : "T"; // 결산 후 점수 비교, 알파벳 출력 순서 규칙 부여된 상태
    answer += arr[F] > arr[C] ? "F" : "C";
    answer += arr[M] > arr[J] ? "M" : "J";
    answer += arr[A] >= arr[N] ? "A" : "N";
    
    return answer;
}