//类功能：1、打开CSV文件并读取相关网页信息	2、提取网页内容

#pragma once
#ifndef CP_EXTRACTWEBRI_H
#define CP_EXTRACTWEBRI_H
#define _AFXDLL

#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector>
#include<afxinet.h>
#include<stdio.h>
using namespace std;

#include"CP_MyString.h"

class extractWebRI
{
public:
	extractWebRI(int num);
	~extractWebRI();

	void ReadWebsite(vector<myString> &str_vec);//提取网页源码

public:
	vector<myString> Website;//存储一百个网页地址

private:
	void GetWebsite();//读取CSV文件中num个网址
	char* FileName;//打开文件的文件名
	int number;

};

#endif // !CP_EXTRACTWEBRI_H
