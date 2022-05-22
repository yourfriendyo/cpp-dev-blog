#pragma once
/*
* contact.h
* 声明通讯录函数和类型
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

//枚举选项内容
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
//定义人的信息结构体
struct PeoInfo {
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};

//通讯录 - 静态版本
//struct Contact {
//	//信息数组
//	struct PeoInfo data[MAX];
//	//人数
//	int sz;
//};

//通讯录 - 动态版本


struct Contact {
	struct PeoInfo* data;
	//有效元个数
	int sz;
	//总容量
	int capacity;
};


//初始化通讯录函数声明
void InitContact(struct Contact* pc);

//增加联系人函数声明
void AddContact(struct Contact* pc);

//显示联系人列表函数声明 
void ShowConstact(struct Contact* pc);

//删除联系人函数声明
void DelContact(struct Contact* pc);

//查找联系人函数声明
void SearchContact(struct Contact* pc);

//修改联系人函数声明
void ModifyContact(struct Contact* pc);

//排序联系人函数声明
void SortContact(struct Contact* pc);

//销毁通讯录函数声明
void DestroyContact(struct Contact* pc);

//保存通讯录函数声明
void SaveContact(struct Contact* pc);

//加载通讯录函数声明
void LoadContact(struct Contact* pc);

//检测最大容量函数声明
void CheckCapacity(struct Contact* pc);