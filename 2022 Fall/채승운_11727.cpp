#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n;
    int arr[1001];
    
    cin >> n;
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;

    for(int i=4; i<=1000; i++)
    {
        arr[i] = (arr[i-1] + (2 * arr[i-2])) % 10007;
    }
    cout << arr[n] % 10007;
}
