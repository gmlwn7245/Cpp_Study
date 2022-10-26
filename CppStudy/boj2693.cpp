#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		vector<int> arr(10);
		for (int j = 0; j < 10; j++) {
			int num;
			cin >> num;
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end(), greater<>());
		res.push_back(arr[2]);
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << endl;
}