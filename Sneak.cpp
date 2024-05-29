#include "Sneak.h"
#include<graphics.h>
#include<easyx.h>
#include<iostream>
#include<random>
#define _CRT_SECURE_NO_WARNINGS
extern const int cell_size;
extern const int width;
extern const int height;
int Sneaknob::num = 0;
extern int food_num;
Sneaknob::Sneaknob()
{
	if (num == 0)
	{
		x = 3*cell_size;
		y = cell_size;
		last = nullptr;
		num++;
	}
	else
	{
		std::cout << "no allowed construction!" << "\n";
	}
}
Sneaknob::Sneaknob(Sneaknob* sn)
{
	if (num == 0)
	{
		x = 3 * cell_size;
		y = cell_size;
		last = nullptr;
		num++;
	}
	else
	{
		x = sn->x - cell_size;
		y = sn->y;
		last = sn;
		num++;
	}
}
Sneak::Sneak()
{
	Sneaknob* nob0 = new Sneaknob(nullptr);
	Sneaknob* nob1 = new Sneaknob(nob0);
	Sneaknob* nob2 = new Sneaknob(nob1);
	body = { nob0,nob1,nob2 };
	head = nob0;
	tail = nob2;
	direct_x = 1;
	direct_y = 0;
	speed = 1 + food_num / 10;
}
Sneak::~Sneak()
{
	while (tail)
	{
		Sneaknob* temp = tail;
		tail = tail->last;
		delete temp;
	}
}

void Sneak::display()
{
	for (auto i : body)
	{
		setfillcolor(RED);
		fillrectangle(i->x, i->y, i->x - cell_size, i->y-cell_size);
	}
}
void Sneak::append()
{
	Sneaknob* nob = new Sneaknob(tail);
	body.push_back(nob);
	tail = nob;
}
void Sneak::run()
{
	//setfillcolor(BLACK);
	//fillrectangle(tail->x, tail->y, tail->x - cell_size, tail->y - cell_size);
	//head->x += direct_x * cell_size;
	//head->y += direct_y * cell_size;
	for (Sneaknob* temp = tail; temp != head; temp = temp->last)
	{
		temp->x = temp->last->x;
		temp->y = temp->last->y;
	}
	head->x += direct_x * cell_size;
	head->y += direct_y * cell_size;
	//setfillcolor(BLACK);
	//fillrectangle(tail->x, tail->y, tail->x - cell_size, tail->y - cell_size);
}
void Sneak::change_direct(int n)
{
	if (n == 0 and direct_x == 0 and direct_y != 0)//???????
	{
		direct_x = 1;
		direct_y = 0;
	}
	else if (n == 1 and direct_x == 0 and direct_y != 0)//???????
	{
		direct_x = -1;
		direct_y = 0;
	}
	else if (n == 2 and direct_x != 0 and direct_y == 0)//???????
	{
		direct_x = 0;
		direct_y = -1;
	}
	else if (n == 3 and direct_x != 0 and direct_y == 0)//???????
	{
		direct_x = 0;
		direct_y = 1;
	}
	else {};
}
bool Sneak::detected()
{
	if (head->x == width+cell_size or head->x==-cell_size or head->y == height+cell_size or head->y == -cell_size)
	{
		return false;
	}
	for (Sneaknob* temp = tail; temp->last != head; temp = temp->last)
	{
		if (head->x == temp->x and head->y == temp->y)
		{
			return false;
		}
	}
	return true;
}
bool Sneak::get_food(Food& f)
{
	if (head->x == f.x and head->y == f.y)
	{
		food_num++;
		return true;
	}
	return false;
}
double Sneak::get_speed(const int foodnum)
{
	speed = 1 + (foodnum / 20);
	return speed;
}
Food::Food()
{
	std::random_device rd; // ???????????
	std::mt19937 gen(rd()); // ???Mersenne Twister???????????????
	std::uniform_int_distribution<> distr_x(cell_size, width/cell_size);
	std::uniform_int_distribution<> distr_y(cell_size, height/cell_size);
	x = distr_x(gen)*cell_size;
	y = distr_y(gen)*cell_size;
	food_num++;
}
Food::~Food()
{
	food_num--;
}

void Food::display()
{
	setfillcolor(WHITE);
	fillrectangle(x, y, x - cell_size, y - cell_size);
}