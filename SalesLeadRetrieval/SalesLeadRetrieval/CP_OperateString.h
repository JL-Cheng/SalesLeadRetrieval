//ʵ�ֶ��ַ����ĸ��ִ���

#pragma once
#ifndef CP_OPERATESTRING_H
#define CP_OPERATESTRING_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class operateString
{
public:
	operateString() {}
	~operateString() {}


	//��pos��ʼ�����������Ӵ�T������S�е�λ�ã�0<=pos<=StrLength(S)���������ڣ��򷵻�-1
	void GetNext(string T, int* next);
	int Index(string S, string T, int pos = 0);

	//�����ַ����ָ�
	void SplitString(const string& s, vector<string>& v, const string& c);

	//�ַ�������,����һ���ַ�����
	string Substr(string str, int pos, int length);

};

#endif // !CP_OPERATESTRING_H
