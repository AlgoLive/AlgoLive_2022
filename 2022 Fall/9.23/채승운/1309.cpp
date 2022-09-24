#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int dp[n+1][3];

    dp[1][0] = 1; // 넣지 않음
    dp[1][1] = 1; // 좌
    dp[1][2] = 1; // 우

    // dp의 의미: 최대 i행에서 i번째 행에 넣지 않거나, 왼쪽에 넣었거나, 오른쪽에 넣었을 때를 의미하는 경우의 수
    for(int i=2; i<=n; i++)
    {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }
    int result = (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
    cout << result;
}
