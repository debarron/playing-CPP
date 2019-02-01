// Matrix.h
// debarron

#include <ostream>
using namespace std;

class Matrix{
private:
	int _rows, _cols;
	int **_values;

public:
	Matrix();
	Matrix(int rows, int cols);
	void setValue(int row, int col, int value){_values[row][col] = value;}
	int getValue(int row, int col){return _values[row][col];}
	int getCols(){return _cols;}
	int getRows(){return _rows;}
	void print(ostream &out);
};

void Matrix::print(ostream &out){
	for (int i = 0; i < _rows; i++){
		for (int j = 0; j < _cols; j++){
			out << _values[i][j] << " ";
		}
		out << '\n';
	}
}

Matrix::Matrix(){
	_rows = 0;
	_cols = 0;
}

Matrix::Matrix(int rows, int cols){
	_rows = rows;
	_cols = cols;

	_values = new int*[_rows];
	for(int i = 0; i < _rows; i++)
		_values[i] = new int[_cols];

}