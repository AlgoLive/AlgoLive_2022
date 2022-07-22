#include<iostream>
#define INF 1e9

using namespace std;

int N, M, a, b, num, val = INF;
int d[101][101];

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i != j && d[i][j] != 1)
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
        int tmp=0;
        for(int j=1; j<=N; j++){
            tmp += d[i][j];
        }
        if(tmp < val){
            val = tmp;
            num = i;
        }
    }
    cout << num;
    return 0;
}