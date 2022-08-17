#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	int max;
	int index;
	int endTime;

	vector<pair<int, int> > meetings;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		meetings.push_back(p);
	}
	sort(meetings.begin(), meetings.end());
	
	max = 1; index = 1;
	endTime = meetings.front().second;
	
	while (index <= N - 1) {
		if (meetings[index].first >= endTime) {
			max++;
			endTime = meetings[index].second;
		}
		index++;
	}

	cout << max;
}