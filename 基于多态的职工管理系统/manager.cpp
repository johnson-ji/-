#include <iostream>
using namespace std;
#include <string>
#include"manager.h"



manager::manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_D_id = did;
}

void manager::show_info()
{
	cout << "经理编号： " << this->m_id
		<< " \t经理姓名： " << this->m_name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：传达老板的指令给员工" << endl;
}

string manager::getDeptName()
{
	return string("经理");
}