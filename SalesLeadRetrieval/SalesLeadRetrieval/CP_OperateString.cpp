#include"CP_OperateString.h"

void operateString::GetNext(string T, int* next)
{
	int j = 0, k = 0;
	int length = T.length();
	next[0] = -1;

	while (j < length)
	{
		if (k == 0 || T[j] == T[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else k = next[k];
	}
}

int operateString::Index(string S, string T,int pos)
{
	int i = pos;
	int j = 0;
	int length1 = S.length();
	int length2 = T.length();
	int *next = new int[length2];
	GetNext(T, next);

	while (i < length1&&j < length2)
	{
		if (j == -1 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else j = next[j];
	}

	if (j >= length2) return i - length2;
	else return -1;
}

string operateString::Substr(string str, int pos, int length)
{
	char *temp_s = new char[length + 1];
	string m_str;
	stringstream ss;
	for (int i = 0, j = pos; i < length; i++, j++)
	{
		temp_s[i] = str[j];
	}
	temp_s[length] = '\0';
	ss << temp_s;
	ss >> m_str;
	delete[]temp_s;
	return m_str;

}

void operateString::SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = Index(s, c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(Substr(s, pos1, pos2 - pos1));

		pos1 = pos2 + c.length();
		pos2 = Index(s, c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(Substr(s,pos1,s.length()-pos1));
}