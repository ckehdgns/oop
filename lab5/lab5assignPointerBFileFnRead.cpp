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
int main() {
	int ii[6]; // static
	float *ff = new float[3]; //dynamic
	ifstream yy("mybin1.dat", ios::binary | ios::in);
	cout << "mybin1.dat\n";
	yy.read((char*)ii, 6 * sizeof(int));
	for (int i = 0; i < 6; i++) cout << ii[i] << endl;
	yy.read((char*)ff, 3 * sizeof(float));
	for (int i = 0; i < 3; i++) cout << ff[i] << endl;
	yy.close();

	yy.open("mybin2.dat", ios::binary | ios::in);
	cout << "mybin2.dat\n";
	yy.read((char*)ii, 6 * sizeof(int));
	for (int i = 0; i < 6; i++) cout << ii[i] << endl;
	yy.read((char*)ff, 3 * sizeof(float));
	for (int i = 0; i < 3; i++) cout << ff[i] << endl;
	yy.close();

	yy.open("mybin3.dat", ios::binary | ios::in);
	cout << "mybin3.dat\n";
	yy.read((char*)ii, 6 * sizeof(int));
	for (int i = 0; i < 6; i++) cout << ii[i] << endl;
	yy.read((char*)ff, 3 * sizeof(float));
	for (int i = 0; i < 3; i++) cout << ff[i] << endl;
	yy.close();

	yy.open("mybin4.dat", ios::binary | ios::in);
	cout << "mybin4.dat\n";
	yy.read((char*)ii, 6 * sizeof(int));
	for (int i = 0; i < 6; i++) cout << ii[i] << endl;
	yy.read((char*)ff, 3 * sizeof(float));
	for (int i = 0; i < 3; i++) cout << ff[i] << endl;
	yy.close();

	delete ff;
	return 55;
}