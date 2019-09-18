/************************************************************************************************/
//  �ļ���CityJson.h
//  ����������-ʡ��-����-�����ļ�����json����
//  ʱ�䣺2019.09.10
//  ���ߣ�
/************************************************************************************************/
#include <fstream>
#include <sstream>

#pragma once

namespace CityJson{

	class ChinaCity
	{
		public:
			ChinaCity(void);
			~ChinaCity(void);
	
		public:
			void GetProvinceFormCountry(std::vector<std::string> &province);
			void GetCityFormProvince(std::vector<std::string> &City,std::string Province="�㶫ʡ");
			void GetCountyFormCity(std::vector<std::string> &County,std::string City="������",std::string Province="�㶫ʡ");

			int GetProvinceIndex(std::string Province);
			int GetCityIndex(std::string City,std::string Province);
			int GetCountyIndex(std::string County,std::string City,std::string Province);
		private:
			void Initjson();
			void UnInitjson();
		private:
			neb::CJsonObject oJsonCity;	
			std::string readFileIntoString(char * filename)//���ļ����뵽string��
			{
				std::ifstream ifile(filename);
				//���ļ����뵽ostringstream����buf��
				std::ostringstream buf;
				char ch;
				while(buf&&ifile.get(ch))
					buf.put(ch);
				//������������buf�������ַ���
				return buf.str();
			}
	};
}