#include<iostream>
#define INF 1e9

using namespace std;

int N, M;
int d[101][101];

int main(){
    int a, b, c;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            d[i][j] = INF;
        }
    }
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        if(d[a][b] > c)
            d[a][b] = c;
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
            if(i == j || d[i][j] == INF)
                cout << 0 << " ";
            else
                cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

