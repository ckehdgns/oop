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
    if (!xx) return 666;  // ���� ������ ������ ������ ������. 
    xx.read(header, 44 * sizeof(char));
    short* n;   n = (short*)(header + 22);  cout << *n << endl; //numchannels
    int* fs;   fs = (int*)(header + 24);  cout << *fs << endl; //samplerate
    int* b;   b = (int*)(header + 28);  cout << *b << endl; //byterate

    int N = fs[0] * 10;   // 10�� �з�
    fs[0] = 4410000;
    short* data; data = new short[fs[0]]; // 1�ʰ� ������ ������ �з�
    const float pi = 3.141592;
    *n = 1;
    *b = n[0] * fs[0] * sizeof(short);
    //Sample 1���� �����ϴ� byte) x (1�ʴ� Sample ��) x (ä�� ��)
    //= (Sample 1���� �����ϴ� byte) x 441000 x 1
    float dt = 1. / fs[0], a = 10000.0, f = 440.0; // 440Hz -->���ΰ� 1�ʺз� ���
    for (int i = 0; i < fs[0]; i++) {
        data[i] = (short)(a * sin(2.0 * pi * f * i * dt)); // a: amp. f: frequency
    }

    xx.read((char*)data, N * sizeof(short)); // ����� ���� �� xx.close();�ϱ� ���� 10�� �з� �����͸� �д´�.

    ofstream yy("my.wav", ios::binary | ios::out);
    if (!yy) return 666;  // ���� ������ ������ ������ ���α׷��� ������. 
    yy.write(header, 44 * sizeof(char)); // ����� ����. 
    yy.write((char*)data, N * sizeof(short));    // ����� �̾ 10�� �з� ����.
    yy.close();

    ifstream x1;
    x1.open("Beatles.wav", ios::binary | ios::in);
    if (!x1) return 666; // ���� �� ������ ����
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

    data = new short[N * 5];    //44100 -> 1��, �� 5 * N�� 5�ʸ� �ǹ�

    float amp1 = 10000.0;
    float f1 = 440.0;

    float amp2 = 5000;
    float f2 = 220.0;

    float amp3 = 7500;
    float f3 = 330;

    sum3sine(data, amp1, f1, amp2, f2, amp3, f3); //���̳ʸ� ���� �ۼ�
    ofstream x2("my.wav", ios::binary | ios::out);
    if (!x2)return 666;
    *NumChannels = 1;
    *SampleRate = 44100;
    *BitsPerSample = 16;
    x2.write(header, sizeof(header));
    x2.write((char*)data, (5 * N) * sizeof(short));

    //txt���� �ۼ�
    ofstream x3;
    x3.open("new_wav.txt");
    for (int i = 0; i < N; i++) {
        x3 << " " << data[i] << " " << endl;
    }
    x2.close();
    x3.close();

    return 0;
}
