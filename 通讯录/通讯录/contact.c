#define _CRT_SECURE_NO_WARNINGS 1
/*
* contact.c
* 通讯录函数实现
* */

#include "contact.h"


//初始化通讯录 - 静态版本
//void InitContact(struct Contact* pc) {
//	memset(pc->data, 0, 100 * sizeof(struct PeoInfo));
//	pc->sz = 0;
//}

//初始化通讯录 - 动态版本
void InitContact(struct Contact* pc) {
	pc->sz = 0;
	pc->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (pc->data == NULL) {
		printf("%s\n", strerror(errno));
	}
	pc->capacity = 3;//默认大小为3
	//加载通讯录
	LoadContact(pc);
}


//增加联系人 - 静态版本
//void AddContact(struct Contact* pc) {
//	//已满
//	if (pc->sz == MAX) {
//		printf("联系人已满，无法创建\n");
//		return;
//	}
//	//未满
//	printf("输入名字:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("输入性别:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("输入年龄:>");
//	scanf("%d", &pc->data[pc->sz].age);
//	printf("输入电话:>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("输入地址:>");
//	scanf("%s", pc->data[pc->sz].addr);
//	printf("增加成功\n");
//	//个数+1
//	pc->sz++;
//}

//增加联系人 - 动态版本
void AddContact(struct Contact* pc) {
	//已满
	CheckCapacity(pc);
	//录入元素
	printf("输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("输入年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("增加成功\n");
	//个数+1
	pc->sz++;
}

//显示联系人列表
void ShowConstact(struct Contact* pc) {
	if (pc->sz == 0) {
		printf("无可显示的联系人\n");
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


//按名字查找联系人
int FindContactorByName(struct Contact* pc, const char name[]) {
	for (int i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}

	}
	return -1;
}

//删除联系人
void DelContact(struct Contact* pc) {
	//判空
	if (pc->sz == 0) {
		printf("无可删除的联系人\n");
		return;
	}
	//输入
	char name[20];
	printf("请输入名字:>");
	scanf("%s", name);
	//查找
	int ret = FindContactorByName(pc, name);
	if (ret == -1) {
		printf("未找到该联系人\n");
		return;
	}
	for (int i = 0; i < pc->sz - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	printf("删除成功\n");
	//个数-1
	pc->sz--;
}


//查找联系人
void SearchContact(struct Contact* pc) {
	char name[20];
	printf("请输入名字:>");
	scanf("%s", name);
	//按名查找
	int ret = FindContactorByName(pc, name);
	if (ret == -1) {
		printf("未找到该联系人\n");
		return;
	}
	//打印
	printf("%15s%5s%5s%20s%30s\n",
		"name", "age", "sex", "tele", "addr");
	printf("%15s%5d%5s%20s%30s\n",
		pc->data[ret].name,
		pc->data[ret].age,
		pc->data[ret].sex,
		pc->data[ret].tele,
		pc->data[ret].addr);
}


//修改联系人
void ModifyContact(struct Contact* pc) {
	char name[20];
	printf("请输入名字:>");
	scanf("%s", name);
	//按名查找
	int ret = FindContactorByName(pc, name);
	if (ret == -1) {
		printf("未找到该联系人\n");
		return;
	}
	//修改
	printf("输入名字:>");
	scanf("%s", pc->data[ret].name);
	printf("输入性别:>");
	scanf("%s", pc->data[ret].sex);
	printf("输入年龄:>");
	scanf("%d", &pc->data[ret].age);
	printf("输入电话:>");
	scanf("%s", pc->data[ret].tele);
	printf("输入地址:>");
	scanf("%s", pc->data[ret].addr);
	printf("修改成功\n");
}


//按名字比较联系人
int CmpContactorByName(const void* Peo1, const void* Peo2) {
	return strcmp((char*)Peo1, (char*)Peo2);
}

//排序联系人
void SortContact(struct Contact* pc) {
	for (int i = 0; i < pc->sz - 1; i++) {
		for (int j = 0; j < pc->sz - i - 1; j++) {
			qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpContactorByName);
		}
	}
	printf("排序成功\n");
	ShowConstact(pc);
}


//销毁通讯录
void DestroyContact(struct Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}


//保存通讯录
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
	printf("保存成功\n");
}


//加载通讯录
void LoadContact(struct Contact* pc) {
	
	FILE* pf = fopen("Contact.txt", "rb");
	if (pf == NULL) {
		perror("LoadContact::fopen");
		return;
	}
	//利用fread返回值的特点，可以循环读入数据
	//struct PeoInfo tmp = { 0 };
	while (fread(&pc->data[pc->sz], sizeof(struct PeoInfo), 1, pf)) {
		pc->sz++;
		CheckCapacity(pc);
		//pc->data[pc->sz] = tmp;
	}
	printf("加载成功\n");
	fclose(pf);
	pf = NULL;
}

//检测最大容量
void CheckCapacity(struct Contact* pc) {
	if (pc->sz == pc->capacity) {
		//增容
		struct PeoInfo* ptr = (struct PeoInfo*)
			realloc(pc->data, (pc->capacity += 2) * sizeof(struct PeoInfo));
		if (ptr != NULL) {
			pc->data = ptr;
			//pc->capacity += 2;
			printf("增容成功\n");
		}
		else {
			printf("增容失败\n");
			//程序异常结束
			exit(1);
		}
	}
}