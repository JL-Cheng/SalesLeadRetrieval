//�๦�ܣ�1����CSV�ļ�����ȡ�����ҳ��Ϣ	2����ȡ��ҳ��Ϣ����Ҫ����

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

	void GetWebsite();//��ȡCSV�ļ���100����ַ

private:
	char* FileName;//���ļ����ļ���
	vector<string> Website;//�洢һ�ٸ���ҳ��ַ

};

#endif // !CP_EXTRACTWEBRI_H
