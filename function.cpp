#include "header.h"
#include <fstream>
//��ü ������ ������
void student::setInfo(int id, string name, string department, int pw) {
	this->StudentID = id;
	this->Name = name;
	this->Department = department;
	this->password = pw;
}
//���� ������ ������
void student::setTable(string lect, string score) {
	classTable.insert({ lect,score });
}

vector<student> studentList;	//�л� ��ü�� ��� vector
map<string, int> Login;	//�α��� ������ ��� map

void run();
int input();
void readLoginFile();
void adminMenu();
void studentMenu();
void writeFile();
int input();
void readLoginFile();
void stop();
void addStudent();
void viewTableStud(string name);
void viewTableProf();
void deleteStudent();

void run() {
	while (1) {
		system("cls");	//���� ȭ�� �����
		cout << "Availiable Login operations:" << endl;
		cout << "1. Admin Login" << endl;
		cout << "2. Student Login" << endl;
		cout << "3. Exit" << endl;
		cout << "\nEnter menu : ";
		switch (input()) {
		case 1:
			adminMenu();
			break;
		case 2:
			studentMenu();
			break;
		case 3:
			stop();	//�����Լ�
		default:
			continue;	//���⿡ ���� �� �����
		}
	}
}

void adminMenu() {
	string tmpID;
	int tmpPW;
	system("cls");
	cout << "������ ���̵� �Է��ϼ��� >> ";
	cin >> tmpID;
	cout << "������ ��й�ȣ�� �Է��ϼ��� >> ";
	cin >> tmpPW;
	if (tmpID == "Admin" && tmpPW == Login.find("Admin")->second) {	//key���� "Admin"�̰� ��й�ȣ�� value�� ��ġ�� ��
	readmin:
		system("cls");
		cout << "- Logged in as Admin -" << endl;
		cout << "1. Add Students" << endl;
		cout << "2. Delete Students" << endl;
		cout << "3. View Table" << endl;
		cout << "4. Main Menu" << endl;
		cout << "5. Exit" << endl;

		cout << "\n Enter menu : ";
		switch (input()) {
		case 1:
			addStudent();	//�л� �߰� �Լ� ����
			goto readmin;
		case 2:
			deleteStudent();	//�л� ���� �Լ� ����
			goto readmin;
		case 3:
			viewTableProf();	//�л� ���� ��ȸ �Լ� ����
			goto readmin;
		case 4:
			return;	//������ �޴� �Լ��� ���� -> ���θ޴��� ����
		case 5:
			stop();	//�����Լ�
		default:
			goto readmin;	//���⿡ ���� �� �����
		}
	}
	else {
		cout << "ID�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n";
		system("pause");
		return;
	}
}

void studentMenu() {
	string name;
	int PW;
	system("cls");
	cout << "���̵� �Է��ϼ��� >> ";
	cin >> name;
	cout << "��й�ȣ�� �Է��ϼ��� >> ";
	cin >> PW;
	if (name == Login.find(name)->first && PW == Login.find(name)->second) {	//�̸��� ��й�ȣ�� ��ġ�� �� ����
	restudent:
		system("cls");
		cout << "- Logged in as Student -" << endl;
		cout << "1. View Table" << endl;
		cout << "2. Main Menu" << endl;
		cout << "3. Exit" << endl;

		cout << "\n Enter menu : ";
		switch (input()) {
		case 1:
			viewTableStud(name);
			goto restudent;	//�л� �޴��� ����
		case 2:
			return;
		case 3:
			stop();
		default:
			goto restudent;	//���⿡ ���� �� �����
		}
	}
	else {
		cout << "ID�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n";
		system("pause");
		return;
	}
}

void addStudent() {
	while (true) {
		string name, score, Dptmt, lect;
		int ID, PW;
		student tmp;	//�ӽ� ��ü ����
		system("cls");
		cout << "�л� �̸�(quit�Է� �� ������) >> ";
		cin >> name;
		if (name == "quit")	//quit�Է� �� �Լ� ����.
			break;
		cout << "�й� >> ";
		cin >> ID;
		cout << "�а� >> ";
		cin >> Dptmt;
		cout << "��й�ȣ >> ";
		cin >> PW;
		tmp.setInfo(ID, name, Dptmt,PW);	//�ӽ� ��ü ���� ����
		Login.insert({ name,PW });	//�α��� ���� ����
		while (true) {	//�����Ͽ� �������� �Է�
			system("cls");
			cout << "����(quit�Է� �� ����) : ";
			cin >> lect;
			if (lect == "quit") break;
			cout << "���� : ";
			cin >> score;
			if (cin.fail())	//������ �ƴ� �Է��� ���� ��
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;	//���۸� ���� �����
			}
			tmp.setTable(lect, score);	//�ӽð�ü�� ���� ���� �Է�
		}
		studentList.push_back(tmp);	//�л� ����Ʈ�� �ӽ� ��ü ���� ����
	}
}

