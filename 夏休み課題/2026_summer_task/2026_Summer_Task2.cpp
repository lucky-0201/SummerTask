#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //変数
    int player;  //プレイヤーが入力する変数
    int cpu;     //ＣＰＵが入力する変数
    int result;  //結果
    int i;
    int win = 0; //勝利カウント
    int lose = 0;//敗北カウント
    int draw = 0;//引き分けカウント

    //乱数初期化
    srand((unsigned int)time(nullptr));

    //ゲーム開始
    cout << "じゃんけんゲームを開始します。" << endl;

    for (i = 0; i < 5; i++)//じゃんけんを５回する
    {
        cout << endl;
        //じゃんけんを１回するごとに、+1追加する
        cout << "-------- " << i + 1 << "回戦 --------" << endl;

        //入力チェック
        while (true)
        {
            cout << "0：グー　1：チョキ　2：パー" << endl;
            cout << "プレイヤーの手を入力してください：" << endl;
            //キーボード入力
            cin >> player;
            //入力処理
            if (player >= 0 && player <= 2)//入力した数字が範囲内の場合
            {
                break;
            }
            //if文のなか以外を入力したら再入力させる
            cout << "入力に誤りがあります。再入力してください。" << endl;
        }

        //CPUが0～2の中からランダムに生成
        cpu = rand() % 3;

        switch (player)//各種手の内容を表示
        {
        case 0:
            cout << "PLAYER：グー" << endl;//0を選択したら、グーと表示させる
            break;

        case 1:
            cout << "PLAYER：チョキ" << endl;//1を選択したら、チョキと表示させる
            break;

        case 2:
            cout << "PLAYER：パー" << endl;//2を選択したら、パーと表示させる
            break;
        }


        switch (cpu)//各種手の内容を表示
        {
        case 0:
            cout << "CPU：グー" << endl;//0を選択したら、グーと表示される
            break;

        case 1:
            cout << "CPU：チョキ" << endl;//1を選択したら、チョキと表示される
            break;

        case 2:
            cout << "CPU：パー" << endl;//2を選択したら、パーと表示される
            break;
        }

        //playerとcpuの値を引いた結果をresultに置き換える
        result = player - cpu;
        //結果判定
        if (result == -1 || result == 2)//結果が2または-1ならwinカウントを+1する
        {
            cout << "PLAYER WIN!" << endl;
            win++;
        }
        else if (result == 0)//結果が0ならdrawカウントを+1する
        {
            cout << "DRAW" << endl;
            draw++;
        }
        else//結果が1ならloseカウントを+1する
        {
            cout << "CPU WIN!" << endl;
            lose++;
        }
    }

    //ゲーム終了
    cout << endl;
    //試合結果を表示
    cout << "==============================" << endl;
    cout << "5回勝負終了！" << endl;
    cout << win << "勝 "
        << draw << "分 "
        << lose << "敗" << endl;
    cout << "==============================" << endl;

    return 0;
}