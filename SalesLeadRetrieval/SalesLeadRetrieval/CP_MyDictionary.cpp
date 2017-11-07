#include"CP_MyDictionary.h"

myDictionary::myDictionary()
{
	myString tempString;
	string s;

	//录入词库的词和专业用语
	ifstream infile1("lexicon.dic");//打开词库
	if (!infile1.is_open())exit(-1);//打开文件失败，返回
	while (getline(infile1, s))
	{
		tempString = s;
		HashDictionary.insert(pair(tempString, 1));
	}

	ifstream infile2("terminology.txt");//打开专业用语
	if (!infile2.is_open())exit(-1);//打开文件失败，返回
	while (getline(infile2, s))
	{
		tempString = s;
		HashDictionary.insert(pair(tempString, 1));
	}
}

int myDictionary::FindWord(myString str)
{
	if (HashDictionary.find(str) != HashDictionary.end())
		return 1;
	else
		return 0;
}