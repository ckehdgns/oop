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
int main() {
	// ��� 2
	// Binary file ��mybin1.dat���� ���� ������ ������� �����϶�.
	ofstream xx("mybin2.dat", ios::binary | ios::out);
	// int  1234
	int ii = 1234;
	xx.write((char *)&ii, sizeof(int));
	// int  1000���� 5000���� ���ڿ� 5�� ���� �� 5��
	int *jj = new int[5];
	mul5(5, jj);
	xx.write((char *)jj, sizeof(int)*5);
	delete jj;
	// float - 0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3��
	float *ff = new float[3];
	square(3, ff);
	xx.write((char *)ff, sizeof(float) * 3);
	delete ff;
	xx.close();
	return 2;
}