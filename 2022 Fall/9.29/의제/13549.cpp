/**
 * @file 13549.cpp
 * @author euije (exitfill1234@naver.com)
 * @brief BFS에 우선순위 큐를 활용할 수 있다.
 * @version 0.1
 * @date 2022-10-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
    int second;
    int x;
    bool over;
    node(int _second, int _x, bool _over) : second(_second), x(_x), over(_over) {}
    bool operator<(const node s) const
    {
        return this->second > s.second;
    }
} node;

int visited[200001];
int dsecond[3] = {1, 1, 0};
int dx[3] = {-1, 1, 0};

int BFS(int N, int K)
{
    priority_queue<node> pq;

    pq.push(node(0, N, false));
    visited[N] = 0;

    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();

        // cout << "S: " << cur.second << " X: " << cur.x << " over " << cur.over << '\n';

        if (cur.x == K)
            return cur.second;

        for (int i = 0; i < 3; i++)
        {
            int nsecond = cur.second + dsecond[i];
            int nx = (i != 2 ? cur.x + dx[i] : cur.x * 2);
            bool nover = (nx > K ? true : false);

            if ((0 <= nx && nx <= K) || (nx > K && cur.over == false))
            {
                if (visited[nx] > nsecond)
                {
                    pq.push(node(nsecond, nx, nover));
                    visited[nx] = nsecond;
                }
            }
        }
    }

    return -1;
}

int main()
{
    int N, K;

    cin >> N >> K;

    for(int i = 0; i < 200001; i++)
        visited[i] = 100001;

    if(N < K)
        cout << BFS(N, K);
    else
        cout << N - K;

    return 0;
}