// 포인터.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void Add(int l,int r,int* out)
{
	*out = l + r;
}

class MyRect
{
public:
	int m_x;
	int m_y;
};

int _tmain(int argc, _TCHAR* argv[])
{
	int* p = new int();
	int p2;

	p2 = 10;
	*p = 10;

	MyRect* r = new MyRect();

	r->m_x = 10;
	r->m_y = 20;

	(*r).m_x = 10;
	(*r).m_y = 20;

	MyRect* r3 = r;
	r3->m_x = 15;

	printf("r.m_x = %d\n", r->m_x);

	MyRect r2;
	r2.m_x = 10;
	r2.m_y = 20;

	MyRect r4 = r2;
	r4.m_x = 15;

	printf("r2.m_x = %d\n", r2.m_x);

	delete p;
	delete r;

	int* sum = new int();
	
	Add(5, 10, sum);
	printf("합계 : %d\n", *sum);
	
	delete sum;

	return 0;
}

