#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;

double v;
ExMessage m1, m2, m3,m;		// 定义消息变量
double a, b, c;

static double distance(ExMessage m1, ExMessage m2)
{
	return sqrt((m1.x - m2.x) * (m1.x - m2.x) + (m1.y - m2.y) * (m1.y - m2.y));
}

//为了解椭圆方程
static double f(double x, double y, ExMessage m1, ExMessage m2, double a)
{
	double z = sqrt((x - m1.x) * (x - m1.x) + (y - m1.y) * (y - m1.y))
		+ sqrt((x - m2.x) * (x - m2.x) + (y - m2.y) * (y - m2.y));
	return abs(z - 2 * a);
}

static void draw(int X,int Y,int R)
{
	R++;
	for (int x = X-R; x <= X+R ; x++)
	{
		for (int y = Y-R; y <= Y+R; y++)
		{
			if (f(x, y, m1, m2, a) <= 1.0)
			{
				putpixel(int(x), int(y), BLUE);
			}
		}
	}
}

bool panduan()
{
	if (peekmessage(&m))
	{
		if (m.message == WM_RBUTTONDOWN)
		{
			return true;
		}
		else return false;
	}
	
}


int main()
{
	int r;
	cout << "请输入小球运动速度：";
	cin >> v;
	cout << "请输入小球大小：";
	cin >> r;
	initgraph(1280, 960);	// 创建绘图窗口，大小为 1280*960 像素
	do
	{
		m1 = getmessage(EX_MOUSE);
		//putpixel(m1.x, m1.y,BLUE);
	} while (m1.message != WM_LBUTTONDOWN);
	fillcircle(m1.x, m1.y, 2);
	do
	{
		m2 = getmessage(EX_MOUSE);
		//putpixel(m2.x, m2.y, BLUE);
	} while (m2.message != WM_LBUTTONDOWN);
	fillcircle(m2.x, m2.y, 2);
	do
	{
		m3 = getmessage(EX_MOUSE);
		//putpixel(m3.x, m3.y, BLUE);
	} while (m3.message != WM_LBUTTONDOWN);
	//fillcircle(m3.x, m3.y, 2);

	int x0 = (m1.x + m2.x) / 2;
	int y0 = (m1.y + m2.y) / 2;
	c = (distance(m1, m2) / 2);
	a = ((distance(m1, m3) + distance(m2, m3)) / 2);
	b = sqrt(a * a - c * c);
	//cout << a << " " << b << " " << c << endl;

	//RECT r = { 10, 10, 10, 10 };
	//const string str="a = "+ to_string(a);
	//drawtext(_T(str), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//x1,y1 是上顶点；x2,y2 是下顶点
	double x1 = b * (m2.y - m1.y) / 2 / c + x0;
	double y1 = -b * (m2.x - m1.x) / 2 / c + y0;
	double x2 = -b * (m2.y - m1.y) / 2 / c + x0;
	double y2 = b * (m2.x - m1.x) / 2 / c + y0;
	//x3,y3 是右顶点；x4,y4 是左顶点
	double x3 = a * (m2.x - m1.x) / 2 / c + x0;
	double y3 = a * (m2.y - m1.y) / 2 / c + y0;
	double x4 = -a * (m2.x - m1.x) / 2 / c + x0;
	double y4 = -a * (m2.y - m1.y) / 2 / c + y0;

	//fillcircle(x1, y1, 2);
	//fillcircle(x2, y2, 2);
	//fillcircle(x3, y3, 2);
	//fillcircle(x4, y4, 2);

	int ymax = 0, ymin = 1000, xmax = 0, xmin = 10000;
	int ymax_x = 0, ymin_x = 1000, xmax_y, xmin_y;
	for (int x = 0; x <= 1280; x++)
	{
		for (int y = 0; y <= 960; y++)
		{
			if (f(x, y, m1, m2, a) <= 1.0)
			{
				putpixel(int(x), int(y), BLUE);

				if (y >= ymax)
				{
					ymax = y;
					ymax_x = x;
				}
				if (y <= ymin)
				{
					ymin = y;
					ymin_x = x;
				}
				if (x >= xmax)
				{
					xmax = x;
					xmax_y = y;
				}
				if (x <= xmin)
				{
					xmin = x;
					xmin_y = y;
				}

			}
		}
	}
	//fillcircle(ymax_x, ymax, 2);
	//fillcircle(ymin_x, ymin, 2);

	//fillcircle(100, 100, 5);
	//Sleep(1000 / v);
	//clearcircle(100, 100, 5);

	int Y = 960, X = 0;
	bool flag = true;
	while (true)
	{
		for (int x = 0; x <= ymax_x; x++)
		{
			for (int y = xmin_y; y >= 0; y--)
			{
				if (panduan())
				{
					while (!panduan())
					{
						/*
						if (peekmessage(&m))
						{
							if (m.message == WM_KEYDOWN)
							{
								if (m.vkcode == VK_ESCAPE)
									return 0;	// 按 ESC 键退出程序
							}
						}
						*/
					}

				}
				if (f(x, y, m1, m2, a) <= 1.0)
				{
					clearcircle(X, Y, r);
					solidcircle(x, y, r);
					Y = y;
					X = x;
					Sleep(10 / v + 0.4);


					//将椭圆轨迹补充完整
					draw(x, y, r);
				}
			}
		}
		for (int x = ymax_x; x <= 1280; x++)
		{
			for (int y = 0; y <= xmax_y; y++)
			{
				if (panduan())
				{
					while (!panduan())
					{
						/*
						if (peekmessage(&m))
						{
							if (m.message == WM_KEYDOWN)
							{
								if (m.vkcode == VK_ESCAPE)
									return 0;	// 按 ESC 键退出程序
							}
						}
						*/
					}

				}
				if (f(x, y, m1, m2, a) <= 1.0)
				{
					clearcircle(X, Y, r);
					solidcircle(x, y, r);
					Y = y;
					X = x;
					Sleep(10 / v + 0.4);

					//将椭圆轨迹补充完整
					draw(x, y, r);
				}
			}
		}
		for (int x = 1280; x >= ymin_x; x--)
		{
			for (int y = xmax_y; y <= 960; y++)
			{
				if (panduan())
				{
					while (!panduan())
					{
						/*
						if (peekmessage(&m))
						{
							if (m.message == WM_KEYDOWN)
							{
								if (m.vkcode == VK_ESCAPE)
									return 0;	// 按 ESC 键退出程序
							}
						}
						*/
					}

				}
				if (f(x, y, m1, m2, a) <= 1.0)
				{
					clearcircle(X, Y, r);
					solidcircle(x, y, r);
					Y = y;
					X = x;
					Sleep(10 / v + 0.4);

					//将椭圆轨迹补充完整
					draw(x, y, r);
				}
			}
		}
		for (int x = ymin_x; x >= 0; x--)
		{
			for (int y = 960; y >= xmin_y; y--)
			{
				if (panduan())
				{
					while (!panduan())
					{
						/*
						if (peekmessage(&m))
						{
							if (m.message == WM_KEYDOWN)
							{
								if (m.vkcode == VK_ESCAPE)
									return 0;	// 按 ESC 键退出程序
							}
						}
						*/
					}

				}
				if (f(x, y, m1, m2, a) <= 1.0)
				{
					clearcircle(X, Y, r);
					solidcircle(x, y, r);
					Y = y;
					X = x;
					Sleep(10 / v + 0.4);

					//将椭圆轨迹补充完整
					draw(x, y, r);
				}
			}
		}
	}



	//ellipse(int(x4), int(y1), int(x3), int(y2));


	//_getch();				// 按任意键继续
	//closegraph();			// 关闭绘图窗口
	return 0;
}