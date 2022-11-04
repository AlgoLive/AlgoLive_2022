#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct node {
    int time;
    int alp;
    int cop;
    
    node(int t, int a, int c){
        this->time = t;
        this->alp = a;
        this->cop = c;
    }
    
    bool operator<(const node a) const {
        return this->time > a.time;
    }
} node;

int max(int a, int b){
    return (a > b ? a : b);
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    priority_queue<node> pq;
    int targetAlp = 0;
    int targetCop = 0;
    
    for(int i = 0; i < problems.size(); i++){
        targetAlp = max(problems[i][0], targetAlp);
        targetCop = max(problems[i][1], targetCop);
    }
    
    pq.push(node(0, alp, cop));
    
    while(!pq.empty()){
        node cur = pq.top();
        pq.pop();
        
        if(cur.alp >= targetAlp && cur.cop >= targetCop){
            answer = cur.time;
            break;
        }
        
        pq.push(node(cur.time + 1, cur.alp + 1, cur.cop));
        pq.push(node(cur.time + 1, cur.alp, cur.cop + 1));
        
        for(int i = 0; i < problems.size(); i++){
            if(cur.alp >= problems[i][0] && cur.cop >= problems[i][1]){
                pq.push(node(
                    cur.time + problems[i][4],
                    cur.alp + problems[i][2],
                    cur.cop + problems[i][3]
                ));
            }
        }
    }
    
    return answer;
}