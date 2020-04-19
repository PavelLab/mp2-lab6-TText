#include <stdio.h>
#include "TText.h"
#include <conio.h>

#define PGDN 81
#define ESC 27
#define DEL 83 //txt.DelDown
#define INS 82 //txt.InsDownLine

TTextMem TTextLink::MemHeader;

void Menu(TText& txt) {
	int key, count=1;
	string str;
	txt.Reset();
	while (true) {
		key = _getch();
		switch (key)
		{
		case PGDN: txt.GoNext(); count++; 
			cout <<"Number pCurr "<< count << endl; break;
		case DEL: txt.DelDown();
			TTextLink::MemCleaner(txt); 
			system("cls");
			
			cout << "New Text" << endl;
			for (txt.Reset(); !txt.IsEnd(); txt.GoNext()) {
				cout << txt.GetLine() << endl;
			}
			count = 1; txt.Reset();
			cout << "Number pCurr " << count << endl; break;
		case INS: cout << "Enter the string ";
			cin >> str;
			txt.InsDownLine(str);
			
			system("cls");
			cout << "New Text" << endl;
			for (txt.Reset(); !txt.IsEnd(); txt.GoNext()) {
				cout << txt.GetLine() << endl;
			}
			count = 1; txt.Reset();
			cout << "Number pCurr " << count << endl; break;
		case ESC: return;
		default:
			break;
		}
	}
}

void main() {
	TTextLink::IntMemSystem(100);
	TText txt;
	int key, count;
	txt.Read("1.txt");
	cout << "PGDN INS DEL ESC" << endl;
	for (txt.Reset(); !txt.IsEnd(); txt.GoNext()) {
		cout << txt.GetLine() << endl;
	}
	Menu(txt);
	txt.Write("2.txt");
	exit(0);
}