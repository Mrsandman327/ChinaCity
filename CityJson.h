/************************************************************************************************/
//  文件：CityJson.h
//  描述：国家-省份-城市-县区四级数据json数据
//  时间：2019.09.10
//  作者：
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
			void GetCityFormProvince(std::vector<std::string> &City,std::string Province="广东省");
			void GetCountyFormCity(std::vector<std::string> &County,std::string City="深圳市",std::string Province="广东省");

			int GetProvinceIndex(std::string Province);
			int GetCityIndex(std::string City,std::string Province);
			int GetCountyIndex(std::string County,std::string City,std::string Province);
		private:
			void Initjson();
			void UnInitjson();
		private:
			neb::CJsonObject oJsonCity;	
			std::string readFileIntoString(char * filename)//从文件读入到string里
			{
				std::ifstream ifile(filename);
				//将文件读入到ostringstream对象buf中
				std::ostringstream buf;
				char ch;
				while(buf&&ifile.get(ch))
					buf.put(ch);
				//返回与流对象buf关联的字符串
				return buf.str();
			}
	};
}