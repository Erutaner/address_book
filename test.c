#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
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
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			printf("Sorting succeed!\n");
			break;
		case EXIT:
			//释放动态开辟的内存
			SaveContact(&con);
			DestoryContact(&con);
			printf("Exit\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("Wrong choice!\n");
			break;
		}
	} while (input);

	return 0;
}