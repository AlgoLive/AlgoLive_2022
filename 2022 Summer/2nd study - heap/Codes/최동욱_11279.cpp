#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	priority_queue<int> pqueue;
	int count; int num;

	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; ++i) {
		cin >> num;
		cin.clear();

		if (num == 0) {
			if (pqueue.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pqueue.top() << "\n";
				pqueue.pop();
			}
		}
		else {
			pqueue.push(num);
		}
	}
}