#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int t, n, num;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		vector<int> v;
		for (int j = 0; j < n; j++) {
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		int res = (v[n-1]-v[0]) * 2;
		cout << res << "\n";
	}

}