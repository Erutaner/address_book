#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("*******************************************************************\n");
	printf("********    1.Add                          2.Delete       *********\n");
	printf("********    3.Retrieve                     4.Modify       *********\n");
	printf("********    5.Display                      6.Sort         *********\n");
	printf("********                      0.Exit                      *********\n");
	printf("*******************************************************************\n");
}
int main(void)
{
	int input = 0;
	//creat an address book
	struct Contact con;//con就是通讯录
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("Please input your choice:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			break;
		case 0:
			printf("Exit\n");
			break;
		default:
			printf("Wrong choice!\n");
			break;
		}
	} while (input);

	return 0;
}