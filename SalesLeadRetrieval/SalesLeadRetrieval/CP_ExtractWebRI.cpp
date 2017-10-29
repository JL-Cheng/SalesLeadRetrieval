#include"CP_ExtractWebRI.h"

extractWebRI::extractWebRI():
	FileName("url.csv")
{
}

extractWebRI::~extractWebRI()
{
}

void extractWebRI::GetWebsite()
{
	ifstream file(FileName);
	string temp_line;
}