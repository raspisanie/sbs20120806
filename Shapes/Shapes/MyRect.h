#pragma once

#include "MyShape.h"

class MyRect : public MyShape
{
public:
	MyRect(void);
	~MyRect(void);

	void MoveLeft(int x) override;
	void MoveRight(int x) override;
	void MoveUp(int y) override;
	void MoveDown(int y) override;

	void Draw() override;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
};