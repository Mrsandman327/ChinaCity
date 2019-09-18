#include "StdAfx.h"
#include "CityJson.h"

using namespace CityJson;


ChinaCity::ChinaCity(void)
{
	Initjson();
}


ChinaCity::~ChinaCity(void)
{
	UnInitjson();
}


void ChinaCity::Initjson()
{
	CString m_strUserPath = AfxGetApp()->m_pszHelpFilePath;
	m_strUserPath = m_strUserPath.Left(m_strUserPath.ReverseFind('\\')+1) + _T("Monitor\\");
	CString strfile = m_strUserPath + _T("chinacity.json");

	std::string filestr=readFileIntoString(strfile.GetBuffer(0));
	CString cfilestr=UTF8_to_ANSI(filestr.c_str());

	if(!oJsonCity.IsEmpty())oJsonCity.Clear();
	oJsonCity.Parse(cfilestr.GetBuffer(0));

	strfile.ReleaseBuffer();
	cfilestr.ReleaseBuffer();
}


void ChinaCity::UnInitjson()
{
	if(!oJsonCity.IsEmpty())oJsonCity.Clear();
}


void ChinaCity::GetProvinceFormCountry(std::vector<std::string> &province)
{
	std::string strkey;
	while(oJsonCity.GetKey(strkey))
	{
		province.push_back(strkey);
	}
}


void ChinaCity::GetCityFormProvince(std::vector<std::string> &City,std::string Province)
{
	std::string strkey;
	while(oJsonCity[Province].GetKey(strkey))
	{
		City.push_back(strkey);
	}
}


void ChinaCity::GetCountyFormCity(std::vector<std::string> &County,std::string City,std::string Province)
{
	std::string strkey;
	int arrysize=oJsonCity[Province][City].GetArraySize();
	for (int i=0;i<arrysize;i++)
	{
		oJsonCity[Province][City].Get(i,strkey);
		County.push_back(strkey);
	}
}


int ChinaCity::GetProvinceIndex(std::string Province)
{
	int index=0;
	std::string strkey;
	while(oJsonCity.GetKey(strkey))
	{
		if (strkey.find(Province)!=std::string::npos)
		{
			//使用while循环是因为GetKey需要取完这个层次的所有key 里面的list才会重新置为第一个键,
			//打断需要调用ResetTraversing()重置遍历
			oJsonCity.ResetTraversing();
			break;
		}
		index++;
	}
	return index;
}


int ChinaCity::GetCityIndex(std::string City,std::string Province)
{
	int index=0;
	std::string strkey;
	while(oJsonCity[Province].GetKey(strkey))
	{
		if (strkey.find(City)!=std::string::npos)
		{
			oJsonCity.ResetTraversing();
			break;
		}
		index++;
	}
	return index;
}


int ChinaCity::GetCountyIndex(std::string County,std::string City,std::string Province)
{
	int index=0;
	std::string strkey;
	int arrysize=oJsonCity[Province][City].GetArraySize();
	for (int i=0;i<arrysize;i++)
	{
		oJsonCity[Province][City].Get(i,strkey);
		if (strkey.find(County)!=std::string::npos)
		{
			break;
		}
		index++;
	}
	return index;
}