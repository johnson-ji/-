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
	cout << "�ϰ��ţ� " << this->m_id
		<< " \t�ϰ������� " << this->m_name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ�������´�ָ��" << endl;
}

string boss::getDeptName()
{
	return string("�ϰ�");
}