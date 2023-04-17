#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main() {
	char header[44];
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) return 666;  // 만일 파일이 열리지 않으면 끝낸다. 
	xx.read(header, 44 * sizeof(char));
	short* n;   n = (short*)(header + 22);  cout << *n << endl; //numchannels
	int* fs;   fs = (int*)(header + 24);  cout << *fs << endl; //samplerate
	int* b;   b = (int*)(header + 28);  cout << *b << endl; //biterate

	int N = fs[0] * 10;   // 10초 분량
	short* data; data = new short[fs[0]]; // 1초간 데이터 저장할 분량
	const float pi = 3.141592;
	*n = 1;
	*b = n[0] * fs[0] * sizeof(short);
	//Sample 1개가 차지하는 byte) x (1초당 Sample 수) x (채널 수)
	//= (Sample 1개가 차지하는 byte) x 441000 x 1
	float dt = 1. / fs[0], a = 10000.0, f = 440.0; // 440Hz -->사인값 1초분량 계산
	for (int i = 0; i < fs[0]; i++) {
		data[i] = (short)(a * sin(2.0 * pi * f * i * dt)); // a 진폭, f 주파수, N 샘플수
	}

	xx.read((char*)data, N * sizeof(short)); // 헤더를 읽은 후 xx.close();하기 전에 10초 분량 데이터를 읽는다.
	xx.close();
	ofstream yy("my.wav", ios::binary | ios::out);
	if (!yy) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
	yy.write(header, 44 * sizeof(char)); // 헤더를 쓴다. 
	yy.write((char*)data, N * sizeof(short));    // 2초 분량
	yy.close();
}
