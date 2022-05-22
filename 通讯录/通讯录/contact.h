#pragma once
/*
* contact.h
* ����ͨѶ¼����������
* */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define DEFAULT_SZ 3
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 20
#define ADDR_MAX 30
#define MAX 100

//ö��ѡ������
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
//�����˵���Ϣ�ṹ��
struct PeoInfo {
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};

//ͨѶ¼ - ��̬�汾
//struct Contact {
//	//��Ϣ����
//	struct PeoInfo data[MAX];
//	//����
//	int sz;
//};

//ͨѶ¼ - ��̬�汾


struct Contact {
	struct PeoInfo* data;
	//��ЧԪ����
	int sz;
	//������
	int capacity;
};


//��ʼ��ͨѶ¼��������
void InitContact(struct Contact* pc);

//������ϵ�˺�������
void AddContact(struct Contact* pc);

//��ʾ��ϵ���б������� 
void ShowConstact(struct Contact* pc);

//ɾ����ϵ�˺�������
void DelContact(struct Contact* pc);

//������ϵ�˺�������
void SearchContact(struct Contact* pc);

//�޸���ϵ�˺�������
void ModifyContact(struct Contact* pc);

//������ϵ�˺�������
void SortContact(struct Contact* pc);

//����ͨѶ¼��������
void DestroyContact(struct Contact* pc);

//����ͨѶ¼��������
void SaveContact(struct Contact* pc);

//����ͨѶ¼��������
void LoadContact(struct Contact* pc);

//������������������
void CheckCapacity(struct Contact* pc);