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
    
    priority_queue<int> maxheap; 
    // for negative number
    priority_queue<int, vector<int>, greater<int> > minheap; 
    // for positive number

    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    
    for(int i = 0; i < N; i++){
        if(input[i] == 0){
            if(maxheap.empty() && minheap.empty())
                cout << 0 << "\n";
            else {
                if(maxheap.empty()){
                    cout << minheap.top() << "\n";
                    minheap.pop();
                }
                else if(minheap.empty()){
                    cout << maxheap.top() << "\n";
                    maxheap.pop();
                }
                else {
                    if(-maxheap.top() > minheap.top()){
                        cout << minheap.top() << "\n";
                        minheap.pop();
                    }
                    else {
                        cout << maxheap.top() << "\n";
                        maxheap.pop();
                    }
                }
            }
        }
        else if(input[i] > 0)
            minheap.push(input[i]);
        else
            maxheap.push(input[i]);
        
    }
    
    return 0;
}
