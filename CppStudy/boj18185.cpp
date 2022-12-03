#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int nums[10002];
int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int tot = 0;
	for (int i = 0; i < N; i++) {
		int a = nums[i];

		if (a == 0)
			continue;

		int b = nums[i + 1];
		int c = nums[i + 2];

		if (b == 0) {
			tot += a * 3;
			continue;
		}
		
		
		if (c == 0) {
			int minNum = min(a, b);
			tot += minNum * 5;
			nums[i] -= minNum;
			nums[i + 1] -= minNum;
			tot += nums[i] * 3;
		}
		else {
			int minNum = min(min(a, b), c);
			tot += minNum * 7;
			nums[i] -= minNum;
			nums[i + 1] -= minNum;
			nums[i + 2] -= minNum;
			i--;
		}
		
		
	}
	cout << tot;
}