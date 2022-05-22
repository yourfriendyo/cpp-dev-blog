#define _CRT_SECURE_NO_WARNINGS 1
/*
* contact.c
* ͨѶ¼����ʵ��
* */

#include "contact.h"


//��ʼ��ͨѶ¼ - ��̬�汾
//void InitContact(struct Contact* pc) {
//	memset(pc->data, 0, 100 * sizeof(struct PeoInfo));
//	pc->sz = 0;
//}

//��ʼ��ͨѶ¼ - ��̬�汾
void InitContact(struct Contact* pc) {
	pc->sz = 0;
	pc->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (pc->data == NULL) {
		printf("%s\n", strerror(errno));
	}
	pc->capacity = 3;//Ĭ�ϴ�СΪ3
	//����ͨѶ¼
	LoadContact(pc);
}


//������ϵ�� - ��̬�汾
//void AddContact(struct Contact* pc) {
//	//����
//	if (pc->sz == MAX) {
//		printf("��ϵ���������޷�����\n");
//		return;
//	}
//	//δ��
//	printf("��������:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("�����Ա�:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("��������:>");
//	scanf("%d", &pc->data[pc->sz].age);
//	printf("����绰:>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�����ַ:>");
//	scanf("%s", pc->data[pc->sz].addr);
//	printf("���ӳɹ�\n");
//	//����+1
//	pc->sz++;
//}

//������ϵ�� - ��̬�汾
void AddContact(struct Contact* pc) {
	//����
	CheckCapacity(pc);
	//¼��Ԫ��
	printf("��������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�����Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("��������:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("����绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�����ַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("���ӳɹ�\n");
	//����+1
	pc->sz++;
}

//��ʾ��ϵ���б�
void ShowConstact(struct Contact* pc) {
	if (pc->sz == 0) {
		printf("�޿���ʾ����ϵ��\n");
		return;
	}
	printf("%15s%5s%5s%20s%30s\n",
		"name", "age", "sex", "tele", "addr");
	for (int i = 0; i < pc->sz; i++) {
		printf("%15s%5d%5s%20s%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}


//�����ֲ�����ϵ��
int FindContactorByName(struct Contact* pc, const char name[]) {
	for (int i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}

	}
	return -1;
}

//ɾ����ϵ��
void DelContact(struct Contact* pc) {
	//�п�
	if (pc->sz == 0) {
		printf("�޿�ɾ������ϵ��\n");
		return;
	}
	//����
	char name[20];
	printf("����������:>");
	scanf("%s", name);
	//����
	int ret = FindContactorByName(pc, name);
	if (ret == -1) {
		printf("δ�ҵ�����ϵ��\n");
		return;
	}
	for (int i = 0; i < pc->sz - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	printf("ɾ���ɹ�\n");
	//����-1
	pc->sz--;
}


//������ϵ��
void SearchContact(struct Contact* pc) {
	char name[20];
	printf("����������:>");
	scanf("%s", name);
	//��������
	int ret = FindContactorByName(pc, name);
	if (ret == -1) {
		printf("δ�ҵ�����ϵ��\n");
		return;
	}
	//��ӡ
	printf("%15s%5s%5s%20s%30s\n",
		"name", "age", "sex", "tele", "addr");
	printf("%15s%5d%5s%20s%30s\n",
		pc->data[ret].name,
		pc->data[ret].age,
		pc->data[ret].sex,
		pc->data[ret].tele,
		pc->data[ret].addr);
}


//�޸���ϵ��
void ModifyContact(struct Contact* pc) {
	char name[20];
	printf("����������:>");
	scanf("%s", name);
	//��������
	int ret = FindContactorByName(pc, name);
	if (ret == -1) {
		printf("δ�ҵ�����ϵ��\n");
		return;
	}
	//�޸�
	printf("��������:>");
	scanf("%s", pc->data[ret].name);
	printf("�����Ա�:>");
	scanf("%s", pc->data[ret].sex);
	printf("��������:>");
	scanf("%d", &pc->data[ret].age);
	printf("����绰:>");
	scanf("%s", pc->data[ret].tele);
	printf("�����ַ:>");
	scanf("%s", pc->data[ret].addr);
	printf("�޸ĳɹ�\n");
}


//�����ֱȽ���ϵ��
int CmpContactorByName(const void* Peo1, const void* Peo2) {
	return strcmp((char*)Peo1, (char*)Peo2);
}

//������ϵ��
void SortContact(struct Contact* pc) {
	for (int i = 0; i < pc->sz - 1; i++) {
		for (int j = 0; j < pc->sz - i - 1; j++) {
			qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpContactorByName);
		}
	}
	printf("����ɹ�\n");
	ShowConstact(pc);
}


//����ͨѶ¼
void DestroyContact(struct Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}


//����ͨѶ¼
void SaveContact(struct Contact* pc) {
	FILE* pf = fopen("Contact.txt", "wb");
	if (pf == NULL) {
		perror("SaveContact::fopen");
		return;
	}
	for (int i = 0; i < pc->sz; i++) {
		fwrite(&pc->data[i], sizeof(struct PeoInfo), 1, pf);
	}
	//fwrite(pc->data, sizeof(struct PeoInfo), pc->sz, pf);
	fclose(pf);
	pf = NULL;
	printf("����ɹ�\n");
}


//����ͨѶ¼
void LoadContact(struct Contact* pc) {
	
	FILE* pf = fopen("Contact.txt", "rb");
	if (pf == NULL) {
		perror("LoadContact::fopen");
		return;
	}
	//����fread����ֵ���ص㣬����ѭ����������
	//struct PeoInfo tmp = { 0 };
	while (fread(&pc->data[pc->sz], sizeof(struct PeoInfo), 1, pf)) {
		pc->sz++;
		CheckCapacity(pc);
		//pc->data[pc->sz] = tmp;
	}
	printf("���سɹ�\n");
	fclose(pf);
	pf = NULL;
}

//����������
void CheckCapacity(struct Contact* pc) {
	if (pc->sz == pc->capacity) {
		//����
		struct PeoInfo* ptr = (struct PeoInfo*)
			realloc(pc->data, (pc->capacity += 2) * sizeof(struct PeoInfo));
		if (ptr != NULL) {
			pc->data = ptr;
			//pc->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else {
			printf("����ʧ��\n");
			//�����쳣����
			exit(1);
		}
	}
}