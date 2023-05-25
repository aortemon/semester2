#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class TProduct {
	public:
		string code;
		string name;
		double cost;
		TProduct(string code_="000", string name_="NO_NAME", double cost_=0.00) {
			code = code_;
			name = name_;
			cost = cost_;
		}

		string get_code() const {
			return code;
		}

		double get_cost() const {
			return cost;
		}

		string get_name() const {
			return name;
		}

		string get_line() {
			string sep = "     ";
			ostringstream sstream;
			sstream << cost;
			string result = code + sep + name + sep + sstream.str();
			return result;
		}

		friend ostream& operator<<(ostream& out, const TProduct& dt) {
			char sep = ';';
			out << dt.code << sep << dt.name << sep << dt.cost;
			return out;
		}
}; 