#include <iostream>

using namespace std;

int main() {
	int N, num, V;
	cin >> N;

	int* nums = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums[i] = num;
	}
	
	cin >> V;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (nums[i] == V)
			cnt++;
	}

	cout << cnt;
	return 0;
}