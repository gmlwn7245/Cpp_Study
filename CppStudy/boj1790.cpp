#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int N, K;
	cin >> N >> K;

	int cnt = 0;
	int num = 0;
	string str;
	while (cnt < K) {
		num++;

		if (num > N) {
			cout << "-1";
			return 0;
		}
		str = to_string(num);
		cnt += str.size();
	}

	cnt -= str.size();

	for (int i = 0; i < str.size(); i++) {
		cnt++;
		if (cnt == K) {
			cout << str.at(i);
			break;
		}
	}
}