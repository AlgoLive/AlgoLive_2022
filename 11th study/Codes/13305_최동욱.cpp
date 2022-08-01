#include <iostream>

using namespace std;

int oil[100001];
int road[100000];
int N;
int lowCity;
int now;
int flag;

long long solution() {
	long long cost = 0;
	long long _oil = oil[lowCity];
	for (now = lowCity; now < N; ++now) {
		if (_oil > oil[now]) {
			lowCity = now;
			break;
		}
		cost += _oil * road[now];
	}
	return cost;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long cost = 0;

	cin >> N;
	for (int i = 1; i < N; ++i) {
		cin >> road[i];
	}
	for (int i = 1; i <= N; ++i) {
		cin >> oil[i];
	}

	flag = 1;
	now = 1;
	lowCity = 1;

	while (flag) {
		cost += solution();
		if (now == N) flag = 0;
	}
	
	cout << cost;
}