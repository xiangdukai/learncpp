#pragma once
#include"worker.h"
#include<bits/stdc++.h>
using namespace std;
class Employee : public Worker
{
public:
	Employee(int id,string name,int dId);
	virtual void ShowInfo() ; //显示个人信息
	virtual string GetDeptID() ; //获取部门名称编号
};

