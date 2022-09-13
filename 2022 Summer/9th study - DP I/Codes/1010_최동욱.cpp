#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int count; cin >> count;
	int answer[1001];
	long long DP[31][31];
	DP[0][0] = 1;

	for (int i = 1; i <= 30; i++) {
		for (int j = i; j <= 30; j++) {
			if (i == 1) DP[i][j] = j;
			else if (i == j) DP[i][j] = 1;
			else DP[i][j] = 0;
		}
	}

	for (int c = 0; c < count; ++c){
		int N; int M;
		cin >> N >> M;

		if (DP[N][M] > 0) answer[c] = DP[N][M];
		else {
			for (int i = 2; i <= N; ++i) {
				for (int j = i + 1; j <= M; ++j) {
					DP[i][j] = DP[i][j - 1] + DP[i - 1][j - 1];
				}
			}
			answer[c] = DP[N][M];
		}
	}
	
	for (int i = 0; i < count; ++i) {
		cout << answer[i] << '\n';
	}
	return 0;
}
