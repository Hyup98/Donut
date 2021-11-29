#include "TicTaToc.h"
#include <iostream>
#include "pMove.h"
#include <vector>
using namespace std;
//User = x
//Computer = o
//
TicTaToc::TicTaToc()
{
	board = new char*[3];
	for (size_t i = 0; i < 3; i++)
	{
		board[i] = new char[3];
	}
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}
}

void TicTaToc::printBoard(char** board)
{
	cout << "  ********\n";
	for (size_t i = 0; i < 3; i++)
	{
		cout << "-------------\n";
		cout << "|";
		for (size_t j = 0; j < 3; j++)
		{
			
			if (board[i][j] == 'x') {
				cout << " x";
			}
			else if (board[i][j] == 'o') {
				cout << " o";
			}
			else {
				cout << "  ";
			}
			cout << " |";
		}
		cout << '\n';
	}
	cout << "-------------\n";
	cout << "  ********\n";
}

TicTaToc::~TicTaToc()
{
	for (size_t i = 0; i < 3; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}
//T - 무승부
//U - 유저 우승
//C - 컴퓨터 우승
//N - 진행중
char TicTaToc::isOver(char** board)
{
	if (board[0][1] == board[0][2] && board[0][1] == board[0][0])
	{
		if (board[0][0] == 'x')
		{
			return 'U';
		}
		else if (board[0][0] == 'o')
		{
			return 'C';
		}
	}
	else if (board[1][1] == board[1][2] && board[1][1] == board[1][0])
	{
		if (board[1][0] == 'x')
		{
			return 'U';
		}
		else if (board[1][0] == 'o')
		{
			return 'C';
		}
	}
	if (board[2][1] == board[2][2] && board[2][1] == board[2][0])
	{
		if (board[2][0] == 'x')
		{
			return 'U';
		}
		else if (board[2][0] == 'o')
		{
			return 'C';
		}
	}
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
	{
		if (board[0][0] == 'x')
		{
			return 'U';
		}
		else if (board[0][0] == 'o')
		{
			return 'C';
		}
	}
	if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
	{
		if (board[1][0] == 'x')
		{
			return 'U';
		}
		else if (board[1][0] == 'o')
		{
			return 'C';
		}
	}
	if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
	{
		if (board[2][0] == 'x')
		{
			return 'U';
		}
		else if (board[2][0] == 'o')
		{
			return 'C';
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		if (board[0][0] == 'x')
		{
			return 'U';
		}
		else if (board[0][0] == 'o')
		{
			return 'C';
		}
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		if (board[0][2] == 'x')
		{
			return 'U';
		}
		else if (board[0][2] == 'o')
		{
			return 'C';
		}
	}
	bool flag = true;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == '0')
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	if (flag)
	{
		return 'N';
	}
	return 'T';
}

//true -> 홀수번쨰 유저가 둔다
//false -> 짝수번째 유저가 둔다

void TicTaToc::Play(bool user)
{
	cout << "*****WELLCOME*****\n";
	printBoard(board);
	int turn = 1;
	pMove tem(0,0);
	while (true)
	{
		if (isOver(board) != 'N')
		{
			if (isOver(board) == 'C')
			{
				cout << "컴퓨터 우승";
			}
			else if (isOver(board) == 'U')
			{
				cout << "유저 우승";
			}
			else if (isOver(board) == 'T')
			{
				cout << "무승부";
			}
			break;
		}

		// 홀수번쨰->유저
		if (turn % 2 == 1)
		{
			cout << "둘 곳을 입력하세요: ";
			int a, b;
			cin >> a;
			cin >> b;
			board[a][b] = 'x';
		}
		//짝수번쨰->컴퓨터
		else
		{
			tem = Move();
			board[tem.mX][tem.mY] = 'o';
		}
		turn++;
		printBoard(board);
	}
}

pMove TicTaToc::Move()
{
	//둘 수 있는 모든 곳 찾기
	vector<pMove> child;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
			{
				child.push_back(pMove(i, j));
			}
		}
	}
	//움직일 수 없는 경우
	if (child.size() == 0)
	{
		return pMove(-1, -1);
	}

	//자식이게 다시 moveRecursive를 호출

	//끝낸 후 자식 중 가장 적합한 녀석을 선택
	return;
}

void TicTaToc::MoveRecursive()
{

}