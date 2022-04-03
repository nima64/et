#include "util.h"
#include <cmath>
#include <vector>
#include <string>
#include <functional>

Matrix::Matrix(int w, int h) : width{ w }, height{ h } {
	data.resize(w* h, 0); 
}

Matrix::Matrix(int w, int h, int arr[]) : width{ w }, height{ h }, data{ arr, arr + h*w} {
}

std::string Matrix::toString()
{
	std::string s{};
	for (int i=1; i <= this->data.size(); i++) {
		std::string space_newln = (i % this->width == 0 && i != this->data.size()) ? ",\n": ", ";
		s += std::to_string(this->data.at(i-1)) + space_newln;
	}
	return s;
}

int Matrix::getIndex(int col, int row) {
	return col + row * width;
} 

//std::string matToStr(Matrix *mat) {
//	std::string s{};
//	for (int i=1; i <= mat->data.size(); i++) {
//		std::string space_newln = (i % mat->width == 0 && i != mat->data.size()) ? ",\n": ", ";
//		s += std::to_string(mat->data.at(i-1)) + space_newln;
//	}
//	return s;
//}

//std::string matToStr(std::vector<int> mat, int matlen) {
//	std::string s{};
//	for (int i=1; i <= mat.size(); i++) {
//		std::string space_newln = (i % matlen == 0 && i != mat.size()) ? ",\n": ", ";
//		s += std::to_string(mat.at(i-1)) + space_newln;
//	}
//	return s;
//}

void rotateMatrix(Matrix *mat, ROT_DIR dir) { 
	double dmat_len = std::sqrt(mat->data.size());
	int mat_len = (int)dmat_len;

	if (mat->height != mat->width){
		printf("ERROR rotateMatrix requires a square matrix!\n You provided a matrix of width: %d height: %d \n", mat->width, mat->height);
		return;
	}

	auto horz_flip = [](Matrix* mat) {
		for (int row = 0; row < mat->height; row++) {
			for (int col = 0; col < mat->width / 2; col++) {
				int idx = mat->getIndex(col, row);
				auto oppidx = mat->getIndex(mat->width - col - 1, row);
				std::swap(mat->data.at(idx), mat->data.at(oppidx));
			}
		}
	};

	//diagonally swaps from left to right
	auto diag_swap = [](Matrix *mat) {
		for (int row = 0; row < mat->height; row++) {
			for (int col = row; col < mat->width; col++) {
				auto idx = mat->getIndex(col, row);
				auto oppidx = mat->getIndex(row, col);
				std::swap(mat->data.at(idx), mat->data.at(oppidx));
			}
		}
	};

	if (dir == ROT_DIR::CLOCKWISE) {
		diag_swap(mat);
		horz_flip(mat);
	} else {
		horz_flip(mat);
		diag_swap(mat);
	}
}











 //void rotmatrix(std::vector<int>* mat, ROT_DIR dir) {
//	double dmat_len = std::sqrt(mat->size());
//	int mat_len = (int)dmat_len;
//
//
//	if (mat->size() % mat_len != 0) {
//		printf("ERROR rotmatrix requires a square matrix!\n You provided a matrix of len %2f \n", dmat_len);
//		return;
//	}
//
//	auto get_index = [mat_len](int col, int row) { return col + row * mat_len; };
//
//	auto horz_flip = [&get_index](std::vector<int>* mat, int matlen) {
//		for (int row = 0; row < matlen; row++) {
//			for (int col = 0; col < matlen / 2; col++) {
//				int idx = get_index(col, row);
//				auto oppidx = get_index(matlen - col - 1, row);
//				std::swap(mat->at(idx), mat->at(oppidx));
//			}
//		}
//	};
//
//	//diagonally swaps from left to right
//	auto diag_swap = [&get_index](std::vector<int>* mat, int matlen) {
//		for (int row = 0; row < matlen; row++) {
//			for (int col = row; col < matlen; col++) {
//				auto idx = get_index(col, row);
//				auto oppidx = get_index(row, col);
//				std::swap(mat->at(idx), mat->at(oppidx));
//			}
//		}
//	};
//
//	if (dir == ROT_DIR::CLOCKWISE) {
//		diag_swap(mat, mat_len);
//		horz_flip(mat, mat_len);
//	} else {
//		horz_flip(mat, mat_len);
//		diag_swap(mat, mat_len);
//	}
//}
