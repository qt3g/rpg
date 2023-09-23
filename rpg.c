//123世代向けPサー秋学期講義用
//プログラミングⅠとchar型の知識でドラクエ（コマンド可）を作る
//122I066
//printf：とりあえず一通り表示させよう
//scanf：コマンド入力を実装しよう
//for：ターンを続行させよう
//配列：ターン数に応じて敵の攻撃が変わるようにしよう
//関数：HPバーを関数化させよう
//文字型：勇者の名前を変えよう
//設定：[プロジェクト]→[プロパティ]→[C/C++]→[SDLチェック]のOFF


#include<stdio.h>

void HPbar(int hit_points) {//HPバーの表示を行うvoid型関数　int型のHPを引数として受け取る
	for (int i = 0; i < hit_points; i++){//forループ
		printf("■");//HPバー１つぶん。これを横つなぎにして棒っぽくする
	}
}

int main(void) {//メイン関数
	char name[10];//名前を格納する変数
	printf("名前を入力してください\n>>>");//指示
	scanf("%10s", name);//名前を入力
	putchar('\n');//改行
	int hero = 10;//プレイヤーのHP
	int boss = 30;//敵のHP

	for (int turn = 1; 1; turn++){//無限ループ
		printf("%sのHP：%d　",name, hero);//プレイヤーのHP表示
		HPbar(hero);//関数呼び出し
		printf("\n魔王のHP：%d　", boss);//敵のHP表示
		HPbar(boss);//関数呼び出し
		int command;//プレイヤーの入力するコマンドを格納する
		printf("\n\nコマンド\n１-攻撃\n２-魔法\n３-防御\n４-逃げる\n>>");//コマンド一覧
		scanf("%d", &command);//コマンド入力

		int attack = 5;//攻撃
		int magic = 10;//魔法・必殺
		int protect = 0;//防御状態 普段はFALSEということで0
		switch (command)//コマンドによって条件分岐するswitch文
		{
		case 1:printf("魔王に%dのダメージを与えた\n", attack);
			boss -= attack;
			break;
		case 2:printf("魔王に%dのダメージを与えた\n", magic);
			boss -= magic;
			break;
		case 3:printf("%sは守りを固めている\n",name);
			protect = 1;//防御状態をTRUEにする
			break;
		case 4:printf("%sは逃げた...\n", name);
			return 0;
			break;
		default:printf("コマンド失敗\n");
			break;
		}

		if (boss <= 0) {//敵のHPが0以下なら実行
			printf("魔王を倒した\n");
			return 0;//プログラム終了
		}

		/*敵のターン*/
		printf("\n魔王の攻撃\n");
		int boss_attack[3] = { 2,4,0, };//ターンによって攻撃が違う
		int boss_act = turn % 3;//ターン数に応じて行動変化。余りを用いて。0 1 2のどれか
		int damege = boss_attack[boss_act];//ダメージ決定
		if (protect){//条件が真、防御状態なら
			damege /= 2;//ダメージが半分になる
		}
		hero -= damege;//ダメージを与える

		switch (boss_act)//行動によってテキスト変化
		{
		case 0:printf("%sは%dのダメージをうけた\n", name, damege);
			break;
		case 1:printf("魔王の必殺技！！　%sは%dのダメージをうけた\n", name, damege);
			break;
		case 2:printf("魔王は様子を見ている\n");
			break;
		default:printf("エラー");//例外処理
			return 0;
			break;
		}

		if (hero <= 0) {//プレイヤーのHP0以下で実行
			printf("ヤラレチャッタ\n");
			return 0;//プログラム終了
		}

		putchar('\n');//改行
	}

	return 0;
}