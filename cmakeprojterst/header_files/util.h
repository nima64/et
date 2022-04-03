#pragma once
#include <vector>
#include <string>

enum class ROT_DIR {
	CLOCKWISE = 1,
	COUNTERCLOCKWISE = 2
};

class Matrix {
	public:
	const int width;
	const int height;
	std::vector<int> data;
	Matrix(int w, int h); 
	Matrix(int w, int h, int arr[] ); 
	std::string toString();
	int getIndex(int col, int row);
};

void rotateMatrix(Matrix* mat, ROT_DIR dir);
//void rotmatrix(std::vector<int>* square_mat, ROT_DIR dir);
//std::string matToStr(std::vector<int> mat, int matlen);
std::string matToStr(Matrix* mat);


