#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main() {
	char header[44];
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) return 666;  // ���� ������ ������ ������ ������. 
	xx.read(header, 44 * sizeof(char));
	short* n;   n = (short*)(header + 22);  cout << *n << endl; //numchannels
	int* fs;   fs = (int*)(header + 24);  cout << *fs << endl; //samplerate
	int* b;   b = (int*)(header + 28);  cout << *b << endl; //biterate

	int N = fs[0] * 10;   // 10�� �з�
	short* data; data = new short[fs[0]]; // 1�ʰ� ������ ������ �з�
	const float pi = 3.141592;
	*n = 1;
	*b = n[0] * fs[0] * sizeof(short);
	//Sample 1���� �����ϴ� byte) x (1�ʴ� Sample ��) x (ä�� ��)
	//= (Sample 1���� �����ϴ� byte) x 441000 x 1
	float dt = 1. / fs[0], a = 10000.0, f = 440.0; // 440Hz -->���ΰ� 1�ʺз� ���
	for (int i = 0; i < fs[0]; i++) {
		data[i] = (short)(a * sin(2.0 * pi * f * i * dt)); // a ����, f ���ļ�, N ���ü�
	}

	xx.read((char*)data, N * sizeof(short)); // ����� ���� �� xx.close();�ϱ� ���� 10�� �з� �����͸� �д´�.
	xx.close();
	ofstream yy("my.wav", ios::binary | ios::out);
	if (!yy) return 666;  // ���� ������ ������ ������ ���α׷��� ������. 
	yy.write(header, 44 * sizeof(char)); // ����� ����. 
	yy.write((char*)data, N * sizeof(short));    // 2�� �з�
	yy.close();
}
