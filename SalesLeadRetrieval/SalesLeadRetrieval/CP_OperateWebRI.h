//������ҳ��Ϣ����ȡ

#pragma once
#ifndef CP_OPERATEWEBRI_H
#define CP_OPERATEWEBRI_H

#include<iostream>
#include"CP_ExtractWebRI.h"
#include"CP_MyStack.h"
#include"CP_MyString.h"
#include"CP_MyStringList.h"
#include"CP_MyDictionary.h"
using namespace std;

class operateWebRI
{
public:
	operateWebRI(int num);//numΪ��ҳ����
	~operateWebRI() {}

	//��ָ����ҳ���ݽ��з�����ȡ���ؼ�����
	void webRIAnalysis(int num);

	//�����ҳ��ȡ����
	void printWebRI();

	//�������ķִ�
	void webRISegment(int num);

private:
	extractWebRI webRI;
	myDictionary dictionary;
	int number;//��ַ����
	vector<myString> webRI_vector;//һ�ٸ���ҳ��Ϣ���ַ�������
	myStringList *analysis_list;//�洢һ�ٸ���ҳ��ȡ�ؼ��ʺ�Ľ�����ֱ�Ϊ100������
	myStringList *segment_list;//�洢�ִ�֮��Ľ��

};


#endif // !CP_OPERATEWEBRI_H
