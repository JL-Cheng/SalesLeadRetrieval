#include"CP_MyString.h"

myString::myString():
	length(0),
	m_str("")
{
}

myString::myString(string str):
	m_str(str)
{
	length = str.length();
}

void myString::GetNext(myString T, int* next)
{
	int j = 0, k = 0;
	int length = T.length;
	next[0] = -1;

	while (j < length)
	{
		if (k == 0 || T.m_str[j] == T.m_str[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else k = next[k];
	}
}

int myString::IndexOf(myString T,int pos)
{
	int i = pos;
	int j = 0;
	int length2 = T.length;
	int *next = new int[length2];
	GetNext(T, next);

	while (i < length&&j < length2)
	{
		if (j == -1 || m_str[i] == T.m_str[j])
		{
			++i;
			++j;
		}
		else j = next[j];
	}

	if (j >= length2) return i - length2;
	else return -1;
}

void myString::Substring(myString str, int pos, int len)
{
	char *temp_s = new char[len + 1];
	stringstream ss;
	for (int i = 0, j = pos; i < len; i++, j++)
	{
		temp_s[i] = str.m_str[j];
	}
	temp_s[len] = '\0';
	ss << temp_s;
	ss >> m_str;
	length = len;
	delete[]temp_s;
}

void myString::SplitString(myString s, vector<myString>& v, myString c)
{
	string::size_type pos1, pos2;
	pos2 = s.IndexOf(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		myString temp_str;
		temp_str.Substring(s, pos1, pos2 - pos1);
		v.push_back(temp_str);

		pos1 = pos2 + c.length;
		pos2 = s.IndexOf(c, pos1);
	}
	if (pos1 != s.length)
	{
		myString temp_str;
		temp_str.Substring(s, pos1, s.length - pos1);
		v.push_back(temp_str);
	}
}

myString& myString::operator=(const string &str)
{
	m_str = str;
	length = str.length();
	return *this;
}

myString& myString::operator=(const myString &myStr)
{
	m_str = myStr.m_str;
	length = myStr.length;
	return *this;
}

myString& myString::operator+(const char &ch)
{
	m_str += ch;
	length++;
	return *this;
}
