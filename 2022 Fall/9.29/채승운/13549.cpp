#include <iostream>
#include <queue>
#include <functional>

using namespace std;
int n, m;
const int MAX = 100001;
bool visited[MAX];

int findmin(int n, int m)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // 우선순위 큐 : 첫번째는 시간, 두번째는 좌표, 시간 기준 오름차순 정렬이라는 속성을 부여
    q.push(make_pair(0, n)); // 첫번째 요소 삽입

    while(!q.empty())
    {
        int nowtime = q.top().first;
        int nowx = q.top().second;
        q.pop();

        if(nowx == m) // 도착했으면 시간 반환, 어찌됐든 우선순위 큐이므로 자동으로 가장 작은 시간에 해당하는 큐를 반환받을 것이기에, 바로 반환해도 됨.ㄴ
            return nowtime;

        if(nowx * 2 < MAX && visited[nowx*2] == false) // 2배씩 점프!
        {
            q.push(make_pair(nowtime, nowx * 2));
            visited[nowx * 2] = true;
        }

        if(nowx + 1 < MAX && visited[nowx+1] == false) // 한칸 앞으로 갈 때 MAX보다 작아야 함
        {
            q.push(make_pair(nowtime+1, nowx+1));
            visited[nowx+1] = true;
        }

        if(nowx - 1 >= 0 && visited[nowx-1] == false) // 한칸 빽도할때 0보다 작으면 안 됨
        {
            q.push(make_pair(nowtime+1, nowx-1));
            visited[nowx-1] = true;
        }
        // 엘리베이터 스타트링크 문제와 유사
    }
}

int main(void) 
{
    cin >> n >> m;
    cout << findmin(n, m);

    return 0;
}
