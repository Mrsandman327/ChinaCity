
# ChinaCity
中国省市区三级数据

本仓库提供的是一种使用Json保存中国省市区三级数据，通过读取文件的方式读取字符串，然后再解析json。

代码中提供了六个public方法
	

代码很少，使用非常简单，

	//获取省份列表
	void GetProvinceFormCountry(std::vector<std::string> &province);            
	//根据省份信息获取城市列表
	void GetCityFormProvince(std::vector<std::string> &City,std::string Province="广东省");			
	//根据省份和城市信息获取县区列表
	void GetCountyFormCity(std::vector<std::string> &County,std::string City="深圳市",std::string Province="广东省");   
	//获取省份索引
	int GetProvinceIndex(std::string Province);		
	//获取城市索引
	int GetCityIndex(std::string City,std::string Province);		
	//获取县区索引
	int GetCountyIndex(std::string County,std::string City,std::string Province);	
demo：

    CityJson::ChinaCity m_chinaCity;
    //获取省份列表
    std::vector<std::string > province;
    m_chinaCity.GetProvinceFormCountry(province);


    //根据省份信息获取城市列表
    std::vector<std::string > city;
    m_chinaCity.GetCityFormProvince(city,province[n]);
    
    //根据省份和城市信息获取县区列表
    std::vector<std::string > county;
    m_chinaCity.GetCountyFormCity(county,city[m,province[n]);

    province.clear();
    city.clear();
    county.clear();
    
    
    文中用到了C++JSON库CJsonObject，该项目地址：https://github.com/Bwar/CJsonObject
