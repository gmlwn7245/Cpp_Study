#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<long long> arr;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		arr.push_back(num);
	}


	while (m--) {
		sort(arr.begin(), arr.end());

		long long sum = arr[0] + arr[1];
		arr[0] = sum;
		arr[1] = sum;
	}

	long long  res = 0;
	for (int i = 0; i < n; i++) {
		res += arr[i];
	}

	cout << res;
}