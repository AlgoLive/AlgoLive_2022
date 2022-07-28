#include <iostream>
#define INF 1e9

using namespace std;


int arr[1000][3];
int dp[1000][3];
int N;
int min(int a, int b, int c){
    if (a < b) {
        return a < c ? a : c;;
    } else return b < c ? b : c;
}

int min(int a, int b){
    return a > b ? b : a;
}

int sol(){
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for(int i = 1 ; i < N; i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
    }
    return min(dp[N-1][0], dp[N-1][1], dp[N-1][2]);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i =0 ; i < N ; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout << sol();
}