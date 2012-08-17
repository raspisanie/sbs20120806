#pragma once
/*
class MyShape
{
public:
	MyShape(void);
	~MyShape(void);

	virtual void MoveLeft(int x) = 0;
	virtual void MoveRight(int x) = 0;
	virtual void MoveUp(int y) = 0;
	virtual void MoveDown(int y) = 0;
	virtual void Draw() = 0;
};
*/
__interface MyShape
{
	virtual void MoveLeft(int x) abstract;
	virtual void MoveRight(int x) abstract;
	virtual void MoveUp(int y) abstract;
	virtual void MoveDown(int y) abstract;
	virtual void Draw() abstract;
};
