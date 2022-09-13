#include <iostream>
#include <queue>

using namespace std;

// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=cksdn788&logNo=220485144752

void printPriority(queue<int> q, int idx[10], int find, int M){
    int count = 1;
    int temp = 0;
    int max = 0;
    
    int i;
    
    for(i = 9; i > 0; i--){
        if(idx[i] != 0){
            max = i;
            break;
        }
    }
    
    while(!q.empty()){
        
        temp = q.front();
        
        if(temp == max && max == find && M == 0){
            cout << count << endl;
            break;
        }
        else if(temp == max){
            idx[max]--;
            if(idx[max] == 0){
                for(i = max - 1; i > 0; i--){
                    if(idx[i] != 0){
                        max = i;
                        break;
                    }
                }
            }
            
            q.pop();
            count++;
            
            M--;
        }
        else {
            q.push(temp);
            q.pop();
            
            M--;
            if(M < 0)
                M = (int)q.size() - 1;
        }
        
    }
}

int main(){
    int test;
    int N[10000] = {0,};
    int M[10000] = {0,};
    
    int input[10000][100] = {{0,},};
    queue<int> q;
    // q는 탐색 X
    
    int key[10000] = {0,};
    int idx[10000][10] = {{0,0,0,0,0,0,0,0,0,0},};
    
    int i,j;
   
    
    cin >> test;
    
    for(i = 0; i < test; i++) {
        cin >> N[i];
        cin >> M[i];
        
        for(j = 0; j < N[i]; j++) {
            cin >> input[i][j];
        }
    }
    
    for(i = 0; i < test; i++) {
        for(j = 0; j < N[i]; j++) {
            q.push(input[i][j]);
            idx[i][input[i][j]]++;
            
            if (j == M[i])
                key[i] = input[i][j];
        }
        printPriority(q, idx[i], key[i], M[i]);
        
        while(!q.empty())
            q.pop();
    }
    
    return 0;
}
