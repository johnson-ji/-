#include"WorkerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"
#include<fstream>
#include<cstdlib>
#define FILENAME "empfile.txt"


WorkerManager::WorkerManager()
{
	//initialization parameters
	ifstream ifs;
	ifs.open(FILENAME, ios::out);

	//the file isn't exist yet
	if (!ifs.is_open())
	{
		cout << "The file isn't exist." << endl;//output the result.
		emp_num = 0;//initialiaztion emp_num
		emp_array = NULL;
		m_empty = true;
		ifs.close();
		return;
	}
	
	//file exist,but it's empty
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "The file is empty." << endl;
		emp_num = 0;
		emp_array = NULL;
		m_empty = true;

		ifs.close();
		return;
	}

	//file exist ,and there're data in it
	int num = this->get_num();
	cout << "there are " << num << " employees in our company."<<endl;
	this->emp_num = num;


	this->emp_array = new worker* [this->emp_num + 4];
	this->init_arr();

	/* test
	for (int i = 0; i < emp_num; i++)
	{
		cout << "id:" << this->emp_array[i]->m_id << " ";
		cout << "name:" << this->emp_array[i]->m_name << " ";
		cout << "did:" << this->emp_array[i]->m_D_id << endl;
	}
	*/
}

int  WorkerManager::get_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//open and read the file

	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}

	return num;

}

void WorkerManager::init_arr()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* work = NULL;
		if (did == 1)
		{
			work = new employee(id, name, did);
		}
		else if (did == 2)
		{
			work = new manager(id, name, did);
		}
		else
		{
			work = new boss(id, name, did);
		}

		this->emp_array[index] = work;
		index++;
	}
	ifs.close();
}


void WorkerManager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::quit_sys()
{
	cout << "See you next time!"<<endl;
	system("pause");
	exit(0);

}

void WorkerManager::add_emp()
{
	

	//Set some new parameters to record newly added employees
	int add_num;
	int new_size;
	

	//Decide how many employees to add
	cout << "please input how many employees u want to add" << endl;
	cin >> add_num;

	if (add_num > 0)
	{
		//expand the space by creating a new space
		new_size = this->emp_num + add_num;
		worker** newspace =new worker* [new_size + 8];
		
		//copy datas to the new space
		if (this->emp_array != 0)
		{
			for (int i = 0; i < emp_num; i++)
			{
				newspace[i] = this->emp_array[i];
			}
		}
		
		//add new datas
		for (int i = 0; i < add_num; i++)
		{
			//creat new data
			int id;
			string name;
			int dep;

			//start adding
			cout << "Start adding data for the "<<i+1<<" employee" << endl;
			//id
			bool exist = true;

			while(exist)
			{ 
				cout << "Please input the id :" << endl;
				cin >> id;
				
				exist = id_repeat(id);
				
				if (exist == false)
				{
					break;
				}
				cout << "wrong input,try again" << endl;
			}

			//name
			cout << "Please input the name :" << endl;
			cin >> name;
			//dep
			cout << "Please input the department :" << endl;
			cin >> dep;

			//creat new object
			worker* add_worker = NULL;
			switch (dep)
			{
			case 1:	
				add_worker = new employee(id, name, dep);
				break;
			case 2:
				add_worker = new manager(id, name, dep);
				break;
			case 3:
				add_worker = new boss(id, name, dep);
				break;
			default:
				break;
			}

			//storage the add_worker into array
			newspace[emp_num + i] = add_worker;
		}

		//free up space
		delete[] this->emp_array;

		//redirect the space to current data
		emp_array = newspace;

		//update the size of data
		emp_num = new_size;

		//change the file stastic
		this->m_empty = false;

		//successfully added
		cout << "successfully added " << add_num << "workers" << endl;

		this->save_file();
	}
	else
	{
		cout << "invalid input" << endl;
	}

	system("pause");
	system("cls");

}


bool WorkerManager::id_repeat(int id)
{
	for (int i = 0; i < emp_num; i++)
	{
		if (id == this->emp_array[i]->m_id)
		{
			return true;
		}
	}

	return false;
}

void WorkerManager::save_file()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < emp_num; i++)
	{
		ofs << emp_array[i]->m_id << " ";
		ofs << emp_array[i]->m_name << " ";
		ofs << emp_array[i]->m_D_id << endl;

	}

	ofs.close();
}

void WorkerManager::show_emp()
{
	if (this->m_empty)
	{
		cout << "There's no employee in your company" << endl;
	}
	else
	{
		for (int i = 0; i < emp_num; i++)
		{
			this->emp_array[i]->show_info();
		}
	}

	system("pause");
	system("cls");
}


