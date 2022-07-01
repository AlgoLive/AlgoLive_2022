#include <iostream>
#include <queue>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        if(abs(a)>abs(b)){
            return true;
        }else if(abs(a) < abs(b)){
            return false;
        }

        if(a < b){
            return false;
        }
        return true;
    }
};
int main(){
    priority_queue<int, vector<int>, compare> pq;
    int N, input;
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> input;
        if(input == 0){
            if(pq.empty()){
                cout << 0 << endl;
            }else{
                cout << pq.top() << endl;
                pq.pop();
            }
        }else{
            pq.push(input);
        }
    }

}