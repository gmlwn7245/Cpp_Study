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
		int b = nums[i + 1];
		int c = nums[i + 2];


		if (b > c) {
			int minNum = min(a, b - c);
			tot += 5 * minNum;

			a -= minNum;
			b -= minNum;

			minNum = min(a, min(b, c));
			tot += 7 * minNum;

			nums[i] = a - minNum;
			nums[i + 1] = b - minNum;
			nums[i + 2] = c - minNum;
		}
		else {
			int minNum = min(a, min(b, c));
			tot += 7 * minNum;

			a -= minNum;
			b -= minNum;
			c -= minNum;

			minNum = min(a, b);
			tot += 5 * minNum;

			nums[i] = a - minNum;
			nums[i + 1] = b - minNum;
			nums[i + 2] = c;
		}

		tot += 3 * nums[i];
	}
	cout << tot;
}