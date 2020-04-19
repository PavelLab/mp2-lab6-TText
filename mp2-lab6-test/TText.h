#pragma once
#include "TTextLink.h"
#include <fstream>
class TText {
	TTextLink *pFirst, *pCurr;
	TStack <TTextLink *> stack;

public:
	TText();
	~TText() {};

	void GoFirstLink();					//перейти на начало текста
	void GoDownLink();					//перейти на подчиненное звено
	void GoNextLink();					//перейти на следующее звено того же уровня
	void GoPrevLink();					//перейти на предыдущее звено
	void SetLine(string str1);			//установить строку
	string GetLine();					//вернуть строку
	void InsNextLine(string str);		//установить строку того же уровня
	void InsNextSectLine(string str);	//установить строку-заголовок того же уровня
	void InsDownLine(string str);		//установить подчиненную строку 
	void InsDownSectLine(string str);	//установить подчиненную строку-заголовок 
	void DelNext();						//удалить следующее звено того же уровня
	void DelDown();						//удалить звено на уровень ниже
	//итератор
	void Reset();						//установить на первую строку
	bool IsEnd();						//проверка на окончание
	int GoNext();						//перейти к следующей записи
	//работа с файлами
	void Read(string fn);				//считать текст из файла
	TTextLink* ReadRec(ifstream &ifs);	//алгоритм считывания
	void Write(string fn);				//напечатать текст в файл
	void WriteRec(ofstream &ifs, TTextLink *p);	//алгоритм печати
};