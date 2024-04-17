#include <iostream>

using namespace std;

int sum = 0;

void dfs(int n) {
	if (n == 0) {
		sum += n;
		return;
	}

	sum += n;
	dfs(n / 10);
}

int main(void) {
	int n; cin >> n;

	dfs(n);
}