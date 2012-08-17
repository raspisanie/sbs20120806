#pragma once

#include "MyShape.h"

class MyTriangle : public MyShape
{
public:
	MyTriangle(void);
	~MyTriangle(void);

	int m_x;
	int m_y;
	int m_height;

	void MoveLeft(int x) override;
	void MoveRight(int x) override;
	void MoveUp(int y) override;
	void MoveDown(int y) override;

	void Draw() override;
};

