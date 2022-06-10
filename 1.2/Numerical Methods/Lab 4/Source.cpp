//0.62*a + 0.56*b - 0.43*c = 1.16
//1.32*a - 0.88*b + 1.76*c = 2.07
//0.73*a + 1.42*b - 0.34*c = 2.18

//0.62 + 0.56 - 0.43      a      1.16
//1.32 - 0.88 + 1.76   *  b   =  2.07
//0.73 + 1.42 - 0.34      c      2.18

#include <iostream>
#include <iomanip>
#include <cmath>
#define size 4

char checkTask(char choise);

void printMatrix(double **matrix, int n, int m);//print syandard matrix result

void methodGauss(double **inputMatrix, int n, int m);

void methodLU(double **mainA, double *mainB, int n, int m);

int main() {

	char choise = ' ';

	std::cout << "Custom matrix - U\nStandard " << size << "x" << size << " matrix - S\nClose - E" << std::endl;//menu

	while ((choise = checkTask(choise)) != 'E') {
		switch (choise) {
		case 'U': {			//custom matrix
			int n, m;
			std::cout << "Enter the amount of x: ";
			std::cin >> n;
			m = n + 1;

			double** matrix = new double*[n];
			double** a = new double* [n];
			double* b = new double [n];

			for (int i = 0; i < n; i++) {

				matrix[i] = new double[m];
				a[i] = new double[n];

				for (int j = 0; j < m; j++) {

					std::cout << "Enter " << i + 1 << " row " << j + 1 << " column matrix element" << std::endl;
					std::cin >> (matrix[i][j]);
					if (j < n) {
						std::cin >> (a[i][j]);
					}
					else {
						std::cin >> (b[i]);
					}
				}
			}

			printMatrix(matrix, n, m);

			methodGauss(matrix, n, m);
			methodLU(a, b, n, m);

			break;
		}
		case 'S': {	//standart matrix
			//double solveMatrix[size] = { 1.16, 2.07, 2.18 }, mainMatrixMemory[size][size] = { {0.62, 0.56, -0.43},{1.32, -0.88, 1.76},{0.73, 1.42, -0.34} };
			
			double solveMatrix[size] = { 0.64, -1.42, 0.42, -0.83 };
			double mainMatrixMemory[size][size] = {
				{0.81, 0.12, -0.34, -0.16},
				{0.34, -1.08, 0.17, -0.18},
				{0.16, 0.34, 0.75, -0.31},
				{0.12, -0.26, -0.08, 0.68} };

			double** matrix = new double* [size];
			double** a = new double* [size];
			double* b = new double[size];

			for (int i = 0; i < size; i++) {
				matrix[i] = new double[size+1];
				a[i] = new double[size];
				b[i] = solveMatrix[i];
				for (int j = 0; j <= size; j++) {
					if (j == size) {
						matrix[i][j] = solveMatrix[i];
					}
					else {
						matrix[i][j] = mainMatrixMemory[i][j];
						a[i][j] = mainMatrixMemory[i][j];
					}
				}
			}

			std::cout << "Standart Matrix" << std::endl;
			printMatrix(matrix, size, size+1);

			methodGauss(matrix, size, size + 1);
			methodLU(a, b, size, size);
			break;
		}
		default: {	//try again
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

void printMatrix(double **matrix, int n, int m) {
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char znak = '\0';
			if (j > 0) {
				( (matrix[i][j]) >= 0 ) ? znak = '+' : znak = '\0';
				if (j == n) {
					znak = '=';
				}
				std::cout << znak << " ";
			}
			std::cout << std::setw(5) << std::setprecision(4) << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "--------------------------------------------------" << std::endl;
}

void methodGauss(double **inputMatrix, int n, int m) {

	std::cout << "\nGauss method\n" << std::endl;

	double** methodMatrix =  new double* [n];
	for (int i = 0; i < n; i++) {
		methodMatrix[i] = new double[m];
		for (int j = 0; j < m; j++) {
			methodMatrix[i][j] = inputMatrix[i][j];
		}
	}

	double* x = new double [n];

	double c;
	for (int row = 0; row < n-1 ; row++) {
		std::cout << "\nThe " << row+1 << "th row" << std::endl;
		for (int i = row+1; i < n; i++) {
			c = methodMatrix[i][row] / methodMatrix[row][row];
			for (int j = 0; j < m; j++) {
				methodMatrix[i][j] = (methodMatrix[i][j] - (methodMatrix[row][j] * c));

				if (fabs(methodMatrix[i][j]) <= 0.000001) { 
					methodMatrix[i][j] = 0;
				}
			}
		}
		printMatrix(methodMatrix, n, m);
	}

	double s;
	for (int i = n - 1; i >= 0; i--)
	{
		s = 0;
		for (int j = i + 1; j < n; j++) {
			s = s + methodMatrix[i][j] * x[j];
		}
		x[i] = ((methodMatrix[i][m-1] - s) / methodMatrix[i][i]);
	}

	std::cout << "\nThe solution is:\n";
	for (int i = 0; i < n; i++)
		std::cout << "x[" << std::setw(2) << i + 1 << "] =" << std::setw(7) << std::setprecision(4) << x[i] << std::endl;

	for (int i = 0; i < n; i++)
		free(methodMatrix[i]);

}


void methodLU(double **a, double *b, int n, int m) {

	std::cout << "\nLU method\n" << std::endl;

	double** A = new double* [n];
	double** L = new double* [n];
	double** U = new double* [n];

	for (int i = 0; i < n; i++) {

		A[i] = new double[m];
		L[i] = new double[m];
		U[i] = new double[m];

		for (int j = 0; j < m; j++) {

			A[i][j] = a[i][j];

			L[i][j] = 0;
			(i==j) ? U[i][j] = 1 : U[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		L[i][0] = A[i][0];
		U[0][i] = A[0][i] / L[0][0];
	}

	double sum;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {

			if (i >= j) {
				sum = 0;

				for (int k = 0; k < j; k++) {
					sum = sum + (L[i][k] * U[k][j]);
				}

				L[i][j] = A[i][j] - sum;
			}
			else {
				sum = 0;
				for (int k = 0; k < i; k++) {
					sum = sum + (L[i][k] * U[k][j]);
				}
				U[i][j] = (A[i][j] - sum) / L[i][i];
			}
		}
	}
	std::cout << "A" << std::endl;
	printMatrix(A, n, m);
	std::cout << "L" << std::endl;
	printMatrix(L, n, m);
	std::cout << "U" << std::endl;
	printMatrix(U, n, m);

	double* Y = new double[n];
	Y[0] = b[0] / L[0][0];
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < i; j++) {
			sum = sum + L[i][j] * Y[j];
		}
		Y[i] = (b[i] - sum) / L[i][i];
	}

	std::cout << "\nY-matrix\n";
	for (int i = 0; i < n; i++)
		std::cout << "Y[" << std::setw(2) << i + 1 << "] =" << std::setw(7) << std::setprecision(4) << Y[i] << std::endl;

	double* X = new double[n];
	for (int i = n - 1; i >= 0; i--) {
		sum = 0;
		for (int j = i + 1; j < n; j++) {
			sum = sum + U[i][j] * X[j];
		}
		std::cout << Y[i] << " - " << sum;
		X[i] = Y[i] - sum;
	}
	std::cout << "\nThe solution is:\n";
	for (int i = 0; i < n; i++)
		std::cout << "X[" << std::setw(2) << i + 1 << "] =" << std::setw(7) << std::setprecision(4) << X[i] << std::endl;
}