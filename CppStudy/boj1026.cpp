#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;
int N;

int main()
{
	cin >> N;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		cin >> num;
		b.push_back(num);
	}

	// 오름차순 정렬
	sort(a.begin(), a.end());
	// 내림차순 정렬
	sort(b.begin(), b.end(), greater<>());

	int res = 0;
	for (int i = 0; i < N; i++) {
		res += a[i] * b[i];
	}

	cout << res;

	return 0;
}