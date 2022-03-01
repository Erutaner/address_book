#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//����ͨѶ¼���ֻ�����Ԫ��
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����,�޷�����\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	return (-1);//�Ҳ��������
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
			if (cmp(((char*)base + j * width), ((char*)base + (j + 1) * width)) > 0)//��cmp����������������Ԫ�صĵ�ַ
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
	printf("�����뱻ɾ���˵�����:\n");
	scanf("%s", name);
	int pos=FindByName(ps,name);
	//�ҵ��˷�����������Ԫ�ص��±꣬�Ҳ�������-1
	
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos;j < ps->size - 1;j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�������\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		
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
	printf("������Ҫ�޸��˵�����:\n");
	scanf("%s", name);
	int pos=FindByName(ps, name);
	if (pos == -1)
		printf("Ҫ�޸��˵����ֲ�����");
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);
		
		printf("�޸����\n");
	}
}
void SortContact(struct Contact* ps)
{
	bubble(ps->data,ps->size,sizeof(ps->data[0]),cmp);
	ShowContact(ps);
}