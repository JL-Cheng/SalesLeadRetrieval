//*索引类，通过使用二叉平衡树、文档链表和已有数据库构建索引词典

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

	//对输入的关键词组进行查询
	void Search(myString word_str);

private:
	//创建索引
	void createIndex();
	//查询该词位置
	void searchWord(myString word, int *record);

	myAVL *IndexTree;//索引字典树
	operateWebRI *OWR;//获取网页内容与分词结果
	int number;//用number个网页的数据内容建立索引
};

#endif // !CP_MYINDEX_H

