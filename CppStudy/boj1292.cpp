#include <iostream>
#include <vector>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int n = 1;
	int cnt = 0;

	vector<int> arr;

	while (cnt != B) {
		for (int i = 1; i <= n; i++) {
			arr.push_back(n);
			cnt++;
			if (cnt == B)
				break;
		}
		n++;
	}


	int res = 0;
	for (int i = A - 1; i < B; i++) {
		res += arr[i];
	}
	cout << res;

	return 0;
}