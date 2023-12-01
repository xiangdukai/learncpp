#pragma once
#include<bits/stdc++.h>
#include"worker.h"
using namespace std;

class Manager : public Worker
{
public:
	Manager(int id, string name, int dId);
	virtual void ShowInfo(); //显示个人信息
	virtual string GetDeptID(); //获取部门名称编号

};
