// Разработать класс Матрица.
// Класс должен хранить квадратную матрицу целых чисел заданного размера(от 2 до 8 строк). Класс должен предоставлять следующие операции:
// 1) задать размер матрицы,
// 2) узнать размер матрицы,
// 3) задать элемент матрицы по его индексам,
// 4) узнать элемент матрицы по его индексам,
// 5) проверить, обладает ли матрица диагональным преобладанием,
// 6) вычислить сумму двух матриц одного размера.
// Класс должен содержать все необходимые конструкторы, деструктор, оператор присваивания, а также «уметь» выводить себя на консоль.


#include <iostream>
using namespace std;


class Matrix {
	private:
		int size;
		int** nums;
	public:
		Matrix(int n = 3) {
			size = n;
			nums = new int*[n];
			for (int i = 0; i < size; i++) 
				nums[i] = new int[n];
			for (int i = 0; i < size; i++) 
				for (int j = 0; j < size; j++)
					nums[i][j] = 0;
		}

		Matrix(const Matrix& matr) {
			size = matr.size;
			nums = new int* [size];
			for (int i = 0; i < size; i++) {
				nums[i] = new int[size];
				for (int j = 0; j < size; j++)
					nums[i][j] = matr.nums[i][j];
			}
		}


		~Matrix() {
			for (int i = 0; i < size; i++) 
				delete[] nums[i];
			delete[] nums;
		}

		void set_size(int n) {
			size = n;
			nums = new int* [n];
			for (int i = 0; i < size; i++)
				nums[i] = new int[n];
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					nums[i][j] = 0;
		}

		int get_size() const {
			return size;
		}

		int* operator[](int i) {
			return nums[i];
		}

		bool is_DDM() const {
			bool is_strong = false;
			for (int i = 0; i < size; i++) {
				int amount = 0;
				for (int j = 0; j < size; j++) {
					if (i != j) amount += nums[i][j];
				}
				if (nums[i][i] < amount) return false;
				else if (nums[i][i] > amount) is_strong = true;
			}
			return true && is_strong;
		}

		Matrix operator+(const Matrix& add) {
			if (size != add.size) throw invalid_argument("Не умею складывать матрицы разных размеров!");

			Matrix result(size);

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++) 
					result.nums[i][j] = nums[i][j] + add.nums[i][j];
			return result;
		}

		Matrix& operator=(const Matrix& mtrx) {
			size = mtrx.size;
			nums = new int* [size];
			for (int i = 0; i < size; i++) {
				nums[i] = new int[size];
				for (int j = 0; j < size; j++)
					nums[i][j] = mtrx.nums[i][j];
			}
		}

		friend ostream& operator<<(ostream& os, const Matrix& mtrx) {
			for (int i = 0; i < mtrx.size; i++) {
				for (int j = 0; j < mtrx.size; j++)
					os << mtrx.nums[i][j] << "  ";
				os << endl;
			}
			return os;
		}
};

int main() {
	Matrix A(2);
	Matrix B(3);

	A.set_size(3);

	cout << "A Matrix Size: " << A.get_size() << endl;

	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) {
			A[i][j] = i * 3 + j;
			B[i][j] = 9 - i * 3 - j;
		}
	

	cout << "A Matrix:" << endl << A << endl;
	cout << "B Matrix:" << endl << B << endl;
	cout << "A + B Matrix: " << endl << A + B << endl;


	Matrix C = A + B;

	C[0][0] = 18;
	C[1][1] = 18;
	C[2][2] = 18;



	cout << "C = A + B, C[x][x] = 18, x=1,2,3" << endl;
	cout << C << endl;
	cout << "Is C DD Matrix: " << C.is_DDM();




	return 0;
}