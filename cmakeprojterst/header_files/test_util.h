#pragma once
#include "test_util.h"
#include "util.h"
#include <vector>
#include <stdio.h>
#include <string>

inline void testMatrixRotation() {
	auto cmparr = [](std::vector<int> &arr, std::vector<int> &arr2){
		if (arr.size() != arr2.size()) {
			printf("can't compare unequal sized arrays\n");
			return false;
		}

		for (int i = 0; i < arr.size(); i++) {
			if (arr.at(i) != arr2.at(i)) {
				//maybe print call stack here?
				return false;
			}
		}
		return true;
	};

	int matdata[] = {
		1, 2, 3, 4, 5,
		6, 7, 8, 9,10,
		11,12,13,14,15,
		16,17,18,19,20,
		21,22,23,24,25,
	};

	int test[] = {
		1, 2, 3, 4, 5,
		6, 7, 8, 9,10,
		11,12,13,14,15,
		16,17,18,19,20,
		21,22,23,24,25,
	};

	int clockwise[]  = {
		21, 16, 11, 6, 1, 
		22, 17, 12, 7, 2,
		23, 18, 13, 8, 3,
		24, 19, 14, 9, 4,
		25, 20, 15, 10, 5,
	};

	int counterclockwise[] = {
		5, 10, 15, 20, 25,
		4, 9, 14, 19, 24,
		3, 8, 13, 18, 23,
		2, 7, 12, 17, 22,
		1, 6, 11, 16, 21
	};

	{
		auto test_mat = Matrix(5,5, test);
		auto clockwise_mat = Matrix(5, 5, clockwise);
		rotateMatrix(&test_mat, ROT_DIR::CLOCKWISE);
		std::string teststr = test_mat.toString();

		std::string expectedstr = clockwise_mat.toString();

		std::string clockwise_result = cmparr(test_mat.data, clockwise_mat.data)? "PASSED": "FAILED";
		printf("CLOCKWISE TEST %s\n", clockwise_result.c_str());
		printf("GOT\n%s \n\n", teststr.c_str());
		printf("EXPECTED\n%s \n\n", expectedstr.c_str());
	}
	{
		auto test_mat = Matrix(5, 5, test);
		rotateMatrix(&test_mat, ROT_DIR::COUNTERCLOCKWISE);
		std::string teststr = test_mat.toString();
		auto counterclockwise_mat = Matrix(5, 5,counterclockwise);
		std::string expectedstr = counterclockwise_mat.toString();

		std::string counterclockwise_result = cmparr(test_mat.data, counterclockwise_mat.data)? "PASSED": "FAILED";
		printf("COUNTER CLOCKWISE TEST %s\n", counterclockwise_result.c_str());
		printf("GOT\n%s \n\n", teststr.c_str());
		printf("EXPECTED\n%s \n", expectedstr.c_str());
	}
}
