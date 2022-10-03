#include<iostream>
using namespace std;

int A, B, cnt=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    while(true){
        if(A==B){
            cnt++;
            cout << cnt;
            break;
        }
        if(A>B){
            cout << -1;
            break;
        }
        if(B % 10 == 1){
            B--;
            B = B/10; // B /= 10;
        }
        else if(B % 2 == 0){
            B = B/2;
        }
        else{
            cout << -1;
            break;
        }
        cnt++;
    }

    return 0;
}
