#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX_DICE_NUMBER = 6;
const int MIN_DICE_NUMBER = 1;
const int DICE = 2;
const int MAX_INPUT = 9;
const int MIN_INPUT = 1;
const int MAX_MASU = 9;
const int MIN_MASU = 1;

//入力関数
int InputCheck(int max,int min)
{
	int Choice;
	while (true)
	{
		cout << "入力してください。" << endl;

		cin >> Choice;
		if (Choice > max || min > Choice)
		{
			cout << "入力に誤りがあります、再度入力してください。" << endl;
		}
		else
		{
			break;
		}
	}

	return Choice;
}

int main()
{
	//変数
	int dice[2];
	int player;
	int cpuchoice;
	int;
	int i;
	int borad[10] = { 0 };

	bool playertrun = true;
	//乱数初期化
	srand((unsigned int)time(NULL));
	//

	while (true)
	{
		if (playertrun)
		{
			dice[0] = rand() % MAX_DICE_NUMBER + MIN_DICE_NUMBER;
			dice[1] = rand() % MAX_DICE_NUMBER + MIN_DICE_NUMBER;

			cout << "サイコロは、" << dice[0] << "と" << dice[1] << "です。" << endl;

			cout << "選べる数字は、" << endl;
			cout << dice[0] << endl;
			if (dice[0] != dice[1])
			{
				cout << dice[1] << endl;
			}
			if (dice[0] + dice[1] <= 9)
			{
				cout << dice[0] + dice[1] << endl;
			}

			while (true)
			{
				player = InputCheck(MAX_INPUT, MIN_INPUT);

				if (borad[player] != 0)
				{
					cout << "とれません" << endl;
					continue;
				}

				if (player == dice[0])
				{
					break;
				}

				if (player == dice[1])
				{
					break;
				}

				if (player == dice[0] + dice[1] &&
					dice[0] + dice[1] <= 9)
				{
					break;
				}


				cout << "その数字は選べません。" << endl;


			}
			borad[player] = 1;
			cout << player << "をとりました。" << endl;

			
		}
		else
		{
			dice[0] = rand() % MAX_DICE_NUMBER + MIN_DICE_NUMBER;
			dice[1] = rand() % MAX_DICE_NUMBER + MIN_DICE_NUMBER;

			cout << "CPUのサイコロは、" << dice[0] << "," << dice[1] << endl;

			int Choices[3];
			int choiceCount = 0;


			if (borad[dice[0]] == 0)
			{
				Choices[choiceCount] = dice[0];
				choiceCount++;
			}

			if (dice[1] != dice[0] &&
				borad[dice[1]] == 0)
			{
				Choices[choiceCount] == dice[1];
				choiceCount++;
			}

			int sum = dice[0] + dice[1];

			if (sum <= MAX_MASU &&
				borad[sum] == 0)
			{
				Choices[choiceCount] = sum;
				choiceCount++;
			}

			if (choiceCount == 0)
			{
				cout << "CPUはとれるマスがありません！" << endl;
				cout << "プレイヤーの勝ちです" << endl;
				break;
			}

			cpuchoice = Choices[rand() % choiceCount];

			cout << "CPUは" << cpuchoice << "を選びました" << endl;

			borad[cpuchoice] = 2;

		}

		cout << endl;
		cout << "現在の盤面" << endl;

		for (i = MIN_MASU;i <= MAX_MASU;i++)
		{
			cout << i << ":";

			if (borad[i] == 0)
			{
				cout << "□";
			}
			else if (borad[i] == 1)
			{
				cout << "P";
			}
			else
			{
				cout << "C";
			}
			cout << endl;
		}

		bool allTaken = true;

		for (i = MIN_MASU;i <= MAX_MASU;i++)
		{
			if (borad[i] == 0)
			{
				allTaken = false;
				break;
			}
		}

		if (allTaken)
		{
			cout << "すべてのマスがとられました！" << endl;

			if (playertrun)
			{
				cout << "playerWin" << endl;
			}
			else
			{
				cout << "CPUWin" << endl;
			}

			break;
		}

		playertrun = !playertrun;
	}
	


	return 0;
}