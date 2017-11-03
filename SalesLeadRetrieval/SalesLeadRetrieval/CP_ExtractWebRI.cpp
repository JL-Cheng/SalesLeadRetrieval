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

//获取网址
void extractWebRI::GetWebsite()//将网址存入字符串向量中
{
	ifstream file(FileName);
	myString temp_str;
	string temp_line;
	vector<myString> temp_str_vector;
	myString separator_str(",");//分割字符串
	myString myLine_str;//读入的每一行字符串
	myString webSite_str;//每个网址的字符串

	getline(file, temp_line);//去除第一行
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

//读取网站内容
void extractWebRI::ReadWebsite()
{
	CInternetSession session("HttpClient");
	//for (int i = 0; i < Website.size(); i++)
	//{
	int i = 2;
		CHttpFile *pfile = (CHttpFile*)session.OpenURL(Website[i].m_str.data());
		DWORD dwStatusCode;//Http请求相关联的状态号
		pfile->QueryInfoStatusCode(dwStatusCode);
		if (dwStatusCode == HTTP_STATUS_OK)//成功连接
		{
			CString content;
			CString data;
			while (pfile->ReadString(data))//读取网页内容
			{
				content += data + "\r\n";
			}
			//content.TrimRight();
			string str = content.GetBuffer(0);

			ofstream file("web_data.txt");//将网页源码输出到文本文件中
			file << str;
			file.close();
		}
		pfile->Close();
		delete pfile;
		
	//}

	session.Close();
}