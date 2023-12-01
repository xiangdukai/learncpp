#include<bits/stdc++.h>
#include"manager.h"
Manager::Manager(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manager::ShowInfo() //显示个人信息
{
	cout << "职工编号： " << this->m_ID
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->GetDeptID()
		<< " \t岗位职责：完成经理交代的任务" << endl;
}
string Manager::GetDeptID() //获取部门名称编号
{
	return string("经理");
}