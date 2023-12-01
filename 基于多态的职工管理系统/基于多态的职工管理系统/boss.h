#pragma once
#include<bits/stdc++.h>
#include"worker.h"
using namespace std;

class Boss : public Worker
{
public:
	Boss(int id, string name, int dId);
	virtual void ShowInfo() ; //显示个人信息
	string GetDeptID() ; //获取部门名称编号
	
};