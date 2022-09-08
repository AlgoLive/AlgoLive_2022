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
        // i번째의 개수는 i-1번째의 모든 개수에서 한개의 직사각형이 추가되는 경우와, i-2번째의 모든 개수에서 정사각형을 더하는 경우 + 직사각형 두개를 더하는 경우이다.
    }
    cout << arr[n] % 10007;
}
