#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//设置通讯录最初只有零个元素
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满,无法增加\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (int i = 0;i < ps->size;i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return (i);
		}
	}
	return (-1);//找不到的情况
}
static int cmp(const void* e1, const void* e2)
{
	return -(((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age);
}
static void bubble(void* base, int sz, int width, int(*cmp)(const void*, const void*))
{
	for (int i = 0;i < sz - 1;i++)
	{
		for (int j = 0;j < sz - i - 1;j++)
		{
			if (cmp(((char*)base + j * width), ((char*)base + (j + 1) * width)) > 0)//给cmp传递两个相邻数组元素的地址
			{
				for (int k = 0;k < width;k++)
				{
					char tmp = *((char*)base + j * width + k);
					*((char*)base + j * width + k) = *((char*)base + (j + 1) * width + k);
					*((char*)base + (j + 1) * width + k) = tmp;


				}
			}
		}
	}
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入被删除人的名字:\n");
	scanf("%s", name);
	int pos=FindByName(ps,name);
	//找到了返回名字所在元素的下标，找不到返回-1
	
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos;j < ps->size - 1;j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的姓名：\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
		
	}
}
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:\n");
	scanf("%s", name);
	int pos=FindByName(ps, name);
	if (pos == -1)
		printf("要修改人的名字不存在");
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[pos].addr);
		
		printf("修改完成\n");
	}
}
void SortContact(struct Contact* ps)
{
	bubble(ps->data,ps->size,sizeof(ps->data[0]),cmp);
	ShowContact(ps);
}