void deleteStudent() {
	string name;
	int tmp;
	bool flag = true;
	cout << "������ �л��� �̸��� �Է��ϼ���. >> ";
	cin >> name;

	for (int i = 0; i < studentList.size(); i++) {	//�л� ����Ʈ�� ������
		if (studentList[i].Name == name) {	//�̸��� ���� �л��� ã�� ��
			tmp = i;	//�ӽú����� ��ġ ����
			flag = false;	//�÷��� ����
			break;
		}
	}
	if (flag) {	//�̸��� ���� �л��� ������
		cout << "�л� ���� ����" << endl;
		return;
	}
	studentList.erase(studentList.begin() + tmp);	//�ش� �л� ��Ͽ��� ����
	Login.erase(name);	//�ش� �л��� �α��� ���� ����
}

void viewTableProf() {

	for (auto iter = studentList.begin(); iter != studentList.end(); iter++)	//�л� ����Ʈ�� ������
	{
		cout << "�̸�: " << iter->Name << "\n�й�: " << iter->StudentID << "\n�а�: " << iter->Department << endl;	//�ش� �л����� ���
		for (auto iter2 = iter->classTable.begin(); iter2 != iter->classTable.end(); iter2++)	//�ش� �л��� ���������� ������
		{
			cout << iter2->first << " : " << iter2->second << endl;	//������ ���� ���
		}
		cout << endl;
	}
	system("pause");
}

void viewTableStud(string name) {
	for (auto iter = studentList.begin(); iter != studentList.end(); iter++)
	{
		if (iter->Name == name) {	//�̸��� ���� ��� -> �ڱ� �ڽ���
			for (auto iter2 = iter->classTable.begin(); iter2 != iter->classTable.end(); iter2++)	//���� ���� ������
			{
				cout << iter2->first << " : " << iter2->second << endl;	//������ ���� ���
			}
			break;
		}
	}
	cout << endl;
	system("pause");
}

void readLoginFile() {
	string name, dptmt,lect, score;
	int password, id;
	ifstream file;
	//�α��� ���� �Է�
	file.open("Login.txt");
	if (file.fail()) {
		cerr << "���� ���⿡ �����߽��ϴ�.";
		stop();
	}
	while (!file.eof()) {
		file >> name >> password;	//�α��� ����(�̸�, ��й�ȣ) �б�
		Login.insert({ name,password });	//�α��� ���� map�� ����
	}
	file.close();

	//�л� ���� �Է�
	file.open("info.txt");
	if (file.fail()) {
		cerr << "���� ���⿡ �����߽��ϴ�.";
		stop();
	}
	while (!file.eof()) {
		student tmp;
		name = "";	//�̸� ���� �ʱ�ȭ
		file >> name >> id >> dptmt;
		if (name=="") break;	//�߰������� �Էµ� ���� ������ �б� ����.
		tmp.setInfo(id, name, dptmt, Login.find(name)->second);	//���� ������ �ӽð�ü�� ����
		while (true) {
			file >> lect;	//�� �ܾ� �Է�
			if (lect == "--") break;	//�� �ܾ "--"�� �� �ݺ� ����.
			file >> score;	//�׷��� ������ ���� �Է�

			tmp.setTable(lect, score);	//������ ���� ��ü �������� map�� ����
		}
		studentList.push_back(tmp); //�ӽð�ü������ �л� ����Ʈvector�� ����
	}
	file.close();
}

void writeFile() {
	ofstream file;

	//�α��� ���� �Է�
	file.open("Login.txt");
	if (file.fail()) {
		cout << "���� ���⿡ �����߽��ϴ�.";
		exit(0);
	}
	for (auto iter = Login.begin(); iter != Login.end(); iter++)
	{
		file << iter->first << " " << iter->second << endl; //����ڸ�� ��й�ȣ ����
	}
	file.close();

	//�л� ���� �Է�
	file.open("info.txt");
	if (file.fail()) {
		cout << "���� ���⿡ �����߽��ϴ�.";
		exit(0);
	}
	for (auto iter = studentList.begin(); iter != studentList.end(); iter++)
	{
		file << iter->Name << " " << iter->StudentID << " " << iter->Department << endl;	//�л� �⺻���� �Է�
		for (auto iter2 = iter->classTable.begin(); iter2 != iter->classTable.end(); iter2++)
		{
			file << iter2->first << " " << iter2->second << endl;	//�������� �Է�
		}
		file << "--" << endl;	//��� ���� �Է� �� ������ �Է�
	}
	file.close();
}

void stop() {
	writeFile();	//������ STL�� ����Ǿ��ִ� ������ ���Ͽ� ����
	exit(0);	//���α׷� ����
}

int input() {	//�Է¹޴� �Լ�, ������ ������ �ƴϸ� �Է� ������ ����ó��
	int input;	//�Է� ������ ���� �� ����
	cin >> input;
	if (cin.fail())	//������ �ƴ� �Է��� ���� ��
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return 0;	//���۸� ���� 0��ȯ->�޴� �Լ� ����� ����
	}

	return input;	//�Է°� ��ȯ
}