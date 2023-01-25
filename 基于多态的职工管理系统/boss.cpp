#include <iostream>
using namespace std;
#include <string>
#include"boss.h"



boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_D_id = did;
}

void boss::show_info()
{
	cout << "老板编号： " << this->m_id
		<< " \t老板姓名： " << this->m_name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：向经理下达指令" << endl;
}

string boss::getDeptName()
{
	return string("老板");
}