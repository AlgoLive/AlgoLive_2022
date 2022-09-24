#include <iostream>
#include <queue>

using namespace std;

int arr[1000][1000];
bool visited[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

void BFS(int startx, int starty) {
		queue<pair<int, int>> q;

		q.push(make_pair(startx, starty)); // 목표지점 좌표를 중심으로 bfs 개시

		while(!q.empty()) {
			int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < N && 0 <= ny && ny < M)
                {
                    if(visited[nx][ny] == false) // 방문하지 않았다면 값을 더해주고 큐에 이 좌표를 넣은 후 방문처리
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

    int targetx, targety;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 2){ // 목표지점 발견
                arr[i][j] = 0; // 0으로 바꾸고
                targetx = i;
                targety = j; // 좌표 확보
                visited[i][j] = true;
            }
            else if(arr[i][j] == 0)
            {
                visited[i][j] = true;
            }
        }
    }
    
    BFS(targetx, targety);

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < M; j++)
        {
            if(visited[i][j] == false) // bfs를 돌았는데 false다? 갈 수가 없는 곳이다!
            {
                cout << "-1 ";
            }
            else
            {
                cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

// j를 i로 잘못 바꿔놓으니 코드 잘 짜놓고도 컴파일 에러가 터졌던 것.
// 반복문은 항상 잘 살펴보자.