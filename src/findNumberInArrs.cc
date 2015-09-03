/**
 * @file findNumberInArrs.cc
 * @brief find a number in a two-dimensional array(like thie {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}}
 * @author sunrlong <sunrlong@gmail.com>
 * @version 0.0.1
 * @date 2015-09-03
 */

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

/**
 * @brief findNumberInArrs 
 *
 * @param arrs
 * @param num
 *
 * @return 
 */
bool findNumberInArrs(int** arrs, int rows, int cols, int num){

	int row,col;
	row = 0;
	col = cols-1;
	while(row < rows && col >=0) {
		int a = *((int*)arrs + row*cols + col);//A pionter of a tow-dimensional is not used for addressing by arrs[][] !!!
		if ( num == a /*arrs[row][col] */) {
			cout << "arr["<<row<<"]["<<col<<"]" << " is " << num<< endl;
			return true;
		}
		else if (num > a/*arrs[row][col]*/)
			row++;
		else 
			col--;
	}

	return false;
}

bool findNumberInArrs2(int ** arrs, int rows, int cols, int num) {

	int row,col;
	row = rows - 1;
	col = 0;
	while(row >= 0 && col < cols) {
		int a = *((int*)arrs + row*cols + col);//A pionter of a tow-dimensional is not used for addressing by arrs[][] !!!
		if ( num == a /*arrs[row][col] */) {
			cout << "arr["<<row<<"]["<<col<<"]" << " is " << num<< endl;
			return true;
		}
		else if (num > a/*arrs[row][col]*/)
			col++;
		else 
			row--;
	}
	return false;
}

int main(int argc, char* argv[]){

	int arrs[][4] = {
		{1,2,8,9},
		{2,4,8,12},
		{4,7,10,12},
		{6,8,11,15}
	};

	string str;
	while(getline(cin,str)){
		cout << "find " << str << " in findNumberInArrs result is " << findNumberInArrs((int**)arrs,4,4,std::stoi(str)) << endl;

		cout << "find " << str << " in findNumberInArrs2 result is " << findNumberInArrs2((int**)arrs,4,4,std::stoi(str)) << endl;

	}

	return 0;
}
