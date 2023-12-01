#include<bits/stdc++.h>
#include"employee.h"
Employee::Employee(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Employee::ShowInfo() //显示个人信息
{
	cout << "职工编号： " << this->m_ID
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->GetDeptID()
		<< " \t岗位职责：完成经理交代的任务" << endl;
}
string Employee::GetDeptID() //获取部门名称编号
{
	return string("员工");
}