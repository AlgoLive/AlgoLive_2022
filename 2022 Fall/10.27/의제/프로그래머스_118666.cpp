#include <string>
#include <vector>

using namespace std;

/*
    R T
    C F
    J M
    A N
*/

/*
    [0] -> 비동의
    [1] -> 동의
*/

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    int score[100] = {0 , };

    for(int i = 0; i < survey.size(); i++){
        int choice = choices[i];
        
        if(choice >= 4)
            score[survey[i][1]] += choice - 4;
        else
            score[survey[i][0]] += 4 - choice;
    }

    answer += score['R'] >= score['T'] ? 'R' : 'T';
    answer += score['C'] >= score['F'] ? 'C' : 'F';
    answer += score['J'] >= score['M'] ? 'J' : 'M';
    answer += score['A'] >= score['N'] ? 'A' : 'N';
    return answer;
}