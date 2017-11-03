#include"CP_ExtractWebRI.h"

extractWebRI::extractWebRI():
	FileName("url.csv")
{
	GetWebsite();

	ReadWebsite();
	
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
			webSite_str = webSite_str + temp_str_vector[1].m_str[i];
		}
		Website.push_back(webSite_str);
	}

}

//��ȡ��վ����
void extractWebRI::ReadWebsite()
{
	CInternetSession session("HttpClient");
	//for (int i = 0; i < Website.size(); i++)
	//{
	int i = 2;
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
			//content.TrimRight();
			string str = content.GetBuffer(0);

			ofstream file("web_data.txt");//����ҳԴ��������ı��ļ���
			file << str;
			file.close();
		}
		pfile->Close();
		delete pfile;
		
	//}

	session.Close();
}