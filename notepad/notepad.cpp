#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <Windows.h>

using namespace std;

class ansestor
{
public:
	ansestor() { printf_s("조상 생성 \n"); }
	virtual ~ansestor() { printf_s("조상 소멸 \n"); }

	virtual void Print()
	{
		printf_s("조상클래스 \n");
		printf_s("조상의 주소 %p \n", &ansestor::Print);
	}
};

class parents : public ansestor
{
public:
	parents() { printf_s("부모 생성 \n"); }
	~parents() { printf_s("부모 소멸 \n"); }

	virtual void Print()
	{
		printf_s("부모클래스 \n");
		printf_s("부모의 주소 %p \n", &parents::Print);
	}
};

class descendant : public parents
{
public:
	descendant() { printf_s("후손 생성 \n"); }
	~descendant() { printf_s("후손 소멸 \n"); }

	virtual void Print()
	{
		printf_s("후손클래스 \n");
		printf_s("후손의 주소 %p \n", &descendant::Print);
	}

};


int main()
{
	ansestor *dcd = new ansestor();


	(*dcd).Print();
	delete dcd;

	return 0;
}
