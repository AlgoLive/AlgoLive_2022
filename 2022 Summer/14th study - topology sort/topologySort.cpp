#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, inDegree[10], result[10]; //n=정점개수, m=간선개수
vector<vector<int>> graph(10);  //vector<int> graph[10];


void topologySort(){
    queue<int> q;

    for(int i=1; i<=n; i++){    //위상정렬 전, 진입차수 0인 노드를 큐에 삽입
        if(inDegree[i] == 0)
            q.push(i);
    }
    for(int i=1; i<=n; i++){
        if(q.empty()){  //n개의 정점을 모두 돌기 전에 큐가 비면 사이클
            cout << "사이클 발생";
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;  //방문 노드 저장
        for(int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if(--inDegree[y] == 0)    //연결된 노드의 진입차수에서 -1한 값이 0이면 큐에 삽입
                q.push(y);
        }
    }
    for(int i=1; i<=n; i++){    //위상정렬 수행 결과 출력
        cout << result[i] << " ";
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);  //정점 a에서 b로 이동
        inDegree[b]++;  //정점 b의 진입차수 증가
    }
    topologySort();

    return 0;
}

