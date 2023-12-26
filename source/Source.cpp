#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct player {
	int HP, attackrate, healrate;
};

int game(int difficulty) {
	int boss;
	switch (difficulty) {
	case 1:
		boss = 500; // 修改 BOSS 的血量
		break;
	case 2:
		boss = 800; // 修改 BOSS 的血量
		break;
	case 3:
		boss = 1500; // 修改 BOSS 的血量
		break;
	default:
		boss = 800; // 修改 BOSS 的血量
	}
	return boss;
}


int timerand() {
	srand((unsigned int)(time(0)) + 110);
	int randomNumber = rand() % 15 + 1;
	printf("%d\n", randomNumber);
	return randomNumber;
}

void bossAttack(int *bossHP, struct player *play) {
	int bossDamage = rand() % 150 + 50; // 修改 BOSS 的攻擊力範圍
	play->HP -= bossDamage;
	printf("BOSS對你造成了 %d 點傷害！\n", bossDamage);
}

void battle(int *bossHP, struct player *play) {
	int playerChoice;
	while (*bossHP > 0 && play->HP > 0) {
		printf("玩家血量：%d\n", play->HP);
		printf("BOSS血量：%d\n", *bossHP);
		printf("選擇你的動作：\n");
		printf("(1) 攻擊\n");
		printf("(2) 治療\n");
		scanf_s("%d", &playerChoice); // 改成 scanf_s

		if (playerChoice == 1) {
			int damage = play->attackrate * (rand() % 5 + 1);
			*bossHP -= damage;
			printf("你對 BOSS 造成了 %d 點傷害！\n", damage);
		}
		else if (playerChoice == 2) {
			int heal = play->healrate * (rand() % 3 + 1);
			play->HP += heal;
			printf("你恢復了 %d 點生命值！\n", heal);
		}
		else {
			printf("無效的選擇。\n");
		}

		if (*bossHP > 0) {
			bossAttack(bossHP, play);
		}

		if (*bossHP <= 0) {
			printf("你打敗了 BOSS！\n");
		}
		else if (play->HP <= 0) {
			printf("你被 BOSS 擊敗了！遊戲結束。\n");
			break; // 玩家死亡，結束遊戲迴圈
		}
	}
}

int main(void) {
	int difficulty = 0;
	struct player play1;
	play1.HP = 1000; // 初始化玩家血量
	play1.attackrate = 50; // 初始化玩家攻擊倍率
	play1.healrate = 30; // 初始化玩家治療倍率

	while (difficulty != 1 && difficulty != 2 && difficulty != 3) {
		printf("請選擇難度\n");
		printf("(1) 簡單 (2) 普通 (3) 困難\n");
		scanf_s("%d", &difficulty);

		if (difficulty != 1 && difficulty != 2 && difficulty != 3) {
			printf("請選擇正確的難度！\n");
		}
	}

	int boss = game(difficulty); // 獲取 BOSS 的血量

	battle(&boss, &play1); // 開始戰鬥

	return 0;
}