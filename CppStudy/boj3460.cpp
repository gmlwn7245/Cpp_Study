#include<iostream>

using namespace std;

int main() {
	int t, n;
	cin >> t;

	while(t--) {
		cin >> n;
		int cnt = 0;
		while (n != 0) {
			if (n % 2 == 1)
				cout << cnt << " ";
			cnt++;
			n /= 2;
		}
	}

	
}