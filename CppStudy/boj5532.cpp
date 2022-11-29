#include <iostream>
#include <algorithm>

using namespace std;

int L, A, B, C, D;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> A >> B >> C >> D;

	int a = A % C == 0 ? A / C : A / C + 1;
	int b = B % D == 0 ? B / D : B / D + 1;


	cout << L - max(a, b);
}