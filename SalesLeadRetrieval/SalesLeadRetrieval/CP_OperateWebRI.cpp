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
	while (i < webRI_vector[num].length - 1)
	{
		if (webRI_vector[num].m_str[i] == '<')//��һ����ǩ
		{
			stack->Push(webRI_vector[num], i);//����ǩѹ��ջ
			stackData tempData;
			myString tempLabel;
			tempData = stack->Top();//��ȡջ����ǩ

			tempLabel = "<div class=\"z\">";
			if (tempData.label.IndexOf(tempLabel)!=-1)//�з������ࡢ����С��ͱ���
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
						if (temp_num == 5) break;//�õ�����������Ϣ���˳�
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
	ofile << "���,��ַ,��������,����С��,��������" << endl;
	for (int i = 0; i < number; i++)
	{
		ofile << i << ",";//������
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

