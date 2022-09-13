#include <iostream>

using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int T;
    int N;
    int price[1000000];

    long long result = 0;
    long long max = -1;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        for (int j = 0; j < N; j++)
        {
            cin >> price[j];
        }

        for (int i = N - 1; i >= 0; i--)
        {
            if (max <= price[i])
                max = price[i];
            else
                result += max - price[i];
        }

        cout << result << '\n';

        max = -1;
        result = 0;
    }
    return 0;
}