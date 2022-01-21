#include <iostream>
#include <time.h>

#define NAME_SIZE			32
#define ITEM_DESC_SIZE		512
#define INVENTORY_MAX		20
#define STORE_WEAPON_MAX	3
#define STORE_ARMOR_MAX		3
#define LEVEL_MAX			10

using namespace std;

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK,
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
};

struct _tagItem
{
	char		strName[NAME_SIZE];
	char		strTypeName[NAME_SIZE];
	char		strDesc[ITEM_DESC_SIZE];
	ITEM_TYPE	eType;
	int			iMin;
	int			iMax;
	int			iPrice;
	int			iSell;
};

struct _tagInventory
{
	_tagItem	tItem[INVENTORY_MAX];
	int			iItemCount;
	int			iGold;
};

struct _tagPlayer
{
	char			strName[NAME_SIZE];
	char			strJobName[NAME_SIZE];
	JOB				eJob;
	int				iAttackMin;
	int				iAttackMax;
	int				iArmorMin;
	int				iArmorMax;
	int				iHP;
	int				iHPMax;
	int				iMP;
	int				iMPMax;
	int				iExp;
	int				iLevel;
	_tagInventory	tInventory;
	_tagItem		tEquip[EQ_MAX];
	bool			bEquip[EQ_MAX];
};

struct _tagMonster
{
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
	int		iGoldMin;
	int		iGoldMax;
};

struct _tagLevelUpStatus
{
	int	iAttackMin;
	int	iAttackMax;
	int	iArmorMin;
	int iArmorMax;
	int iHPMin;
	int iHPMax;
	int iMPMin;
	int iMPMax;
};

