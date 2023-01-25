#include<iostream>
using namespace std;
#include "WorkerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"


int main()
{
	//test
	/*
	worker* work = new manager(1, "johnson", 2);
	work->show_info();
	*/

	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		//调用展示菜单成员函数
		wm.show_menu();
		//输入选择
		cout << "please input the function you need:" << endl;
		cin >> choice;


		switch (choice)
		{
		case 0: //退出系统
			wm.quit_sys();
			break;
		case 1: //添加职工
			wm.add_emp();
			break;
		case 2: //显示职工
			wm.show_emp();
			break;
		case 3: //删除职工
			wm.del_emp();
			break;
		case 4: //修改职工
			wm.mod_emp();
			break;
		case 5: //查找职工
			wm.search_emp();
			break;
		case 6: //排序职工
			wm.sort_arr();
			break;
		case 7: //清空文件
			wm.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}




	system("pause");

	return 0;
}