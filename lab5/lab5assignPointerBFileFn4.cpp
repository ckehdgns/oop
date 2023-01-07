// Author : Doug Suh
// Date   : June 11, 2020
//
// Binary file ��mybin.dat���� ���� ������ ������� �����϶�.
// int  1234
// int  1000���� 5000���� ���ڿ� 5�� ���� �� 5��
// float - 0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3��
#include <iostream>
#include <fstream>
using namespace std;
void mul5(int n,int *x) { 
	for (int i = 0; i < n; i++) x[i] = 5*(1000 * (i + 1));
}
void square(int n, float *x) { 
	for (int i = 0; i < 3; i++) {
		float y = -0.5 + 0.5*(float)i;
		x[i] = y*y;
	}
}
void All(char *ss) {
	// ��� 4
	int *jj = new int[9];
	// int  1234
	jj[0] = 1234;
	// int  1000���� 5000���� ���ڿ� 5�� ���� �� 5��
	mul5(5, jj + 1);
	// float - 0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3��
	float *ff = (float *)(jj + 6);
	square(3, ff);
	// Binary file ��mybin1.dat���� ���� ������ ������� �����϶�.
	ofstream xx(ss, ios::binary | ios::out);
	xx.write((char *)jj, sizeof(int) * 9);
	xx.close();
	delete jj;
}
int main() {
	All((char*)"mybin4-1.dat");
	return 41;
}