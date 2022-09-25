#include <iostream>

using namespace std;

int dp[1001][1001];
int N, M;

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int max(int x, int y){
    return (x >= y) ? x : y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char input[1001];
    int result = 0;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            dp[i][j+1] = input[j] - '0';
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if(dp[i][j] != 0){
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
                result = max(dp[i][j], result);
            }
        }
    }

    cout << result * result;

    return 0;
}
