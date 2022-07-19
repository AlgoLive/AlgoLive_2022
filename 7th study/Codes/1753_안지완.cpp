#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int v,e,k;
vector<pair<int, int> > graph[20001];
int d[20001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist) continue;
        for (int i = 0; i < graph[now].size(); i++) { //현재 노드에 연결된 간선의 갯수만큼 선회 시작
            int cost = dist + graph[now][i].second;
            if (cost < d[graph[now][i].first]) { //경유해서 탄 Cost가 (새롭게 발견한 경로) 현재 적힌 최단경로보다 작으면
                d[graph[now][i].first] = cost; //갱신한다.
                pq.push(make_pair(-cost, graph[now][i].first)); //우선순위 큐에 push (최소힙으로)
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e >> k;

    for (int i = 0; i < e; i++) {
        int a, b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    fill(d, d + 20001, INF);

    dijkstra(k);

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) {
            cout << "INF" << "\n";
        }else{
            cout << d[i] << "\n";
        }
    }
}