#define _CRT_SECURE_NO_WARNINGS //scanf경고 맘에 안들어서 씀
#define _CRT_NONSTDC_NO_WARNINGS //getch경고 맘에 안들어서 씀

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
		for (i = 1; i <= 3; i++) {  // i는 해당게임의 stage 를 의미함.
			load_game_obstacles_and_guns();
			stage_ui(); // 화면에 stage 1 이런식으로 출력 (아스키)
			while_playing_the_game();
		}
	case 2: system("cls"); help(); goto start;
	case 3: system("cls"); printf("\n    빠이빠이\n"); getch(); exit(1);
	}

}

void intro() {            //시작화면
	printf(" ●●●  ●●●  ●  ●\n");
	printf(" ●  ●  ●  ●   ●●\n");
	printf(" ●●●  ●  ●    ●\n");
	printf(" ●  ●  ●  ●    ●\n");
	printf(" ●●●  ●●●  ●  ●\n");
	printf("\n");
	printf("●  ● ●●●   ●   ●●\n");
	printf("●  ● ●      ●●  ● ●\n");
	printf("●●● ●●● ●●● ●  ●\n");
	printf("●  ● ●     ●  ● ● ●\n");
	printf("●  ● ●●● ●  ● ●●\n\n\n");
	printf("       GAME START\n");
	printf("      INFORMATION\n");
	printf("      FINISH GAME\n\n\n");
	getch();
	system("cls");
}

void help() {            //도움말

}

void start() {            //게임시작함수

}

void choice() {
	int list_key;
	list = 1;
	printf(" ●●●  ●●●  ●  ●\n");
	printf(" ●  ●  ●  ●   ●●\n");
	printf(" ●●●  ●  ●    ●\n");
	printf(" ●  ●  ●  ●    ●\n");
	printf(" ●●●  ●●●  ●  ●\n");
	printf("\n");
	printf("●  ● ●●●   ●   ●●\n");
	printf("●  ● ●      ●●  ● ●\n");
	printf("●●● ●●● ●●● ●  ●\n");
	printf("●  ● ●     ●  ● ● ●\n");
	printf("●  ● ●●● ●  ● ●●\n\n\n");
	printf("    ▶ GAME START ◀\n");
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
				printf(" ●●●  ●●●  ●  ●\n");
				printf(" ●  ●  ●  ●   ●●\n");
				printf(" ●●●  ●  ●    ●\n");
				printf(" ●  ●  ●  ●    ●\n");
				printf(" ●●●  ●●●  ●  ●\n");
				printf("\n");
				printf("●  ● ●●●   ●   ●●\n");
				printf("●  ● ●      ●●  ● ●\n");
				printf("●●● ●●● ●●● ●  ●\n");
				printf("●  ● ●     ●  ● ● ●\n");
				printf("●  ● ●●● ●  ● ●●\n\n\n");
				printf("    ▶ GAME START ◀\n");
				printf("      INFORMATION\n");
				printf("      FINISH GAME\n\n\n");
			}
			else if (list == 2) {
				list = 2;
				printf(" ●●●  ●●●  ●  ●\n");
				printf(" ●  ●  ●  ●   ●●\n");
				printf(" ●●●  ●  ●    ●\n");
				printf(" ●  ●  ●  ●    ●\n");
				printf(" ●●●  ●●●  ●  ●\n");
				printf("\n");
				printf("●  ● ●●●   ●   ●●\n");
				printf("●  ● ●      ●●  ● ●\n");
				printf("●●● ●●● ●●● ●  ●\n");
				printf("●  ● ●     ●  ● ● ●\n");
				printf("●  ● ●●● ●  ● ●●\n\n\n");
				printf("       GAME START\n");
				printf("   ▶ INFORMATION ◀\n");
				printf("      FINISH GAME\n\n\n");
			}
			else if (list >= 3) {
				list = 3;
				printf(" ●●●  ●●●  ●  ●\n");
				printf(" ●  ●  ●  ●   ●●\n");
				printf(" ●●●  ●  ●    ●\n");
				printf(" ●  ●  ●  ●    ●\n");
				printf(" ●●●  ●●●  ●  ●\n");
				printf("\n");
				printf("●  ● ●●●   ●   ●●\n");
				printf("●  ● ●      ●●  ● ●\n");
				printf("●●● ●●● ●●● ●  ●\n");
				printf("●  ● ●     ●  ● ● ●\n");
				printf("●  ● ●●● ●  ● ●●\n\n\n");
				printf("       GAME START\n");
				printf("      INFORMATION\n");
				printf("   ▶ FINISH GAME ◀\n\n\n");
			}
		}
	}
}

void login_or_register_interface() { // 프로그램을 시작하면 제일 먼저 뜨는 화면. 
									 // 로그인, 회원가입 버튼등을 첨부할것

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