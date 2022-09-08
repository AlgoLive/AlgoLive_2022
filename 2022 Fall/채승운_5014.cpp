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
        if(now == G)
        {
            return to_string(arr[now] - 1);
        }
        if(now + U <= F)
        {
            if(arr[now + U] == 0){
                arr[now + U] = arr[now] + 1;
                q.push(now + U);
            }
        }
        if(now - D > 0)
        {
            if(arr[now - D] == 0){
                arr[now - D] = arr[now] + 1;
                q.push(now - D);
            }
        }
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
