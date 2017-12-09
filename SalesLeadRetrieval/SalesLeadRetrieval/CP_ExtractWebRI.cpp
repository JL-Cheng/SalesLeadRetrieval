#include"CP_ExtractWebRI.h"

extractWebRI::extractWebRI(int num):
	FileName("input/url.csv"),
	number(num)
{
	GetWebsite();	
}

extractWebRI::~extractWebRI()
{
}

//��ȡ��ַ
void extractWebRI::GetWebsite()//����ַ�����ַ���������
{
	ifstream file(FileName);
	myString temp_str;
	string temp_line;
	vector<myString> temp_str_vector;
	myString separator_str(",");//�ָ��ַ���
	myString myLine_str;//�����ÿһ���ַ���
	myString webSite_str;//ÿ����ַ���ַ���

	getline(file, temp_line);//ȥ����һ��
	while (getline(file, temp_line))
	{
		temp_str_vector.clear();
		webSite_str = "";
		temp_str = temp_line;
		temp_str.SplitString(temp_str_vector, separator_str);
		for (int i = 1; i < temp_str_vector[1].length - 1; i++)
		{
			webSite_str = webSite_str + temp_str_vector[1][i];
		}
		Website.push_back(webSite_str);
	}

}

//��ȡ��վ����
void extractWebRI::ReadWebsite(vector<myString> &str_vec)
{
	CInternetSession session("HttpClient");
	cout << "������ȡ��ַ..." << endl;
	for (int i = 0; i < number; i++)
	{
		cout << i;
		CHttpFile *pfile = (CHttpFile*)session.OpenURL(Website[i].m_str.data());
		DWORD dwStatusCode;//Http�����������״̬��
		pfile->QueryInfoStatusCode(dwStatusCode);
		if (dwStatusCode == HTTP_STATUS_OK)//�ɹ�����
		{
			CString content;
			CString data;
			while (pfile->ReadString(data))//��ȡ��ҳ����
			{
				content += data + "\r\n";
			}
			string str = content.GetBuffer(0);

			//����ҳԴ�����뵽������
			myString mStr(str);
			str_vec.push_back(mStr);
		}
		pfile->Close();
		delete pfile;	
	}

	session.Close();
}