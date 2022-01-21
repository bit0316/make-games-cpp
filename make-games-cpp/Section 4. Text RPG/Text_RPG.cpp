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

	// �������� �ʿ��� ����ġ ���
	const int iLevelUpExp[LEVEL_MAX] =
	{ 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };

	// JOB_END �� 4�̴�. ������ 3���̹Ƿ� -1�� ���༭ �迭�� �� �������� �����Ѵ�.
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





	// ������ ������ �� �÷��̾� ������ �����ϰ� �Ѵ�.
	_tagPlayer	tPlayer = {};

	// �÷��̾� �̸��� �Է¹޴´�.
	cout << "====================  ĳ����  ====================" << endl << endl;
	cout << "�̸� : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	// �÷��̾� ������ �Է¹޴´�.
	int iJob = JOB_NONE;
	while (true)
	{
		system("cls");
		cout << "====================  ĳ����  ====================" << endl << endl;
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob >= JOB_END)
		{
			cout << "�߸� �����Ͽ����ϴ�." << endl;
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
		strcpy_s(tPlayer.strJobName, "���");
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
		strcpy_s(tPlayer.strJobName, "�ü�");
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
		strcpy_s(tPlayer.strJobName, "������");
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
	




	// ���� ����� �����Ѵ�.
	_tagMonster	tMonsterArr[MT_BACK - 1] = {};

	// ��� ����
	strcpy_s(tMonsterArr[0].strName, "���");
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

	// Ʈ�� ����
	strcpy_s(tMonsterArr[1].strName, "Ʈ��");
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

	// �巡�� ����
	strcpy_s(tMonsterArr[2].strName, "�巡��");
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





	// �������� �Ǹ��� ������ ����� �����Ѵ�.
	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_WEAPON_MAX] = {};

	// ����
	strcpy_s(tStoreWeapon[0].strName, "�Ϲ� ����");
	strcpy_s(tStoreWeapon[0].strTypeName, "����");
	strcpy_s(tStoreWeapon[0].strDesc, "�Ϲ� �����.");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	strcpy_s(tStoreWeapon[1].strName, "��� ����");
	strcpy_s(tStoreWeapon[1].strTypeName, "����");
	strcpy_s(tStoreWeapon[1].strDesc, "�Ϲ� ���⺸�� ���ϴ�.");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;

	strcpy_s(tStoreWeapon[2].strName, "���� ����");
	strcpy_s(tStoreWeapon[2].strTypeName, "����");
	strcpy_s(tStoreWeapon[2].strDesc, "��� ���⺸�� ���ϴ�.");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 90;
	tStoreWeapon[2].iMax = 150;
	tStoreWeapon[2].iPrice = 30000;
	tStoreWeapon[2].iSell = 15000;

	// ��
	strcpy_s(tStoreArmor[0].strName, "�Ϲ� ����");
	strcpy_s(tStoreArmor[0].strTypeName, "��");
	strcpy_s(tStoreArmor[0].strDesc, "�Ϲ� �����̴�.");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 2;
	tStoreArmor[0].iMax = 5;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	strcpy_s(tStoreArmor[1].strName, "��� ����");
	strcpy_s(tStoreArmor[1].strTypeName, "��");
	strcpy_s(tStoreArmor[1].strDesc, "�Ϲ� ���ʺ��� ưư�ϴ�.");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].iMax = 20;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;

	strcpy_s(tStoreArmor[2].strName, "���� ����");
	strcpy_s(tStoreArmor[2].strTypeName, "��");
	strcpy_s(tStoreArmor[2].strDesc, "��� ���ʺ��� ưư�ϴ�.");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 70;
	tStoreArmor[2].iMax = 90;
	tStoreArmor[2].iPrice = 30000;
	tStoreArmor[2].iSell = 15000;





	while (true)
	{
		system("cls");
		cout << "====================   �κ�   ====================" << endl << endl;
		cout << "1. ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
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
			cout << "������ �����մϴ�." << endl;
			break;
		}

		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "====================    ��    ====================" << endl << endl;
				cout << "1. ����" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "4. �ڷΰ���" << endl;
				cout << "���� �����ϼ��� : ";
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
					cout << "�߸� �����Ͽ����ϴ�." << endl;
					system("pause");
					continue;
				}
				// ������ �޴����� 1�� ���ָ� ���� �迭�� �ε����� �ȴ�.
				// �׷��� �ؼ� �ش� ���� ���͸� �������ش�.
				_tagMonster tMonster = tMonsterArr[iMap - 1];

				while (true)
				{
					system("cls");
					switch (iMap)
					{
					case MT_EASY:
						cout << "====================   ����   ====================" << endl << endl;
						break;
					case MT_NORMAL:
						cout << "====================   ����   ====================" << endl << endl;
						break;
					case MT_HARD:
						cout << "====================  �����  ====================" << endl << endl;
						break;
					}

					// �÷��̾� ������ ����Ѵ�.
					cout << "  ------------------ �÷��̾� ------------------  " << endl;
					cout << "  �̸� : " << tPlayer.strName << endl;
					cout << "  ���� : " << tPlayer.strJobName << endl;
					cout << "  ���� : " << tPlayer.iLevel << endl;
					cout << "  ����ġ : " << tPlayer.iExp << endl;

					// ���⸦ �����ϰ� ���� ��� ���ݷ¿� ���� ���ݷ��� �߰��Ͽ� ����Ѵ�.
					if (tPlayer.bEquip[EQ_WEAPON])
					{
						cout << "  ���ݷ� : "
							<< tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " ~ "
							<< tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax << endl;
						cout << "  �������� : " << tPlayer.tEquip[EQ_WEAPON].strName;
					}
					else
					{
						cout << "  ���ݷ� : " << tPlayer.iAttackMin << " ~ "
							<< tPlayer.iAttackMax << endl;
						cout << "  �������� : ����" << endl;
					}

					// ���� �����ϰ� ���� ��� ���¿� �� ������ �߰��Ͽ� ����Ѵ�.
					if (tPlayer.bEquip[EQ_ARMOR])
					{
						cout << "  ���� : "
							<< tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " ~ "
							<< tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
						cout << "  ������ : " << tPlayer.tEquip[EQ_ARMOR].strName;
					}
					else
					{
						cout << "  ���� : " << tPlayer.iArmorMin << " ~ "
							<< tPlayer.iArmorMax << endl;
						cout << "  ������ : ����" << endl;
					}

					cout << "  ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax << endl;
					cout << "  ���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "  ���� ��� : " << tPlayer.tInventory.iGold << " Gold" << endl;
					cout << endl;

					// ���� ���� ���
					cout << "  ------------------  ����  ------------------  " << endl;
					cout << "  �̸� : " << tMonster.strName << endl;
					cout << "  ���� : " << tMonster.iLevel << endl;
					cout << "  ����ġ : " << tMonster.iExp << endl;
					cout << "  ���ݷ� : " << tMonster.iAttackMin << " ~ " << tMonster.iAttackMax << endl;
					cout << "  ���� : " << tMonster.iArmorMin << " ~ " << tMonster.iArmorMax << endl;
					cout << "  ü�� : " << tMonster.iHP << " / " << tMonster.iHPMax << endl;
					cout << "  ���� : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "  ȹ�� ����ġ : " << tMonster.iExp << endl;
					cout << "  ȹ�� ��� : " << tMonster.iGoldMin << " ~ " << tMonster.iGoldMax << endl;
					cout << endl;

					cout << "1. ����" << endl;
					cout << "2. ��������" << endl;
					cout << "�޴��� �����ϼ��� : ";
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

						// ���� HP ����
						tMonster.iHP -= iDamage;
						cout << tPlayer.strName << " ��(��) " << tMonster.strName << " ���� "
							<< iDamage << " ���ظ� �־����ϴ�." << endl;

						// ���Ͱ� �׾��� ���
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << " ��(��) óġ�Ͽ����ϴ�." << endl;

							tPlayer.iExp += tMonster.iExp;
							cout << tMonster.iExp << "����ġ�� ȹ���Ͽ����ϴ�." << endl;

							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1)
								+ tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;
							cout << iGold << "��带 ȹ���Ͽ����ϴ�." << endl;

							// ������ HP, MP�� ȸ���Ѵ�.
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							// �������� �ߴ��� Ȯ���Ѵ�.
							if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1])
							{
								// �÷��̾� ����ġ�� �������� �ʿ��� ����ġ��ŭ ������ ��, ������.
								tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];
								tPlayer.iLevel++;
								cout << "������ �Ͽ����ϴ�." << endl;

								// �ɷ�ġ�� ��½�Ų��.
								// ���� �ε����� ���Ѵ�.
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

								// ü�°� ������ ȸ����Ų��.
								tPlayer.iHP = tPlayer.iHPMax;
								tPlayer.iMP = tPlayer.iMPMax;
							}

							system("pause");
							break;
						}

						// ���Ͱ� ������� ��� (�÷��̾ ����)
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

						// �÷��̾� HP ����
						tPlayer.iHP -= iDamage;
						cout << tMonster.strName << " ��(��) " << tPlayer.strName << " ���� "
							<< iDamage << " ���ظ� �־����ϴ�." << endl;

						// �÷��̾ �׾��� ���
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << " ��(��) ����Ͽ����ϴ�." << endl;

							int iExp = tPlayer.iExp / 10;
							tPlayer.iExp -= iExp;
							cout << iExp << "����ġ�� �Ҿ����ϴ�." << endl;

							int iGold = tPlayer.tInventory.iGold / 10;
							tPlayer.tInventory.iGold -= iGold;
							cout << iGold << "��带 �Ҿ����ϴ�." << endl;

							// �÷��̾��� HP, MP�� ȸ���Ѵ�.
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}
						system("pause");
					}
					break;

					default:
						cout << "�߸� �����Ͽ����ϴ�." << endl;
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
				cout << "====================   ����   ====================" << endl << endl;
				cout << "1. ����" << endl;
				cout << "2. ��" << endl;
				cout << "3. �ڷΰ���" << endl;
				cout << "������ �����ϼ��� : ";
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
						cout << "====================   ����   ====================" << endl << endl;
						for (int i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << i + 1 << ". " << tStoreWeapon[i].strName << endl;
							cout << "���� : " << tStoreWeapon[i].strTypeName << endl;
							cout << "���ݷ� : " << tStoreWeapon[i].iMin << " ~ "
								<< tStoreWeapon[i].iMax << endl;
							cout << "���� : " << tStoreWeapon[i].strDesc << endl;
							cout << "���Ű��� : " << tStoreWeapon[i].iPrice << "���" << endl;
							cout << "�ǸŰ��� : " << tStoreWeapon[i].iSell << "���" << endl;
							cout << " " << endl;
						}
						cout << STORE_WEAPON_MAX + 1 << ". �ڷΰ���" << endl << endl;
						cout << "�����ݾ� : " << tPlayer.tInventory.iGold << " ���" << endl;
						cout << "�������� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount
							<< " ĭ" << endl;
						cout << "������ ������ �����ϼ��� : ";
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
							cout << "�߸� �����Ͽ����ϴ�." << endl;
							system("pause");
							continue;
						}

						// �ǸŸ�� �迭�� �ε����� ���Ѵ�.
						int iWeaponIndex = iWeapon - 1;

						// ��尡 ������ ���
						if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "��尡 �����մϴ�." << endl;
							system("pause");
							continue;
						}

						// ���� ������ ������ ���
						else if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX)
						{
							cout << "������ ���� á���ϴ�." << endl;
							system("pause");
							continue;
						}

						// ��� ����
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						// ������ �ε����� �߰�
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] =
							tStoreWeapon[iWeaponIndex];
						tPlayer.tInventory.iItemCount++;
						cout << tStoreWeapon[iWeaponIndex].strName << "��(��) �����Ͽ����ϴ�." << endl;

						system("pause");
					}
					break;

				case SM_ARMOR:
					while (true)
					{
						system("cls");
						cout << "====================  ��  ====================" << endl << endl;
						for (int i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << i + 1 << ". " << tStoreArmor[i].strName << endl;
							cout << "���� : " << tStoreArmor[i].strTypeName << endl;
							cout << "���� : " << tStoreArmor[i].iMin << " ~ "
								<< tStoreWeapon[i].iMax << endl;
							cout << "���� : " << tStoreArmor[i].strDesc << endl;
							cout << "���Ű��� : " << tStoreArmor[i].iPrice << "���" << endl;
							cout << "�ǸŰ��� : " << tStoreArmor[i].iSell << "���" << endl;
							cout << " " << endl;
						}
						cout << STORE_ARMOR_MAX + 1 << ". �ڷΰ���" << endl << endl;
						cout << "�����ݾ� : " << tPlayer.tInventory.iGold << " ���" << endl;
						cout << "�������� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount
							<< " ĭ" << endl;
						cout << "������ ������ �����ϼ��� : ";
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
							cout << "�߸� �����Ͽ����ϴ�." << endl;
							system("pause");
							continue;
						}

						// �ǸŸ�� �迭�� �ε����� ���Ѵ�.
						int iArmorIndex = iArmor - 1;

						// ��尡 ������ ���
						if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "��尡 �����մϴ�." << endl;
							system("pause");
							continue;
						}

						// ���� ������ ������ ���
						else if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX)
						{
							cout << "������ ���� á���ϴ�." << endl;
							system("pause");
							continue;
						}

						// ��� ����
						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

						// ������ �ε����� �߰�
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] =
							tStoreArmor[iArmorIndex];
						tPlayer.tInventory.iItemCount++;
						cout << tStoreArmor[iArmorIndex].strName << "��(��) �����Ͽ����ϴ�." << endl;

						system("pause");
					}
					break;

				default:
					cout << "�߸� �����Ͽ����ϴ�." << endl;
					system("pause");
					break;
				}
			}
			break;





		case MM_INVENTORY:
			while (true)
			{
				system("cls");
				cout << "====================   ����   ====================" << endl << endl;
				cout << "  ------------------ �÷��̾� ------------------  " << endl;
				cout << "  �̸� : " << tPlayer.strName << endl;
				cout << "  ���� : " << tPlayer.strJobName << endl;
				cout << "  ���� : " << tPlayer.iLevel << endl;
				cout << "  ����ġ : " << tPlayer.iExp << endl;

				// ���⸦ �����ϰ� ���� ��� ���ݷ¿� ���� ���ݷ��� �߰��Ͽ� ����Ѵ�.
				if (tPlayer.bEquip[EQ_WEAPON])
				{
					cout << "  ���ݷ� : "
						<< tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " ~ "
						<< tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax << endl;
					cout << "  �������� : " << tPlayer.tEquip[EQ_WEAPON].strName;
				}
				else
				{
					cout << "  ���ݷ� : " << tPlayer.iAttackMin << " ~ "
						<< tPlayer.iAttackMax << endl;
					cout << "  �������� : ����" << endl;
				}

				// ���� �����ϰ� ���� ��� ���¿� �� ������ �߰��Ͽ� ����Ѵ�.
				if (tPlayer.bEquip[EQ_ARMOR])
				{
					cout << "  ���� : "
						<< tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " ~ "
						<< tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					cout << "  ������ : " << tPlayer.tEquip[EQ_ARMOR].strName;
				}
				else
				{
					cout << "  ���� : " << tPlayer.iArmorMin << " ~ "
						<< tPlayer.iArmorMax << endl;
					cout << "  ������ : ����" << endl;
				}

				cout << "  ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax << endl;
				cout << "  ���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
				cout << "  ���� ��� : " << tPlayer.tInventory.iGold << " Gold" << endl;
				cout << endl;

				cout << "  ------------------   ���   ------------------  " << endl;
				for (int i = 0; i < tPlayer.tInventory.iItemCount; i++)
				{
					cout << "  " << i + 1 << ". " << tPlayer.tInventory.tItem[i].strName << endl;
					cout << "  ���� : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
					cout << "  ����/���� : " << tPlayer.tInventory.tItem[i].iMin << " ~ "
						<< tPlayer.tInventory.tItem[i].iMax << endl;
					cout << "  ���� : " << tPlayer.tInventory.tItem[i].strDesc << endl;
					cout << "  ���Ű��� : " << tPlayer.tInventory.tItem[i].iPrice << "���" << endl;
					cout << "  �ǸŰ��� : " << tPlayer.tInventory.tItem[i].iSell << "���" << endl;
					cout << endl;
				}

				cout << "  " << tPlayer.tInventory.iItemCount + 1 << ". �ڷΰ���" << endl << endl;
				cout << "������ �������� �����ϼ��� : ";
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
					cout << "�߸� �����Ͽ����ϴ�." << endl;
					system("pause");
					continue;
				}

				// ������ �ε����� ���Ѵ�.
				int idx = iEquip - 1;

				// ����� �������� ��� �ش� ����� ������ ���� ���������� �����Ѵ�.
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

				// ��� �����Ǿ� ���� ��� ������ ���� ������ ��� ��ü�ؾ��Ѵ�.
				// Swap �˰����� Ȱ���Ѵ�.
				if (tPlayer.bEquip[eq])
				{
					_tagItem	tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}

				// �����Ǿ����� ���� ��� �κ��丮 ����� �����ϰ�, �κ��丮 1ĭ�� ����.
				else
				{
					// ��� ����
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

					// �κ��丮 ���ڸ� ä���
					for (int i = idx; i < tPlayer.tInventory.iItemCount - 1; i++)
						tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];

					tPlayer.tInventory.iItemCount--;

					// ��� �����߱� ������ true�� ��ȯ�Ѵ�.
					tPlayer.bEquip[eq] = true;
				}

				cout << tPlayer.tEquip[eq].strName << "��(��) �����Ͽ����ϴ�." << endl;


				system("pause");
			}
			break;


			

			
		default:
			cout << "�߸� �����Ͽ����ϴ�." << endl;
			system("pause");
			break;
		}
	}

	return 0;
}

// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7825?tab=curriculum
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7826?tab=curriculum
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7827?tab=curriculum
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7828?tab=curriculum
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7829?tab=curriculum
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7830?tab=curriculum
// ��ó : https://www.inflearn.com/course/c_game-making/lecture/7831?tab=curriculum