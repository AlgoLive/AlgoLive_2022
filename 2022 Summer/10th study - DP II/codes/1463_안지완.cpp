#include <iostream>

using namespace std;

int N;
int dp[1000001];

int min(int a, int b){
    return a > b ? b : a;
}

int sol(int N){
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i =4 ; i < N+1 ; i++){
        if(i % 2 == 0 && i % 3 == 0){
            dp[i] = min(dp[i/3], dp[i/2])+1;
        }
        else if(i % 3 == 0){
            dp[i] = min(dp[i/3], dp[i-1])+1;
        }else if(i % 2== 0) {
            dp[i] = min(dp[i/2], dp[i-1])+1;
        }else{
            dp[i] = dp[i-1] + 1;
        }
    }
    return dp[N];
}

int main(void){
    cin >> N;
    cout << sol(N);
}