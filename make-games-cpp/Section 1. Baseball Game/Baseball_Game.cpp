#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[9] = {};

	// 1 ~ 9 ���� ���ڸ� �����Ѵ�.
	for (int i = 0; i < 9; i++)
		iNumber[i] = i + 1;

	// ������ ���ڸ� �����ش�.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	// ���� �����
	//cout << "< * * * >" << endl;

	// ���� ����
	cout << "< " << iNumber[0] << " " << iNumber[1] << " " << iNumber[2] << " >" << endl;

	int iStrike = 0, iBall = 0;
	int iInput[3];
	int iGameCount = 1;

	while (true)
	{
		cout << endl;
		cout << "[ " << iGameCount << " ȸ ]" << endl;
		cout << "1 ~ 9 ������ ���� �� 3���� �Է��ϼ���(0 : ����) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;

		else if (!(0 < iInput[0] < 10) || !(0 < iInput[1] < 10) || !(0 < iInput[2] < 10))
			cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�." << endl;

		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[2] == iInput[0])
			cout << "�ߺ��� ���ڸ� �Է��Ͽ����ϴ�." << endl;

		// �Ź� Strike�� Ball�� ���� �޶����� ������ 0���� �ʱ�ȭ�ϰ� �ٽ� ����Ѵ�.
		iStrike = iBall = 0;

		// i for���� ����� �� ������ �ε����� ���Ѵ�.
		for (int i = 0; i < 3; i++)
		{
			// j for���� �Է¹��� ������ �ε����� ���Ѵ�.
			for (int j = 0; j < 3; j++)
			{
				// i�� 0�� �� j�� 0 ~ 2 ���� �ݺ��ϰ� �ȴ�.
				// ��, ������� ������ ù��° ���� �Է¹��� ������ ù��°, �ι�°, ����°��
				// ���ʴ�� ���Ͽ� ���� ���� �ִ��� ã�Ƴ���.
				if (iNumber[i] == iInput[j])
				{
					// ���� ���� ���� ���� ��� Strike �ƴϸ� Ball �̹Ƿ� �ڸ��� ������ Ȯ���Ѵ�.
					// i�� j�� ���� ������� ������ �ε����� �Է¹��� ������ �ε����̰�,
					// �� ���� �����Ƿ� �� �ε����� �� ��ġ�� �ȴ�.
					// �ε����� ���� ���� ���� �ڸ��� ���ٴ� �ǹ��̹Ƿ� Strike�� �����ϰ�,
					// �ƴ� ���� �ڸ��� �ٸ��ٴ� �ǹ��̹Ƿ� Ball�� �����Ѵ�.
					if (i == j)
						iStrike++;
					else
						iBall++;

					// �Է¹��� ���ڿ� ������� ���ڸ� ���� �� ���� ���� ������
					// �� �ڷδ� �� �̻� ���� ���� �����Ƿ� ���� ������� ���ڿ� ���ϸ� �ȴ�.
					// �׷��� break�� �Ͽ� j for���� ���������� i++�� ���� ������� ���ڿ� ���Ѵ�.
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
			cout << "Out" << endl;

		else
			cout << iStrike << " strike " << iBall << " ball " << endl;

		iGameCount++;
	}

	return 0;
}

// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7813?tab=note