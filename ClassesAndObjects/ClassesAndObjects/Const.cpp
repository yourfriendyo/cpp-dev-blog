#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream> 
#include "Date.h"
using namespace std;
int main()
{
	Date d1;
	d1.Print();
	
	const Date d2;
	d2.Print();


	

	return 0;
}