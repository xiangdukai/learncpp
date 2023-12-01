#pragma once
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
class Worker
{
public:
	virtual void ShowInfo() = 0; //显示个人信息
	virtual string GetDeptID() = 0; //获取部门名称编号
	int m_ID; //职工编号
	string m_Name;
	int m_DeptId; //职工所在部门名称编号
};

