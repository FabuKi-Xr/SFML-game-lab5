#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int, int);
void draw_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void erase_color();
void erase_ship(int , int );
void draw_bullet(int , int );
void erase_bullet(int , int);
int main()
{
	int x = 38, y = 20,direction=0,bullet_status,off=0,on=1,a,b;
	char ch = '.', bullet[5];
	setcursor(0);
	draw_ship(x, y);
	bullet_status = off;
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {
				direction = 4;
			}
			if (ch == 'd') {
				direction = 5;
			}
			if (ch == 's') {
			
			}
			fflush(stdin);
		}
		if (direction) {
			if (direction == 4) {
				erase_ship(x, y);
				draw_ship(--x, y);
			}
			if (direction == 5) {
				erase_ship(x, y);
				draw_ship(++x, y);
			}
			if (direction == 7) {
				erase_bullet(a, b);
				draw_bullet(a,--b);
			}
		}
		Sleep(50);
	} while (ch != 'x');
	return 0;
}
void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); 
	printf(" <-0-> ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void erase_color()
{
	setcolor(0,0);
	printf("       ");
}
void erase_ship(int x, int y) {
	system("cls");
}
void draw_bullet(int x, int y) {
	gotoxy(x,y);
	printf(" A ");
}
void erase_bullet(int a ,int b) {
	printf("   ");
}