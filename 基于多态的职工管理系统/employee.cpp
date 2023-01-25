#include <iostream>
using namespace std;
#include <string>
#include"employee.h"


	//constructer
	employee::employee(int id, string name, int did)
	{
		this->m_id = id;
		this->m_name = name;
		this->m_D_id = did;
	}
	//show the information of the worker
	void employee::show_info()
	{
		cout << "职工编号： " << this->m_id
			<< " \t职工姓名： " << this->m_name
			<< " \t岗位：" << this->getDeptName()
			<< " \t岗位职责：完成经理交给的任务" << endl;
	}

	//show the department he works in
	string employee::getDeptName()
	{
		return string("员工");
	}
