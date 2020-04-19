#pragma once
#include "TTextLink.h"
#include <fstream>
class TText {
	TTextLink *pFirst, *pCurr;
	TStack <TTextLink *> stack;

public:
	TText();
	~TText() {};

	void GoFirstLink();					//������� �� ������ ������
	void GoDownLink();					//������� �� ����������� �����
	void GoNextLink();					//������� �� ��������� ����� ���� �� ������
	void GoPrevLink();					//������� �� ���������� �����
	void SetLine(string str1);			//���������� ������
	string GetLine();					//������� ������
	void InsNextLine(string str);		//���������� ������ ���� �� ������
	void InsNextSectLine(string str);	//���������� ������-��������� ���� �� ������
	void InsDownLine(string str);		//���������� ����������� ������ 
	void InsDownSectLine(string str);	//���������� ����������� ������-��������� 
	void DelNext();						//������� ��������� ����� ���� �� ������
	void DelDown();						//������� ����� �� ������� ����
	//��������
	void Reset();						//���������� �� ������ ������
	bool IsEnd();						//�������� �� ���������
	int GoNext();						//������� � ��������� ������
	//������ � �������
	void Read(string fn);				//������� ����� �� �����
	TTextLink* ReadRec(ifstream &ifs);	//�������� ����������
	void Write(string fn);				//���������� ����� � ����
	void WriteRec(ofstream &ifs, TTextLink *p);	//�������� ������
};