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
	string Name;//이름
	int password;//비밀번호
	int StudentID;//학번
	string Department;//학과
	map <string, string> classTable;	//성적 정보를 저장하는 map
	student() {};
	void setInfo(int id, string name, string department,int pw);
	void setTable(string lect, string score);
};