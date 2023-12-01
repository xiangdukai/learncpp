#pragma once
#include<bits/stdc++.h>
#include"worker.h"
#include<fstream>
#define FILENAME  "empFile.txt"
using namespace std;
class WorkerManager
{
public:

	WorkerManager();
	void Show_Menu();
	void Add_Emp();
	void Save();
	int get_EmpNum();
	void init_Emp();
	void Show_Emp();
	void Del_Emp();
	int IsExist(int id);
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();
	void exitSystem();
	~WorkerManager();
	int m_Empnum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;
};
