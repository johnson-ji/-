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

	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		//����չʾ�˵���Ա����
		wm.show_menu();
		//����ѡ��
		cout << "please input the function you need:" << endl;
		cin >> choice;


		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.quit_sys();
			break;
		case 1: //���ְ��
			wm.add_emp();
			break;
		case 2: //��ʾְ��
			wm.show_emp();
			break;
		case 3: //ɾ��ְ��
			wm.del_emp();
			break;
		case 4: //�޸�ְ��
			wm.mod_emp();
			break;
		case 5: //����ְ��
			wm.search_emp();
			break;
		case 6: //����ְ��
			wm.sort_arr();
			break;
		case 7: //����ļ�
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