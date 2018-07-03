#define _CRT_SECURE_NO_WARNINGS //scanf��� ���� �ȵ� ��
#define _CRT_NONSTDC_NO_WARNINGS //getch��� ���� �ȵ� ��

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

void intro();
void start();
void help();
void choice();
void login_or_register_interface();
void player_login();
void player_register();

void select_game_mode_interface();

void load_game_obstacles_and_guns();
void set_walls();
void where_to_spwan_player();

void stage_ui();

void while_playing_the_game();
void spawn_weapons_random();
void move_player();
void shoot_the_weapon();
void bullet_info();
int check_my_hp_info();

int list;

int main() {
	int i;
start:
	intro();
	choice();
	switch (list) {
	case 1:
		system("cls");
		login_or_register_interface();
		select_game_mode_interface();
		for (i = 1; i <= 3; i++) {  // i�� �ش������ stage �� �ǹ���.
			load_game_obstacles_and_guns();
			stage_ui(); // ȭ�鿡 stage 1 �̷������� ��� (�ƽ�Ű)
			while_playing_the_game();
		}
	case 2: system("cls"); help(); goto start;
	case 3: system("cls"); printf("\n    ���̺���\n"); getch(); exit(1);
	}

}

void intro() {            //����ȭ��
	printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
	printf(" ��  ��  ��  ��   �ܡ�\n");
	printf(" �ܡܡ�  ��  ��    ��\n");
	printf(" ��  ��  ��  ��    ��\n");
	printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
	printf("\n");
	printf("��  �� �ܡܡ�   ��   �ܡ�\n");
	printf("��  �� ��      �ܡ�  �� ��\n");
	printf("�ܡܡ� �ܡܡ� �ܡܡ� ��  ��\n");
	printf("��  �� ��     ��  �� �� ��\n");
	printf("��  �� �ܡܡ� ��  �� �ܡ�\n\n\n");
	printf("       GAME START\n");
	printf("      INFORMATION\n");
	printf("      FINISH GAME\n\n\n");
	getch();
	system("cls");
}

void help() {            //����

}

void start() {            //���ӽ����Լ�

}

void choice() {
	int list_key;
	list = 1;
	printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
	printf(" ��  ��  ��  ��   �ܡ�\n");
	printf(" �ܡܡ�  ��  ��    ��\n");
	printf(" ��  ��  ��  ��    ��\n");
	printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
	printf("\n");
	printf("��  �� �ܡܡ�   ��   �ܡ�\n");
	printf("��  �� ��      �ܡ�  �� ��\n");
	printf("�ܡܡ� �ܡܡ� �ܡܡ� ��  ��\n");
	printf("��  �� ��     ��  �� �� ��\n");
	printf("��  �� �ܡܡ� ��  �� �ܡ�\n\n\n");
	printf("    �� GAME START ��\n");
	printf("      INFORMATION\n");
	printf("      FINISH GAME\n\n\n");
	system("cls");
	while (1) {
		if (kbhit()) {
			list_key = getch();
			if (list_key == 224 || list_key == 0) {
				list_key = getch();
				switch (list_key) {
				case 72: list--; system("cls");  break;
				case 80: list++; system("cls");  break;
				}
			}
			else if (list_key == 13) {
				break;
			}
			if (list <= 1) {
				list = 1;
				printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
				printf(" ��  ��  ��  ��   �ܡ�\n");
				printf(" �ܡܡ�  ��  ��    ��\n");
				printf(" ��  ��  ��  ��    ��\n");
				printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
				printf("\n");
				printf("��  �� �ܡܡ�   ��   �ܡ�\n");
				printf("��  �� ��      �ܡ�  �� ��\n");
				printf("�ܡܡ� �ܡܡ� �ܡܡ� ��  ��\n");
				printf("��  �� ��     ��  �� �� ��\n");
				printf("��  �� �ܡܡ� ��  �� �ܡ�\n\n\n");
				printf("    �� GAME START ��\n");
				printf("      INFORMATION\n");
				printf("      FINISH GAME\n\n\n");
			}
			else if (list == 2) {
				list = 2;
				printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
				printf(" ��  ��  ��  ��   �ܡ�\n");
				printf(" �ܡܡ�  ��  ��    ��\n");
				printf(" ��  ��  ��  ��    ��\n");
				printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
				printf("\n");
				printf("��  �� �ܡܡ�   ��   �ܡ�\n");
				printf("��  �� ��      �ܡ�  �� ��\n");
				printf("�ܡܡ� �ܡܡ� �ܡܡ� ��  ��\n");
				printf("��  �� ��     ��  �� �� ��\n");
				printf("��  �� �ܡܡ� ��  �� �ܡ�\n\n\n");
				printf("       GAME START\n");
				printf("   �� INFORMATION ��\n");
				printf("      FINISH GAME\n\n\n");
			}
			else if (list >= 3) {
				list = 3;
				printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
				printf(" ��  ��  ��  ��   �ܡ�\n");
				printf(" �ܡܡ�  ��  ��    ��\n");
				printf(" ��  ��  ��  ��    ��\n");
				printf(" �ܡܡ�  �ܡܡ�  ��  ��\n");
				printf("\n");
				printf("��  �� �ܡܡ�   ��   �ܡ�\n");
				printf("��  �� ��      �ܡ�  �� ��\n");
				printf("�ܡܡ� �ܡܡ� �ܡܡ� ��  ��\n");
				printf("��  �� ��     ��  �� �� ��\n");
				printf("��  �� �ܡܡ� ��  �� �ܡ�\n\n\n");
				printf("       GAME START\n");
				printf("      INFORMATION\n");
				printf("   �� FINISH GAME ��\n\n\n");
			}
		}
	}
}

void login_or_register_interface() { // ���α׷��� �����ϸ� ���� ���� �ߴ� ȭ��. 
									 // �α���, ȸ������ ��ư���� ÷���Ұ�

	player_login();
	player_register();

}

void select_game_mode_interface() {

}

void player_login() {

}

void player_register() {

}

void load_game_obstacles_and_guns() {
	set_walls();
	where_to_spwan_player();
}

void set_walls() {

}

void where_to_spwan_player() {

}

void stage_ui() {

}

void while_playing_the_game() {
	int what_is_my_hp;

	while (1) {
		spawn_weapons_random();
		move_player();
		shoot_the_weapon();
		bullet_info();
		what_is_my_hp = check_my_hp_info();
		if (what_is_my_hp <= 0)
			break;
	}
}

void spawn_weapons_random() {

}

void move_player() {

}

void shoot_the_weapon() {

}

void bullet_info() {

}

int check_my_hp_info() {
	return 1;
}