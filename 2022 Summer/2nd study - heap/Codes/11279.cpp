#include <iostream>
#include <queue>

using namespace std;

// https://leeminju531.tistory.com/33

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    int input[100000];
    
    priority_queue<int> heap;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    
    for(int i = 0; i < N; i++){
        if(input[i] == 0){
            if(heap.empty())
                cout << 0 << "\n";
            else {
                cout << heap.top() << "\n";
                heap.pop();
            }
        }
        else {
            heap.push(input[i]);
        }
    }
    
    return 0;
}
