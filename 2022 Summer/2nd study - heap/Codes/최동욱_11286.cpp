#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	priority_queue<int, vector<int>, greater<int> > minheap = {};
	int count; int num; 
	int absnum[2];
	deque<vector<int>> dq;
	cin >> count;

	for (int i = 0; i < count; ++i) {
		cin >> num;

		if (num == 0) {
			if (minheap.empty()) {
				cout << 0 << endl;
			}
			else {
				int pop = minheap.top();
				for (int i = 0; i < dq.size(); ++i) {
					if (dq[i][0] == pop) {
						if (dq[i][1] == 0) cout << pop;
						else cout << pop * -1;
					}
				}
				cout << dq.back()[1] << endl;
				dq.pop_back();
			}
		}
		else {
			absnum[0] = abs(num);
			if (num > 0) {
				absnum[1] = 1;
				dq.push_back(absnum);
			}
			else {
				absnum[1] = 0;
				dq.push_front(absnum);
			}
			minheap.push(absnum[0]);
		}
	}
}