int main()
{
	srand((unsigned int)time(0));

	// 레벨업에 필요한 경험치 목록
	const int iLevelUpExp[LEVEL_MAX] =
	{ 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };

	// JOB_END 는 4이다. 직업은 3개이므로 -1을 해줘서 배열을 각 직업별로 생성한다.
	_tagLevelUpStatus	tLevelUpTable[JOB_END - 1] = {};

	tLevelUpTable[JOB_KNIGHT - 1].iAttackMin = 4;
	tLevelUpTable[JOB_KNIGHT - 1].iAttackMax = 10;
	tLevelUpTable[JOB_KNIGHT - 1].iArmorMin = 8;
	tLevelUpTable[JOB_KNIGHT - 1].iArmorMax = 16;
	tLevelUpTable[JOB_KNIGHT - 1].iHPMin = 50;
	tLevelUpTable[JOB_KNIGHT - 1].iHPMax = 100;
	tLevelUpTable[JOB_KNIGHT - 1].iMPMin = 10;
	tLevelUpTable[JOB_KNIGHT - 1].iMPMax = 20;

	tLevelUpTable[JOB_ARCHER - 1].iAttackMin = 10;
	tLevelUpTable[JOB_ARCHER - 1].iAttackMax = 15;
	tLevelUpTable[JOB_ARCHER - 1].iArmorMin = 5;
	tLevelUpTable[JOB_ARCHER - 1].iArmorMax = 10;
	tLevelUpTable[JOB_ARCHER - 1].iHPMin = 30;
	tLevelUpTable[JOB_ARCHER - 1].iHPMax = 60;
	tLevelUpTable[JOB_ARCHER - 1].iMPMin = 30;
	tLevelUpTable[JOB_ARCHER - 1].iMPMax = 50;

	tLevelUpTable[JOB_WIZARD - 1].iAttackMin = 15;
	tLevelUpTable[JOB_WIZARD - 1].iAttackMax = 20;
	tLevelUpTable[JOB_WIZARD - 1].iArmorMin = 3;
	tLevelUpTable[JOB_WIZARD - 1].iArmorMax = 7;
	tLevelUpTable[JOB_WIZARD - 1].iHPMin = 20;
	tLevelUpTable[JOB_WIZARD - 1].iHPMax = 40;
	tLevelUpTable[JOB_WIZARD - 1].iMPMin = 50;
	tLevelUpTable[JOB_WIZARD - 1].iMPMax = 100;





	// 게임을 시작할 때 플레이어 정보를 설정하게 한다.
	_tagPlayer	tPlayer = {};

	// 플레이어 이름을 입력받는다.
	cout << "====================  캐릭터  ====================" << endl << endl;
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	// 플레이어 직업을 입력받는다.
	int iJob = JOB_NONE;
	while (true)
	{
		system("cls");
		cout << "====================  캐릭터  ====================" << endl << endl;
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob >= JOB_END)
		{
			cout << "잘못 선택하였습니다." << endl;
			system("pause");
			continue;
		}
		break;
	}





	tPlayer.eJob = (JOB)iJob;
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.tInventory.iGold = 10000;
	tPlayer.tInventory.iItemCount = 0;

	switch (iJob)
	{
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "기사");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMPMax = 100;
		tPlayer.iMP = 100;
		break;

	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "궁수");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMPMax = 200;
		tPlayer.iMP = 200;
		break;

	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "마법사");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMPMax = 300;
		tPlayer.iMP = 300;
		break;
	}
	




	// 몬스터 목록을 생성한다.
	_tagMonster	tMonsterArr[MT_BACK - 1] = {};

	// 고블린 생성
	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// 트롤 생성
	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	// 드래곤 생성
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;





	// 상점에서 판매할 아이템 목록을 생성한다.
	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_WEAPON_MAX] = {};

	// 무기
	strcpy_s(tStoreWeapon[0].strName, "일반 무기");
	strcpy_s(tStoreWeapon[0].strTypeName, "무기");
	strcpy_s(tStoreWeapon[0].strDesc, "일반 무기다.");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	strcpy_s(tStoreWeapon[1].strName, "희귀 무기");
	strcpy_s(tStoreWeapon[1].strTypeName, "무기");
	strcpy_s(tStoreWeapon[1].strDesc, "일반 무기보다 강하다.");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;

	strcpy_s(tStoreWeapon[2].strName, "전설 무기");
	strcpy_s(tStoreWeapon[2].strTypeName, "무기");
	strcpy_s(tStoreWeapon[2].strDesc, "희귀 무기보다 강하다.");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 90;
	tStoreWeapon[2].iMax = 150;
	tStoreWeapon[2].iPrice = 30000;
	tStoreWeapon[2].iSell = 15000;

	// 방어구
	strcpy_s(tStoreArmor[0].strName, "일반 갑옷");
	strcpy_s(tStoreArmor[0].strTypeName, "방어구");
	strcpy_s(tStoreArmor[0].strDesc, "일반 갑옷이다.");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 2;
	tStoreArmor[0].iMax = 5;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	strcpy_s(tStoreArmor[1].strName, "희귀 갑옷");
	strcpy_s(tStoreArmor[1].strTypeName, "방어구");
	strcpy_s(tStoreArmor[1].strDesc, "일반 갑옷보다 튼튼하다.");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].iMax = 20;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;

	strcpy_s(tStoreArmor[2].strName, "전설 갑옷");
	strcpy_s(tStoreArmor[2].strTypeName, "방어구");
	strcpy_s(tStoreArmor[2].strDesc, "희귀 갑옷보다 튼튼하다.");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 70;
	tStoreArmor[2].iMax = 90;
	tStoreArmor[2].iPrice = 30000;
	tStoreArmor[2].iSell = 15000;





	while (true)
	{
		system("cls");
		cout << "====================   로비   ====================" << endl << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}

		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "====================    맵    ====================" << endl << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 : ";
				int iMap;
				cin >> iMap;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMap == MT_BACK)
					break;

				else if (iMap < 1 || iMap > MT_BACK)
				{
					cout << "잘못 선택하였습니다." << endl;
					system("pause");
					continue;
				}
				// 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
				// 그렇게 해서 해당 맵의 몬스터를 생성해준다.
				_tagMonster tMonster = tMonsterArr[iMap - 1];

				while (true)
				{
					system("cls");
					switch (iMap)
					{
					case MT_EASY:
						cout << "====================   쉬움   ====================" << endl << endl;
						break;
					case MT_NORMAL:
						cout << "====================   보통   ====================" << endl << endl;
						break;
					case MT_HARD:
						cout << "====================  어려움  ====================" << endl << endl;
						break;
					}

					// 플레이어 정보를 출력한다.
					cout << "  ------------------ 플레이어 ------------------  " << endl;
					cout << "  이름 : " << tPlayer.strName << endl;
					cout << "  직업 : " << tPlayer.strJobName << endl;
					cout << "  레벨 : " << tPlayer.iLevel << endl;
					cout << "  경험치 : " << tPlayer.iExp << endl;

					// 무기를 장착하고 있을 경우 공격력에 무기 공격력을 추가하여 출력한다.
					if (tPlayer.bEquip[EQ_WEAPON])
					{
						cout << "  공격력 : "
							<< tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " ~ "
							<< tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax << endl;
						cout << "  장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
					}
					else
					{
						cout << "  공격력 : " << tPlayer.iAttackMin << " ~ "
							<< tPlayer.iAttackMax << endl;
						cout << "  장착무기 : 없음" << endl;
					}

					// 방어구를 장착하고 있을 경우 방어력에 방어구 방어력을 추가하여 출력한다.
					if (tPlayer.bEquip[EQ_ARMOR])
					{
						cout << "  방어력 : "
							<< tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " ~ "
							<< tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
						cout << "  장착방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName;
					}
					else
					{
						cout << "  방어력 : " << tPlayer.iArmorMin << " ~ "
							<< tPlayer.iArmorMax << endl;
						cout << "  장착방어구 : 없음" << endl;
					}

					cout << "  체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << endl;
					cout << "  마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "  보유 골드 : " << tPlayer.tInventory.iGold << " Gold" << endl;
					cout << endl;

					// 몬스터 정보 출력
					cout << "  ------------------  몬스터  ------------------  " << endl;
					cout << "  이름 : " << tMonster.strName << endl;
					cout << "  레벨 : " << tMonster.iLevel << endl;
					cout << "  경험치 : " << tMonster.iExp << endl;
					cout << "  공격력 : " << tMonster.iAttackMin << " ~ " << tMonster.iAttackMax << endl;
					cout << "  방어력 : " << tMonster.iArmorMin << " ~ " << tMonster.iArmorMax << endl;
					cout << "  체력 : " << tMonster.iHP << " / " << tMonster.iHPMax << endl;
					cout << "  마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "  획득 경험치 : " << tMonster.iExp << endl;
					cout << "  획득 골드 : " << tMonster.iGoldMin << " ~ " << tMonster.iGoldMax << endl;
					cout << endl;

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요 : ";
					int iAction;
					cin >> iAction;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					if (iAction == BATTLE_BACK)
						break;

					switch (iAction)
					{
					case BATTLE_ATTACK:
					{
						int iAttackMin = tPlayer.iAttackMin;
						int iAttackMax = tPlayer.iAttackMax;

						if (tPlayer.bEquip[EQ_WEAPON])
						{
							iAttackMin += tPlayer.tEquip[EQ_WEAPON].iMin;
							iAttackMax += tPlayer.tEquip[EQ_WEAPON].iMax;
						}

						int iAttack = rand() % (iAttackMax - iAttackMin + 1)
							+ iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1)
							+ tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;
						iDamage = iDamage > 0 ? iDamage : 1;

						// 몬스터 HP 감소
						tMonster.iHP -= iDamage;
						cout << tPlayer.strName << " 이(가) " << tMonster.strName << " 에게 "
							<< iDamage << " 피해를 주었습니다." << endl;

						// 몬스터가 죽었을 경우
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << " 을(를) 처치하였습니다." << endl;

							tPlayer.iExp += tMonster.iExp;
							cout << tMonster.iExp << "경험치를 획득하였습니다." << endl;

							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1)
								+ tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;
							cout << iGold << "골드를 획득하였습니다." << endl;

							// 몬스터의 HP, MP를 회복한다.
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							// 레벨업을 했는지 확인한다.
							if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1])
							{
								// 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한 뒤, 레벨업.
								tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];
								tPlayer.iLevel++;
								cout << "레벨업 하였습니다." << endl;

								// 능력치를 상승시킨다.
								// 직접 인덱스를 구한다.
								int iJobIndex = tPlayer.eJob - 1;
								int iHPUp = rand() % (tLevelUpTable[iJobIndex].iHPMax - tLevelUpTable[iJobIndex].iHPMin + 1)
									+ tLevelUpTable[iJobIndex].iHPMin;
								int iMPUp = rand() % (tLevelUpTable[iJobIndex].iMPMax - tLevelUpTable[iJobIndex].iMPMin + 1)
									+ tLevelUpTable[iJobIndex].iMPMin;

								tPlayer.iAttackMin += tLevelUpTable[iJobIndex].iAttackMin;
								tPlayer.iAttackMax += tLevelUpTable[iJobIndex].iAttackMax;
								tPlayer.iArmorMin += tLevelUpTable[iJobIndex].iArmorMin;
								tPlayer.iArmorMax += tLevelUpTable[iJobIndex].iArmorMax;
								tPlayer.iHPMax += iHPUp;
								tPlayer.iMPMax += iMPUp;

								// 체력과 마나를 회복시킨다.
								tPlayer.iHP = tPlayer.iHPMax;
								tPlayer.iMP = tPlayer.iMPMax;
							}

							system("pause");
							break;
						}

						// 몬스터가 살아있을 경우 (플레이어를 공격)
						int iArmorMin = tPlayer.iArmorMin;
						int iArmorMax = tPlayer.iArmorMax;

						if (tPlayer.bEquip[EQ_ARMOR])
						{
							iArmorMin += tPlayer.tEquip[EQ_ARMOR].iMin;
							iArmorMax += tPlayer.tEquip[EQ_ARMOR].iMax;
						}

						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1)
							+ tMonster.iAttackMin;
						iArmor = rand() % (iArmorMax - iArmorMin + 1)
							+ iArmorMin;

						iDamage = iAttack - iArmor;
						iDamage = iDamage > 0 ? iDamage : 1;

						// 플레이어 HP 감소
						tPlayer.iHP -= iDamage;
						cout << tMonster.strName << " 이(가) " << tPlayer.strName << " 에게 "
							<< iDamage << " 피해를 주었습니다." << endl;

						// 플레이어가 죽었을 경우
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << " 이(가) 사망하였습니다." << endl;

							int iExp = tPlayer.iExp / 10;
							tPlayer.iExp -= iExp;
							cout << iExp << "경험치를 잃었습니다." << endl;

							int iGold = tPlayer.tInventory.iGold / 10;
							tPlayer.tInventory.iGold -= iGold;
							cout << iGold << "골드를 잃었습니다." << endl;

							// 플레이어의 HP, MP를 회복한다.
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}
						system("pause");
					}
					break;

					default:
						cout << "잘못 선택하였습니다." << endl;
						system("pause");
						break;
					}
				}
			}
			break;





		case MM_STORE:
			while (true)
			{
				system("cls");
				cout << "====================   싱점   ====================" << endl << endl;
				cout << "1. 무기" << endl;
				cout << "2. 방어구" << endl;
				cout << "3. 뒤로가기" << endl;
				cout << "상점을 선택하세요 : ";
				int iStore;
				cin >> iStore;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iStore == SM_BACK)
					break;

				switch (iStore)
				{
				case SM_WEAPON:
					while (true)
					{
						system("cls");
						cout << "====================   무기   ====================" << endl << endl;
						for (int i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << i + 1 << ". " << tStoreWeapon[i].strName << endl;
							cout << "종류 : " << tStoreWeapon[i].strTypeName << endl;
							cout << "공격력 : " << tStoreWeapon[i].iMin << " ~ "
								<< tStoreWeapon[i].iMax << endl;
							cout << "설명 : " << tStoreWeapon[i].strDesc << endl;
							cout << "구매가격 : " << tStoreWeapon[i].iPrice << "골드" << endl;
							cout << "판매가격 : " << tStoreWeapon[i].iSell << "골드" << endl;
							cout << " " << endl;
						}
						cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << endl << endl;
						cout << "보유금액 : " << tPlayer.tInventory.iGold << " 골드" << endl;
						cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount
							<< " 칸" << endl;
						cout << "구매할 물건을 선택하세요 : ";
						int iWeapon;
						cin >> iWeapon;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						if (iWeapon == STORE_WEAPON_MAX + 1)
							break;

						else if (iWeapon < 1 || iWeapon > STORE_WEAPON_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}

						// 판매목록 배열의 인덱스를 구한다.
						int iWeaponIndex = iWeapon - 1;

						// 골드가 부족할 경우
						if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "골드가 부족합니다." << endl;
							system("pause");
							continue;
						}

						// 가방 공간이 부족할 경우
						else if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX)
						{
							cout << "가방이 가득 찼습니다." << endl;
							system("pause");
							continue;
						}

						// 골드 차감
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						// 아이템 인덱스에 추가
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] =
							tStoreWeapon[iWeaponIndex];
						tPlayer.tInventory.iItemCount++;
						cout << tStoreWeapon[iWeaponIndex].strName << "을(를) 구매하였습니다." << endl;

						system("pause");
					}
					break;

				case SM_ARMOR:
					while (true)
					{
						system("cls");
						cout << "====================  방어구  ====================" << endl << endl;
						for (int i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << i + 1 << ". " << tStoreArmor[i].strName << endl;
							cout << "종류 : " << tStoreArmor[i].strTypeName << endl;
							cout << "방어력 : " << tStoreArmor[i].iMin << " ~ "
								<< tStoreWeapon[i].iMax << endl;
							cout << "설명 : " << tStoreArmor[i].strDesc << endl;
							cout << "구매가격 : " << tStoreArmor[i].iPrice << "골드" << endl;
							cout << "판매가격 : " << tStoreArmor[i].iSell << "골드" << endl;
							cout << " " << endl;
						}
						cout << STORE_ARMOR_MAX + 1 << ". 뒤로가기" << endl << endl;
						cout << "보유금액 : " << tPlayer.tInventory.iGold << " 골드" << endl;
						cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount
							<< " 칸" << endl;
						cout << "구매할 물건을 선택하세요 : ";
						int iArmor;
						cin >> iArmor;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						if (iArmor == STORE_ARMOR_MAX + 1)
							break;

						else if (iArmor < 1 || iArmor > STORE_ARMOR_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}

						// 판매목록 배열의 인덱스를 구한다.
						int iArmorIndex = iArmor - 1;

						// 골드가 부족할 경우
						if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "골드가 부족합니다." << endl;
							system("pause");
							continue;
						}

						// 가방 공간이 부족할 경우
						else if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX)
						{
							cout << "가방이 가득 찼습니다." << endl;
							system("pause");
							continue;
						}

						// 골드 차감
						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

						// 아이템 인덱스에 추가
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] =
							tStoreArmor[iArmorIndex];
						tPlayer.tInventory.iItemCount++;
						cout << tStoreArmor[iArmorIndex].strName << "을(를) 구매하였습니다." << endl;

						system("pause");
					}
					break;

				default:
					cout << "잘못 선택하였습니다." << endl;
					system("pause");
					break;
				}
			}
			break;





		case MM_INVENTORY:
			while (true)
			{
				system("cls");
				cout << "====================   가방   ====================" << endl << endl;
				cout << "  ------------------ 플레이어 ------------------  " << endl;
				cout << "  이름 : " << tPlayer.strName << endl;
				cout << "  직업 : " << tPlayer.strJobName << endl;
				cout << "  레벨 : " << tPlayer.iLevel << endl;
				cout << "  경험치 : " << tPlayer.iExp << endl;

				// 무기를 장착하고 있을 경우 공격력에 무기 공격력을 추가하여 출력한다.
				if (tPlayer.bEquip[EQ_WEAPON])
				{
					cout << "  공격력 : "
						<< tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " ~ "
						<< tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax << endl;
					cout << "  장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
				}
				else
				{
					cout << "  공격력 : " << tPlayer.iAttackMin << " ~ "
						<< tPlayer.iAttackMax << endl;
					cout << "  장착무기 : 없음" << endl;
				}

				// 방어구를 장착하고 있을 경우 방어력에 방어구 방어력을 추가하여 출력한다.
				if (tPlayer.bEquip[EQ_ARMOR])
				{
					cout << "  방어력 : "
						<< tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " ~ "
						<< tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					cout << "  장착방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName;
				}
				else
				{
					cout << "  방어력 : " << tPlayer.iArmorMin << " ~ "
						<< tPlayer.iArmorMax << endl;
					cout << "  장착방어구 : 없음" << endl;
				}

				cout << "  체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << endl;
				cout << "  마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
				cout << "  보유 골드 : " << tPlayer.tInventory.iGold << " Gold" << endl;
				cout << endl;

				cout << "  ------------------   장비   ------------------  " << endl;
				for (int i = 0; i < tPlayer.tInventory.iItemCount; i++)
				{
					cout << "  " << i + 1 << ". " << tPlayer.tInventory.tItem[i].strName << endl;
					cout << "  종류 : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
					cout << "  공격/방어력 : " << tPlayer.tInventory.tItem[i].iMin << " ~ "
						<< tPlayer.tInventory.tItem[i].iMax << endl;
					cout << "  설명 : " << tPlayer.tInventory.tItem[i].strDesc << endl;
					cout << "  구매가격 : " << tPlayer.tInventory.tItem[i].iPrice << "골드" << endl;
					cout << "  판매가격 : " << tPlayer.tInventory.tItem[i].iSell << "골드" << endl;
					cout << endl;
				}

				cout << "  " << tPlayer.tInventory.iItemCount + 1 << ". 뒤로가기" << endl << endl;
				cout << "장착할 아이템을 선택하세요 : ";
				int iEquip;
				cin >> iEquip;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iEquip == tPlayer.tInventory.iItemCount + 1)
					break;

				else if (iEquip < 1 || iEquip > tPlayer.tInventory.iItemCount + 1)
				{
					cout << "잘못 선택하였습니다." << endl;
					system("pause");
					continue;
				}

				// 아이템 인덱스를 구한다.
				int idx = iEquip - 1;

				// 제대로 선택했을 경우 해당 장비의 종류에 따라 장착부위를 결정한다.
				EQUIP	eq;

				switch (tPlayer.tInventory.tItem[idx].eType)
				{
				case IT_WEAPON:
					eq = EQ_WEAPON;
					break;
				case IT_ARMOR:
					eq = EQ_ARMOR;
					break;
				}

				// 장비가 장착되어 있을 경우 장착된 장비와 장착할 장비를 교체해야한다.
				// Swap 알고리즘을 활용한다.
				if (tPlayer.bEquip[eq])
				{
					_tagItem	tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}

				// 장착되어있지 않을 경우 인벤토리 장비을 장착하고, 인벤토리 1칸을 비운다.
				else
				{
					// 장비 장착
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

					// 인벤토리 빈자리 채우기
					for (int i = idx; i < tPlayer.tInventory.iItemCount - 1; i++)
						tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];

					tPlayer.tInventory.iItemCount--;

					// 장비를 장착했기 때문에 true로 변환한다.
					tPlayer.bEquip[eq] = true;
				}

				cout << tPlayer.tEquip[eq].strName << "을(를) 장착하였습니다." << endl;


				system("pause");
			}
			break;


			

			
		default:
			cout << "잘못 선택하였습니다." << endl;
			system("pause");
			break;
		}
	}

	return 0;
}

// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7825?tab=curriculum
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7826?tab=curriculum
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7827?tab=curriculum
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7828?tab=curriculum
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7829?tab=curriculum
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7830?tab=curriculum
// 출처 : https://www.inflearn.com/course/c_game-making/lecture/7831?tab=curriculum