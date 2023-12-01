#include"boss.h"
using namespace std;
Boss::Boss(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId =dId;
}
void Boss::ShowInfo() //显示个人信息
{
	cout << "职工编号： " << this->m_ID
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->GetDeptID()
		<< " \t岗位职责：管理公司所有事务" << endl;
}
string Boss::GetDeptID() //获取部门名称编号
{
	return "老板";
}