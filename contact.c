#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
}
void CheckCapacity(struct Contact*ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr=realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("Extension succeed\n");
		}
		else
		{
			printf("Extension failed\n");
		}
	}

}
void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);
	
		printf("Please input the name：");
		scanf("%s", ps->data[ps->size].name);
		printf("Please input the age：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("Please input the gender：");
		scanf("%s", ps->data[ps->size].sex);
		printf("Please input the phone number：");
		scanf("%s", ps->data[ps->size].tele);
		printf("Please input the address：");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("Added successfully\n");
	
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
	printf("Please input the name of the person to delete:\n");
	scanf("%s", name);
	int pos=FindByName(ps,name);
	//找到了返回名字所在元素的下标，找不到返回-1
	
	if (pos == -1)
	{
		printf("The person is not in the address book\n");
	}
	else
	{
		int j = 0;
		for (j = pos;j < ps->size - 1;j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("Deleted successfully\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("Please enter the name of the person to find：\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("The person is not in the address book\n");
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
	printf("Please input the name of the person to modify:\n");
	scanf("%s", name);
	int pos=FindByName(ps, name);
	if (pos == -1)
		printf("The person is not in the address book");
	else
	{
		printf("Please input the name：");
		scanf("%s", ps->data[pos].name);
		printf("Please input the age：");
		scanf("%d", &(ps->data[pos].age));
		printf("Please input the gender：");
		scanf("%s", ps->data[pos].sex);
		printf("Please input the phone number：");
		scanf("%s", ps->data[pos].tele);
		printf("Please input the address：");
		scanf("%s", ps->data[pos].addr);
		
		printf("Modification completed\n");
	}
}
void SortContact(struct Contact* ps)
{
	bubble(ps->data,ps->size,sizeof(ps->data[0]),cmp);
	
}
void DestoryContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}
void menu()
{
	printf("*******************************************************************\n");
	printf("********    1.Add                          2.Delete       *********\n");
	printf("********    3.Retrieve                     4.Modify       *********\n");
	printf("********    5.Display                      6.Sort         *********\n");
	printf("********                      0.Exit                      *********\n");
	printf("*******************************************************************\n");
}