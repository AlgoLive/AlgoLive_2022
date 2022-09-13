#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define INF 1e9

using namespace std;

int n, m, start;
// start -> 2��° ��
// n, m -> 1��° ���� 0(node), 1��° ���� 1(vertex)
// ���� -> 3��° �ٺ����� 0�� 1 ���̰� 2�� ����ġ�� �ִ�

vector< pair<int, int> > graph[20001];
// graph ǥ��. index->node, vertex_weight 
int d[20001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
		int until = graph[now].size();
		
		for (int i = 0; i < until; ++i) {
			int cost = graph[now][i].second + dist;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> start;
	
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	fill(d, d + 20001, INF);

	dijkstra(start);
	
	for (int i = 1; i <= n; ++i) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}