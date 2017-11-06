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
	final_list[num].addNode(webRI.Website[num]);//�ȼ�����ַ
	int i = 0;
	bool AddContent = NULL;//��Ϊ��ֻ��һ�����ݣ�����ֻ�����������
	bool AddAuthor = NULL;//ֻ�������
	bool AddDate = NULL;//�������
	while (i < webRI_vector[num].length - 1)
	{
		if (webRI_vector[num].m_str[i] == '<')//��һ����ǩ
		{
			stack->Push(webRI_vector[num], i);//����ǩѹ��ջ
			stackData tempData;
			myString tempLabel;
			tempData = stack->Top();//��ȡջ����ǩ

			tempLabel = "<div class=\"z\">";//�з������ࡢ����С��ͱ���
			if (tempData.label.IndexOf(tempLabel)!=-1)
			{
				int temp_num = 0;//��ȡ����Ϣ��
				while (true)
				{
					if (webRI_vector[num].m_str[i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						tempData = stack->Top();
						if (tempData.No == 2)//<a��ͷ��ǩ
							temp_num++;
						if (temp_num >= 3 && tempData.No == 2)
						{
							myString str;//�洢��Ϣ
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
						}//�õ�����������Ϣ���˳�
					}

					i++;
				}
			}

			tempLabel = "<td class=\"t_f\"";//�з���������δ���
			if (tempData.label.IndexOf(tempLabel) != -1&&!AddContent)
			{
				AddContent = true;
				int temp_num = 0;
				myString str;//�洢��Ϣ
				myString unicodeStr = "";//��¼unicode�ı���
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
						else if (unicodeStr.length != 0)//��������ֻ���ĸ
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
					else if(webRI_vector[num].m_str[i] == '&')//��ʼunicode����
					{
						i++;
						while (true)
						{
							if (webRI_vector[num].m_str[i] != ';')
							{
								unicodeStr = unicodeStr + webRI_vector[num].m_str[i];
								i++;
							}
							else if (webRI_vector[num].m_str[i] == ';')//unicode�����
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
								unicodeStr = "";//��ԭ
								i++;
								break;
							}
						}
						continue;
					}
					else//�������ַ�
					{
						str = str + webRI_vector[num].m_str[i];
						i++;
						continue;
					}
				}
			}

			tempLabel = "<div class=\"authi\">";//������
			if (tempData.label.IndexOf(tempLabel) != -1 && !AddAuthor)
			{
				AddAuthor = true;
				while (true)
				{
					if (webRI_vector[num].m_str[i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						continue;
					}
					else
					{
						myString str;//�洢��Ϣ
						int j = i;
						while (webRI_vector[num].m_str[j] != '<')
						{
							str = str + webRI_vector[num].m_str[j];
							j++;
						}
						i = j;
						final_list[num].addNode(str);
						stack->Push(webRI_vector[num], i);
						break;
					}
				}
			}

			tempLabel = "<em id"; //������
			if (tempData.label.IndexOf(tempLabel) != -1 && !AddDate)
			{
				while (true)
				{
					if (webRI_vector[num].m_str[i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						break;
					}
					else if(!AddDate&&webRI_vector[num].m_str[i]>='0'&& webRI_vector[num].m_str[i]<='9')
					{
						myString str;//�洢��Ϣ
						int j = i;
						while (webRI_vector[num].m_str[j] != ' ')
						{
							str = str + webRI_vector[num].m_str[j];
							j++;
						}
						i = j;
						final_list[num].addNode(str);
						AddDate = true;
					}
					else
					{
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
	ofile << "���,��ַ,��������,����С��,��������,������,��������" << endl;
	for (int i = 0; i < number; i++)
	{
		ofile << i << ",";//������
		cout << i;
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

