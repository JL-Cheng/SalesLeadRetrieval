//实现对字符串的各种处理

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


	//从pos开始搜索，返回子串T在主串S中的位置，0<=pos<=StrLength(S)；若不存在，则返回-1
	void GetNext(string T, int* next);
	int Index(string S, string T, int pos = 0);

	//进行字符串分割
	void SplitString(const string& s, vector<string>& v, const string& c);

	//字符串拷贝,返回一段字符串。
	string Substr(string str, int pos, int length);

};

#endif // !CP_OPERATESTRING_H
