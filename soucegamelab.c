#include<stdio.h>
#include<windows.h>
#include<conio.h>

void draw_ship(int x,int y){
	COORD c = { x, y };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , c);
	printf(" <-0-> ");   //length = 7
}

void erase_ship(int x,int y){
	COORD c = { x, y };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , c);
	printf("       ");
}

int main()
{
	char ch=' ';
	int x=38,y=20;
	draw_ship(x,y);
	do {
		if (_kbhit()){
			ch=_getch();
			if(ch=='a') {if (x>0) {draw_ship(--x,y);}}	//limit 72>=x>=0
			if(ch=='d') {if (x<72) {draw_ship(++x,y);}}
			if(ch=='w') {if (y>0 ) {erase_ship(x,y); draw_ship(x,--y);}}		//limit 80>=y>=0	
			if(ch=='s') {if (y<80) {erase_ship(x,y); draw_ship(x,++y);}}   
			fflush(stdin);
		}
		Sleep(500);
	} while (ch!='x');
return 0;
}