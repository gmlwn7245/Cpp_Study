#include <iostream>
#include <string>

using namespace std;

string getStr(string num);
int getSum(string str);
int getNum(char ch);

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int num1 = getSum(s1);
	int num2 = getSum(s2);

	string num = to_string(num1 + num2);
	cout << num << "\n";

	cout << getStr(num);
	
}

int getNum(char ch) {
	switch (ch) {
	case 'M':return 1000;
	case 'D':return 500;
	case 'C':return 100;
	case 'L':return 50;
	case 'X':return 10;
	case 'V':return 5;
	case 'I':return 1;
	}
}

int getSum(string str) {
	int ans = 0;
	
	// 직전 숫자
	int last = -1;
	// 총합
	int sum = 0;
	// 현재 숫자
	int now = 0;

	for (int i = 0; i < str.size(); i++) {
		now = getNum(str.at(i));

		if (last == -1) {
			last = now;
			sum += now;
			continue;
		}

		if (now > last) {
			ans += now - sum;
			last = now;
			sum = 0;
		}
		else if (now == last) {
			sum += now;
		}
		else {	// now < last
			ans += sum;
			sum = now;
			last = now;
		}
	}
	ans += sum;

	return ans;
}


string getStr(string num) {
	string strMap[4][2] = {
		{"I","V"},{"X","L"},{"C","D"},{"M",}
	};
	//cout << "num" << num << "\n";
	
	string ans = "";
	for (int i = num.size() - 1; i >= 0; i--) {
		int n = num.at(num.size()-1-i)-'0';
		if (n <= 3) {
			for (int j = 0; j < n; j++) {
				ans.append(strMap[i][0]);
			}
		}
		else if (n == 9) {
			ans.append(strMap[i][0]);
			ans.append(strMap[i + 1][0]);
		}
		else if(n==5) {
			ans.append(strMap[i][1]);
		}
		else if (n == 4) {
			ans.append(strMap[i][0]);
			ans.append(strMap[i][1]);
		}
		else {
			ans.append(strMap[i][1]);
			for (int j = 0; j < n - 5; j++) {
				ans.append(strMap[i][0]);
			}
		}
	}
	return ans;
}



