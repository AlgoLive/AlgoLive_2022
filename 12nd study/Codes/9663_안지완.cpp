#include <iostream>

using namespace std;

int N;
int arr[16]; //
int ans;

bool isPossible(int row){
    for(int i =0 ; i < row ;i++){ //dfs를 통해 해당 행까지 탐색
        if((arr[i] == arr[row]) || row-i == abs(arr[i]-arr[row])){ //현재 위치의 행에 놓여있는 퀸의 열과 같은 값의 열이 발견되거나,
            //대각선이라면
            return false; //탐색 종료 후 BackTrack
        } //같은 열 or 대각선
    }
    return true;
}

void dfs(int row){
    if(row == N){
        ans++;
        return;
    }else{
        for(int i =0 ; i < N ; i++){ //행 row에서 0부터 N까지 열 탐색
            arr[row] = i; //해당 행,열에 Queen 체스말 우선 배치
            if(isPossible(row)){ //배치 후 조건이 안 맞으면 즉시 중단하고 다음 열 탐색
                dfs(row+1);
            }
        }
    }
}
int main(void){
    cin >> N;
    dfs(0);
    cout << ans;
}