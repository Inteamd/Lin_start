#pragma once
#include<iostream>
class Data
{
private:
	int year;//年
	int month;//月
	int day;//日
public:
	Data();//默认构造函数
	Data(int, int, int);//输入数据进行构造
	Data operator+(int) const;//重载+
	Data operator-(int) const;//重载-
	friend Data operator+(int, const Data&);//重载+
	friend Data operator-(int, const Data&);//重载-
	Data& operator+=(int);//重载+=
	Data& operator-=(int);//重载-=
	friend std::ostream& operator<<(std::ostream&, const Data&);//重载<<
	friend std::istream& operator>>(std::istream&, Data&);//重载>>
	bool operator>(const Data&) const;//重载>
	bool operator<(const Data&) const;//重载<
	bool operator==(const Data&) const;//重载==
	bool operator!=(const Data&) const;//重载!=
	bool operator<=(const Data&) const;//重载<=
	bool operator>=(const Data&) const;//重载>=
};

