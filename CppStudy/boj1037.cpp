#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n,num;
	cin >> n;

	if (n == 1) {
		cin >> num;
		cout << (num * num);
		return 0;
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	long long res = v[0] * v[n - 1];

	cout << res;
}