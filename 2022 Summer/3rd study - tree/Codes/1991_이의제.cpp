#include <iostream>

using namespace std;

char tree[54] = {'.',};
char input[3];

void preorder(int i){
    if(tree[i] == '.') return;

    cout << tree[i];
    preorder(2*i);
    preorder(2*i+1);
}

void inorder(int i){
    if(tree[i] == '.') return;

    inorder(2*i);
    cout << tree[i];
    inorder(2*i+1);
}

void postorder(int i){
    if(tree[i] == '.') return;

    postorder(2*i);
    postorder(2*i+1);
    cout << tree[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++){
            cin >> input[j];
        }
        tree[i] = input[0];
        tree[2*i] = input[1];
        tree[2*i+1] = input[2];
    }

    for(int i=1; i<=N; i++){
        cout << tree[i];
    }
    // preorder(1);
    // inorder(1);
    // postorder(1);

    // 왜안되지,,,,

    
    return 0;
}