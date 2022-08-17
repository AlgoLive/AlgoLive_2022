#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, preNum, preNode;
int time[10001];
int inDegree[10001], result[10001];
vector<vector<int>> graph(10001);

void topologySort(){
    queue<int> q;

    for(int i=1; i<=n; i++){   
        if(inDegree[i] == 0)
            q.push(i);
        result[i] = time[i];
    }
    while(!q.empty()){
        int x = q.front();
        q.pop(); 

        for(int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if(--inDegree[y] == 0) 
                q.push(y);
            result[y] = max(result[y], result[x]+time[y]);  // 동시진행 고려해 가장 늦게 끝나는 작업 시간
        }
    }
    int print=0;
    for(int i=1; i<=n; i++){
        print = max(print, result[i]);
    }
    cout << print;  
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> time[i] >> preNum;
        for(int j=0; j<preNum; j++){
            cin >> preNode;
            graph[preNode].push_back(i);    //입력받은 선행된 노드에 현재 노드 연결
            inDegree[i]++;
        }
    }
    topologySort();

    return 0;
}