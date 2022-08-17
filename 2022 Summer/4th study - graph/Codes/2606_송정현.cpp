#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int n, m, a, b, num=0;
bool visited[101];

void dfs(int now){
	visited[now] = true;
	num++;
	for(auto next : adj[now]){
		if(!visited[next]) dfs(next);
	}
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    dfs(1);
    cout<<num-1<<"\n";
	return 0;
}