#include <iostream>
using namespace std;
const int INTER = 1, SEOUL = 2, KWANG = 3;
const int WOE = 1, CHE = 2, JUN = 3, GONG = 4, KUK = 5;
const int SW = 1, EE = 2,  CE = 3, ME = 5;

void main() {
	// �������۽� ���������� ���ڰ��̸�...
	short c =  0;
	c = INTER<<6;
	c |= JUN<<3;
	c |= EE;

	cout << "  o"<< oct << c << endl;

	/* 2. size
	cout <<  " int size " << sizeof(int) << endl;
	cout << " short size " << sizeof(short) << endl;
	cout << " unsigned short size " << sizeof(unsigned short) << endl;
	cout << " long size " << sizeof(long) << endl;
	// 1. hex
	for (short c = 0; c<16; c++)
		cout << dec << c << "  0x" << hex << c
		<< "  o" << oct << c  << endl;
		*/
	getchar();
}
