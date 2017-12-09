#include"CP_MyIndex.h"
#include<iostream>
using namespace std;

int main(int argc, char *args[])
{
	myString m_str;
	string str;
	myIndex *index=new myIndex(1000);
	for (int i = 0; i < 10; i++)
	{
		cin >> str;
		m_str = str;
		index->Search(str);
	}
	delete index;

	system("pause");
	return 0;
}