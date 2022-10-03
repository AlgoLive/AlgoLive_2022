#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n, dp[1001];
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    dp[4] = 11;

    cin >> n;
    for(int i=5; i<=n; i++){
        dp[i] = (dp[i-1]+dp[i-2]*2)%10007;
    }
    cout << dp[n];

    return 0;
}