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


		int sum = num1 + num2 + tmp;//���� 10�� �ڸ� ���� ��� �����ش�->���� 1�� �ڸ����� �� ���� 10�� �ڸ����� �����ֱ�
		tmp = sum / 10;//10�� �ڸ��� ����
		sum %= 10;//1�� �ڸ��� ���
		result += (sum + '0');//�� ���� 1�� �ڸ��� �ٿ��ֱ� 
	}
	if (tmp > 0) {
		result += tmp + '0';
	}
	string ans = "";
	for (int i = result.length() - 1; i >= 0; i--) {//�Ųٷ� ���
		ans += result[i];
	}
	cout << ans;


	return 0;
}

