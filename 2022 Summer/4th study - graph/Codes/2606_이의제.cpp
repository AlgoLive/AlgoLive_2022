#include <iostream>
#include <queue>

using namespace std;

int graph[101][101];
int visited[101];
int cnt = 0;

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=1; i<=100; i++){
            if(graph[cur][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                cnt++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int V;

    int a,b;

    cin >> N;
    cin >> V;

    for(int i = 0; i < V; i++){
        cin >> a;
        cin >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    bfs(1);
    cout << cnt;

    return 0;
}