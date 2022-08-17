#include <iostream>
#define INF 1e9

using namespace std;

int N = 4;
int d[101][101];
int a[101][101];

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int count;
	cin >> count;
	for (int m = 0; m < count; ++m) {
		for (int n = 0; n < count; ++n) {
			cin >> d[m][n];
			if (d[m][n] == 0)
				d[m][n] = INF;
		}
	}

	for (int k = 0; k < count; ++k) {
		for (int i = 0; i < count; ++i) {
			for (int j = 0; j < count; ++j) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int m = 0; m < count; ++m) {
		for (int n = 0; n < count; ++n) {
			if (d[m][n] == INF)
				d[m][n] = 0;
			else
				d[m][n] = 1;
		}
	}

	for (int m = 0; m < count; ++m) {
		for (int n = 0; n < count; ++n) {
			cout << d[m][n] << " ";
		}
		cout << "\n";
	}
}