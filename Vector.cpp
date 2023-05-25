// Разработать класс Вектор.
// Класс должен хранить вектор целых чисел заданного размера(от 1 до 20).Класс должен предоставлять следующие операции :
// 1) задать размер вектора,
// 2) узнать размер вектора,
// 3) задать компоненту вектора по ее номеру,
// 4) узнать компоненту вектора по ее номеру,
// 5) вычислить длину вектора,
// 6) найти скалярное произведение двух векторов,
// 7) найти сумму двух векторов одного размера.
// Класс должен содержать все необходимые конструкторы, деструктор, оператор присваивания, а также «уметь» выводить себя на консоль.

#include <iostream>
#include <locale>
using namespace std;

class Vector {
private:
	int size;
	int* nums;
public:
	Vector(int size_ = 1) {
		size = size_;
		nums = new int[size];
		for (int i = 0; i < size; i++) nums[i] = 0;
	}

	Vector(const Vector& element) {
		size = element.size;
		nums = new int[size];
		for (int i = 0; i < size; i++) {
			nums[i] = element.nums[i];
		}
	}

	~Vector() {
		delete[] nums;
	}

	void set_size(int new_size) {
		size = new_size;
		nums = new int[size];
		for (int i = 0; i < size; i++) nums[i] = 0;
	}

	int get_size() const {
		return size;
	}

	int& operator[](int i) {
		return nums[i];
	}

	double get_length() {
		int amount = 0;
		for (int i = 0; i < size; i++) {
			amount += nums[i] * nums[i];
		}
		return sqrt(amount);
	}

	const Vector operator+(const Vector& add) {
		if (size != add.size) throw invalid_argument("Не могу сложить векторы разных размеров!");
		Vector result(size);
		for (int i = 0; i < size; i++) {
			result[i] = nums[i] + add.nums[i];
		}
		return result;
	}

	const double operator*(const Vector& mult) const {
		if (this->size != mult.size) throw invalid_argument("Не могу умножить векторы разных размеров!");
		double result = 0;
		for (int i = 0; i < size; i++) {
			result += mult.nums[i] * nums[i];
		}
		return result;
	}

	Vector& operator=(const Vector& equ) {
		size = equ.size;
		nums = new int[size];
		for (int i = 0; i < size; i++) 
			nums[i] = equ.nums[i];
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Vector& vect) {
		os << "{  ";
		for (int i = 0; i < vect.size; i++)
			os << vect.nums[i] << "  ";
		os << "}";
		return os;
	}

};

int main() {
	setlocale(LC_CTYPE, "ru");
	Vector a(2), b(2);
	a.set_size(5);
	for (int i = 0; i < 5; i++) a[i] = (i + 1) * (i + 1);
	cout << "Vector Size: " << a.get_size() << endl;
	cout << "a[2] = " << a[2] << endl;
	a[3] = 12345678;
	cout << "a[3] = " << a[3] << endl;
	a.set_size(2);
	a[0] = 4;
	a[1] = 3;
	b[0] = 1;
	b[1] = -1;
	cout << "Vector Length: " << a.get_length() << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " + " << b << " = " << (a + b) << endl;
	a = b;
	cout << a << endl << b;



	return 0;
}