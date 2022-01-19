#include <iostream>

#define NAME_SIZE		32
#define ADDRESS_SIZE	128
#define PHONE_SIZE		14
#define STUDENT_MAX		10

using namespace std;

struct _tagStudent
{
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_SIZE];
	int		iNumber;
	int		iKor;
	int		iMath;
	int		iEng;
	int		iTotal;
	float	fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};

	char	strName[NAME_SIZE] = {};
	int		iStudentNumber = 1;
	int		iStudentCount = 0;

	while (true)
	{
		system("cls");

		// 메뉴를 출력한다.
		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생검색" << endl;
		cout << "4. 학생결과" << endl;
		cout << "5. 종료" << endl;

		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		// cin은 오른쪽에 int 변수가 오면 정수를 입력해야 한다.
		// 오른쪽에 오는 변수 타입에 맞춰서 값을 입력해야하는데
		// 다른 타입의 문자를 입력할 경우 에러가 발생한다. 
		// 그렇기 때문에 예외처리로 에러가 발생했는지 이곳에서 체크하여 에러가 발생하면
		// cin 내부의 에러버퍼를 비워주고, cin 내부에 입력버퍼가 있는데
		// 입력버퍼는 입력한 값을 저장해놓고 그 값을 변수에 넣어주는 역할을 한다.
		// 이 입력버퍼에 \n이 남아있으므로 버퍼를 순회하여 \n을 지워준다.
		// 버퍼 : 임시저장공간
		// 먼저 에러를 체크한다. cin.fail() 을 했을 때 입력 에러가 발생했을 경우 true를 반환한다.
		if (cin.fail())
		{
			// 에러버퍼를 비워준다.
			cin.clear();

			// 입력버퍼에 \n이 남아있으므로 입력버퍼를 검색하여 지워준다.
			// 첫번째는 검색하고자 하는 버퍼의 크기를 지정한다. (넉넉하게 1024byte 정도 지정)
			// 두번째는 찾고자 하는 문자를 넣어준다.
			// 그래서 입력버퍼 처음부터 \n이 있는 곳까지 찾아서
			// 그 부분을 모두 지우고 다시 입력받을 수 있도록 해준다.
			cin.ignore(1024, '\n');
		}

		if (iMenu == MENU_EXIT)
			break;





		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "==================== 학생추가 ====================" << endl;

			// 등록된 학생이 등록할 수 있는 최대치일 경우 더이상 등록이 안되게 막는다.
			if (iStudentCount >= STUDENT_MAX)
				break;

			// 학생정보를 추가한다. 학생정보 : 학번, 이름, 주소, 전화번호
			// 국어, 수학, 영어 점수를 입력받고 학번, 총점, 평균은 연산을 통해 계산한다.
			// 이름을 입력받는다.
			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;
			cin.ignore(1024, '\n');

			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "국어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "수학 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			cout << "영어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			// 총점
			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iMath +
				tStudentArr[iStudentCount].iEng;

			// 평균
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;

			// 학번
			tStudentArr[iStudentCount].iNumber = iStudentNumber;

			cout << "학생 추가 완료" << endl;
			iStudentNumber++;
			iStudentCount++;
			break;





		case MENU_DELETE:
			system("cls");
			cout << "==================== 학생삭제 ====================" << endl;

			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			// 등록된 학생 수만큼 반복하며 학생을 찾는다.
			for (int i = 0; i < iStudentCount; i++)
			{
				// 학생을 찾았을 경우
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					for (int j = i; j < iStudentCount - 1; j++)
						tStudentArr[j] = tStudentArr[j + 1];

					cout << "학생을 삭제하였습니다." << endl;
					iStudentCount--;

					break;
				}
			}
			break;





		case MENU_SEARCH:
			system("cls");
			cout << "==================== 학생탐색 ====================" << endl;

			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			// 등록된 학생 수만큼 반복하며 학생을 찾는다.
			for (int i = 0; i < iStudentCount; i++)
			{
				// 학생을 찾았을 경우
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "국어 : " << tStudentArr[i].iKor << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
					break;
				}
			}
			break;





		case MENU_OUTPUT:
			system("cls");
			cout << "==================== 학생출력 ====================" << endl;
			for (int i = 0; i < iStudentCount; i++)
			{
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "학번 : " << tStudentArr[i].iNumber << endl;
				cout << "국어 : " << tStudentArr[i].iKor << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
			}
			break;





		default:
			cout << "메뉴를 잘못 선택했습니다." << endl;
			break;
		}

		system("pause");
	}

	return 0;
}

// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7822?tab=note
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7823?tab=note