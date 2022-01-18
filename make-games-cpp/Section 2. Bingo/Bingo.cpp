#include <iostream>
#include <time.h>

using namespace std;

// AI 난이도
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
	int iBingo = 0, iAIBingo = 0; // Player와 AI의 Bingo 수
	int iNoneSelect[25] = {}; // 선택되지 않은 목록 배열을 만들어준다.
	int iNoneSeclectCount = 0; // 선택되지 않은 숫자 개수를 저장한다.

	for (int i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1; // Player
		iAINumber[i] = i + 1; // AI
	}

	// 숫자를 섞어준다.
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





	// AI 난이도를 선택한다.
	while (true) {
		cout << " 1. Easy" << endl;
		cout << " 2. Hard" << endl;
		cout << "AI 모드를 선택하세요 : ";
		cin >> iAIMode;

		if (AM_EASY <= iAIMode <= AM_HARD)
			break;
	}





	while (true)
	{
		system("cls");
		
		// Player Bingo 판을 출력한다.
		cout << "================ Player ================" << endl;

		// 숫자를 5 x 5 로 출력한다.
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

		// Player Bingo 수를 출력한다.
		cout << "## Bingo Line : " << iBingo << " ##" << endl << endl;





		// AI 난이도 출력
		switch (iAIMode)
		{
		case AM_EASY:
			cout << "[ AI Mode : Easy ]" << endl;
			break;
		case AM_HARD:
			cout << "[ AI Mode : Hard ]" << endl;
			break;
		}

		// AI Bingo 판을 출력한다.
		cout << "================   AI   ================" << endl;

		// 숫자를 5 x 5 로 출력한다.
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

		// AI Bingo 수를 출력한다.
		cout << "## Bingo Line : " << iAIBingo << " ##" << endl << endl;





		// Player 차례
		// Bingo가 5 이상일 경우 게임을 종료한다.
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





		// Bingo 숫자 입력
		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (!(1 <= iInput <= 25))
			continue;





		// 중복입력을 체크하기 위한 변수이다.
		// 기본적으로 중복되었다고 하기위해 true로 지정한다.
		bool bAcc = true;

		// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지 확인한다.
		for (int i = 0; i < 25; i++)
		{
			// 같은 숫자가 있을 경우
			if (iInput == iNumber[i])
			{
				// 숫가를 찾았을 경우 중복된 숫자가 아니므로
				// bACC 변수를 false로 만들어준다.
				bAcc = false;

				// 숫자를 *로 변경하기 위해 특수한 값인 INT_MAX로 해준다.
				iNumber[i] = INT_MAX;

				// 더 이상 다른 숫자를 찾아볼 필요가 없으므로
				// for문을 빠져나간다.
				break;
			}
		}

		// bAcc 변수가 true일 경우 중복된 숫자를 입력해서
		// 숫자를 *로 바꾸지 못했으므로 다시 입력받게 continue 해준다.
		if (bAcc)
			continue;

		// 중복이 아니라면 AI의 숫자도 찾아서 *로 바꿔준다.
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iAINumber[i])
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}





		// AI Mode : Easy, Hard
		// AI가 선택을 한다. AI가 선택하는 것은 AI모드에 따라서 달라진다.
		switch (iAIMode)
		{
			/*
			AI Easy 모드는 현재 AI의 숫자목록 중 *로 바뀌지 않은 숫자 목록을 만들어서
			그 목록 중 하나를 선택하게 한다.(랜덤하게)
			*/
		case AM_EASY:
			// 선택되지 않은 숫자 목록을 만들어준다.
			// 선택되지 않은 숫자 개수는 목록을 만들 때 카운트해준다.
			iNoneSeclectCount = 0;
			for (int i = 0; i < 25; i++)
			{
				// 현재 숫자가 *이 아닐 경우
				if (iAINumber[i] != INT_MAX)
				{
					// *이 아닌 숫자일 경우 iNoneSelectCount를 인덱스로 활용한다.
					// 선택 안된 목록에 추가할때마다 개수를 1씩 증가하여 총 선택안된 개수를 구한다.
					// 그런데 0부터 카운트가 시작이므로 0번에 넣고 ++해서 1개 추가되었다고 해준다.
					iNoneSelect[iNoneSeclectCount] = iAINumber[i];
					iNoneSeclectCount++;
				}
			}

			// for문을 빠져나오면 선택되지 않은 목록이 만들어지고 목록의 개수가 만들어진다.
			// 선택되지 않은 목록의 숫자 중 랜덤한 하나의 숫자를 구하기 위해 랜덤한 인덱스를 구한다.
			iInput = iNoneSelect[rand() % iNoneSeclectCount];
			break;





			/*
			하드모드는 현재 숫자 중 빙고줄 완성 가능성이 가장 높은 줄을 찾아서
			그 줄에 있는 숫자 중 하나를 *로 만들어준다.
			*/
		case AM_HARD:
			int iLine = 0, iStarCount = 0, iSaveCount = 0;

			// 가로 줄 중 *이 가장 많은 라인을 찾아낸다.
			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						iStarCount++;
				}

				// '별이 5개 미만이어야 Bingo'인 라인이 아닌
				// '기존에 가장 많은 라인의 별 개수보다 커야 가장 별이 많은 라인'이므로
				// 라인 교체해주고 저장된 별 수를 교체한다.
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// 가로 라인은 0 ~ 4 로 의미를 부여한다.
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// 가로 라인 중 가장 별이 많은 라인은 이미 구했다.
			// 이 값과 세로 라인들을 비교하여 별이 가장 많은 라인을 구한다.
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
					// 세로 라인은 5 ~ 9 로 의미를 부여한다.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// 좌상단부터 우하단 대각선 확인
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

			// 우상단부터 좌하단 대각선 확인
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

			// 모든 라인을 조사했으면 iLine에 가능성이 가장 높은 줄 번호가 저장된다.
			// 그 줄에 있는 *이 아닌 숫자 중 하나를 선택하게 된다.
			
			// 가로 줄일 경우
			if (LN_H1 <= iLine && iLine <= LN_H5)
			{
				// iLine : 0 ~ 4
				for (int i = 0; i < 5; i++)
				{
					// 현재 줄에서 *이 아닌 숫자를 찾아낸다.
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}

			// 세로 줄일 경우
			else if (LN_V1 <= iLine && iLine <= LN_V5)
			{
				// iLine : 5 ~ 9
				for (int i = 0; i < 5; i++)
				{
					// 현재 줄에서 *이 아닌 숫자를 찾아낸다.
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			// 좌상단부터 우하단 대각선 확인
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

			// 우상단부터 좌하단 대각선 확인
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





		// AI가 숫자를 선택했으므로 플레이어와 AI의 숫자를 *로 바꿔준다.
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

		// 빙고 줄 수를 체크하는 것은 매번 숫자를 입력할때마다 처음부터 새로 카운트한다.
		// 그러므로 iBingo 변수를 0으로 매번 초기화하고 새롭게 줄 수를 구해주도록 한다.
		iBingo = 0, iAIBingo = 0;

		// 가로, 세로 줄 수를 구해준다.
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;

		for (int i = 0; i < 5; i++)
		{
			// 한줄을 체크하기 전에 먼저 0으로 별 개수를 초기화한다.
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				// Player 가로 별 개수를 구해준다.
				if (iNumber[i * 5 + j] == INT_MAX)
					iStar1++;

				// Player 세로 별 개수를 구해준다.
				if (iNumber[j * 5 + i] == INT_MAX)
					iStar2++;

				// AI 가로 별 개수를 구해준다.
				if (iAINumber[i * 5 + j] == INT_MAX)
					iAIStar1++;

				// AI 세로 별 개수를 구해준다.
				if (iAINumber[j * 5 + i] == INT_MAX)
					iAIStar2++;
			}

			// j for 문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇개인지
			// iStar1 변수에 들어가게 된다.
			// iStar1 값이 5면 한줄이 모두 *이므로 iBingo 카운트를 추가한다.
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

		// Player 좌상단부터 우하단 대각선 확인
		for (int i = 0; i < 25; i += 6)
			if (iNumber[i] == INT_MAX)
				iStar1++;

		// Player 우상단부터 좌하단 대각선 확인
		for (int i =20; i > 0; i -= 4)
			if (iNumber[i] == INT_MAX)
				iStar2++;

		// AI 좌상단부터 우하단 대각선 확인
		for (int i = 0; i < 25; i += 6)
			if (iAINumber[i] == INT_MAX)
				iAIStar1++;

		// AI 우상단부터 좌하단 대각선 확인
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

// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7816?tab=note
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7817?tab=note
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7818?tab=note
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7819?tab=note