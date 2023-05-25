#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include "Container.h"
#include "DateTime.h"
#include "Product.h"
#include "Line.h"
#include "Matrix.h"
#include "ReceiptLine.h"
#include "Receipt.h"
using namespace std;

const string PATH = "mtrx.txt";

int main() {
	setlocale(LC_CTYPE, "ru");
	TMatrix mtrx = TMatrix();
	mtrx._import(PATH);

	int session_receipt_num = 1;
	bool is_run = true;
	bool is_receipt = false;

	while (is_run) {
		cout << string(81, '=') << endl;
		cout << "1. Новый чек" << endl << "2. Выход" << endl << endl;
		string answer;
		cin >> answer;
		if (answer == "1") {
			cout << endl << "Вы выбрали: Новый чек" << endl << endl;
			is_receipt = true;
			TReceipt rec(session_receipt_num);
			cout << "Введите код товара или одну из команд:" << endl << "/sum - для вывода суммы чека" << endl << "/del - для удаление позиции" << endl << "/close - для закрытия чека" << endl;
			while (is_receipt) {
				cout << endl;
				cin >> answer;
				if (answer == "/sum") cout << fixed << setprecision(2) << "Сумма чека: " << rec.get_amount() << endl;
				else if (answer == "/del") {
					cout << "Введите код товара, который нужно удалить: ";
					cin >> answer;
					try {
						rec.del(mtrx.get(answer));
						mtrx.get(answer)++;
						cout << "Успешно удален \"" << mtrx.get(answer).get_prod() << "\"!" << endl;
					}
					catch (const invalid_argument& e) { cout << "Такого кода нет в матрице!" << endl; }
				}
				else if (answer == "/close") {
					session_receipt_num++;
					cout << endl;
					rec.print();
					cout << endl << endl;
					is_receipt = false;
					mtrx._export(PATH);
				}
				else {
					try {
						if (mtrx.get(answer).get_num() > 0) {
							mtrx.get(answer)--;
							cout << mtrx.get(answer).get_prod() << endl;
							rec.add(mtrx.get(answer));
						}
						else cout << "Товар \"" << mtrx.get(answer).get_prod().get_name() << "\" закончился!" << endl;
					}
					catch (const invalid_argument& e) { cout << "Такого кода нет в матрице, попробуйте снова." << endl; }
				}
			}
		}
		else is_run = false;
	}

	mtrx._export(PATH);
	return 0;
}