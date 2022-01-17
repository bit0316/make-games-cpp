#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[9] = {};

	// 1 ~ 9 까지 숫자를 설정한다.
	for (int i = 0; i < 9; i++)
		iNumber[i] = i + 1;

	// 설정된 숫자를 섞어준다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	// 숫자 비공개
	//cout << "< * * * >" << endl;

	// 숫자 공개
	cout << "< " << iNumber[0] << " " << iNumber[1] << " " << iNumber[2] << " >" << endl;

	int iStrike = 0, iBall = 0;
	int iInput[3];
	int iGameCount = 1;

	while (true)
	{
		cout << endl;
		cout << "[ " << iGameCount << " 회 ]" << endl;
		cout << "1 ~ 9 사이의 숫자 중 3개를 입력하세요(0 : 종료) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;

		else if (!(0 < iInput[0] < 10) || !(0 < iInput[1] < 10) || !(0 < iInput[2] < 10))
			cout << "잘못된 숫자를 입력하였습니다." << endl;

		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[2] == iInput[0])
			cout << "중복된 숫자를 입력하였습니다." << endl;

		// 매번 Strike와 Ball의 수가 달라지기 때문에 0으로 초기화하고 다시 계산한다.
		iStrike = iBall = 0;

		// i for문은 맞춰야 할 숫자의 인덱스를 구한다.
		for (int i = 0; i < 3; i++)
		{
			// j for문은 입력받은 숫자의 인덱스를 구한다.
			for (int j = 0; j < 3; j++)
			{
				// i가 0일 때 j는 0 ~ 2 까지 반복하게 된다.
				// 즉, 맞춰야할 숫자의 첫번째 값과 입력받은 숫자의 첫번째, 두번째, 세번째를
				// 차례대로 비교하여 같은 값이 있는지 찾아낸다.
				if (iNumber[i] == iInput[j])
				{
					// 값이 같은 것이 있을 경우 Strike 아니면 Ball 이므로 자리가 같은지 확인한다.
					// i와 j는 현재 맞춰야할 숫자의 인덱스와 입력받은 숫자의 인덱스이고,
					// 두 값이 같으므로 이 인덱스가 곧 위치가 된다.
					// 인덱스가 서로 같은 경우는 자리가 같다는 의미이므로 Strike를 증가하고,
					// 아닌 경우는 자리가 다르다는 의미이므로 Ball을 증가한다.
					if (i == j)
						iStrike++;
					else
						iBall++;

					// 입력받은 숫자와 맞춰야할 숫자를 비교할 때 같은 수가 있으면
					// 이 뒤로는 더 이상 같은 수가 없으므로 다음 맞춰야할 숫자와 비교하면 된다.
					// 그래서 break를 하여 j for문을 빠져나가고 i++로 다음 맞춰야할 숫자와 비교한다.
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
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

// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7813?tab=note