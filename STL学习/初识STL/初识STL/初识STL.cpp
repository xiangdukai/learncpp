#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> v;

class Person
{
public:
	Person(string name, int age)
	{
		this->Age = age;
		this->Name = name;
	}
	string Name;
	int Age;
};

void myprint(int val)
{
	cout << val << " ";
}

void print1()
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void print2()
{
	for_each(v.begin(), v.end(), myprint);
}

void test01()
{
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	print1();
	v.pop_back();
	print2();
}

void test02()
{
	vector<Person*> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it)->Name << " " << (*it)->Age << "\t";
	}
	cout << endl;

}

//²âÊÔ¶þÎ¬vectorÈÝÆ÷
void test03()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator i = v.begin(); i != v.end(); i++)
	{
		for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
		{
			cout << (*j) << " ";
		}
		cout << endl;
	}
}

int main()
{
	//test01();
	//test02();
	test03();
}