int WorkerManager::isExist(int id)
{

	int index = -1;
	for (int i = 0; i < emp_num; i++)
	{
		if (emp_array[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}


void WorkerManager::del_emp()
{
	if (!m_empty)
	{

		int num = 0;
		int index = 0;
		cout << "Please enter the employee ID you want to delete" << endl;
		cin >> num;
		index = isExist(num);

		if ( index!= -1)
		{
			for (int i = index; i < emp_num - 1; i++)
			{
				this->emp_array[i] = this->emp_array[i + 1];
			}
			cout << "the data is successfully deleted." << endl;

			//change the number of employees
			this->emp_num--;
			
			//save the change into file
			this->save_file();

			return;
		}
		else
		{
			cout << "sorry,the id is wrong" << endl;
		}

	}
	else
	{
		cout << "the file isn't exist!" << endl;
	}

	system("pause");
	system("cls");

}

void WorkerManager::mod_emp()
{
	
	if (this->m_empty)
	{
		cout << "file is not exist" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int num = 0;
		int index = -1;

		cout << "please input the employee u want to modify" << endl;
		cin >> num;

		index = isExist(num);

		if (index != -1)
		{
			int id;
			string name;
			int dep;

			//delete former data,in case the class changes.
			delete this->emp_array[index];


			cout << "Start modifying data for the employee" << endl;
			//id
			bool exist = true;

			while (exist)
			{
				cout << "Please input the id :" << endl;
				cin >> id;

				exist = id_repeat(id);

				if (exist == false)
				{
					break;
				}
				cout << "wrong input,try again" << endl;
			}

			//name
			cout << "Please input the name :" << endl;
			cin >> name;
			//dep
			cout << "Please input the department :" << endl;
			cin >> dep;

			//creat new object
			worker* mod_worker = NULL;
			switch (dep)
			{
			case 1:
				mod_worker = new employee(id, name, dep);
				break;
			case 2:
				mod_worker = new manager(id, name, dep);
				break;
			case 3:
				mod_worker = new boss(id, name, dep);
				break;
			default:
				break;
			}

			//storage the add_worker into array
			this->emp_array[index] = mod_worker;

			cout << "modify succesfully!" << endl;

			this->save_file();
		}
		else
		{
			cout << "this employee doesn't exist" << endl;
		}

	}
	
	system("pause");
	system("cls");
}

void WorkerManager::search_emp()
{
	if (this->m_empty)
	{
		cout << "The file isn't exist" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "please input the way u want to search" << endl;
		cout << "1.search by id" << endl;
		cout << "2.search by name" << endl;

		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			int id;
			cout << "please input the id u want to search" << endl;
			cin >> id;

			for (int i = 0; i < emp_num; i++)
			{
				if (id == this->emp_array[i]->m_id)
				{
					cout << "id: " << id << endl;
					cout << "name: " << this->emp_array[i]->m_name << endl;
					cout << "department: " << this->emp_array[i]->m_D_id << endl;
					break;
				}
				else
				{
					cout << "This ID doesn't exist" << endl;
				}
			}
			
		case 2:
			string name;
			cout << "please input the name u want to search" << endl;
			cin >> name;

			bool exist = false;
			for (int i = 0; i < emp_num; i++)
			{
				if (name == this->emp_array[i]->m_name)
				{
					cout << "id: " << this->emp_array[i]->m_id << endl;
					cout << "name: " << this->emp_array[i]->m_name << endl;
					cout << "department: " << this->emp_array[i]->m_D_id << endl;

					exist = true;
					break;
				}
			}

			if (exist == false)
			{
				cout << "Dosen't exist" << endl;
			}
		}

	system("pause");
	system("cls");
	}
}

void WorkerManager::sort_arr()
{
	if (this->m_empty)
	{
		cout << "The file isn't exist" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "choose the way to sort: " << endl;
		cout << "1、Sort by employee number in ascending order" << endl;
		cout << "2、Sort by employee number in descending order" << endl;

		int select = 0;
		bool se = true;
		while(se)
		{ 
		
		cin >> select;

		if (select == 1 || select == 2)
			{
				se = false;
			}
		}

		for (int i = 0; i < emp_num; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < emp_num; j++)
			{
				if (select == 1) //升序
				{
					if (emp_array[minOrMax]->m_id > emp_array[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (emp_array[minOrMax]->m_id < emp_array[j]->m_id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				worker* temp = emp_array[i];
				emp_array[i] = emp_array[minOrMax];
				emp_array[minOrMax] = temp;
			
			}
		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save_file();
		this->show_emp();
	}
}

void WorkerManager::clean_file()
{
	cout << "sure to clear？" << endl;
	cout << "1、yes" << endl;
	cout << "2、no" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->emp_array != NULL)
		{
			for (int i = 0; i < this->emp_num; i++)
			{
				if (this->emp_array[i] != NULL)
				{
					delete this->emp_array[i];
				}
			}
			this->emp_num = 0;
			delete[] this->emp_array;
			this->emp_array = NULL;
			this->emp_num = true;
		}
		cout << "successfully clear!" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->emp_array != NULL)
	{
		delete[] emp_array;
		emp_array = NULL;
	}
}