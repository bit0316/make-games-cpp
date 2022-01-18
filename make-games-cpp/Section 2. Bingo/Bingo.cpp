#include <iostream>
#include <time.h>

using namespace std;

// AI ���̵�
enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,	LN_H2,	LN_H3,	LN_H4,	LN_H5,
	LN_V1,	LN_V2,	LN_V3,	LN_V4,	LN_V5,
	LN_LT,	LN_RT
};

int main()
{
	srand((unsigned int)time(0));

	int iAIMode; // AI Mode
	int iNumber[25] = {}; // Player
	int iAINumber[25] = {}; // AI
	int iBingo = 0, iAIBingo = 0; // Player�� AI�� Bingo ��
	int iNoneSelect[25] = {}; // ���õ��� ���� ��� �迭�� ������ش�.
	int iNoneSeclectCount = 0; // ���õ��� ���� ���� ������ �����Ѵ�.

	for (int i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1; // Player
		iAINumber[i] = i + 1; // AI
	}

	// ���ڸ� �����ش�.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		// Player
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}





	// AI ���̵��� �����Ѵ�.
	while (true) {
		cout << " 1. Easy" << endl;
		cout << " 2. Hard" << endl;
		cout << "AI ��带 �����ϼ��� : ";
		cin >> iAIMode;

		if (AM_EASY <= iAIMode <= AM_HARD)
			break;
	}





	while (true)
	{
		system("cls");
		
		// Player Bingo ���� ����Ѵ�.
		cout << "================ Player ================" << endl;

		// ���ڸ� 5 x 5 �� ����Ѵ�.
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		// Player Bingo ���� ����Ѵ�.
		cout << "## Bingo Line : " << iBingo << " ##" << endl << endl;





		// AI ���̵� ���
		switch (iAIMode)
		{
		case AM_EASY:
			cout << "[ AI Mode : Easy ]" << endl;
			break;
		case AM_HARD:
			cout << "[ AI Mode : Hard ]" << endl;
			break;
		}

		// AI Bingo ���� ����Ѵ�.
		cout << "================   AI   ================" << endl;

		// ���ڸ� 5 x 5 �� ����Ѵ�.
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAINumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		// AI Bingo ���� ����Ѵ�.
		cout << "## Bingo Line : " << iAIBingo << " ##" << endl << endl;





		// Player ����
		// Bingo�� 5 �̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5 && iAIBingo >= 5)
		{
			cout << "Draw!" << endl;
			break;
		}
		else if (iBingo >= 5)
		{
			cout << "Player Win!" << endl;
			break;
		}
		else if (iAIBingo >= 5)
		{
			cout << "AI Win!" << endl;
			break;
		}





		// Bingo ���� �Է�
		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (!(1 <= iInput <= 25))
			continue;





		// �ߺ��Է��� üũ�ϱ� ���� �����̴�.
		// �⺻������ �ߺ��Ǿ��ٰ� �ϱ����� true�� �����Ѵ�.
		bool bAcc = true;

		// ��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ��� Ȯ���Ѵ�.
		for (int i = 0; i < 25; i++)
		{
			// ���� ���ڰ� ���� ���
			if (iInput == iNumber[i])
			{
				// ������ ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				// bACC ������ false�� ������ش�.
				bAcc = false;

				// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;

				// �� �̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ�
				// for���� ����������.
				break;
			}
		}

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ�
		// ���ڸ� *�� �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue ���ش�.
		if (bAcc)
			continue;

		// �ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iAINumber[i])
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}





		// AI Mode : Easy, Hard
		// AI�� ������ �Ѵ�. AI�� �����ϴ� ���� AI��忡 ���� �޶�����.
		switch (iAIMode)
		{
			/*
			AI Easy ���� ���� AI�� ���ڸ�� �� *�� �ٲ��� ���� ���� ����� ����
			�� ��� �� �ϳ��� �����ϰ� �Ѵ�.(�����ϰ�)
			*/
		case AM_EASY:
			// ���õ��� ���� ���� ����� ������ش�.
			// ���õ��� ���� ���� ������ ����� ���� �� ī��Ʈ���ش�.
			iNoneSeclectCount = 0;
			for (int i = 0; i < 25; i++)
			{
				// ���� ���ڰ� *�� �ƴ� ���
				if (iAINumber[i] != INT_MAX)
				{
					// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
					// ���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� �����Ͽ� �� ���þȵ� ������ ���Ѵ�.
					// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1�� �߰��Ǿ��ٰ� ���ش�.
					iNoneSelect[iNoneSeclectCount] = iAINumber[i];
					iNoneSeclectCount++;
				}
			}

			// for���� ���������� ���õ��� ���� ����� ��������� ����� ������ ���������.
			// ���õ��� ���� ����� ���� �� ������ �ϳ��� ���ڸ� ���ϱ� ���� ������ �ε����� ���Ѵ�.
			iInput = iNoneSelect[rand() % iNoneSeclectCount];
			break;





			/*
			�ϵ���� ���� ���� �� ������ �ϼ� ���ɼ��� ���� ���� ���� ã�Ƽ�
			�� �ٿ� �ִ� ���� �� �ϳ��� *�� ������ش�.
			*/
		case AM_HARD:
			int iLine = 0, iStarCount = 0, iSaveCount = 0;

			// ���� �� �� *�� ���� ���� ������ ã�Ƴ���.
			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						iStarCount++;
				}

				// '���� 5�� �̸��̾�� Bingo'�� ������ �ƴ�
				// '������ ���� ���� ������ �� �������� Ŀ�� ���� ���� ���� ����'�̹Ƿ�
				// ���� ��ü���ְ� ����� �� ���� ��ü�Ѵ�.
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// ���� ������ 0 ~ 4 �� �ǹ̸� �ο��Ѵ�.
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// ���� ���� �� ���� ���� ���� ������ �̹� ���ߴ�.
			// �� ���� ���� ���ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[j * 5 + i] == INT_MAX)
						iStarCount++;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// ���� ������ 5 ~ 9 �� �ǹ̸� �ο��Ѵ�.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// �»�ܺ��� ���ϴ� �밢�� Ȯ��
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
					iStarCount++;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_LT; // 10
				iSaveCount = iStarCount;
			}

			// ���ܺ��� ���ϴ� �밢�� Ȯ��
			iStarCount = 0;
			for (int i = 20; i > 0; i -= 4)
			{
				if (iAINumber[i] == INT_MAX)
					iStarCount++;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_RT; // 11
				iSaveCount = iStarCount;
			}

			// ��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��ȣ�� ����ȴ�.
			// �� �ٿ� �ִ� *�� �ƴ� ���� �� �ϳ��� �����ϰ� �ȴ�.
			
			// ���� ���� ���
			if (LN_H1 <= iLine && iLine <= LN_H5)
			{
				// iLine : 0 ~ 4
				for (int i = 0; i < 5; i++)
				{
					// ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}

			// ���� ���� ���
			else if (LN_V1 <= iLine && iLine <= LN_V5)
			{
				// iLine : 5 ~ 9
				for (int i = 0; i < 5; i++)
				{
					// ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			// �»�ܺ��� ���ϴ� �밢�� Ȯ��
			else if (iLine == LN_LT)
			{
				// iLine : 10
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}

			// ���ܺ��� ���ϴ� �밢�� Ȯ��
			else if (iLine == LN_RT)
			{
				// iLine : 10
				for (int i = 20; i > 0; i -= 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			break;
		}





		// AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; i++)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		// ���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�Ѵ�.
		// �׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ�ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0, iAIBingo = 0;

		// ����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;

		for (int i = 0; i < 5; i++)
		{
			// ������ üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				// Player ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					iStar1++;

				// Player ���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX)
					iStar2++;

				// AI ���� �� ������ �����ش�.
				if (iAINumber[i * 5 + j] == INT_MAX)
					iAIStar1++;

				// AI ���� �� ������ �����ش�.
				if (iAINumber[j * 5 + i] == INT_MAX)
					iAIStar2++;
			}

			// j for ���� ���������� ���� ���� ���� ���� �� ������ �����
			// iStar1 ������ ���� �ȴ�.
			// iStar1 ���� 5�� ������ ��� *�̹Ƿ� iBingo ī��Ʈ�� �߰��Ѵ�.
			if (iStar1 == 5)
				iBingo++;

			if (iStar2 == 5)
				iBingo++;

			if (iAIStar1 == 5)
				iAIBingo++;

			if (iAIStar2 == 5)
				iAIBingo++;
		}

		iStar1 = iStar2 = 0;
		iAIStar1 = iAIStar2 = 0;

		// Player �»�ܺ��� ���ϴ� �밢�� Ȯ��
		for (int i = 0; i < 25; i += 6)
			if (iNumber[i] == INT_MAX)
				iStar1++;

		// Player ���ܺ��� ���ϴ� �밢�� Ȯ��
		for (int i =20; i > 0; i -= 4)
			if (iNumber[i] == INT_MAX)
				iStar2++;

		// AI �»�ܺ��� ���ϴ� �밢�� Ȯ��
		for (int i = 0; i < 25; i += 6)
			if (iAINumber[i] == INT_MAX)
				iAIStar1++;

		// AI ���ܺ��� ���ϴ� �밢�� Ȯ��
		for (int i = 20; i > 0; i -= 4)
			if (iAINumber[i] == INT_MAX)
				iAIStar2++;

		if (iStar1 == 5)
			iBingo++;

		if (iStar2 == 5)
			iBingo++;

		if (iAIStar1 == 5)
			iAIBingo++;

		if (iAIStar2 == 5)
			iAIBingo++;
	}

	return 0;
}

// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7816?tab=note
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7817?tab=note
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7818?tab=note
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7819?tab=note