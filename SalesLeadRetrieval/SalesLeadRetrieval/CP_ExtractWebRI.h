//�๦�ܣ�1����CSV�ļ�����ȡ�����ҳ��Ϣ	2����ȡ��ҳ��Ϣ����Ҫ����

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
	extractWebRI();
	~extractWebRI();

	void ReadWebsite();//��ȡ��ҳԴ��

private:
	void GetWebsite();//��ȡCSV�ļ���100����ַ
	char* FileName;//���ļ����ļ���
	vector<myString> Website;//�洢һ�ٸ���ҳ��ַ

};

#endif // !CP_EXTRACTWEBRI_H
