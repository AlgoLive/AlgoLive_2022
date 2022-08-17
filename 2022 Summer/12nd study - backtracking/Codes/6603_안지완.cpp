#include <iostream>
using namespace std;

int K=1;
int arr[13];
int temp[13];
bool visited[6];

void dfs(int depth, int prev){
    if(depth == 6){
        for(int i= 0 ; i < 6 ; i++){
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i =0 ; i < K; i++){
        if(!visited[i] && prev < arr[i]){
            visited[i] = true;
            temp[depth] = arr[i];
            prev = temp[depth];
            dfs(depth+1, prev);
            visited[i] = false;
        }
    }
}

int main(){
    while(K != 0){
        cin >> K;
        for(int i = 0 ; i < K ; i++){
            cin >> arr[i];
        }
        dfs(0,0);
        cout << "\n";
    }
}