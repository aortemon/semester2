#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Container.h"
#include "Product.h"
#include "Line.h"

using namespace std;

class TMatrix {
public:
	TContainer<TLine> cont;
	TMatrix();

	void _import(std::string path);
	void _export(std::string path);
	TLine& get(std::string code);
};

TMatrix::TMatrix() {}

void TMatrix::_import(string path) {
	ifstream file(path);
	TContainer<TLine> new_cont(10, 5);
	string line = string('a', 120);
	char sep = ';';
	while (getline(file, line)) {
		stringstream stream(line);
		string code, name, price, n;
		getline(stream, code, sep);
		getline(stream, name, sep);
		getline(stream, price, sep);
		getline(stream, n, sep);
		double cost = atof(price.c_str());
		int qty = stoi(n);
		TProduct prod(code, name, cost);
		TLine another(prod, qty);
		cont.push_back(another);
	}
	file.close();
}


void TMatrix::_export(string path) {
	ofstream file;
	file.open(path);
	if (file.is_open()) {
		for (int i = 0; i < (cont).get_size(); i++) {
			file << (cont)[i] << endl;
		}
	}
	else cout << "An error occured during opening file...";
	file.close();
}

TLine& TMatrix::get(string code) {
	for (int i = 0; i < (cont).get_size(); i++) {
		if ((cont)[i].get_code() == code) {
			return (cont)[i];
		}
	}
	throw invalid_argument("Value cannot be found");
}