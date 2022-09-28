#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    int result = 0;
    string num = "";
    bool minus = false;

    for(int i=0; i<=str.size(); i++)
    {
        // 연산자는 같은 것이 연속으로 나올 수 없다. 즉 -가 나오면 다음은 무조건 +이다.
        if(str[i] == '+' || str[i] == '-' || str[i] == '\0') // \0을 고려하는 이유: 끝에 도달했을 때 남은 num도 연산해주어야 하기 떄문
        {
            if(minus == true)
            {
                result -= stoi(num);
                // 음수기호가 발견된 상태에서 뒤에 올 값들을 모두 빼버리면 최소가 된다.
                // 예를 들어, 100 + 10 - 20 + 30 - 10 + 20이면, - 뒤에 오는 (a+b) 형태의 모든 값을 빼버리면 된다.
                // 10 + 10 - (50) - (30) 이 최소가 되는 것이다.
            } else {
                result += stoi(num);
            }
            num = "";

            if(str[i] == '-') // 음수기호가 최초로 발견되면 
                minus = true; // true처리
            continue;
        }
        num += str[i]; // 연산자가 아니면 값을 계속 더해준다.
    }
    cout << result;
    return 0;
}
