#include <iostream>

using namespace std;

/*
    [x][0] : x번째 열에 사자를 한 마리도 배치하지 않는 경우의 수
    [x][1] : x번째 열에 사자를 왼쪽에 배치하는 경우의 수
    [x][2] : x번째 열에 사자를 오른쪽에 배치하는 경우의 수
*/
int dp[100001][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    if(N == 1){
        cout << 3 % 9901;
        return 0;
    }

    for(int i = 2; i <= N; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }

    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
    
    return 0;
}