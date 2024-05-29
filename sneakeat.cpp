// sneakeat.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<graphics.h>
#include<easyx.h>
#include <conio.h>
#include <ctime>
#include <chrono>
#include"Sneak.h"
#include <thread>
#include<Windows.h>
#include <imm.h>
#define _CRT_SECURE_NO_WARNINGS



using namespace std;
extern const int width = 800;
extern const int height = 600;
extern const int cell_size = 20;
const int rows = height / cell_size;
const int cols = width / cell_size;
extern int food_num = -1;
void display_boundaries()
{
    for (int i = 0; i <= cols; i++)
    {
        for (int j = 0; j <= rows; j++)
        {
            setlinecolor(WHITE);
            rectangle(i * cell_size, j * cell_size, (i + 1) * cell_size, (j + 1) * cell_size);
        }
    }
    
}
void displaygame(Sneak& s, bool& l,Food&food,int f)
{
    //initgraph(width, height);
    //setbkcolor(BLACK);
    IMAGE drawPage,displaypage;
    getimage(&displaypage, 0, 0, width, height);
    getimage(&drawPage, 0, 0, width, height);
    
    while (l)
    {
        clock_t start = clock();
        int fps = f / 2 * s.get_speed(food_num);
        auto frame_duration = std::chrono::milliseconds(1000 / fps);
        //cleardevice();
        //clock_t start = clock();
        //cleardevice();
        //setbkcolor(GREEN);
        //display_boundaries();
        for (int i = 0; i <= cols; i++)
        {
            for (int j = 0; j <= rows; j++)
            {
                setlinecolor(WHITE);
                rectangle(i * cell_size, j * cell_size, (i + 1) * cell_size, (j + 1) * cell_size);
            }
        }
        //putimage(0, 0, &drawPage);
        food.display();
        //setbkcolor(GREEN);
        //display_boundaries();
        //s.run();
        s.display();
        //putimage(0, 0, &drawPage);
        clock_t elapsed = clock() - start;
        clock_t wait = CLK_TCK / fps - elapsed;
        //putimage(0, 0, &drawPage);
        if (wait > 0)
        {
            Sleep(wait);
        }
        //putimage(0, 0, &drawPage);
        cleardevice();
        
    }
}
void io(Sneak& s, bool& l,int f)
{
    int fps = f * 1000;
    auto frame_duration = std::chrono::milliseconds(1000 / fps);
    while (l)
    {
        clock_t start = clock();
        if (GetAsyncKeyState(0x57) & 0x8000)
        {
            s.change_direct(2);
        }
        else if (GetAsyncKeyState(0x53) & 0x8000)
        {
            s.change_direct(3);
        }
        else if (GetAsyncKeyState(0x41) & 0x8000)
        {
            s.change_direct(1);
        }
        else if (GetAsyncKeyState(0x44) & 0x8000)
        {
            s.change_direct(0);
        }
        clock_t elapsed = clock() - start;
        clock_t wait = CLK_TCK / fps - elapsed;
        if (wait > 0)
        {
            Sleep(wait);
        }
    }
}
void sneakself(Sneak& s, bool& l,Food&food,int f)
{
    
    while (l)
    {
        int fps = f / 2*s.get_speed(food_num);
        auto frame_duration = std::chrono::milliseconds(1000 / fps);
        clock_t start = clock();
        s.run();
        //s.display();
        if (s.get_food(food))
        {
            food = Food();
            s.append();
        }
        if (!s.detected())
        {
            cout << "die!!!" << endl;
            l = false;
        }
        clock_t elapsed = clock() - start;
        clock_t wait = CLK_TCK / fps - elapsed;
        if (wait > 0)
        {
            Sleep(wait);
        }
    }
}
int main()
{

    initgraph(width, height);
    setbkcolor(BLACK);
    settextcolor(WHITE);
    settextstyle(40, 20,_T("Arial"));
    TCHAR welcome[] = _T("welcome to sneakeat game");
    TCHAR control_promot[] = _T("use w/a/s/d to control direction");
    outtextxy(150, 200, welcome);
    outtextxy(150, 240, control_promot);
    Sleep(3000);
    //system("pause");
    int fps = 10;
    //auto frame_duration = std::chrono::milliseconds(1000 / fps);
    Sneak sneak;
    //initgraph(width, height);
   //setbkcolor(GREEN);
    bool live = true;
    Food food;
   // bool keyState[256] = { false };
  
    thread thread1(displaygame, ref(sneak), ref(live), ref(food),fps);
    thread thread2(io, ref(sneak), ref(live),fps);
    thread thread3(sneakself, ref(sneak), ref(live), ref(food), fps);
    thread1.join();
    thread2.join();
    thread3.join();
    string foodnum= to_string(food_num);
    string end1 = "Your score is: "+foodnum;
    char promot[30];
    TCHAR end[30];
    sprintf_s(promot, "Your socre is %d", food_num);
    //cout << _endgame << endl;
    //TCHAR end[] = promot;
    //TCHAR end[] = promot;
#ifdef UNICODE
    MultiByteToWideChar(CP_ACP, 0, promot, -1, end, 100);
#else
    strcpy(end, promot);
#endif
    TCHAR epro[] = _T("END GAME");
    outtextxy(200, 200, epro);
    outtextxy(200, 240, end);
    Sleep(10000);
    
     
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
