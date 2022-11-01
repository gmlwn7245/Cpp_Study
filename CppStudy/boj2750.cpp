#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> v;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
}