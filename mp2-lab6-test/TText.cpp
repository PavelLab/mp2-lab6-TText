#include "TText.h"

TText::TText() {
	pFirst = NULL;
}

void TText::GoFirstLink() {
	pCurr = pFirst;
	stack.clear();
}
void TText::GoDownLink() {
	if (pCurr == NULL) throw "pCurr==NULL";
	if (pCurr->pDown == NULL) return;
	stack.push(pCurr);
	pCurr = pCurr->pDown;
}
void TText::GoNextLink() {
	if (pCurr == NULL) throw "pCurr==NULL";
	if (pCurr->pNext == NULL) return;
	stack.push(pCurr);
	pCurr = pCurr->pNext;
}
void TText::GoPrevLink() {
	if (pCurr == NULL) throw "pCurr==NULL";
	if (stack.isempty()) return;
	pCurr = stack.pop();
}
void TText::SetLine(string str1) {
	if (!pCurr) throw "pCurr==NULL";
	strcpy_s(pCurr->str, str1.c_str());
}
string TText::GetLine() {
	if (pCurr == NULL) throw "pCurr==NULL";
	return string(pCurr->str);
}
void TText::InsNextLine(string str) {
	if (pCurr == NULL) throw "pCurr==NULL";
	TTextLink *p = new TTextLink(str.c_str());
	p->pNext = pCurr->pNext;
	pCurr->pNext = p;
}
void TText::InsNextSectLine(string str) {
	if (pCurr == NULL) throw "pCurr==NULL";
	TTextLink *p = new TTextLink(str.c_str());
	p->pDown = pCurr->pNext;
	pCurr->pNext = p;
}
void TText::InsDownLine(string str) {
	if (pCurr == NULL) throw "pCurr==NULL";
	TTextLink *p = new TTextLink(str.c_str());
	p->pNext = pCurr->pDown;
	pCurr->pDown = p;
}
void TText::InsDownSectLine(string str) {
	if (pCurr == NULL) throw "pCurr==NULL";
	TTextLink *p = new TTextLink(str.c_str());
	p->pDown = pCurr->pDown;
	pCurr->pDown = p;
}
void TText::DelNext() {
	if (pCurr == NULL) throw "pCurr==NULL";
	if (pCurr->pNext == NULL) return;
	TTextLink *tmp = pCurr->pNext;
	pCurr->pNext = tmp->pNext;
	delete tmp;
}
void TText::DelDown() {
	if (pCurr == NULL) throw "pCurr==NULL";
	if (pCurr->pDown == NULL) return;
	TTextLink *tmp = pCurr->pDown;
	pCurr->pDown = tmp->pNext;
	delete tmp;
}
//итератор
void TText::Reset() {
	stack.clear();
	//текущая строка в стеке не хранится(первая-исключение)
	pCurr = pFirst;
	if (pCurr != NULL) {
		stack.push(pCurr);
		if (pCurr->pNext != NULL) stack.push(pCurr->pNext);
		if (pCurr->pDown != NULL) stack.push(pCurr->pDown);
	}
}

bool TText::IsEnd() {
	return stack.isempty();
}

int TText::GoNext() {
	if (!IsEnd()) {
		pCurr = stack.pop();
		if (pCurr != pFirst) {
			if (pCurr->pNext != NULL) stack.push(pCurr->pNext);
			if (pCurr->pDown != NULL) stack.push(pCurr->pDown);
		}
		return true;
	}
	return false;
}

//работа с файлами
void TText::Read(string fn) {
	ifstream ifs(fn);
	pFirst = ReadRec(ifs);
}
TTextLink* TText::ReadRec(ifstream &ifs) {
	TTextLink *pHead, *p, *tmp;
	pHead = p = NULL;
	char str[81];
	while (!ifs.eof()) {
		ifs.getline(str, 80, '\n');
		if (str[0] == '}') break;
		else if (str[0] == '{') p->pDown = ReadRec(ifs);
		else {
			tmp = new TTextLink(str);
			if (pHead == NULL) pHead = p = tmp;
			else {
				p->pNext = tmp;
				p = p->pNext;
			}
		}
	}
	return pHead;
}
void TText::Write(string fn) {
	ofstream ofs(fn);
	WriteRec(ofs, pFirst);
}
void TText::WriteRec(ofstream &ofs, TTextLink *p) {
	ofs << p->str << endl;
	if (p->pDown) {
		ofs << '{' << endl;
		WriteRec(ofs, p->pDown);
		ofs << '}' << endl;
	}
	if (p->pNext) {
		WriteRec(ofs, p->pNext);
	}
}