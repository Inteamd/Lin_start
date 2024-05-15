#include "Data.h"
Data::Data()
{
	year = 0;
	month = 1;
	day = 1;
}
Data::Data(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	while (month > 12 or month<0)
	{
		std::cout << "wrong month!! \n enter the  right month" << std::endl;
		std::cin >> month;
	}
	while (day > 31 or day<0)
	{
		std::cout << "wrong day!! \n enter the  right day" << std::endl;
		std::cin >> day;
	}
	while (day > 30)
	{
		if (month == 2 or month == 4 or month == 6 or month == 9 or month == 11)
		{
			std::cout << "wrong day!! \n enter the  right day" << std::endl;
			std::cin >> day;
		}
		else
		{
			break;
		}
	}
	while (day > 29)
	{
		if (month == 2)
		{
			std::cout << "wrong day!! \n enter the  right day" << std::endl;
			std::cin >> day;
		}
	}
	while (day >28 )
	{
		if (month == 2)
		{ 
			if (year % 4 != 0 or year % 100 == 0)
			{
				std::cout << "wrong day!! \n enter the  right day" << std::endl;
				std::cin >> day;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	
}
Data Data::operator+(int a) const
{
	Data temp = *this;
	if (a < 0)
	{
		return *this - (-a);
	}
	else
	{
		temp.day += a;
		while (temp.day > 28)
		{
			if (temp.day > 31)
			{
				if (temp.month == 1 or temp.month == 3 or temp.month == 5 or temp.month == 7 or temp.month == 8 or temp.month == 10 or temp.month == 12)
				{
					temp.day -= 31;
					temp.month++;
				}
				else if (temp.month == 4 or temp.month == 6 or temp.month == 9 or temp.month == 11)
				{
					temp.day -= 30;
					temp.month++;
				}
				else if (temp.month == 2 and temp.year % 4 == 0 and temp.year % 100 != 0)
				{
					temp.day -= 29;
					temp.month++;
				}
				else
				{
					temp.day -= 28;
					temp.month++;
				}
			}
			if (temp.day == 31)
			{
				if (temp.month == 1 or temp.month == 3 or temp.month == 5 or temp.month == 7 or temp.month == 8 or temp.month == 10 or temp.month == 12)
				{
					return temp;
				}
				else if (temp.month == 4 or temp.month == 6 or temp.month == 9 or temp.month == 11)
				{
					temp.day -= 30;
					temp.month++;
				}
				else if (temp.month == 2 and temp.year % 4 == 0 and temp.year % 100 != 0)
				{
					temp.day -= 29;
					temp.month++;
				}
				else
				{
					temp.day -= 28;
					temp.month++;
				}
			}
			else if (temp.day == 30)
			{
				if (temp.month == 2 and temp.year % 4 == 0 and temp.year % 100 != 0)
				{
					temp.day -= 29;
					temp.month++;
				}
				else if (temp.month == 2)
				{
					temp.day -= 28;
					temp.month++;
				}
				else
				{
					return temp;
				}
			}
			else if (temp.day == 29)
			{
				if (temp.month == 2 and temp.year % 4 == 0 and temp.year % 100 != 0)
				{
					return temp;
				}
				else if (temp.month == 2)
				{
					temp.day -= 28;
					temp.month++;
				}
				else
				{
					return temp;
				}
			}
			if (temp.month > 12)
			{
				temp.month -= 12;
				temp.year++;
			}
		}
	}
	return temp;
	
	
}
Data operator+(int a,const Data& d)
{
	return d + a;
}
Data Data::operator-(int a) const
{
	Data temp = *this;
	temp.day -= a;
	while (temp.day <= 0)
	{
		
		
	
			if (temp.month - 1 == 1 or temp.month - 1 == 3 or temp.month - 1 == 5 or temp.month - 1 == 7 or temp.month - 1 == 8 or temp.month - 1 == 10 or temp.month - 1 == 12)
			{
				temp.month--;
				temp.day += 31;
			}
			else if (temp.month - 1 == 4 or temp.month - 1 == 6 or temp.month -1 == 9 or temp.month - 1 == 11)
			{
				temp.day += 30;
				temp.month--;
			}
			else if (temp.month - 1 == 2 and temp.year % 4 == 0 and temp.year % 100 != 0)
			{
				temp.day += 29;
				temp.month--;
			}
			else if (temp.month - 1 == 2)
			{
				temp.day += 28;
				temp.month--;
			}
			else if (temp.month - 1 <= 0)
			{
				temp.day += 31;
				temp.month--;
			}
		
		if (temp.month <= 0)
		{
			temp.month += 12;
			temp.year--;
		}
	}
		
	
	return temp;

}
Data operator-(int a, const Data& d)
{
	return d - a;
}
Data& Data::operator+=(int a)
{
	*this = *this + a;
	return *this;
}
Data& Data::operator-=(int a)
{
	*this = *this - a;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const Data& d)
{
	os << d.year << "." << d.month << "." << d.day << "";
	return os;
}
std::istream& operator>>(std::istream& is, Data& d)
{
	int year, month, day;
	is >> year >> month >> day;
	d = Data(year, month, day);
	return is;
}
bool Data::operator>(const Data& d) const
{
	if (year > d.year)
	{
		return true;
	}
	else if (year == d.year)
	{
		if (month > d.month)
		{
			return true;
		}
		else if (month == d.month)
		{
			if (day > d. day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Data::operator<(const Data& d) const
{
	return d > *this;
}
bool Data::operator==(const Data& d) const
{
	if (year == d.year and month == d.month and day == d.day)
	{
		return true;
	}
	return false;
}
bool Data::operator!=(const Data& d) const
{
	return !(*this == d);
}
bool Data::operator>=(const Data& d) const
{
	if (*this == d)
	{
		return true;
	}
	return *this > d;
}
bool Data::operator<=(const Data& d) const
{
	if (*this == d)
	{
		return true;
	}
	return d>*this;
}