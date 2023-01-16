#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <vector>
using std::vector;

class Matrix {
	private:
		// Student's implementation
        vector<vector<int> > mat;
        
	public:
		Matrix();
		Matrix(const Matrix& other);
		~Matrix();
		Matrix& operator=(const Matrix& other);
		void file_to_matrix(char* filename);
		void matrix_to_file(char* filename);

		// Task 1
		std::vector<int> multiply_vector(std::vector<int> B);
		int count_mults(std::vector<int> B);
		int count_adds(std::vector<int> B);

		// Task 2
		Matrix multiply(Matrix B);
		Matrix transpose();
		int count_mults(Matrix B);
		int count_adds(Matrix B);
		bool is_multipliable(Matrix B);

		// Task 3
		Matrix kronecker(Matrix B);
		int count_mults_kron(Matrix B);
};

#endif  // MATRIX_H