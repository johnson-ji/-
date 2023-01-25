#pragma once //防止头文件重复包含
#include <iostream>
using namespace std;
#include "worker.h"

class WorkerManager
{
public:
	//constructor
	WorkerManager();

	//to detect whether the file is empty
	bool m_empty;

	//to count the total number of employees.
	int emp_num;

	//an array for storing all pointers
	worker** emp_array;

	//Count the number of employees
	int get_num();

	//initial the array;
	void init_arr();

	//a function for adding workers   
	void add_emp();

	//a function to determine whether the ID is repeated
	bool id_repeat(int id);

	//a funciton to store datas into file
	void save_file();

	//a function to search employee
	void search_emp();

	//show all the employee
	void show_emp();

	//Determine whether the employee exists
	int isExist(int id);

	//Delete employee by id
	void del_emp();

	//modify employee by id
	void mod_emp();

	//sort the array
	void sort_arr();

	//creat a function to show menu.
	void show_menu();

	//clear the file
	void clean_file();

	//creat a function to quit the system.
	void quit_sys();


	//destructor
	~WorkerManager();


};