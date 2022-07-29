#include <iostream>

using namespace std;

int arr[10000];
int dp[10000];

int max(int a, int b){
    return a > b ? a : b;
}

int sol(int num){
    int maxD = 0;

    if(num == 0){ return 0;}
    if(num == 1){ return arr[0];}

    /*for(int i = 3 ; i < num ; i++){
        for(int j=i; num-j > 0; j++){
            if(num-j-2 > 0){
                maxD = max(maxD, arr[num-j]+dp[num-j-2]);
            }else{
                maxD = max(maxD, arr[num-j])
            }
        }*/

    /*for(int i = 0 ; i < num ; i++){
        if(num-i-2 > 0){
            maxD = max(maxD, arr[num-i-1]+dp[num-i-2-1]);
            //cout << "num : " << num <<  " i : " << i << " maxD : " << maxD << endl;
        }else{
            maxD = max(maxD, dp[num-i-2]);
            //cout << "num : " << num << " i : " << i << " maxD : " << maxD << endl;
        }
    }*/
    maxD = max(arr[num-1] + dp[num-3], dp[num-2]);

        //cout << "num : " << num <<  " i : " << i << " maxD : " << maxD << endl;

        //cout << "num : " << num << " i : " << i << " maxD : " << maxD << endl;

    return maxD;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, ans = 0;
    cin >> N;


    for(int i =0 ; i < N ; i++){
        cin >> arr[i];
    }

    for(int i =0 ; i < N ;i++){
        dp[i] = sol(i) + arr[i];
        if(i>0){
            dp[i] = max(dp[i], dp[i-1]); //연속 2회 안 마실경우
        }
        ans = dp[i];
        //cout << " ans : " << ans << endl;
    }
    cout << ans;
}



