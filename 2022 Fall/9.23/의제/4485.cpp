#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

typedef struct Pair
{
    int x;
    int y;
    int weight;
    Pair(int x, int y, int weight) : x(x), y(y), weight(weight) {}

    bool operator<(const Pair s) const
    {
        return this->weight > s.weight;
    }
} Pair;

// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
// 125 * 125 * 4
vector<Pair> graph[125][125];
// 최단 거리 테이블 만들기
int d[125][125];
int N; // 동굴의 갯수

void dijkstra(int startX, int startY)
{
    priority_queue<Pair> pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push(Pair(startX, startY, 0));
    d[startX][startY] = 0;
    while (!pq.empty())
    { // 큐가 비어있지 않다면
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int dist = pq.top().weight; // 현재 노드까지의 비용
        int nowX = pq.top().x;      // 현재 노드
        int nowY = pq.top().y;      // 현재 노드
        pq.pop();

        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (d[nowX][nowY] < dist)
            continue;

        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (vector<Pair>::iterator iter = graph[nowX][nowY].begin();
             iter != graph[nowX][nowY].end();
             iter++)
        {
            int cost = dist + iter->weight;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[iter->x][iter->y])
            {
                d[iter->x][iter->y] = cost;
                pq.push(Pair(iter->x, iter->y, cost));
            }
        }
    }
}

void testGraph(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << i << " , " << j << "의 인접 노드 : ";
            for (vector<Pair>::iterator iter = graph[i][j].begin();
                 iter != graph[i][j].end();
                 iter++)
            {
                cout << "(" << iter->x << "," << iter->y << "," << iter->weight << ")";
            }
        }
        cout << '\n';
    }
}

void testDistance(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}

void initDistance(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            d[i][j] = INF;
}

void initGraph(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            graph[i][j].clear();
            vector<Pair>().swap(graph[i][j]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int W;
    int count = 1;
    int ans[125];

    while (1)
    {
        cin >> N;

        if (N == 0)
            break;

        // 모든 간선 정보를 입력받기
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int weight;
                cin >> weight;
                if (i == 0 && j == 0)
                    W = weight;

                if (0 <= i - 1 && i - 1 < N && 0 <= j && j < N)
                    graph[i - 1][j].push_back(Pair(i, j, weight));

                if (0 <= i + 1 && i + 1 < N && 0 <= j && j < N)
                    graph[i + 1][j].push_back(Pair(i, j, weight));

                if (0 <= i && i < N && 0 <= j - 1 && j - 1 < N)
                    graph[i][j - 1].push_back(Pair(i, j, weight));

                if (0 <= i && i < N && 0 <= j + 1 && j + 1 < N)
                    graph[i][j + 1].push_back(Pair(i, j, weight));

                // u번 노드에서 v번 노드로 가는 비용이 1라는 의미
                // graph[u].push_back(make_pair(v, 1));
            }
        }

        // 최단 거리 테이블을 모두 무한으로 초기화
        initDistance();

        // 다익스트라 알고리즘을 수행
        dijkstra(0, 0);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                d[i][j] += W;
            }
        }

        ans[count] = d[N - 1][N - 1];
        count++;
        initGraph();
    }

    for(int i = 1; i < count; i++)
        cout << "Problem " << i << ": " << ans[i] << '\n';

    return 0;
}