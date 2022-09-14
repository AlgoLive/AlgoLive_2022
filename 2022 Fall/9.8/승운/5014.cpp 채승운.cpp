#include <iostream>
#include <queue>
using namespace std;

string BFS(int F, int S, int G, int U, int D)
{   
    int arr[F+1];
    for(int i=0; i<=F+1; i++)
    {
        arr[i] = 0;
    }
    queue<int> q;
    q.push(S);
    arr[S] = 1;

    while(q.size() != 0)
    {
        int now = q.front();
        q.pop();
        if(now == G) // 목표 층에 도착한 경우
        {
            return to_string(arr[now] - 1);
        }
        if(now + U <= F) // 목표 층에 도달하지 않음 + 최고층 뚫지 않음
        {
            if(arr[now + U] == 0){ // 최초 방문에만 값이 초기화되어야 함.
                arr[now + U] = arr[now] + 1;
                q.push(now + U);
            }
        }
        if(now - D > 0) // 목표 층에 도달하지 않음 + 내려가야 하는 상황
        {
            if(arr[now - D] == 0){ // 최초 방문에만 값이 초기화되어야 함.
                arr[now - D] = arr[now] + 1;
                q.push(now - D);
            }
        }
        // 한 사이클마다 특정 층 + G층과 특정 층 - D층에 방문 횟수가 새겨짐
    }
    return "use the stairs";
}

int main(void)
{
    int F, S, G, U, D;
    cin>>F>>S>>G>>U>>D;

    cout<<BFS(F, S, G, U, D);
    return (0);
}
