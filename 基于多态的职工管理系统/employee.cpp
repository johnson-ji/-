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
		cout << "ְ����ţ� " << this->m_id
			<< " \tְ�������� " << this->m_name
			<< " \t��λ��" << this->getDeptName()
			<< " \t��λְ����ɾ�����������" << endl;
	}

	//show the department he works in
	string employee::getDeptName()
	{
		return string("Ա��");
	}
