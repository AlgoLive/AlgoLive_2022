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

    int min = INF;
    int sum = 0;
    int min_i = 0;

    cin >> N;
    cin >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            d[i][j] = INF;
            // 0이면 안됨.
        }
    }

    for(int i=1; i<=M; i++){
        int p, q;
        cin >> p >> q;
        d[p][q] = 1;
        d[q][p] = 1;
    }

    floyd(N);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            sum += d[i][j];
        }
        if(sum < min){
            min = sum;
            min_i = i;
        }
        sum = 0;
    }

    // 결과 출력
    cout << min_i;

    return 0;
}
