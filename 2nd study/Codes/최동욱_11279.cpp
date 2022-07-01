#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v = {};
	int count; int num;
	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; ++i) {
		cin >> num;
		cin.clear();

		if (num == 0) {
			if (v.empty()) {
				cout << 0 << endl;
			}
			else {
				pop_heap(v.begin(), v.end());
				cout << v.back() << endl;
				v.pop_back();
			}
		}
		else {
			v.push_back(num);
			push_heap(v.begin(), v.end());
		}
	}
}