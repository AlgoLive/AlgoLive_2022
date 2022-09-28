#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000];
bool visited[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

void BFS(int startX, int startY)
{
    queue< pair<int, int> > q;

    q.push(make_pair(startX, startY));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if (visited[nx][ny] == false)
                {
                    map[nx][ny] = map[x][y] + 1;
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int destX, destY;

    cin >> N >> M;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            cin >> map[x][y];
            if (map[x][y] == 2)
            {
                // 목표 지점인 경우
                map[x][y] = 0;
                destX = x; destY = y;
                visited[x][y] = true;
            }
            else if (map[x][y] == 0)
            {
                // 갈 수 없는 땅인 경우
                visited[x][y] = true;
                // 0 그대로 출력
            }
        }
    }

    BFS(destX, destY);

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (visited[x][y] == false)
            {
                // 원래 땅인 부분 중에서 도달할 수 없는 위치는 
                // -1을 출력한다 라고 문제에 제시되어 있으므로
                cout << "-1 ";
            }
            else
            {
                cout << map[x][y] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}