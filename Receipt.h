#pragma once
#include "Container.h"
#include "ReceiptLine.h"
#include "DateTime.h"
#include "Line.h"

class TReceipt {
private:
	TContainer<TReceiptLine> cont;
	TDateTime time;
	int num;

public:
	TReceipt(int n) { num = n; };

	int find(string code) {
		for (int i = 0; i < cont.get_size(); i++) {
			if (cont[i].get_code() == code) return i;
		}
		return -1;
	}


	void add(TLine& line) {
		int index = find(line.get_code());
		if (index > -1) {
			cont[index]++;
		}
		else {
			TReceiptLine addition(line);
			cont.push_back(addition);
		}
	}


	void del(TLine& line) {
		int index = find(line.get_code());
		if (index > -1) {
			cont[index]--;
			if (cont[index].get_num() == 0) cont.remove(index);
		}
	}

	double get_amount() {
		double total = 0;
		for (int i = 0; i < cont.get_size(); i++) {
			total += cont[i].get_sum();
		}
		return total;
	};

	void print() {
		cout << "Чек #" << num << endl;

		for (int i = 0; i < cont.get_size(); i++) {
			cout << cont[i] << endl;
		}

		cout << endl << "Сумма чека: " << get_amount();
	}

};