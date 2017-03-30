#include<stdio.h>
#include<conio.h>
#include<windows.h>
void show_map(void);
void move(void);
void gotoxy(int x, int y);
void HideCursor(void);
int count = 0;
int map[8][6] = {
	{0,1,1,1,1,0},
	{1,1,0,0,1,0},
	{1,4,3,0,1,0},
	{1,1,3,0,1,1},
	{1,1,0,3,0,1},
	{1,2,3,0,0,1},
	{1,2,2,5,2,1},
	{1,1,1,1,1,1},
};
int main(void)
{
	system("mode con cols=16 lines=11");
	system("chcp 437");
	move();
}
void show_map(void)
{
	int i, j;
	system("cls");
	printf("\n ");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 6; j++) {
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1)printf("%c", 219);
			else if (map[i][j] == 2)printf("%c", 236);
			else if (map[i][j] == 3)printf("%c", 240);
			else if (map[i][j] == 4)printf("%c", 232);
			else if (map[i][j] == 5)printf("%c", 178);
			else if (map[i][j] == 6)printf("%c", 232);
		}
		printf("\n ");
	}
	gotoxy(1, 9);
	printf("%d times moved.", count);
	HideCursor();
}
void move(void)
{
	show_map();
	int x = 2, y = 1;
	while (1) {
		char ch = _getch();
		if (ch = -32) {
			switch (ch = getch()) {
			case 72:ch = 'w'; break;
			case 80:ch = 's'; break;
			case 75:ch = 'a'; break;
			case 77:ch = 'd'; break;
			}
		}
		if (ch == 'a') {
			if (map[x][y] == 4) {  //�����ɫ���ڵ�û�б�־��
				if (map[x][y - 1] == 3) {    //�����ɫ�����һ��������
					if (y > 1 && map[x][y - 2] == 0) {   //�����������ǿյ�
						map[x][y - 2] = 3;
						map[x][y - 1] = 4;
						map[x][y] = 0;
						--y;
						count++;
					}
					else if (y > 1 && map[x][y - 2] == 2) {   //������������һ����־��
						map[x][y - 2] = 5;       //�����ƶ���Ŀ���
						map[x][y - 1] = 4;
						map[x][y] = 0;
						--y;
						count++;
					}
				}
				else if (map[x][y - 1] == 5) {     //��ɫ�����һ��������
					if (y > 1 && map[x][y - 2] == 0) {    //�������������ǿյ�
						map[x][y - 2] = 3;
						map[x][y - 1] = 6;    //��ɫ�ƶ���Ŀ���
						map[x][y] = 0;
						--y;
						count++;
					}
					else if (y > 1 && map[x][y - 2] == 2) {    //�����������Ŀ���
						map[x][y - 2] = 5;
						map[x][y - 1] = 6;
						map[x][y] = 0;
						--y;
						count++;
					}
				}
				else if (map[x][y - 1] == 0) {   //�����ɫ����ǿյ�
					map[x][y - 1] = 4;
					map[x][y] = 0;
					--y;
					count++;
				}
				else if (map[x][y - 1] == 2) {
					map[x][y - 1] = 6;
					map[x][y] = 0;
					--y;
					count++;
				}
			}
			else if (map[x][y] == 6) {     //�����ɫλ�ڱ�ǵ�
				if (map[x][y - 1] == 5) {   //����������λ�ڱ�ǵ�
					if (y > 1 && map[x][y - 2] == 0) {      //�����������ǿյ�
						map[x][y - 2] = 3;
						map[x][y - 1] = 6;
						map[x][y] = 2;
						--y;
						count++;
					}
					else if (y > 1 && map[x][y - 2] == 2) {    //�����������Ǳ�ǵ�
						map[x][y - 2] = 5;
						map[x][y - 1] = 6;
						map[x][y] = 2;
						--y;
						count++;
					}
				}
				else if (map[x][y - 1] == 3) {   //�������Ǹ�������
					if (y > 1 && map[x][y - 2] == 0) {  //�����������Ǹ��յ�
						map[x][y - 2] = 3;
						map[x][y - 1] = 4;
						map[x][y] = 2;
						--y;
						count++;
					}
					else if (y > 1 && map[x][y - 2] == 2) {  //������������һ����־��
						map[x][y - 2] = 5;
						map[x][y - 1] = 4;
						map[x][y] = 2;
						--y;
						count++;
					}
				}
				else if (map[x][y - 1] == 0) {
					map[x][y - 1] = 4;
					map[x][y] = 2;
					--y;
					count++;
				}
				else if (map[x][y - 1] == 2) {
					map[x][y - 1] = 6;
					map[x][y] = 2;
					--y;
					count++;
				}
			}
		}
		if (ch == 'w') {
			if (map[x][y] == 4) {  //�����ɫ���ڵ�û�б�־��
				if (map[x - 1][y] == 3) {    //�����ɫ������һ��������
					if (x > 1 && map[x - 2][y] == 0) {   //������������ǿյ�
						map[x - 2][y] = 3;
						map[x - 1][y] = 4;
						map[x][y] = 0;
						--x;
						count++;
					}
					else if (x > 1 && map[x - 2][y] == 2) {   //�������������һ����־��
						map[x - 2][y] = 5;       //�����ƶ���Ŀ���
						map[x - 1][y] = 4;
						map[x][y] = 0;
						--x;
						count++;
					}
				}
				else if (map[x - 1][y] == 5) {     //��ɫ������һ��������
					if (x > 1 && map[x - 2][y] == 0) {    //��������������ǿյ�
						map[x - 2][y] = 3;
						map[x - 1][y] = 6;    //��ɫ�ƶ���Ŀ���
						map[x][y] = 0;
						--x;
						count++;
					}
					else if (x > 1 && map[x - 2][y] == 2) {    //������������Ŀ���
						map[x - 2][y] = 5;
						map[x - 1][y] = 6;
						map[x][y] = 0;
						--x;
						count++;
					}
				}
				else if (map[x - 1][y] == 0) {   //�����ɫ�����ǿյ�
					map[x - 1][y] = 4;
					map[x][y] = 0;
					--x;
					count++;
				}
				else if (map[x - 1][y] == 2) {
					map[x - 1][y] = 6;
					map[x][y] = 0;
					--x;
					count++;
				}
			}
			else if (map[x][y] == 6) {     //�����ɫλ�ڱ�ǵ�
				if (map[x - 1][y] == 5) {   //����������λ�ڱ�ǵ�
					if (x > 1 && map[x - 2][y] == 0) {      //�����������ǿյ�
						map[x - 2][y] = 3;
						map[x - 1][y] = 6;
						map[x][y] = 2;
						--x;
						count++;
					}
					if (x > 1 && map[x - 2][y] == 2) {    //�����������Ǳ�ǵ�
						map[x - 2][y] = 5;
						map[x - 1][y] = 6;
						map[x][y] = 2;
						--x;
						count++;
					}
				}
				else if (map[x - 1][y] == 3) {   //�������Ǹ�������
					if (x > 1 && map[x - 2][y] == 0) {  //�����������Ǹ��յ�
						map[x - 2][y] = 3;
						map[x - 1][y] = 4;
						map[x][y] = 2;
						--x;
						count++;
					}
					else if (x > 1 && map[x - 2][y] == 2) {  //������������һ����־��
						map[x - 2][y] = 5;
						map[x - 1][y] = 4;
						map[x][y] = 2;
						--x;
						count++;
					}
				}
				else if (map[x - 1][y] == 0) {
					map[x - 1][y] = 4;
					map[x][y] = 2;
					--x;
					count++;
				}
				else if (map[x - 1][y] == 2) {
					map[x - 1][y] = 6;
					map[x][y] = 2;
					--x;
					count++;
				}
			}
		}
		if (ch == 'd') {
			if (map[x][y] == 4) {  //�����ɫ���ڵ�û�б�־��
				if (map[x][y + 1] == 3) {    //�����ɫ�ұ���һ��������
					if (y < 6 && map[x][y + 2] == 0) {   //��������ұ��ǿյ�
						map[x][y + 2] = 3;
						map[x][y + 1] = 4;
						map[x][y] = 0;
						++y;
						count++;
					}
					else if (y < 6 && map[x][y + 2] == 2) {   //��������ұ���һ����־��
						map[x][y + 2] = 5;       //�����ƶ���Ŀ���
						map[x][y + 1] = 4;
						map[x][y] = 0;
						++y;
						count++;
					}
				}
				else if (map[x][y + 1] == 5) {     //��ɫ�ұ���һ��������
					if (y < 6 && map[x][y + 2] == 0) {    //����������ұ��ǿյ�
						map[x][y + 2] = 3;
						map[x][y + 1] = 6;    //��ɫ�ƶ���Ŀ���
						map[x][y] = 0;
						++y;
						count++;
					}
					else if (y < 6 && map[x][y + 2] == 2) {    //�������ұ���Ŀ���
						map[x][y + 2] = 5;
						map[x][y + 1] = 6;
						map[x][y] = 0;
						++y;
						count++;
					}
				}
				else if (map[x][y + 1] == 0) {   //�����ɫ�ұ��ǿյ�
					map[x][y + 1] = 4;
					map[x][y] = 0;
					++y;
					count++;
				}
				else if (map[x][y + 1] == 2) {
					map[x][y + 1] = 6;
					map[x][y] = 0;
					++y;
					count++;
				}
			}
			else if (map[x][y] == 6) {     //�����ɫλ�ڱ�ǵ�
				if (map[x][y + 1] == 5) {   //����������λ�ڱ�ǵ�
					if (y < 6 && map[x][y + 2] == 0) {      //�����������ǿյ�
						map[x][y + 2] = 3;
						map[x][y + 1] = 6;
						map[x][y] = 2;
						++y;
						count++;
					}
					else if (y < 6 && map[x][y + 2] == 2) {    //�����������Ǳ�ǵ�
						map[x][y + 2] = 5;
						map[x][y + 1] = 6;
						map[x][y] = 2;
						++y;
						count++;
					}
				}
				else if (map[x][y + 1] == 3) {   //�������Ǹ�������
					if (y < 6 && map[x][y + 2] == 0) {  //�����������Ǹ��յ�
						map[x][y + 2] = 3;
						map[x][y + 1] = 4;
						map[x][y] = 2;
						++y;
						count++;
					}
					else if (y < 6 && map[x][y + 2] == 2) {  //������������һ����־��
						map[x][y + 2] = 5;
						map[x][y + 1] = 4;
						map[x][y] = 2;
						++y;
						count++;
					}
				}
				else if (map[x][y + 1] == 0) {
					map[x][y + 1] = 4;
					map[x][y] = 2;
					++y;
					count++;
				}
				else if (map[x][y + 1] == 2) {
					map[x][y + 1] = 6;
					map[x][y] = 2;
					++y;
					count++;
				}
			}
		}
		if (ch == 's') {
			if (map[x][y] == 4) {  //�����ɫ���ڵ�û�б�־��
				if (map[x + 1][y] == 3) {    //�����ɫ������һ��������
					if (x < 5 && map[x + 2][y] == 0) {   //������������ǿյ�
						map[x + 2][y] = 3;
						map[x + 1][y] = 4;
						map[x][y] = 0;
						++x;
						count++;
					}
					else if (x < 5 && map[x + 2][y] == 2) {   //�������������һ����־��
						map[x + 2][y] = 5;       //�����ƶ���Ŀ���
						map[x + 1][y] = 4;
						map[x][y] = 0;
						++x;
						count++;
					}
				}
				else if (map[x + 1][y] == 5) {     //��ɫ������һ��������
					if (x < 5 && map[x + 2][y] == 0) {    //��������������ǿյ�
						map[x + 2][y] = 3;
						map[x + 1][y] = 6;    //��ɫ�ƶ���Ŀ���
						map[x][y] = 0;
						++x;
						count++;
					}
					else if (x < 5 && map[x + 2][y] == 2) {    //������������Ŀ���
						map[x + 2][y] = 5;
						map[x + 1][y] = 6;
						map[x][y] = 0;
						++x;
						count++;
					}
				}
				else if (map[x + 1][y] == 0) {   //�����ɫ�����ǿյ�
					map[x + 1][y] = 4;
					map[x][y] = 0;
					++x;
					count++;
				}
				else if (map[x + 1][y] == 2) {
					map[x + 1][y] = 6;
					map[x][y] = 0;
					++x;
					count++;
				}
			}
			else if (map[x][y] == 6) {     //�����ɫλ�ڱ�ǵ�
				if (map[x + 1][y] == 5) {   //����������λ�ڱ�ǵ�
					if (x < 5 && map[x + 2][y] == 0) {      //�����������ǿյ�
						map[x + 2][y] = 3;
						map[x + 1][y] = 6;
						map[x][y] = 2;
						++x;
						count++;
					}
					else if (x < 5 && map[x + 2][y] == 2) {    //�����������Ǳ�ǵ�
						map[x + 2][y] = 5;
						map[x + 1][y] = 6;
						map[x][y] = 2;
						++x;
						count++;
					}
				}
				else if (map[x + 1][y] == 3) {   //�������Ǹ�������
					if (x < 5 && map[x + 2][y] == 0) {  //�����������Ǹ��յ�
						map[x + 2][y] = 3;
						map[x + 1][y] = 4;
						map[x][y] = 2;
						++x;
						count++;
					}
					else if (x < 5 && map[x + 2][y] == 2) {  //������������һ����־��
						map[x + 2][y] = 5;
						map[x + 1][y] = 4;
						map[x][y] = 2;
						++x;
						count++;
					}
				}
				else if (map[x + 1][y] == 0) {
					map[x + 1][y] = 4;
					map[x][y] = 2;
					++x;
					count++;
				}
				else if (map[x + 1][y] == 2) {
					map[x + 1][y] = 6;
					map[x][y] = 2;
					++x;
					count++;
				}
			}
		}
		show_map();
		if (map[2][2] == 5 && map[3][2] == 5 && map[3][3] == 5) {
			system("cls");
			gotoxy(35, 15);
			printf("Congratulations!\n");
			break;
		}
	}
}
void gotoxy(int x, int y)//�ƶ���굽���꣨x,y) 
{
	HANDLE hwnd;    //����һ����Ϊhwnd�ľ������ 
	COORD coord;    //struct���Ͷ��� 
	coord.X = x;      //�Խṹ���б�����ֵ����Ժ����� 
	coord.Y = y;      //��Կ���̨������ 
	hwnd = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��ǰ����̨���ھ�� 
	SetConsoleCursorPosition(hwnd, coord);//����ƶ����ô��ڵ����λ�ã�x,y) 
}
void HideCursor(void)//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
