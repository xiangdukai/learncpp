#include<iostream>
#include"MyArray.hpp"
using namespace std;

template<typename T>
void Myprint(MyArray<T>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	int n = 5;
	MyArray<double> myarray(n);
	for (double i = 0; i < n; i++)
	{
		myarray.Push_back(i);
	}
	Myprint(myarray);
	myarray.Pop_back();
	Myprint(myarray);
}
int main()
{
	test01();
}