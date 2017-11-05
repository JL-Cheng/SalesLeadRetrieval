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
	bool AddContent = NULL;//因为不只有一份内容，所以只添加主贴内容
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
						if (temp_num == 5)
						{
							stack->Push(webRI_vector[num], i);
							break;
						}//得到三条有用信息后退出
					}

					i++;
				}
			}

			tempLabel = "<td class=\"t_f\"";
			if (tempData.label.IndexOf(tempLabel) != -1&&!AddContent)//有发帖内容且未添加
			{
				AddContent = true;
				int temp_num = 0;
				myString str;//存储信息
				myString unicodeStr = "";//记录unicode的编码
				while (true)
				{
					if (webRI_vector[num].m_str[i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						if (temp_num == 0)
						{
							temp_num = 1;
							continue;
						}
						else if (unicodeStr.length != 0)//最后有数字或字母
						{
							for (int temp_l = 0; temp_l < unicodeStr.length; temp_l++)
							{
								str = str + unicodeStr.m_str[temp_l];
							}
						}
						final_list[num].addNode(str);
						break;
					}
					else if (webRI_vector[num].m_str[i] == '\n' || webRI_vector[num].m_str[i] == '\r' || webRI_vector[num].m_str[i] == ' ')
					{
						i++;
						continue;
					}
					else if(webRI_vector[num].m_str[i] == '&')//开始unicode编码
					{
						i++;
						while (true)
						{
							if (webRI_vector[num].m_str[i] != ';')
							{
								unicodeStr = unicodeStr + webRI_vector[num].m_str[i];
								i++;
							}
							else if (webRI_vector[num].m_str[i] == ';')//unicode码结束
							{
								unsigned short number = 0;
								char czChinese[3];
								wchar_t wcChinese[2];
								myString spaceStr = "nbsp";
								if (unicodeStr.m_str[0] == '#')
								{
									for (int k = 1; k < unicodeStr.length; k++)
									{
										number = number * 10 + unicodeStr.m_str[k] - '0';
									}
									wcChinese[0] = number;
									wcChinese[1] = 0;
									WideCharToMultiByte(CP_ACP, 0, wcChinese, -1, czChinese, sizeof(czChinese), NULL, NULL);
									str = str + czChinese[0];
									str = str + czChinese[1];
								}
								else if(unicodeStr.IndexOf(spaceStr)!=-1)
								{
									str = str + ' ';
								}
								unicodeStr = "";//还原
								i++;
								break;
							}
						}
						continue;
					}
					else//是其他字符
					{
						str = str + webRI_vector[num].m_str[i];
						i++;
						continue;
					}
				}
			}

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
	ofile << "序号,网址,发帖大类,发帖小类,发帖标题,发帖内容" << endl;
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

