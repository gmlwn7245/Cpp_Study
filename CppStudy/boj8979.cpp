#include <iostream>
#include <algorithm>
using namespace std;

struct area {
	int num;
	int gold;
	int sliver;
	int bronze;

};

bool cmp(area a1, area a2);

area arr[1001];
int n, k;
int n1, n2, n3, n4;
int result = 0, val = 0;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> n1 >> n2 >> n3 >> n4;
		arr[i].num = n1;
		arr[i].gold = n2;
		arr[i].sliver = n3;
		arr[i].bronze = n4;
	}

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		if (arr[i].num == k) {
			result = i;
			break;
		}
	}
	for (int i = result - 1;; i--) {
		if (arr[i].gold != arr[result].gold || arr[i].sliver != arr[result].sliver || arr[i].bronze != arr[result].bronze) {
			break;
		}
		val++;
	}
	cout << result - val + 1 << endl;
}

bool cmp(area a1, area a2) {
	if (a1.gold > a2.gold) return true;
	else if (a1.gold == a2.gold) {
		if (a1.sliver > a2.sliver) return true;
		if (a1.sliver == a2.sliver) {
			if (a1.bronze > a2.bronze) return true;
		}
	}

	return false;
}