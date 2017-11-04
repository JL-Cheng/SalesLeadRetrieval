#include"CP_OperateWebRI.h"

operateWebRI::operateWebRI(int num)
{
	final_list = new myStringList[num];
	number = num;
	webRI.ReadWebsite(webRI_vector);

	for (int i = 0; i < num; i++)
	{
		webRIAnalysis(i);
	}
}

void operateWebRI::webRIAnalysis(int num)
{
	myStack *stack = new myStack(1000);
	final_list[num].addNode(webRI.Website[num]);//先加入网址
	int i = 0;
	while (i < webRI_vector[num].length - 1)
	{
		if (webRI_vector[num].m_str[i] == '<')//是一个标签
		{
			stack->Push(webRI_vector[num], i);//将标签压入栈
			stackData tempData;
			myString tempLabel;
			tempData = stack->Top();//获取栈顶标签

			tempLabel = "<div class=\"z\">";
			if (tempData.label.IndexOf(tempLabel)!=-1)//有发帖大类、发帖小类和标题
			{
				int temp_num = 0;//获取的信息数
				while (true)
				{
					if (webRI_vector[num].m_str[i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						tempData = stack->Top();
						if (tempData.No == 2)//<a开头标签
							temp_num++;
						if (temp_num >= 3 && tempData.No == 2)
						{
							myString str;//存储信息
							int j = i;
							while (webRI_vector[num].m_str[j] != '<')
							{
								str = str + webRI_vector[num].m_str[j];
								j++;
							}
							i = j;
							i--;
							final_list[num].addNode(str);
						}
						if (temp_num == 5) break;//得到三条有用信息后退出
					}

					i++;
				}
			}

			continue;

		}
		else
		{
			i++;
			continue;
		}
	}
	cout << num;
}

void operateWebRI::printWebRI()
{
	ofstream ofile;
	ofile.open("result.csv", ios::out | ios::trunc);
	ofile << "序号,网址,发帖大类,发帖小类,发帖标题" << endl;
	for (int i = 0; i < number; i++)
	{
		ofile << i << ",";//输出序号
		myStringNode *temp_node = final_list[i].head->next;
		while (temp_node != NULL)
		{
			ofile << temp_node->data.m_str << ",";
			temp_node = temp_node->next;
		}
		ofile << endl;
	}
	ofile.close();
}

