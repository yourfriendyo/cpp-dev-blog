#define _CRT_SECURE_NO_WARNINGS 1
/*
* 通讯录实现
* 1. 容量：100人
*	信息：名字+性别+年龄+电话+住址
* 功能：
*	1. 增加联系人
*	2. 删除联系人
*	3. 修改联系人
*	4. 查找联系人
*	5. 排序联系人
*
* 扩展功能：
* 1. 使用动态内存
* 2. 存入文件
*		1. 退出时保存数据进文件
*		2. 运行时加载文件数据
* */

/*
* test.c 
* 测试各个功能
* */
#include "contact.h"

void menu() {
	printf("***********************************\n");
	printf("****** 1. Add    *** 2. Del   *****\n");
	printf("****** 3. Search *** 4.Modify *****\n");
	printf("****** 5. Show   *** 6.Sort   *****\n");
	printf("***********   0. Exit   ***********\n");
	printf("***********************************\n");
}

int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);	
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
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
			ShowConstact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			//保存通讯录
			SaveContact(&con);
			//销毁通讯录
			DestroyContact(&con);
			printf("退出成功，已销毁\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
