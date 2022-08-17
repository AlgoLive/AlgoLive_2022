#include <iostream>
#define INF 1e9

using namespace std;

int d[101][101];
int a[101][101];

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int city; cin >> city;
	int bus; cin >> bus;
	
	for (int m = 1; m <= city; ++m) {
		for (int n = 1; n <= city; ++n) {
			d[m][n] = INF;
		}
	}

	for (int m = 1; m <= city; ++m) {
		d[m][m] = 0;
	}

	for (int i = 1; i <= bus; ++i) {
		int city1; int city2; int weight;
		cin >> city1 >> city2 >> weight;
		if (d[city1][city2] > weight) {
			d[city1][city2] = weight;
		}
	}

	for (int k = 1; k <= city; ++k) {
		for (int i = 1; i <= city; ++i) {
			for (int j = 1; j <= city; ++j) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int m = 1; m <= city; ++m) {
		for (int n = 1; n <= city; ++n) {
			if (d[m][n] == INF) cout << 0 << " ";
			else cout << d[m][n] << " ";
		}
		cout << "\n";
	}
}