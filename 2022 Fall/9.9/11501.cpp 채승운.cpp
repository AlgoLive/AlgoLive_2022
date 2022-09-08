#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            arr[i] = x;
        }

        int maxnum = -1;
        long sum = 0;
        // 역발상: 배열을 역행하면서 max 갱신, max보다 작아지는 순간부터 모두 매수해야 최대 수익 습득가능
        for(int i = n-1; i>=0; i--)
        {
            maxnum = max(maxnum, arr[i]);
            sum += (maxnum - arr[i]);            
        }
        cout << sum << "\n";
    }
}
