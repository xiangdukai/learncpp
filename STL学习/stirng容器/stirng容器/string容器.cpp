#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//string容器的构造函数
void test01()
{
	string s1;//无参构造
	cout << s1 << endl;
	const char* str = "hello world!";
	string s2(str);
	cout << s2 << endl;
	string s3(s2);//拷贝构造
	cout << s3 << endl;
	string s4(5, 'a');
	cout << s4 << endl;
}

//string容器赋值
void test02()
{
	string s1;
	s1 = "hello world!";
	cout << s1 << endl;

	string s2;
	s2 = s1;
	cout << s2 << endl;

	string s3;
	s3 = 'a';
	cout << s3 << endl;

	string s4;
	s4.assign("hello c++");
	cout << s4 << endl;

	string s5;
	s5.assign("hello c++",5);
	cout << s5 << endl;

	string s6;
	s6.assign(s4);
	cout << s6 << endl;

	string s7;
	s7.assign(5,'a');
	cout << s7 << endl;
}

//string容器拼接
void test03()
{
	string s("I");
	s += " love game : ";
	s.append("LOL PVZ", 4);//把字符串s的前n个字符连接到当前字符串结尾
	s.append("LOL PVZ", 4, 3);//字符串s中从pos开始的n个字符连接到字符串结尾
	cout << s << endl;
}

//stirng中的find与replace
void test04()
{
	string s("asdfgjkldf");
	int pos = s.find("df");
	if (pos == -1)
	{
		cout << "未找到\n";
	}
	else 
	{
		cout << pos << endl;
	}

	int rpos = s.rfind("df");
	if (rpos == -1)
	{
		cout << "未找到\n";
	}
	else
	{
		cout << rpos << endl;
	}

	s = s.replace(1, 3, "12345");
	cout << s << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
}