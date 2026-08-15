#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	//定数
	const int CARD = 3;//所持カードの最大値
	const int CARD_NUMBER = 10;//カードの数字を算出

	//変数
	int i, hit = 0;
	int playerCard[CARD];//プレイヤーのカード
	int enemyCard[CARD];//エネミーのカード
	int plyChoice[CARD];//playerが入力する変数
	int emyChoice[CARD];//enemyが入力する変数

	bool trunFlag = true;
	bool judgementFlag = false;

	//乱数初期化
	srand((unsigned int)time(NULL));

	for (i = 0; i < CARD; i++)//playerとenemyに３枚のカードが渡される
	{
		//0～9の中からランダムでカードを配布
		playerCard[i] = rand() % CARD_NUMBER;
		enemyCard[i] = rand() % CARD_NUMBER;
	}
	
	cout << "===================   Hit & Blow   ============================" << "\n";
	cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";
	cout << "あなたの配られてカードは," << "\n";
	//ランダムで所持できるカードを配布
	for (i = 0; i < CARD; i++)
	{
		cout << i + 1 << "番目" << playerCard[i] << "\n";
	}
	//ゲーム開始
	cout << "===================   GAME STRAT   ============================" << "\n";

	//ゲームループ
	while (true)
	{
		//trunFlagが真の場合
		if (trunFlag)
		{
			//ヒットカウントを初期化
			hit = 0;
			cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";
			for (i = 0; i < CARD; i++)
			{
				//入力チェック
				while (true)
				{
					//キーボード入力
					cin >> plyChoice[i];
					if (0 > plyChoice[i] || 9 < plyChoice[i])//選択した数字が範囲外の場合
					{
						cout << "入力に誤りがあります。再度入力してください。\n";
					}
					else//選択した数字が範囲内の場合
					{
						break;
					}
				}
			}

			//カードを３枚選択
			for (i = 0; i < CARD; i++)
			{
				if (plyChoice[i] == enemyCard[i])//条件一致の場合
				{
					cout << "Hit,";//Hitを表示
					hit++;//hitカウントを+1
				}
				else//条件不一致の場合
				{
					cout << "Blow,";//Blowを表示
				}
			}
			cout << "\n";
			if (hit == 3)//Hitカウントが３の場合
			{
				cout << "3Hit!!\n";//3Hit表示
				judgementFlag = true;//judgementFlagを真にする
				break;
			}
			cout << "\n";
			trunFlag = false;//trunFlagを偽にする
		}
		else//trunflagが偽の場合
		{
			//hitカウントを初期化
			hit = 0;

			cout << "ENEMY TRUN \n";
			//カードを３枚選択
			for (i = 0; i < CARD; i++)
			{
				emyChoice[i] = rand() % CARD_NUMBER;//enemyがカードを選択

				cout << i + 1 << "番目" << emyChoice[i] << "\n";
			}

			for (i = 0; i < CARD; i++)
			{
				if (emyChoice[i] == playerCard[i])//条件一致の場合
				{
					cout << "Hit,";//Hitを表示
					hit++;//hitカウント+1
				}
				else//条件不一致の場合
				{
					cout << "Blow,";//Blowを表示
				}
			}
			cout << "\n";
			if (hit == 3)//hitカウントが３の場合
			{
				cout << "3Hit!!\n";//3Hit表示
				break;
			}

			cout << "\n";
			trunFlag = true;
		}
	}

	//結果表示
	if (judgementFlag)//条件一致の場合
	{
		//プレイヤー勝利
		cout << "PLAYER WINNER\n";
	}
	else//条件不一致の場合
	{
		//エネミー勝利
		cout << "ENEMY WINNER\n";
	}

	return 0;
}