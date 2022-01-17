#include <iostream>
#include <time.h>
#include <conio.h>
// console input output 헤더파일이다. 콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일이다.

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}

	// 가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값 INT_MAX를 사용한다.
	// INT_MAX는 이미 정의된 값이며, int로 표현할 수 있는 최대값이다.
	iNumber[24] = INT_MAX;

	// 별이 있는 위치를 저장할 변수를 만들어준다.
	int iStarIndex = 24;

	// 마지막 공백을 제외한 1 ~ 24 까지의 숫자만 섞어준다.
	// 즉, 인덱스는 0 ~ 23 까지만 섞어준다.
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
		// i for문이 세로 줄을 의미한다.
		for (int i = 0; i < 5; i++)
		{
			// j for문이 가로 칸을 의미한다.
			for (int j = 0; j < 5; j++)
			{
				// i가 0일 때 j는 0 ~ 4 까지 반복한다. 이 경우 0 * 5 + (0 ~ 4) 를 더하였기 때문에
				// 인덱스는 0, 1, 2, 3, 4 가 나오게 된다.
				// (줄 번호 * 가로 개수 + 칸 번호)
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		// true로 주어서 먼저 모두 맞췄다고 가정한다.
		bool bWin = true;

		// 퍼즐을 맞추었는지 체크한다.
		for (int i = 0; i < 24; i++)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		cout << endl << "[w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료]" << endl;

		if (bWin == true)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		// _getch() 함수는 문자 1개를 입력받는 함수이다.
		// Enter를 치지 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.
		char cInput = _getch();

		if (cInput == 'Q' || cInput == 'q')
			break;

		switch (cInput)
		{
		case 'W':
		case 'w':
			// 가장 윗줄일 때는 W를 눌러도 위로 올라가서는 안된다.
			if (iStarIndex > 4)
			{
				// 별이 있는 위치에 바로 상단의 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// 상단의 위치에 별을 넣어줘서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex - 5] = INT_MAX;
				// 별이 한 칸 위로 올라갔으므로 한 칸 위의 인덱스로 만들어준다.
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

	cout << endl << "게임을 종료합니다." << endl;

	return 0;
}

// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7814?tab=note