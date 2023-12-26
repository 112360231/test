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
		boss = 500; // �ק� BOSS ����q
		break;
	case 2:
		boss = 800; // �ק� BOSS ����q
		break;
	case 3:
		boss = 1500; // �ק� BOSS ����q
		break;
	default:
		boss = 800; // �ק� BOSS ����q
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
	int bossDamage = rand() % 150 + 50; // �ק� BOSS �������O�d��
	play->HP -= bossDamage;
	printf("BOSS��A�y���F %d �I�ˮ`�I\n", bossDamage);
}

void battle(int *bossHP, struct player *play) {
	int playerChoice;
	while (*bossHP > 0 && play->HP > 0) {
		printf("���a��q�G%d\n", play->HP);
		printf("BOSS��q�G%d\n", *bossHP);
		printf("��ܧA���ʧ@�G\n");
		printf("(1) ����\n");
		printf("(2) �v��\n");
		scanf_s("%d", &playerChoice); // �令 scanf_s

		if (playerChoice == 1) {
			int damage = play->attackrate * (rand() % 5 + 1);
			*bossHP -= damage;
			printf("�A�� BOSS �y���F %d �I�ˮ`�I\n", damage);
		}
		else if (playerChoice == 2) {
			int heal = play->healrate * (rand() % 3 + 1);
			play->HP += heal;
			printf("�A��_�F %d �I�ͩR�ȡI\n", heal);
		}
		else {
			printf("�L�Ī���ܡC\n");
		}

		if (*bossHP > 0) {
			bossAttack(bossHP, play);
		}

		if (*bossHP <= 0) {
			printf("�A���ѤF BOSS�I\n");
		}
		else if (play->HP <= 0) {
			printf("�A�Q BOSS ���ѤF�I�C�������C\n");
			break; // ���a���`�A�����C���j��
		}
	}
}

int main(void) {
	int difficulty = 0;
	struct player play1;
	play1.HP = 1000; // ��l�ƪ��a��q
	play1.attackrate = 50; // ��l�ƪ��a�������v
	play1.healrate = 30; // ��l�ƪ��a�v�����v

	while (difficulty != 1 && difficulty != 2 && difficulty != 3) {
		printf("�п������\n");
		printf("(1) ²�� (2) ���q (3) �x��\n");
		scanf_s("%d", &difficulty);

		if (difficulty != 1 && difficulty != 2 && difficulty != 3) {
			printf("�п�ܥ��T�����סI\n");
		}
	}

	int boss = game(difficulty); // ��� BOSS ����q

	battle(&boss, &play1); // �}�l�԰�

	return 0;
}