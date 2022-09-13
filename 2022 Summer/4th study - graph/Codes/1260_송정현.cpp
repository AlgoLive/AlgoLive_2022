#include <bits/stdc++.h>

using namespace std;
int n, m, v, a, b;
bool visited[10001];
vector<int> adj[10001];

void reset(){
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}
void bfs(int start){
    queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
        cout<<now<<" ";
		for(auto next : adj[now]){
			if(!visited[next]){
                q.push(next);
			    visited[next] = true;
            }
		}
	}
}
void dfs(int now){
    cout<<now<<" ";
	visited[now] = true;
	for(auto next : adj[now]){
		if(!visited[next]) dfs(next);
	}
}

int main(void) {
   cin>>n>>m>>v;
   for(int i=0; i<m; i++){
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
   for(int i=1; i<=n; i++){
      sort(adj[i].begin(), adj[i].end());
   }
   reset();
   dfs(v);
   cout<<"\n";
   reset();
   bfs(v);

   return 0;
}