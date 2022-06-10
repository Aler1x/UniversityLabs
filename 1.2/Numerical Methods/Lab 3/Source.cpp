//0.62*a + 0.56*b - 0.43*c = 1.16
//1.32*a - 0.88*b + 1.76*c = 2.07
//0.73*a + 1.42*b - 0.34*c = 2.18

//0.62 + 0.56 - 0.43      a      1.16
//1.32 - 0.88 + 1.76   *  b   =  2.07
//0.73 + 1.42 - 0.34      c      2.18

//n - column
//m - row

#include <iostream>
#include <cmath>
#define size 3

char checkTask(char choise);

void printResult(double matrix[size][size], double solveMatrix[size], double X[size]);

double determinant(double matrix[size][size]);
double det(double minorMatrix[size-1][size-1]);
double minor(double matrix[size][size], int row, int column);

void matrixMethod(double matrix[size][size], double solveMatrix[size]);

void kramerMethod(double matrix[size][size], double solveMatrix[size]);

int main() {

	double solveMatrix[size] = {1.16, 2.07, 2.18}, matrix[size][size] = {{0.62, 0.56, -0.43},{1.32, -0.88, 1.76},{0.73, 1.42, -0.34}};//standart matrix
	int sizeMatrix = size;//size of matrix

	char choise = ' ';

	std::cout << "Custom 3x3 matrix - U\nStandart 3x3 matrix - S\nClose - E" << std::endl;//menu

	while ((choise = checkTask(choise)) != 'E') {
		switch (choise) {
		case 'U':{			//custom matrix

			for (int i = 0; i < size; i++) {
				for (int j = 0; j <= size; j++) {
					std::cout << "Enter " << i + 1 << " row " << j+1 << " column matrix element" << std::endl;
					if (j != size) {
						std::cin >> matrix[i][j];
					}
					else {
						std::cin >> solveMatrix[i];
					}
				}
			}

			std::cout << "Your Matrix\n" << matrix[0][0] << "x " << matrix[0][1] << "y " << matrix[0][2] << "z\t = " << solveMatrix[0] << "\n"
				<< matrix[1][0] << "x " << matrix[1][1] << "y " << matrix[1][2] << "z\t = " << solveMatrix[1] << "\n"
				<< matrix[2][0] << "x " << matrix[2][1] << "y " << matrix[2][2] << "z\t = " << solveMatrix[2] << std::endl;

			if (solveMatrix[0] == 0 && solveMatrix[1] == 0 && solveMatrix[2] == 0) {
				std::cout << "\nMatrix homogeneous" << std::endl;
				double x[size] = { 0, 0, 0 };
				printResult(matrix, solveMatrix, x);
				break;
			}
			else {
				matrixMethod(matrix, solveMatrix);
				kramerMethod(matrix, solveMatrix);
			}
			break;
		}
		case 'S': {	//standart matrix
			std::cout << "Standart Matrix\n" << matrix[0][0] << "x + " << matrix[0][1] << "y " << matrix[0][2] << "z\t" << solveMatrix[0] << "\n"
				<< matrix[1][0] << "x " << matrix[1][1] << "y + " << matrix[1][2] << "z\t" << solveMatrix[1] << "\n"
				<< matrix[2][0] << "x + " << matrix[2][1] << "y " << matrix[2][2] << "z\t" << solveMatrix[2] << std::endl;

			matrixMethod(matrix, solveMatrix);
			kramerMethod(matrix, solveMatrix);
			break;
		}
		default:{	//try again
			if (choise != '\n') {
				std::cout << "Not correct sumbol" << std::endl;
			}
			break;
		}
		}
	}
	
	return 0;
}

char checkTask(char choise) {
	std::cin >> choise;
	return choise;
}

void printResult(double matrix[size][size], double solveMatrix[size], double X[size]) {
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << matrix[0][0] << "*" << X[0] << " " << matrix[0][1] << "*" << X[1] << " " << matrix[0][2] << "*" << X[2] << "   " << solveMatrix[0] << "\n"
		<< matrix[1][0] << "*" << X[0] << " " << matrix[1][1] << "*" << X[1] << " " << matrix[1][2] << "*" << X[2] << " = " << solveMatrix[1] << "\n"
		<< matrix[2][0] << "*" << X[0] << " " << matrix[2][1] << "*" << X[1] << " " << matrix[2][2] << "*" << X[2] << "   " << solveMatrix[2] << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "x = " << X[0] << "\ny = " << X[1] << "\nz = " << X[2] << std::endl;
}

double determinant(double matrix[size][size]) {
	return (matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[2][0] * matrix[1][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] - (matrix[0][2] * matrix[1][1] * matrix[2][0] + matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][0] * matrix[1][2] * matrix[2][1]));
}

double det(double minorMatrix[size-1][size-1]) {
	return (minorMatrix[0][0] * minorMatrix[1][1] - minorMatrix[1][0] * minorMatrix[0][1]);
}

double minor(double matrix[size][size], int row, int column) {
	int subi = 0, subj = 0;
	double subMatrix[size-1][size-1];
	for (int i = 0; i < size; i++)
	{
		if (i != row)
		{
			for (int j = 0; j < size; j++)
			{
				if (j != column)
				{
					subMatrix[subi][subj] = matrix[i][j];
					subj++;
				}
			}
			subi++;
			subj = 0;
		}
	}
	double minor = ((row + column) % 2 == 0) ? det(subMatrix) : -det(subMatrix);
	std::cout << "Minor " << row + 1 << " row " << column + 1 << " column = " << minor << std::endl;
	return minor;
}

void matrixMethod(double matrix[size][size], double solveMatrix[size]) {
	if (determinant(matrix) == 0) {
		std::cout << "Determinant = 0\nMatrix was singular" << std::endl;
		return;
	}
	double a[size][size], aTemp[size][size], x[size];

	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = minor(matrix, i, j);
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			aTemp[i][j] = a[j][i];
		}
	}
	
	double detA = determinant(matrix);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = (aTemp[i][j]/detA);
		}
	}

	std::cout << "\nInverse matrix\n" << a[0][0] << " " << a[0][1] << " " << a[0][2] << "\n"
		<< a[1][0] << " " << a[1][1] << " " << a[1][2] << "\n"
		<< a[2][0] << " " << a[2][1] << " " << a[2][2] << std::endl;

	for (int i = 0; i < size; i++) {
		x[i] = a[i][0] * solveMatrix[0] + a[i][1] * solveMatrix[1] + a[i][2] * solveMatrix[2];
	}
	std::cout << "\nMatrix method result" << std::endl;
	printResult(matrix, solveMatrix, x);
}

void kramerMethod(double matrix[size][size], double solveMatrix[size]) {
	if (determinant(matrix) == 0) {
		std::cout << "Determinant = 0\nMatrix was singular" << std::endl;
		return;
	}

	double a[size][size], x[size];
	double detA = determinant(matrix);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				if (k == i) {
					a[j][k] = solveMatrix[j];
				}
				else {
					a[j][k] = matrix[j][k];
				}
			}
		}
		x[i] = determinant(a) / detA;
	}

	std::cout << "\nMethod Kramera result" << std::endl;
	printResult(matrix, solveMatrix, x);
}