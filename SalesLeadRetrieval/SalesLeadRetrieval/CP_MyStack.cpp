#include"CP_MyStack.h"

myStack::myStack(int max_size):
	m_StackSize(max_size)
{
	Init();
}

void myStack::Init()
{
	m_Stack.base = new stackData[m_StackSize];
	m_Stack.stacksize = m_StackSize;
	if (!m_Stack.base) return;
	m_Stack.top = m_Stack.base;
	return;
}

void myStack::Push(myString S, int &start_i)
{
	if (m_Stack.top - m_Stack.base >= m_Stack.stacksize)return;
	myString tempString;
	myString tempLabel;
	stackData tempData;
	int j = start_i;
	while (true)
	{
		tempString = tempString + S.m_str[j];
		if (S.m_str[j] == '>') break;
		j++;
	}

	start_i = ++j;
	tempData.label = tempString;
	tempData.No = 0;

	tempLabel = "<div";//若是div标签
	if (tempString.IndexOf(tempLabel)!=-1)
	{
		tempData.No = 1;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "<a";//若是a标签
	if (tempString.IndexOf(tempLabel)!=-1)
	{
		tempData.No = 2;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "</";//若是结束标签
	if (tempString.IndexOf(tempLabel)!=-1)
	{
		Pop();
		return;
	}

	tempLabel = "/>";//若不是自结束且不是前边提到的标签
	if (tempString.IndexOf(tempLabel) == -1)
	{
		*m_Stack.top++ = tempData;
		return;
	}
}

void myStack::Pop()
{
	if (Empty())
		return;
	m_Stack.top--;
	return;
}

