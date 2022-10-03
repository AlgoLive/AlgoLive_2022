#include<iostream>
#include<string>
using namespace std;

int main(){
    string st;
    cin >> st;

    int result = 0;
    string num;
    bool minus = false;

    for(int i=0; i<=st.size(); i++){
        if(st[i] == '-' || st[i] == '+' || i == st.size()){
            if(minus == true){
                result -= stoi(num);
                num = "";
            }
            else{
                result += stoi(num);
                num = "";
            }
            if(st[i] == '-')
                minus = true;
        }
        else
            num += st[i];
    }
    cout << result;
    return 0;
}