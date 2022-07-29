#include <iostream>

using namespace std;

int N;
int arr[1000];
int dp[1000];

int max(int a, int b){
    return a > b ? a : b;
}

int sol(){
    int maxD;
    dp[0] = arr[0];
    for(int i =1 ; i < N ; i++){
        maxD = 0;
        for(int j=0; j < i; j++){
            maxD = max(maxD, arr[j]+dp[i-j-1]);
            maxD = max(maxD, arr[i]);
        }
        dp[i] = maxD;
    }
    return dp[N-1];
}

int main(void){
    cin >> N;
    for(int i = 0; i < N ; i++){
        cin >> arr[i];
    }
    cout << sol();
}