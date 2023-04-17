#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void sum3sine(short* data, float amp1, float f1, float amp2, float f2, float amp3, float f3) {
    const float pi = 3.141592;
    float dt = 1./44100.0;
    for (int i = 0; i < (5 * 44100); i++)
        data[i] = (short)(amp1 * sin(2.0 * pi * f1 * i * dt) + amp2 * sin(2.0 * pi * f2 * i * dt) + amp3 * sin(2.0 * pi * f3 * i * dt));   
}
int main(){
    char header[44];
    ifstream xx("Beatles.wav", ios::binary | ios::in);
    if (!xx) return 666;  // 만일 파일이 열리지 않으면 끝낸다. 
    xx.read(header, 44 * sizeof(char));
    short* n;   n = (short*)(header + 22);  cout << *n << endl; //numchannels
    int* fs;   fs = (int*)(header + 24);  cout << *fs << endl; //samplerate
    int* b;   b = (int*)(header + 28);  cout << *b << endl; //byterate

    int N = fs[0] * 10;   // 10초 분량
    fs[0] = 4410000;
    short* data; data = new short[fs[0]]; // 1초간 데이터 저장할 분량
    const float pi = 3.141592;
    *n = 1;
    *b = n[0] * fs[0] * sizeof(short);
    //Sample 1개가 차지하는 byte) x (1초당 Sample 수) x (채널 수)
    //= (Sample 1개가 차지하는 byte) x 441000 x 1
    float dt = 1. / fs[0], a = 10000.0, f = 440.0; // 440Hz -->사인값 1초분량 계산
    for (int i = 0; i < fs[0]; i++) {
        data[i] = (short)(a * sin(2.0 * pi * f * i * dt)); // a: amp. f: frequency
    }

    xx.read((char*)data, N * sizeof(short)); // 헤더를 읽은 후 xx.close();하기 전에 10초 분량 데이터를 읽는다.

    ofstream yy("my.wav", ios::binary | ios::out);
    if (!yy) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
    yy.write(header, 44 * sizeof(char)); // 헤더를 쓴다. 
    yy.write((char*)data, N * sizeof(short));    // 헤더에 이어서 10초 분량 쓴다.
    yy.close();

    ifstream x1;
    x1.open("Beatles.wav", ios::binary | ios::in);
    if (!x1) return 666; // 파일 안 열리면 종료
    x1.read(header, sizeof(header));
    x1.close();

    short* NumChannels;
    NumChannels = (short*)(header + 22);
    cout << *NumChannels << endl;
    int* SampleRate;
    SampleRate = (int*)(header + 24);
    cout << *SampleRate << endl;
    short* BitsPerSample;
    BitsPerSample = (short*)(header + 34);
    cout << *BitsPerSample << endl;

    data = new short[N * 5];    //44100 -> 1초, 즉 5 * N은 5초를 의미

    float amp1 = 10000.0;
    float f1 = 440.0;

    float amp2 = 7500;
    float f2 = 330.0;

    float amp3 = 5000;
    float f3 = 220.0;

    sum3sine(data, amp1, f1, amp2, f2, amp3, f3); //바이너리 파일 작성
    ofstream x2("my.wav", ios::binary | ios::out);
    if (!x2)return 666;
    *NumChannels = 1;
    *SampleRate = 44100;
    *BitsPerSample = 16;
    x2.write(header, sizeof(header));
    x2.write((char*)data, (5 * N) * sizeof(short));

    //txt파일 작성
    ofstream x3;
    x3.open("new_wav.txt");
    for (int i = 0; i < N; i++) {
        x3 << " " << data[i] << " " << endl;
    }
    x2.close();
    x3.close();

    return 0;
}
