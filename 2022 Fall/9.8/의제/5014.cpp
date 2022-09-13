#include <iostream>
#include <queue>
#include <string>

using namespace std;

// BFS는 이렇게 쓰는 것이다!!!

string BFS(int F, int S, int G, int U, int D)
{
    bool visited[1000001] = {
        false,
    };
    int count[1000001] = {
        0,
    };
    queue<int> queue;
    int dir[2];

    visited[S] = true;
    count[S] = 0;
    queue.push(S);

    dir[0] = U;
    dir[1] = -D;

    while (!queue.empty())
    {
        int cur = queue.front();
        queue.pop();

        if (cur == G)
            return to_string(count[cur]);

        // BFS 스킬
        // 자식 노드를 dir로 만들고 해당 자식 노드 수만큼 반복문을 돌림
        for (int i = 0; i < 2; i++)
        {
            int nextPos = cur + dir[i];

            if (1 <= nextPos && nextPos <= F)
            {
                if (!visited[nextPos])
                {
                    visited[nextPos] = true;
                    queue.push(nextPos);
                    count[nextPos] = count[cur] + 1;
                }
            }
        }
    }

    return "use the stairs";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    cout << BFS(F, S, G, U, D);

    return 0;
}