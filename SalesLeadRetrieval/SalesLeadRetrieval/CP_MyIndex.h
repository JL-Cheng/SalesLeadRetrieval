//*�����࣬ͨ��ʹ�ö���ƽ�������ĵ�������������ݿ⹹�������ʵ�

#pragma once
#ifndef CP_MYINDEX_H
#define CP_MYINDEX_H

#include"CP_MyAVL.h"
#include"CP_OperateWebRI.h"

class myIndex
{
public:
	myIndex(int num);
	~myIndex();

	//������Ĺؼ�������в�ѯ
	void Search(myString word_str);

private:
	//��������
	void createIndex();
	//��ѯ�ô�λ��
	void searchWord(myString word, int *record);

	myAVL *IndexTree;//�����ֵ���
	operateWebRI *OWR;//��ȡ��ҳ������ִʽ��
	int number;//��number����ҳ���������ݽ�������
};

#endif // !CP_MYINDEX_H

