#include <iostream>
#include <fstream>
#include <string>
#include <string.h>


using namespace std;

//Наша структура
struct Book                     //Это структура, она является цельным элементом, который содержит в себе набор элементов, к которым можно обращаться
{
	int readcode;               //код читателя
	string author_secondname;   //фамилия автора книги
	string author_othername;    //ИО автора книги
	string title;               //название книги
	float price;                //цена книги
};

int CountBooks();
void FillBooks(Book* BM, int n);
void FindTolstoi(Book* BM, int n);
void Find_PriceBooks(Book* BM, int n);



int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	n = CountBooks();  //Считаем, сколько книжек у нас в файле

	Book* BM = new Book[n]; //Создаём динамический массив под кол-во книг. Массив будет содержать в себе книги в виде структур
	FillBooks(BM, n);       //Заполняем массив данными из файла

	cout << "Весь список книг:";  //Выводим на экран заполненный массив
	for (int i = 0; i < n; i++)
		//Т.к. каждый элемент - это структура, то и обращаться к каждому элементу нужно как к структуре
		//то есть сначала находим k-й элемент массива (это структура) и потом обращаемся к его параметру через точку
		cout << endl << BM[i].readcode << "  " << BM[i].author_secondname + " " + BM[i].author_othername << "  " << BM[i].title << "  " << BM[i].price;


	FindTolstoi(BM, n); //Вывод сех книг Толстого

	Find_PriceBooks(BM, n); //Вывод книг по ценнику с условиями из лабораторной

	return 0;
}



//Ищем книги по ценнику (на вход поступает массив структур (массив книг) и кол-во книг)
void Find_PriceBooks(Book* BM, int n)
{
	//Сначала сортируем все книги по фамилиям авторов в алфавитном порядке
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (strcmp(BM[i].author_secondname.c_str(), BM[j].author_secondname.c_str()) < 0) //сравниваем строки. Если они стоят не в алфавитном порядке
				swap(BM[i], BM[j]);                                 //меняем книги местами

	cout << endl << endl << "Список книг меньше 1000, но больше 100 рублей:";
	for (int i = 0; i < n; i++)
		if ((BM[i].price > 100) and (BM[i].price <= 1000))  //Идём по отсортированному массиву книгу и выбираем те книги, которые попадают под условие
			cout << endl << BM[i].readcode << "  " << BM[i].author_secondname + " " + BM[i].author_othername << "  " << BM[i].title << "  " << BM[i].price;
}


//Ищем книжки Толстого
void FindTolstoi(Book* BM, int n)
{
	cout << endl << endl << "Книги Толстого А.А. :";
	for (int i = 0; i < n; i++)
		if (BM[i].author_secondname == "Tolstoi") //Идём по массиву книг. Если нашли книгу Толстого - выводим её
			cout << endl << BM[i].readcode << "  " << BM[i].author_secondname + " " + BM[i].author_othername << "  "
			<< BM[i].title << "  " << BM[i].price;
}

//Считаем кол-во книг в файле данных


	//пока файл не кончится
	while (!file.eof())
	{
		file >> temp.readcode;  //считываем слово до пробела или отсупа на след. строку прямиком в нашу временную переменную-книгу (это будет читательский номер)
		file >> temp.author_secondname;   //так же считываем фамилию автора
		file >> temp.author_othername;    //Так же считываем ИО автора
		file >> temp.title;               //название книги
		file >> temp.price;               //и цену книги

		BM[k] = temp;  //присваиваем элементу массива считанную книгу

		k++;  //Переходим на след. элемент массива
	}

	file.close();  //закрываем файл
}


