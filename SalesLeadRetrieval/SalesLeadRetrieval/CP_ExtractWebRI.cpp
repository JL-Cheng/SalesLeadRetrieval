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
			webSite_str = webSite_str + temp_str_vector[1][i];
		}
		Website.push_back(webSite_str);
	}

}

//读取网站内容
void extractWebRI::ReadWebsite(vector<myString> &str_vec)
{
	CInternetSession session("HttpClient");
	cout << "正在提取网址..." << endl;
	for (int i = 0; i < number; i++)
	{
		cout << i;
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
			string str = content.GetBuffer(0);

			//将网页源码输入到向量中
			myString mStr(str);
			str_vec.push_back(mStr);
		}
		pfile->Close();
		delete pfile;	
	}

	session.Close();
}