#include "pch.h"
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	BinarySearchTree<int> a;int inta, int1a;
	BinarySearchTree<double> b; double doubleb, double1b;
	BinarySearchTree<float> c; float floatc, float1c;

	int ch, vibor;
	cout << "Введите тип данных:" << endl;
	cout << "[1]-> Инт." << endl;
	cout << "[2]-> Флоат." << endl;
	cout << "[3]-> Дабл." << endl;
	cin >> vibor;

//	system("cls");
	while (1)
	{

		cout << " Выберите действие. " << endl;
		cout << " [1]-> Заполнение элементов дерева[По одному]. " << endl;
		cout << " [2]-> Вывод элементов заполненного дерева[Сортировка по возр-ю]. " << endl;
		cout << " [3]-> Удаление элементов дерева. " << endl;
		cout << " [4]-> Найти элемент в дереве." << endl;
		cout << " [5]-> Выход из программы. " << endl;
		cout << " Введите цифру: ";
		cin >> ch;
		switch (ch)
		{
		case 1:

			cout << " Заполните один элемент: ";
			if (vibor == 1) {
				cin.ignore(1);
				cin >> inta;
				b.insert(inta); system("cls");
			}if (vibor == 2) {
				cin.ignore(1);
				cin >> doubleb;
				b.insert(doubleb); system("cls");
			}if (vibor == 3) {
				cin.ignore(1);
				cin >> floatc;
				b.insert(floatc); system("cls");
			}break;

		case 2: cout << endl;
			cout << " Выведенное дерево: " << endl;
			b.print_inorder(); system("pause"); system("cls");
			break;
		case 3:
			if (vibor == 1) {
				cout << " Введите данные для удаления: ";
				cin.clear();
				cin.ignore(1);
				cin >> int1a;
				b.remove(int1a);
			}if (vibor == 2) {
				cout << " Введите данные для удаления: ";
				cin.clear();
				cin.ignore(1);
				cin >> double1b;
				b.remove(double1b);
			}if (vibor == 3) {
				cout << " Введите данные для удаления: ";
				cin.clear();
				cin.ignore(1);
				cin >> float1c;
				b.remove(float1c);
			}break;
		case 4:
		{
			cout << "Введите цифру для проверки её наличия : ";
			cin.ignore(1);
			cin >> doubleb;
			b.search(doubleb);
		}break;
	/*	case 5:
		{
			cin.ignore(1);
			b.vivod(doubleb);
		}break;*/
		case 5:
			return 0;
			break;
		}
	//	system("cls");
	}
}