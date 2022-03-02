#define _CRT_SECURE_NO_WARNINGS 1
//#define MAX 1000
#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录类型
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT

};
struct Contact
{
	struct PeoInfo *data;//用指针代替数组，可以进行动态内存的调整
	int size;//记录当前已经有的元素个数
	int capacity;//Maximum capacity of current address_book
};
//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact(struct Contact* ps);
void DestoryContact(struct Contact* ps);
void menu();