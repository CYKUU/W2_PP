#include <iostream> // input, output 스트림
#include <conio.h> // 콘솔 인풋 아웃풋
#include <Windows.h> // 창문

//game state == 0
int print_title_screen() {


	std::cout << "****************************************" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*             지렁이 게임              *" << std::endl;
	std::cout << "*            (Snake  Bite)             *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*  1. 게임 시작                        *" << std::endl;
	std::cout << "*  2. 게임 설명                        *" << std::endl;
	std::cout << "*  3. 게임 랭킹 보기                   *" << std::endl;
	std::cout << "*  4. 게임 종료 (esc)                  *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "****************************************" << std::endl;

	return 0;

}

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y }; // x, y 좌표를 받음

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 받은 좌표로 커서를 이동
}


void print_game_screen(int width, int height) {
	char** map = (char**)malloc(sizeof(char*) * height);
	//char형 포인터의 크기와 height 의 곱, height 개의 char형 포인터가 들어갈 공간 할당
	for (int i = 0; i < height; i++) {
		map[i] = (char*)malloc(sizeof(char) * width);
		// char 크기와 width 의 곱만큼을 할당
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1) { //height - 1 이 마지막 행이다
				map[i][j] = '*'; // i 가 0 이거나 height -1 이거나 j = 0 이거나 width -1 인 경우는 가장자리 뿐이다.
			}
			else {
				map[i][j] = ' '; // 가장자리가 아닌 이외 부분은 공백을 넣어준다.
			}
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << map[i][j] << " ";
		} // * 혹은 공백으로 출력한다
		std::cout << std::endl; // 개행문자 삽입하여 다음 줄로 이동
	}
	for (int i = 0; i < height; i++) {
		free(map[i]);
	} // 동적으로 할당된 메모리 해제
	free(map);
}




//game state == 2
int print_introduction_screen() {

	std::cout << "****************************************" << std::endl;
	std::cout << "*              게임 설명.              *" << std::endl;
	std::cout << "*      Snake bite란 뭘까욥?....        *" << std::endl;
	std::cout << "****************************************" << std::endl;
	std::cout << "*   타이틀화면으로 돌아갈까용? (Y/N)   *" << std::endl;

	return 0;
}


int main() {

	int game_state = 0;
	int mod = 1;
	int is_game_runing = 1; // 게임이 실행되어 있으면 1 이다.

	while (is_game_runing)
	{
		char key_input = 0;  // 0으로 초기화
		switch (game_state)
		{
		case 0: // 1번을 누를 경우
			if (mod) {
				print_title_screen();
			};
			key_input = _getch(); // 1,2,3,4 중 입력을 받음


			mod = 0; // 0으로 바꿔서 안뜨게 만든다.

			switch (key_input)
			{
			case '1':
				game_state = 1;
				mod = 1;
				break;  // while 문으로 첨부터 감
			case '2':
				game_state = 2;
				mod = 1;
				break;
			case '3':
				break;
			case '4':
				is_game_runing = 0;
				break;
			case 27:
				is_game_runing = 0;
			default:
				break;
			}
			break;
		case 1:

			if (mod) {
				int x = 0;  // 가로 변수
				int y = 0;  // 세로 변수
				std::cout << "*맵을 만들기 위해 x,y값을 입력해주세요!*" << std::endl;
				std::cout << "****************************************" << std::endl;
				scanf_s("%d", &x);  //가로 값 입력 받음
				x = x + 2; // 가장자리도 포함되기 때문에 2를 더함

				scanf_s("%d", &y);  //세로 값 입력 받음
				y = y + 2; // 가장자리도 포함되기 때문에 2를 더함

				system("cls");  //지금까지 출력된 화면을 지워줌
				print_game_screen(x, y);
			};
			key_input = _getch();
			mod = 0;
			break;
		case 2:

			if (mod) {
				print_introduction_screen(); // 게임 설명 화면으로 이동
			}

			key_input = 0;  //키 입력을 위해 변수 초기화
			key_input = _getch();  // 문자 하나 입력 받음

			mod = 0;

			if (key_input == 'y') {
				game_state = 0;  // 타이틀 스크린
				mod = 1;
			}
			else if (key_input == 'n') {

			}

		default:
			break;
		}

	}
	return 0;
}

