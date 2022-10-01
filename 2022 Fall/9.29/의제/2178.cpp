/**
 * @file 2178.cpp
 * @author euije (exitfill1234@naver.com)
 * @brief BFS는 모든 간선의 가중치가 동일해야 한다는 전제 조건이 필요
 *          + BOJ 에서 char * 을 인풋 받을 때 자동 초기화가 안됨.
 * @version 0.1
 * @date 2022-10-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
bool visited[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

void BFS(int startX, int startY)
{
    queue< pair<int, int> > q;

    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;

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

    char input[100][100];

    cin >> N >> M;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            visited[x][y] = false;
        }
    }

    for (int x = 0; x < N; x++)
    {
        cin >> input[x];
        for (int y = 0; y < M; y++)
        {
            map[x][y] = input[x][y] - '0';

            if (map[x][y] == 0)
            {
                // 갈 수 없는 땅인 경우
                visited[x][y] = true;
            }
        }
    }

    BFS(0,0);

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            cout << map[x][y] << ' ';
        }
        cout << '\n';
    }

    cout << map[N-1][M-1];

    return 0;
}