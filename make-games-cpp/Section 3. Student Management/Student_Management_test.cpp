#include <iostream>

#define NAME_SIZE 64

using namespace std;

/*
����ü
- �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ����̴�.
- ����� ���� ���� Ÿ���̴�.
- ���� : struct ����ü�� {}; �� ���·� �����ȴ�.

�迭�� ����ü�� ������
- �������� �����̴�.
- ���ӵ� �޸� ���� �Ҵ�ȴ�.
- ����ü ������� ���ӵ� �޸� ������ ������ �ȴ�.
*/
struct _tagStudent
{
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

int main()
{
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// ����ü ����� ������ ���� . �� �̿��ؼ� �����ϰ� �ȴ�.
	tStudent.iKor = 100;

	//tStudent.strName = "ȫ�浿"; // error
	// ���ڿ��� �迭�� �־��� ������ �ܼ� �������δ� �Ұ����ϴ�.
	// strcpy_s ��� �Լ��� �̿��Ͽ� ���ڿ��� �����ؾ� �Ѵ�.
	strcpy_s(tStudent.strName, "ȫ�浿");

	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	// �����ʿ� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�.
	// strName���� "ȫ�浿"�� �����߱� ������ �� �ڿ� ���ڿ��� �ٿ��� ������ش�.
	strcat_s(tStudent.strName, " ���ڿ� ���̱�");

	// strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ�,
	// �ٸ� ��� 0�� �ƴ� ���� ��ȯ�Ѵ�.
	strcpy_s(tStudent.strName, "��ö��");

	cout << "���� �̸��� �Է��ϼ��� : ";
	char	strName[NAME_SIZE] = {};
	cin >> strName;
	
	if (strcmp(tStudent.strName, strName) == 0)
		cout << "�л��� ã�ҽ��ϴ�." << endl;
	else
		cout << "ã�� �л��� �����ϴ�." << endl;

	

	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	// ���ڿ��� ���� �׻� 0(NULL)���� ������ �Ѵ�. �׷��� ������ ���� ���ִ�
	// ���¿��� �Ʒ�ó�� �� �迭 ��ҿ� ���� �־��ָ� �� ���� ��µǰ�
	// �־����� ���� �κ��� ������ ������ �״�� ��µȴ�.
	// ����� �� ���ڿ��� ���� �ν��� �� ���� �����̴�.
	// 0�� ���� �ϴ� �ڸ��� ������ ���� �� �ֱ� �����ִ�.

	cout << "�̸� :	" << tStudent.strName << endl;
	cout << "�й� :	" << tStudent.iNumber << endl;
	cout << "���� :	" << tStudent.iKor << endl;
	cout << "���� :	" << tStudent.iEng << endl;
	cout << "���� :	" << tStudent.iMath << endl;
	cout << "���� :	" << tStudent.iTotal << endl;
	cout << "��� :	" << tStudent.fAvg << endl;

	return 0;
}

// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7821?tab=note