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
	cout << "�����ţ� " << this->m_id
		<< " \t���������� " << this->m_name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ�𣺴����ϰ��ָ���Ա��" << endl;
}

string manager::getDeptName()
{
	return string("����");
}