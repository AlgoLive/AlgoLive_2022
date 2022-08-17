#include <iostream>
#include <vector>

using namespace std;

int memo[1000001];
int N;

int getMin(vector<int> nums) {
	pair<int, int> mins;
	mins.first = 1000001; // value
	mins.second; // index
	int temp;
	while (!nums.empty()) {
		temp = nums.back(); nums.pop_back();
		if (mins.first > memo[temp]) {
			mins.first = memo[temp];
			mins.second = temp;
		}
	}
	return mins.first + 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	memo[1] = 0;
	memo[2] = 1;
	memo[3] = 1;

	for (int i = 4; i <= N; ++i) {
		vector<int> temp;
		int min;

		if (i % 3 == 0) {
			temp.push_back(i / 3);
		}
		if (i % 2 == 0) {
			temp.push_back(i / 2);
		}
		temp.push_back(i - 1);

		min = getMin(temp);
		memo[i] = min;
	}
	cout << memo[N];
}