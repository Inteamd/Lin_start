#pragma once
#include<vector>
class Sneaknob
{
public:
	int x;
	int y;
	Sneaknob* last;
	static int num;
	Sneaknob();
	Sneaknob(Sneaknob*);
};
class Food
{
public:
	int x, y;
	Food();
	~Food();
	void display();
};
class Sneak
{
private:
	Sneaknob* head;
	Sneaknob* tail;
	std::vector<Sneaknob*> body;
	int direct_x;
	int direct_y;
	double speed;
public:
	Sneak();
	~Sneak();
	void display();
	void append();
	void run();
	void change_direct(int n);
	bool detected();
	bool get_food(Food& f);
	double get_speed(const int);
};


