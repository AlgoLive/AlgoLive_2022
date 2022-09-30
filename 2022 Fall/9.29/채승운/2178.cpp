#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

void BFS(int startx, int starty) {
		visited[startx][starty] = true;
        queue<pair<int, int>> q;
		q.push(make_pair(startx, starty));

		while(!q.empty()) {
			int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 < nx && nx <= N && 0 < ny && ny <= M)
                {
                    if(arr[nx][ny] == 1 && visited[nx][ny] == false) // 방문하지 않았다면 값을 더해주고 큐에 이 좌표를 넣은 후 방문처리
                    {
                        visited[nx][ny] = true;
                        arr[nx][ny] = arr[x][y] + 1;
                        q.push(make_pair(nx,ny));
                    }      
                }
			}
		}
	}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    string str;
    for(int i = 1; i <= N; i++)
    { 
        cin >> str;
        for(int j = 1; j <= M; j++)
        {
            arr[i][j] = str[j-1] - '0';
        }
    }
    
    BFS(1, 1);
    cout << arr[N][M];
    return 0;
}