#include <iostream>

#define INF 1e9

using namespace std;

int N;
int M;
int d[101][101]; // 결과 그래프
// int a[101][101]; // 입력 그래프

void floyd(int n) {
    // 플로이드 워셜 알고리즘
    for(int k=1; k<=n; k++){// k = 거쳐가는 노드
        for(int i=1; i<=n; i++){// i = 출발 노드
            for(int j=1; j<=n; j++){// j = 도착 노드
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main(){

    int p, q, w;

    cin >> N;
    cin >> M;

    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(i == j){
                d[i][j] = 0;
            }
            else{
                d[i][j] = INF;
            }
        }    
    }

    for(int i=1; i<=M; i++){
        cin >> p >> q >> w;
        if (w < d[p][q])
        {
            d[p][q] = w;
        }
    }

    floyd(N);

    // 결과 출력
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(d[i][j] == INF)
                cout << 0 << " ";
            else
                cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
