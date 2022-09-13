#include <iostream>
#include <algorithm>

using namespace std;

int N; int K;
int sum;
int heights[300001];
int diffs[300000];

int main() {
	sum = 0;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		cin >> heights[i];
	}

	for (int i = 1; i < N; ++i) {
		diffs[i] = heights[i + 1] - heights[i];
	}

	sort(diffs, diffs + N);

	for (int i = 1; i <= N - K; ++i) {
		sum += diffs[i];
	}
	cout << sum;
}