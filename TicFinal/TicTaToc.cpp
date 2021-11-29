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
//T - ���º�
//U - ���� ���
//C - ��ǻ�� ���
//N - ������
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

//true -> Ȧ������ ������ �д�
//false -> ¦����° ������ �д�

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
				cout << "��ǻ�� ���";
			}
			else if (isOver(board) == 'U')
			{
				cout << "���� ���";
			}
			else if (isOver(board) == 'T')
			{
				cout << "���º�";
			}
			break;
		}

		// Ȧ������->����
		if (turn % 2 == 1)
		{
			cout << "�� ���� �Է��ϼ���: ";
			int a, b;
			cin >> a;
			cin >> b;
			board[a][b] = 'x';
		}
		//¦������->��ǻ��
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
	//�� �� �ִ� ��� �� ã��
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
	//������ �� ���� ���
	if (child.size() == 0)
	{
		return pMove(-1, -1);
	}

	//�ڽ��̰� �ٽ� moveRecursive�� ȣ��

	//���� �� �ڽ� �� ���� ������ �༮�� ����
	return;
}

void TicTaToc::MoveRecursive()
{

}