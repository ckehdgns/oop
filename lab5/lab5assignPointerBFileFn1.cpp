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
int mul5(int x) { return x * 5; }
float square(float x) { return x * x; }
int main() {
	// ��� 1
	// Binary file ��mybin1.dat���� ���� ������ ������� �����϶�.
	ofstream xx("mybin1.dat", ios::binary | ios::out);
	// int  1234
	int ii = 1234;
	xx.write((char *)&ii, sizeof(int));
	// int  1000���� 5000���� ���ڿ� 5�� ���� �� 5��
	int *jj = new int[5];
	for (int i = 0; i < 5; i++) jj[i] = mul5(1000*(i+1));
	xx.write((char *)jj, sizeof(int)*5);
	delete jj;
	// float - 0.5���� 0.5�� �����ϸ鼭 �ڽ��� �� �� 3��
	float *ff = new float[3];
	for (int i = 0; i < 3; i++) ff[i] = square(-0.5 + 0.5*(float)i);
	xx.write((char *)ff, sizeof(float) * 3);
	delete ff;
	xx.close();
	return 1;
}