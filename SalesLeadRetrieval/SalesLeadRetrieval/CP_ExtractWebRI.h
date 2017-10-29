//类功能：1、打开CSV文件并读取相关网页信息	2、提取网页信息中重要内容

#pragma once
#ifndef CP_EXTRACTWEBRI_H
#define CP_EXTRACTWEBRI_H

#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector>
using namespace std;

class extractWebRI
{
public:
	extractWebRI();
	~extractWebRI();

	void GetWebsite();//读取CSV文件中100个网址

private:
	char* FileName;//打开文件的文件名
	vector<string> Website;//存储一百个网页地址

};

#endif // !CP_EXTRACTWEBRI_H
