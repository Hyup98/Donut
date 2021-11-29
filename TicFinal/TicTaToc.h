#pragma once
class TicTaToc
{
public:
	TicTaToc();//보드 생성
	~TicTaToc();
	char isOver(char** board);
	void Play(bool user);
	void printBoard(char** board);
	pMove Move();
	void MoveRecursive();
private:
	bool mUser;
	char** board;
};

