#include <iostream>
#define INF 1e9

using namespace std;

int d[101][101];
int sum[101];

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int users; int network;
	cin >> users >> network;
	for (int m = 1; m <= users; ++m) {
		for (int n = 1; n <= users; ++n) {
			d[m][n] = INF;
		}
	}

	for (int m = 1; m <= users; ++m) {
		d[m][m] = 0;
	}

	for (int i = 1; i <= network; ++i) {
		int user1; int user2;
		cin >> user1 >> user2;
		d[user1][user2] = 1;
		d[user2][user1] = 1;
	}

	for (int k = 1; k <= users; ++k) {
		for (int i = 1; i <= users; ++i) {
			for (int j = 1; j <= users; ++j) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int min = 1;

	for (int m = 1; m <= users; ++m) {
		sum[m] = 0;
		for (int n = 1; n <= users; ++n) {
			sum[m] += d[m][n];
		}
		if (sum[m] < sum[min]) min = m;
	}

	cout << min;
	
}