#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K; // 0 <= K <= 10
    int input[1025];

    cin >> K;

    for(int i=1; i <= (int)pow(2, K) - 1; i++){
        cin >> input[i];
    }

    for(int i=K; i >= 1; i--){
        for(int j = 0; j < (int)pow(2, K-i); j++){
            if(j == 0){
                cout << input[(int)pow(2, i-1)];
                cout << " ";
            }
            else {
                cout << input[(int)pow(2, i-1) + (int)pow(2, i) * j];
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}