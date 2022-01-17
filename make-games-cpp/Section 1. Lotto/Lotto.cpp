#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	// Lotto Program
	int iLotto[45] = {};

	// 1 ~ 45 ������ ���ڸ� ���ʴ�� �־��ش�.
	for (int i = 0; i < 45; i++)
	{
		iLotto[i] = i + 1;
	}

	// Swap �˰���
	/*
	int iNum1 = 1, iNum2 = 2, iNum3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;
	*/

	// Shuffle
	int iTemp, idx1, idx2;

	// 100�� ���� ���� �����ش�.
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	for (int i = 0; i < 6; i++)
		cout << iLotto[i] << "\t";

	cout << "���ʽ� ��ȣ : " << iLotto[6] << endl;

	return 0;
}

// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7812?tab=note