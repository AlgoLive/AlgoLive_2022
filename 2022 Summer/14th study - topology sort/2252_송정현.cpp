#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int inDegree[32001], result[32001];
vector<vector<int>> graph(32001);

void topologySort(){
    queue<int> q;

    for(int i=1; i<=n; i++){   
        if(inDegree[i] == 0)
            q.push(i);
    }
    for(int i=1; i<=n; i++){
        int x = q.front();
        q.pop();
        result[i] = x;  

        for(int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if(--inDegree[y] == 0) 
                q.push(y);
        }
    }
    for(int i=1; i<=n; i++){    
        cout << result[i] << " ";
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); 
        inDegree[b]++;  
    }
    topologySort();
    
    return 0;
}