#pragma once
using namespace std;

#include <iostream>
#include <string>
#include "TStack.h"
class TText;
class TTextLink;

struct TTextMem {
	TTextLink* pFirst;
	TTextLink* pLast;
	TTextLink* pFree;//указатель на первое свободное звено
	friend class TTextLink;
};

class TTextLink {
protected:
	static TTextMem MemHeader;
public:
	TTextLink *pNext;
	TTextLink *pDown;
	char str[81];
	
	TTextLink(const char *c = NULL, TTextLink *pN = NULL, TTextLink *pD = NULL) {
		pNext = pN;
		pDown = pD;
		if (c == NULL) str[0] = '\0';
		else {
			strcpy_s(str, c);
		}
	}
	static void IntMemSystem(int size = 20);	//инициализация памяти
	static void PrintFreeLink();				//печать свободных звеньев
	void* operator new(size_t size);			//выделение звена
	void operator delete(void *pM);				//освобождение звена
	static void MemCleaner(TText &txt);			//сборка мусора
	friend class TText;
};
