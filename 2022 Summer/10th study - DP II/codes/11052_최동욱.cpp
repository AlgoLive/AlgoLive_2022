#include <iostream>
#include <vector>

using namespace std;

int N;
int price[1001];
int memo[1001];

int max(int N, int M) {
	return N > M ? N : M;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> price[i];
	}
	memo[0] = 0;
	memo[1] = price[1];

	for (int i = 2; i <= N; ++i) {
		vector<pair<int, int> > cal;
		for (int j = 0; j <= i / 2; ++j) {
			cal.push_back(make_pair(j, i - j));
		}
		int maxNum = 0;
		for (int k = 1; k <= i / 2; ++k) {
			int value = memo[cal[k].first] + memo[cal[k].second];
			maxNum = max(maxNum, value);
		}
		maxNum = max(maxNum, price[i]);
		memo[i] = maxNum;
	}
	cout << memo[N];
}