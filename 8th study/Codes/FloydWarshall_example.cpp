#include<iostream>
#define INF 1e9

using namespace std;

int N = 4;
int d[4][4]; // 결과 그래프
int a[4][4] = {
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

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
    for(int i=0; i<N; i++){
        for(int j=0; j<N; i++){
            d[i][j] = a[i][j];
        }    
    }

    floyd(N);

    // 결과 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }    
}

