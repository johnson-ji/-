#pragma once
#include <iostream>
using namespace std;
#include <string>

//creat a class named worker as the fundation of all the workers.
class worker
{
public:
	//show the information of the worker
	virtual void show_info() = 0;
	//show the department he works in
	virtual string getDeptName() = 0;


	//id of the worker
	int m_id;
	//name of the worker
	string m_name;
	//id of the departement
	int m_D_id;
};