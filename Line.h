#pragma once
#include "Product.h"


class TLine {
	private:
		TProduct prod;
		int num;
	public:
		TLine() {}

		TLine(TProduct& prod_, int num_) {
			prod = prod_;
			num = num_;
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

		double get_cost() const {
			return prod.get_cost();
		}

		friend ostream& operator<<(ostream& out, const TLine& dt) {
			char sep = ';';
			out << dt.prod << sep << dt.num << sep;
			return out;
		}

		void operator--(int i) {
			num--;
		}

		void operator++(int i) {
			num++;
		}
};