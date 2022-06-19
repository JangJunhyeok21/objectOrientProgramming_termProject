#include "header.h"

void run();
void readLoginFile();

int main()
{
	readLoginFile(); //로그인 정보가 담긴 파일을 불러옴.
	run();	//프로그램 실행
}