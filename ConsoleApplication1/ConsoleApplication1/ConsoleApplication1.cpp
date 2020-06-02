#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "file.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	n = CountBooks();  //Считаем, сколько книжек у нас в файле

	Book* BM = new Book[n]; //Создаём динамический массив под кол-во книг. Массив будет содержать в себе книги в виде структур
	FillBooks(BM, n);       //Заполняем массив данными из файла

	

	return 0;
}

