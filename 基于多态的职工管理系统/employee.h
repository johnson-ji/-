#pragma once
#include <iostream>
using namespace std;
#include <string>
#include"worker.h"

//creat a class named worker as the fundation of all the workers.
class employee : public worker
{
public:
	//constructor
	employee(int id, string name, int did);

	//show the information of the worker
	virtual void show_info();

	//show the department he works in
	virtual string getDeptName();

};