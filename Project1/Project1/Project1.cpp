#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str1;
	string str2;
	string result = "";
	cin >> str1;
	cin >> str2;
	int length1 = str1.length() - 1;
	int length2 = str2.length() - 1;
	int tmp = 0;
	while (length1 >= 0 || length2 >= 0) {
		int num1 = 0;
		int num2 = 0;
		if (length1 >= 0) {
			num1 = str1[length1--] - '0';
		}

		if (length2 >= 0) {
			num2 = str2[length2--] - '0';
		}


		int sum = num1 + num2 + tmp;//남긴 10의 자리 수를 계속 더해준다->다음 1의 자리수에 그 전에 10의 자리수를 더해주기
		tmp = sum / 10;//10의 자리수 남김
		sum %= 10;//1의 자리수 계산
		result += (sum + '0');//값 더한 1의 자리수 붙여주기 
	}
	if (tmp > 0) {
		result += tmp + '0';
	}
	string ans = "";
	for (int i = result.length() - 1; i >= 0; i--) {//거꾸로 출력
		ans += result[i];
	}
	cout << ans;


	return 0;
}