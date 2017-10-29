#include"CP_OperateString.h"
#include<iostream>
using namespace std;
#include<string>
#include<vector>


int main(int argc, char *args[])
{
	string s, t;
	operateString str;
	vector<string> temp_v;
	cin >> s;
	str.SplitString(s, temp_v, ",");
	for (int i = 0; i < temp_v.size(); i++)
	{
		cout << temp_v[i] << endl;
	}
	system("pause");
	return 0;
}