#pragma once
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

class student {
public:
	string Name;//�̸�
	int password;//��й�ȣ
	int StudentID;//�й�
	string Department;//�а�
	map <string, string> classTable;	//���� ������ �����ϴ� map
	student() {};
	void setInfo(int id, string name, string department,int pw);
	void setTable(string lect, string score);
};