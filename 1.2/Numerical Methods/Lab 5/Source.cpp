//0.81 + 0.12 - 0.34 - 0.16 = 0,64
//0.34 -  1.08 + 0.17 -  0.18 = -1.42
//0.16 + 0.34 + 0.75 - 0.31  = 0.42
//0.12 - 0.26 - 0.08 + 0.68 = -0.83

#include <iostream>
#include <iomanip>
#include <cmath>

#define SIZE 3

void printMatrix(double **A, double *B, int n);

bool convergence(double **A, double **Alpha, int size);

void methodJacobi(double **a, double *b, int n, double eps);

void methodZeydelya(double** A, double* B, int size, double eps);

int main() {

	std::cout << "Custom matrix - U\nStandard 3x3 matrix - S\nClose - E" << std::endl;//menu

	for (char choise = '\n'; choise != 'E'; std::cin >> choise) {
		switch (choise) {
		case 'U': {			//custom matrix
			int n, m;
			std::cout << "Enter the amount of x: ";
			std::cin >> n;

			double** a = new double* [n];
			double* b = new double[n];

			for (int i = 0; i < n; i++) {

				a[i] = new double[n];

				for (int j = 0; j < n + 1; j++) {

					if (j < n) {

						std::cout << "Enter " << i + 1 << " row " << j + 1 << " column A-matrix element" << std::endl;
						std::cin >> (a[i][j]);
					}
					else {
						std::cout << "Enter " << i + 1 << " row B-matrix element" << std::endl;
						std::cin >> (b[i]);
					}
				}
			}

			double eps;
			std::cout << "Enter eps:" << std::endl;
			std::cin >> eps;

			printMatrix(a, b, n);

			methodJacobi(a, b, n, eps);
			methodZeydelya(a, b, n, eps);
			break;
		}
		case 'S': {	//standart matrix
			double solveMatrix[SIZE] = { 8.7 , 13.7 , 6.02};
			//double mainMatrixMemory[SIZE][SIZE] = {{3.2, -1.5, 6.9} ,{-2, 8, -1},{3, 0.9, 1.1}};
			double mainMatrixMemory[SIZE][SIZE] = {
				{3, 0.9, 1.1},
				{-2, 8, -1},
				{3.2, -1.5, 6.9} };

			double** a = new double* [SIZE];
			double* b = new double[SIZE];

			for (int i = 0; i < SIZE; i++) {
				a[i] = new double[SIZE];
				b[i] = solveMatrix[i];
				for (int j = 0; j < SIZE; j++) {
						a[i][j] = mainMatrixMemory[i][j];
				}
			}

			double eps;
			std::cout << "Enter eps: ";
			std::cin >> eps;

			std::cout << "Standart Matrix" << std::endl;
			printMatrix(a, b, SIZE);

			methodJacobi(a, b, SIZE, eps);
			methodZeydelya(a, b, SIZE, eps);

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

void printMatrix(double **A, double *B, int n) {
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {

			char znak = '\0';

			if (j == n) {
				znak = '=';
				std::cout << znak << " ";
				std::cout << std::setw(5) << std::setprecision(4) << B[i];
			}
			else {
				if (j > 0) {
					((A[i][j]) >= 0) ? znak = '+' : znak = '\0';
				}
				std::cout << znak << " ";
				std::cout << std::setw(5) << std::setprecision(4) << A[i][j] << " ";
			}

		}
		std::cout << "\n";
	}
	std::cout << "--------------------------------------------------" << std::endl;
}

bool convergence(double **A, double **Alpha, int size) {

	
	bool  bCheck = false;

	std::cout << "Norma 1" << std::endl;
	double dCheck = 0;
	for (int i = 0; i < size; i++) {
		dCheck = 0;
		for (int j = 0; j < size; j++) {
			dCheck += fabs(Alpha[i][j]);
		}
		bCheck = (dCheck <= 1) ? true : false;
		std::cout << dCheck << " < 1" << std::endl;
	}

	std::cout << "\nNorma 2" << std::endl;
	for (int i = 0; i < size; i++) {
		dCheck = 0;
		for (int j = 0; j < size; j++) {
				dCheck += fabs(Alpha[j][i]);
		}
		bCheck = (dCheck <= 1) ? true : false;
		std::cout << dCheck << " < 1" << std::endl;
	}

	std::cout << "\nNorma 3" << std::endl;
	for (int i = 0; i < size; i++) {
		dCheck = 0;
		for (int j = 0; j < size; j++) {
			if (i != j) {
				dCheck = (Alpha[i][j] * Alpha[i][j]);
			}
		}
		bCheck = (sqrt(dCheck) <= 1) ? true : false;
		std::cout << sqrt(dCheck) << " < 1" << std::endl;
	}

	//--------------------------------------------------------
	
	//std::cout << "Naslidok 1.1" << std::endl;
	//dCheck = 0;
	//for (int i = 0; i < size; i++) {
	//	dCheck = 0;
	//	for (int j = 0; j < size; j++) {
	//		dCheck += fabs(Alpha[i][j]);
	//	}
	//	bCheck = (dCheck <= 1) ? true : false;
	//	std::cout << dCheck << " < 1" << std::endl;
	//}

	//std::cout << "Naslidok 2.1" << std::endl;
	//for (int i = 0; i < size; i++) {
	//	dCheck = 0;
	//	for (int j = 0; j < size; j++) {
	//		if(i!=j)
	//			dCheck += fabs(A[i][j]);
	//	}
	//	bCheck = (dCheck <= fabs(A[i][i])) ? true : false;
	//	std::cout << dCheck << " < " << fabs(A[i][i]) << std::endl;
	//}
	
	//--------------------------------------------------------

	std::cout << "\n" << std::endl;
	return bCheck;
}

void methodJacobi(double **A, double *B, int size, double eps) {
	std::cout << "\nJacobi method\n" << std::endl;
	double** Alpha = new double* [size];
	//--------------------------------------------------------
	for (int i = 0; i < size; i++) {
		Alpha[i] = new double[size];
		for (int j = 0; j < size; j++) {
			Alpha[i][j] = (i != j) ? (-(A[i][j] / A[i][i])) : 0;
		}
	}
	//--------------------------------------------------------

	double* Beta = new double [size];
	//--------------------------------------------------------
	for (int i = 0; i < size; i++) {
		Beta[i] = (B[i] / A[i][i]);
	}
	//--------------------------------------------------------

	if (!convergence(A, Alpha, size)) {
		std::cout << "Matrix not convergence" << std::endl;
		return;
	}

	printMatrix(Alpha, Beta, size);

	double* X1 = new double[size];
	double* X0 = new double[size];
	for (int i = 0; i < size; i++) {
		X1[i] = Beta[i];
	}

	int itr = 0;
	double max;
	double sum;
	std::cout << "Iter" << std::setw(10) << "X1" << std::setw(10) << "X2" << std::setw(10) << "X3" << std::setw(10) << "X4" << std::endl;

		do {
			for (int i = 0; i < size; i++) {
				sum = 0;
				for (int j = 0; j < size; j++) {
					sum += Alpha[i][j] * X1[j];
				}
				X0[i] = Beta[i] + sum;
			}

			max = fabs(X0[0] - X1[0]);
			for (int i = 1; i < size; i++)
			{
				if (fabs(X0[i] - X1[i]) > max)
					max = fabs(X0[i] - X1[i]);
			}
			for (int i = 0; i < size; i++) {
				X1[i] = X0[i];
			}

			std::cout << std::setw(4) << itr + 1 << " | ";
			for (int i = 0; i < size; i++) {
				std::cout << std::setw(8) << std::setprecision(-4) << X1[i] << " | ";
			}
			std::cout << "\n";

			itr++;
		} while (max >= eps);
		
	std::cout << "\n\nIterations: " << itr << std::endl;
	std::cout << "The solution is:\n";
	for (int i = 0; i < size; i++)
		std::cout << "X[" << std::setw(2) << i + 1 << "] = " << std::setw(7) << std::setprecision(-4) << X1[i] << std::endl;
}

void methodZeydelya(double** A, double* B, int size, double eps) {
	std::cout << "\nMethod Zeydelya\n" << std::endl;
	double** Alpha = new double* [size];
	//--------------------------------------------------------
	for (int i = 0; i < size; i++) {
		Alpha[i] = new double[size];
		for (int j = 0; j < size; j++) {
			Alpha[i][j] = (i != j) ? (-(A[i][j] / A[i][i])) : 0;
		}
	}
	//--------------------------------------------------------

	double* Beta = new double[size];
	//--------------------------------------------------------
	for (int i = 0; i < size; i++) {
		Beta[i] = (B[i] / A[i][i]);
	}
	//--------------------------------------------------------

	if (!convergence(A, Alpha, size)) {
		std::cout << "Matrix not convergence" << std::endl;
		return;
	}

	printMatrix(Alpha, Beta, size);

	double* X0 = new double[size];
	double* X1 = new double[size];
	for (int i = 0; i < size; i++) {
		X1[i] = Beta[i];
	}

	int itr = 0;
	double max;
	double sum;
	std::cout << "Iter" << std::setw(10) << "X1" << std::setw(10) << "X2" << std::setw(10) << "X3" << std::setw(10) << "X4" << std::endl;
	do {
		for (int i = 0; i < size; i++) {
			for (int i = 0; i < size; i++) {
				X0[i] = X1[i];
			}
			X1[i] = Beta[i];
			for (int j = i + 1; j < size; j++) {
				 X1[i] += Alpha[i][j] * X1[j];
			}
			for (int j = 0; j <= i-1 ; j++) {
				X1[i] += Alpha[i][j] * X0[j];
			}

		}

		max = 0;
		for (int i = 0; i < size; i++)
		{
			if (fabs(X0[i] - X1[i]) > max)
				max = fabs(X0[i] - X1[i]);
		}

		std::cout << std::setw(4) << itr + 1 << " | ";
		for (int i = 0; i < size; i++) {
			std::cout << std::setw(8) << std::setprecision(-4) << X1[i] << " | ";
		}
		std::cout << "\n";

		itr++;
	} while (max >= eps);

	std::cout << "\n\nIterations: " << itr << std::endl;
	std::cout << "The solution is:\n";
	for (int i = 0; i < size; i++)
		std::cout << "X[" << std::setw(2) << i + 1 << "] = " << std::setw(7) << std::setprecision(-4) << X1[i] << std::endl;
}