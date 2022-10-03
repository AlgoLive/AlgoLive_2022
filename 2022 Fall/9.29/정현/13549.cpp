#include<iostream>
#include<queue>
#include<vector>
#define MAX 100001
using namespace std;

int n, k;
bool visited[MAX];
 
int bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, n});
    visited[n] = true;

    while (!q.empty()) {
        int t = q.top().first;
        int x = q.top().second;
        q.pop();
 
        if (x == k) return t;
 
        if (x*2 < MAX && !visited[x*2]) {
            q.push({t, x*2});
            visited[x*2] = true;
        }
        else if (x+1 < MAX && !visited[x+1]) {
            q.push({t+1, x+1});
            visited[x+1] = true;
        }
        else if (x-1 >= 0 && !visited[x-1]) {
            q.push({t+1, x-1});
            visited[x-1] = true;
        }
    }
}

int main(){
    cin >> n >> k;
    cout << bfs() << '\n';

    return 0;
}
