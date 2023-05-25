#pragma once
#include "Product.h"
#include "Line.h"
#include <iostream>
using namespace std;

class TReceiptLine {
private:
	TProduct prod;
	int num;
	double sum;
public:
	TReceiptLine() {}

	TReceiptLine(TProduct& prod_, int num_) {
		prod = prod_;
		num = num_;
		sum = prod.get_cost() * num;
	}

	TReceiptLine(TLine& line_) {
		prod = line_.get_prod();
		num = line_.get_num();
		sum = num * line_.get_cost();
	}

	TProduct get_prod() const {
		return prod;
	}

	string get_code() const {
		return prod.get_code();
	}

	int get_num() const {
		return num;
	}

	double get_sum() const {
		return sum;
	}

	friend ostream& operator<<(ostream& out, const TReceiptLine& dt) {
		string sep = "     ";
		out << dt.get_prod().get_line() << sep << dt.num << sep << dt.sum;
		return out;
	}

	void operator--(int i) {
		num--;
		sum -= prod.get_cost();
	}

	void operator++(int i) {
		num++;
		sum += prod.get_cost();
	}
};