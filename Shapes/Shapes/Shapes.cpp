// Shapes.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyRect.h"
#include <windows.h>
#include <vector>
using namespace std;
#include "MyTriangle.h"

//vector<MyRect>		rectangels;
//vector<MyTriangle>	triangles;

vector<MyShape*> g_shapes;

MyRect myRect;

void printxy2(int x,int y,char ch)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos
		);
	printf("%c", ch);
}

int GetPressedKeyboard()
{
	if (::GetAsyncKeyState(VK_LEFT))
		return VK_LEFT;

	if (::GetAsyncKeyState(VK_RIGHT))
		return VK_RIGHT;

	if (::GetAsyncKeyState(VK_UP))
		return VK_UP;

	if (::GetAsyncKeyState(VK_DOWN))
		return VK_DOWN;

	if (::GetAsyncKeyState(VK_SPACE))
		return VK_SPACE;

	if (::GetAsyncKeyState(VK_LBUTTON))
		return VK_LBUTTON;
	
	return 0;
}

void Init()
{
	MyRect* npc1;
	npc1 = new MyRect();

	npc1->m_x = 0;
	npc1->m_y = 0;
	npc1->m_width = 15;
	npc1->m_height = 4;

	g_shapes.push_back(npc1);

	// g_shapes[0] != npc1

	MyRect* npc2 = npc1;
	npc2->m_x = 0;
	npc2->m_y = 0;
	npc2->m_width = 1;
	npc2->m_height = 1;

	g_shapes.push_back(npc2);

	MyRect* npc3 = new MyRect();
	npc3->m_x = 0;
	npc3->m_y = 0;
	npc3->m_width = 2;
	npc3->m_height = 2;
	g_shapes.push_back(npc3);

	MyRect* npc4 = new MyRect();
	npc4->m_x = 3;
	npc4->m_y = 3;
	npc4->m_width = 2;
	npc4->m_height = 2;
	g_shapes.push_back(npc4);

	/*
	MyRect npc5;
	MyRect npc6;
	MyRect npc7;
	MyRect npc8;
	MyRect npc9;
	MyRect npc10;

	

	

	

	

	npc5.m_x = 6;
	npc5.m_y = 6;
	npc5.m_width = 2;
	npc5.m_height = 2;

	npc6.m_x = 9;
	npc6.m_y = 9;
	npc6.m_width = 2;
	npc6.m_height = 2;

	npc7.m_x = 12;
	npc7.m_y = 12;
	npc7.m_width = 2;
	npc7.m_height = 2;

	npc8.m_x = 15;
	npc8.m_y = 15;
	npc8.m_width = 2;
	npc8.m_height = 2;

	npc9.m_x = 18;
	npc9.m_y = 18;
	npc9.m_width = 2;
	npc9.m_height = 2;

	npc10.m_x = 21;
	npc10.m_y = 18;
	npc10.m_width = 2;
	npc10.m_height = 2;
	*/
	myRect.m_x = 5;
	myRect.m_y = 5;
	myRect.m_width = 3;
	myRect.m_height = 3;
}

void ProcessKeyboard()
{
	if (VK_LEFT == GetPressedKeyboard())
	{
		myRect.MoveLeft(5);
	}

	if (VK_RIGHT == GetPressedKeyboard())
	{
		myRect.MoveRight(5);
	}

	if (VK_UP == GetPressedKeyboard())
	{
		myRect.MoveUp(5);
	}

	if (VK_DOWN == GetPressedKeyboard())
	{
		myRect.MoveDown(5);
	}

	if (VK_SPACE == GetPressedKeyboard())
	{
		// 스페이스바를 눌렀을 경우
		// 화면 임의의 위치에 새로운 shape를 만들어서
		// 그릴 수 있도록 준비해 주세요
		MyRect* npc = new MyRect();
		npc->m_x = 5;
		npc->m_y = 5;
		npc->m_width = 3;
		npc->m_height = 3;

		g_shapes.push_back(npc);
	}

	if (VK_LBUTTON == GetPressedKeyboard())
	{
		MyTriangle* triangle = new MyTriangle();
		triangle->m_x = 3;
		triangle->m_y = 3;
		triangle->m_height = 5;

		g_shapes.push_back(triangle);
	}
}

void ProcessData()
{
	for (int i = 0; i < g_shapes.size(); i = i + 1)
	{
		MyShape* shape = g_shapes[i];
		// 뭔가 움직인다
		shape->UpdateAI();
	}
}

void Draw()
{
	// 화면 지우기
	system("cls");

	for (int i = 0; i < g_shapes.size(); i = i + 1)
	{
		MyShape* shape = g_shapes[i];
		shape->Draw();
	}

	myRect.Draw();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Init();

	while (true)
	{
		ProcessKeyboard();
		ProcessData();
		Draw();

		Sleep(30);
	}

	return 0;
}

