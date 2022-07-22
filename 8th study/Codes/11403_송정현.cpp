#include<iostream>
#define INF 1e9

using namespace std;

int N;
int d[101][101];

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> d[i][j];
            if(d[i][j] == 0)
                d[i][j] = INF;
        }
    }
    // 플로이드 워셜 알고리즘
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }    
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(d[i][j] == INF)
                cout << 0 << " ";
            else
                cout << 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

