#include"CP_OperateWebRI.h"
#include<iostream>
using namespace std;

int main(int argc, char *args[])
{
	operateWebRI *OWR=new operateWebRI(100);
	OWR->printWebRI();
	delete OWR;

	system("pause");
	return 0;
}