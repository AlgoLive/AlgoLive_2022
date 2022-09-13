#include <iostream>
#include <queue>

using namespace std;

int graph[1001][1001];
int visited[1001];

void init(){
    for(int i=1; i<=1001; i++){
        visited[i] = 0;
    }
}

void dfs(int node){
    visited[node] = 1;

    cout << node << " ";

    for(int i=1; i<=1001; i++){
        if(graph[node][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for(int i=1; i<=1001; i++){
            if(graph[cur][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    int V;

    int a,b;

    cin >> N;
    cin >> M;
    cin >> V;

    for(int i = 0; i < M; i++){
        cin >> a;
        cin >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(V);

    init();
    cout << '\n';
    
    bfs(V);

    return 0;
}