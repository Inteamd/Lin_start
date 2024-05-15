#pragma once
#include<iostream>
class Data
{
private:
	int year;//��
	int month;//��
	int day;//��
public:
	Data();//Ĭ�Ϲ��캯��
	Data(int, int, int);//�������ݽ��й���
	Data operator+(int) const;//����+
	Data operator-(int) const;//����-
	friend Data operator+(int, const Data&);//����+
	friend Data operator-(int, const Data&);//����-
	Data& operator+=(int);//����+=
	Data& operator-=(int);//����-=
	friend std::ostream& operator<<(std::ostream&, const Data&);//����<<
	friend std::istream& operator>>(std::istream&, Data&);//����>>
	bool operator>(const Data&) const;//����>
	bool operator<(const Data&) const;//����<
	bool operator==(const Data&) const;//����==
	bool operator!=(const Data&) const;//����!=
	bool operator<=(const Data&) const;//����<=
	bool operator>=(const Data&) const;//����>=
};

