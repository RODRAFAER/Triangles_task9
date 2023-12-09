#include <iostream>
#include <cstdlib>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

int proverka(int a) {
	while (cin.fail() || a < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода данных, введите значение заново: ";
		cin >> a;
	}

	return a;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int NMatrix, NRow;

	cout << "Укажите количество треугольников: ";
	cin >> NMatrix;
	NMatrix = proverka(NMatrix);

	cout << "Укажите количество строк в треугольниках: ";
	cin >> NRow;
	NRow = proverka(NRow);

	int NCols = (NRow * 2)-1;

	char** Matrix = new char* [NCols];
	for (int i = 0; i < (NRow); i++) {
		Matrix[i] = new char[NCols];
	}

	int p = 2;
	int x = NCols / 2 + 1;
	int h = NCols / 2;
	for (int i = 0; i < NRow; i++) {
		for (int j = 0; j < NCols; j++) {
			Matrix[i][j] = ' ';
			while (x != h && j == h) {
				Matrix[i][j] = '*';
				h++;
				if (x == h) {
					h = h - p;
					x++;
					p = p + 2;
				}
			}
		}
	}

	//int y1 = 1;
	//int y = 0;
	//for (int i = (NRow-1); i >= 0; i--) {
	//	for (int j = 0; j < NCols/2+1; j++){
	//		while (y < NCols / 2 + 1) {
	//			Matrix[i][y] = '*';
	//			y++;
	//		}
	//	}
	//	y = y1;
	//	y1++;
	//}

	//int y3 = NCols-2;
	//int y2 = NCols-1;
	//for (int i = (NRow-1); i >=0; i--) {
	//	for (int j = NCols-1; j >= NCols/2+1; j--) {
	//		while (y2 > NCols/2) {
	//			Matrix[i][y2] = '*';
	//			y2--;
	//			if (y2 < NCols/2) {
	//				continue;
	//			}
	//		}
	//	}
	//	y2 = y3;
	//	y3--;
	//} 
	

	for (int i1 = 0; i1 < NMatrix; i1++) {
		for (int i = 0; i < NRow; i++) {
			for (int j = 0; j < NCols; j++) {
				cout << Matrix[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}