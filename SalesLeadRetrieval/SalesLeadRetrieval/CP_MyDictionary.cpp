#include"CP_MyDictionary.h"

myDictionary::myDictionary()
{
	myString tempString;
	string s;

	//¼��ʿ�Ĵʺ�רҵ����
	ifstream infile1("lexicon.dic");//�򿪴ʿ�
	if (!infile1.is_open())exit(-1);//���ļ�ʧ�ܣ�����
	while (getline(infile1, s))
	{
		tempString = s;
		HashDictionary.insert(pair(tempString, 1));
	}

	ifstream infile2("terminology.txt");//��רҵ����
	if (!infile2.is_open())exit(-1);//���ļ�ʧ�ܣ�����
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