// Author : Doug Suh
// Date   : June 4, 2020
//
// Binary file ��mybin.dat���� ���� ������ �д´�.
// int  1234
// int  1000���� 5000���� ���ڿ� 5�� ���� �� 5��
// float - 0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3��
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream xx("mybin.dat", ios::binary | ios::in);
	if (!xx) {
		cout << " File not found : " << "mybin.dat\n";
		return 666;
	}
	int ii[6];
	float ff[3];
	xx.read((char*)ii, sizeof(int) * 6);
	xx.read((char*)ff, sizeof(float) * 3);
	xx.close();
	for (int i = 0; i < 6; i++) cout << i << "  " << ii[i] << endl;
	for (int i = 0; i < 3; i++) cout << i << "  " << ff[i] << endl;

	return 1;
}
