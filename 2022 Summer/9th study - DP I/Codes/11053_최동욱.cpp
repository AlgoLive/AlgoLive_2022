#include <iostream>
#include <vector>

using namespace std;

int seq[1001];
int dp[1001];

int max(int N, int M) {
	return N > M ? N : M;
}

int solution(int N) {
	if (dp[N] == NULL) {
		dp[N] = 1;
		for (int i = N - 1; i >= 0; i--) {
			if (seq[i] < seq[N]) {
				dp[N] = max(dp[N], solution(i) + 1);
			}
		}
	}
	return dp[N];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int answer = 0;

	int length; cin >> length;
	for (int i = 0; i < length; ++i) {
		cin >> seq[i];
	}
	
	for (int i = 0; i < length; ++i) {
		solution(i);
	}
	
	for (int i = 0; i < length; ++i) {
		answer = max(answer, dp[i]);
	}

	cout << answer;
}