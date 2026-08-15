#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
//ゲームメイン
int main()
{
	//変数
	int answer = -1;//回答はまだ入力していないので-1
	int question;//問題を出す変数
	int count = 0;//回答した回数をカウントする変数
	//乱数初期化
	srand((unsigned int)time(nullptr));
	//問題の数字を0～100の中からランダムで出題する
	question = rand() % 101;
	//ゲーム開始
	cout << "数字当てゲーム" << endl;
	cout << "0～100までの数字を当ててください。" << endl;
	//ゲームループ
	while (question != answer)//回答と問題が異なればループする
	{
		//回答した回数+1追加する
		count++;
		//入力チェック
		while (true)
		{
			cout << "0～100の数字を入力してください：" << endl;
			//キーボード入力
			cin >> answer;
			//入力処理
			if (answer < 0 || answer > 100)//回答が0より小さく、100より大きければ入力をループさせる
			{
				cout << "入力に誤りがあります。再入力してください。" << endl;
			}
			else//回答が0～100の中で入力したらループを抜ける
			{
				break;
			}
		}

		//回答した数字を判定
		if (question > answer)//回答した数字が問題より小さければ以下の文字を表示する
		{
			cout << "もっと大きい数字です。" << endl;
		}
		else if (question < answer)//回答した数字が問題より大きければ以下の文字を表示する
		{
			cout << "もっと小さい数字です。" << endl;
		}
	}

	cout << endl;
	//回答した数字が問題の数字と同じならば以下の文字を表示する
	cout << "おめでとうございます！正解です！" << endl;
	cout << "正解：" << answer << endl;
	//回答した回数を表示する
	cout << count << "回目で当てることができました。" << endl;

	return 0;
}