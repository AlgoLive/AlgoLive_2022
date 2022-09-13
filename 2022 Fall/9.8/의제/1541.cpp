#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char input[100];
    char* context = NULL;
    char* token = NULL;
    int temp = 0;
    int result = 0;
    bool firstMinus = true;

    cin >> input;
    context = input;

    for(int i = 0; context[i] != '\0'; i++){
        if(context[i] == '+'){
            token = strtok_r(context, "+", &context);
            temp += stoi(token);
            i = 0;
        }
        else if(context[i] == '-'){
            token = strtok_r(context, "-", &context);
            temp += stoi(token);
            i = 0;

            if(firstMinus){
                result += temp;
                firstMinus = false;
            }
            else
                result -= temp;

            temp = 0;
        }
    }
    temp += stoi(context);

    if(firstMinus)
        result = temp;
    else
        result -= temp;

    cout << result;

    return 0;
}