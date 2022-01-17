#include <iostream>
#include <time.h>
#include <conio.h>
// console input output ��������̴�. �ܼ�â���� ����� �ϴ� ��ɵ��� �������ִ� ��������̴�.

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}

	// ���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� �� INT_MAX�� ����Ѵ�.
	// INT_MAX�� �̹� ���ǵ� ���̸�, int�� ǥ���� �� �ִ� �ִ밪�̴�.
	iNumber[24] = INT_MAX;

	// ���� �ִ� ��ġ�� ������ ������ ������ش�.
	int iStarIndex = 24;

	// ������ ������ ������ 1 ~ 24 ������ ���ڸ� �����ش�.
	// ��, �ε����� 0 ~ 23 ������ �����ش�.
	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		system("cls");
		// i for���� ���� ���� �ǹ��Ѵ�.
		for (int i = 0; i < 5; i++)
		{
			// j for���� ���� ĭ�� �ǹ��Ѵ�.
			for (int j = 0; j < 5; j++)
			{
				// i�� 0�� �� j�� 0 ~ 4 ���� �ݺ��Ѵ�. �� ��� 0 * 5 + (0 ~ 4) �� ���Ͽ��� ������
				// �ε����� 0, 1, 2, 3, 4 �� ������ �ȴ�.
				// (�� ��ȣ * ���� ���� + ĭ ��ȣ)
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		// true�� �־ ���� ��� ����ٰ� �����Ѵ�.
		bool bWin = true;

		// ������ ���߾����� üũ�Ѵ�.
		for (int i = 0; i < 24; i++)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		cout << endl << "[w : �� s : �Ʒ� a : ���� d : ������ q : ����]" << endl;

		if (bWin == true)
		{
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}

		// _getch() �Լ��� ���� 1���� �Է¹޴� �Լ��̴�.
		// Enter�� ġ�� �ʴ��� ���ڸ� ������ ���� �ٷ� �� ���ڸ� ��ȯ�ϰ� �����Ѵ�.
		char cInput = _getch();

		if (cInput == 'Q' || cInput == 'q')
			break;

		switch (cInput)
		{
		case 'W':
		case 'w':
			// ���� ������ ���� W�� ������ ���� �ö󰡼��� �ȵȴ�.
			if (iStarIndex > 4)
			{
				// ���� �ִ� ��ġ�� �ٷ� ����� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// ����� ��ġ�� ���� �־��༭ 2���� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex - 5] = INT_MAX;
				// ���� �� ĭ ���� �ö����Ƿ� �� ĭ ���� �ε����� ������ش�.
				iStarIndex -= 5;
			}
			break;

		case 'A':
		case 'a':
			if (iStarIndex % 5 > 0)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				iStarIndex -= 1;
			}
			break;

		case 'S':
		case 's':
			if (iStarIndex < 20)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;

		case 'D':
		case 'd':
			if (iStarIndex % 5 < 4)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				iStarIndex += 1;
			}
			break;

		}
	}

	cout << endl << "������ �����մϴ�." << endl;

	return 0;
}

// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7814?tab=note