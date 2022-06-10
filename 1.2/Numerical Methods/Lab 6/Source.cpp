/*------------------

x + 3y - 2z = 5
3x + 4y - 5z = 6
-2x - 5y + 3x = -13
0x + y - 2z = 4
-2x - 3y + 2z = 10

-------------------*/

#include <iostream>
#include <iomanip>
#include <cmath>

#define n_ 5
#define m_ 3

void printMatrix(double** A, int n, int m);
void printMatrix(double** A, double* B, int n, int m);

void transposingmatrix(double** A, double** At, int n, int m);
double det(double** A);

int main() {

	double baseA[5][3] = {{1, 3, -2}, {3, 4, -5}, {-2, -5, 3}, {0, 1, -2}, {-2, -3, 2}};
	double baseB[5] = { 5, 6, -13, 4, 10 };

	double** A = new double*[n_];
	double* B = new double[n_];
	for (int i = 0; i < n_; i++) {
		B[i] = baseB[i];
		A[i] = new double[m_];
		for (int j = 0; j < m_; j++) {
			A[i][j] = baseA[i][j];
		}
	}
	std::cout << "\t[ Matrix A and B ]" << std::endl;
	printMatrix(A, B, n_, m_);
	
	//------Transposing Matrix A------------//

	double** At = new double*[m_];

	for (int i = 0; i < m_; i++) {
		At[i] = new double[n_];
	}
	transposingmatrix(A, At, n_, m_);

	//---------------End-------------------//

	std::cout << "\t[ Matrix At ]" << std::endl;
	printMatrix(At, m_, n_);
	
	//------------MATRIX N-----------------//


	double** N = new double*[m_];
	double* C = new double[m_];
	for (int i = 0; i < m_; i++)
		N[i] = new double[m_];

	for (int i = 0; i < m_; i++) {
		double sumb = 0;
		for (int j = 0; j < m_; j++) {
			double suma = 0;
			sumb = 0;
			for (int k = 0; k < n_; k++) {
				suma += At[i][k] * A[k][j];
				sumb += At[i][k] * B[k];
			}
			N[i][j] = suma;
		}
		C[i] = sumb;
	}
	//---------------End-------------------//

	std::cout << "\t[ Matrix N and C ]" << std::endl;
	printMatrix(N, C, m_, m_);
	if (det(N) > 0) {
		std::cout << "\nDeterminant N: " << det(N) << std::endl;
	}
	else {
		std::cout << "\nError: determinant N <= 0\nDeterminant N: " << det(N) << std::endl;
		return 1;
	}

	for (int i = 0; i < m_; i++) {
		delete[] At[i];
	}
	delete[] At;

	//-------Method Square roots-----------//

	double** l = new double* [m_];
	double** lt = new double* [m_];
	for (int i = 0; i < m_; i++) {
		l[i] = new double[m_];
		lt[i] = new double[m_];
		for (int j = 0; j < m_; j++) {
			l[i][j] = 0;
			lt[i][j] = 0;
		}
	}


	for (int i = 0; i < m_; i++) {
		double tmp = 0;

		for (int k = 0; k < i; k++)
			tmp += lt[k][i] * lt[k][i];

		lt[i][i] = sqrt(N[i][i] - tmp);

		for (int j = i; j < m_; j++) {
			tmp = 0;

			for (int k = 0; k < i; k++)
				tmp += lt[k][i] * lt[k][j];

			lt[i][j] = (N[i][j] - tmp) / lt[i][i];
		}
	}

	transposingmatrix(lt, l, m_, m_);

	std::cout << "\t[ Matrix l ]" << std::endl;
	printMatrix(l, m_, m_);
	std::cout << "\t[ Matrix lt ]" << std::endl;
	printMatrix(lt, m_, m_);

	std::cout << "L*Y=C" << std::endl;
	double* Y = new double[m_];
	for (int i = 0; i < m_; i++)
		Y[i] = 0;

	for (int i = 0; i < m_; i++) {
		double sum = 0;
		for (int j = 0; j < i; j++) {
			sum += Y[j] * l[i][j];
		}
		Y[i] = (C[i] - sum)/l[i][i];
	}
	std::cout << "[ Y ]" << std::endl;
	for (int i = 0; i < m_; i++)
		std::cout << "Y[" << std::setw(2) << i + 1 << "] = " << std::setw(7) << std::setprecision(-4) << Y[i] << std::endl;

	std::cout << "Lt*X=Y" << std::endl;
	double* X = new double[m_];
	for (int i = 0; i < m_; i++)
		X[i] = 0;

	for (int i = 2; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < 3; j++) {
			sum += X[j] * l[j][i];
		}
		X[i] = (Y[i] - sum) / l[i][i];
	}
	std::cout << "[ X ]" << std::endl;
	for (int i = 0; i < m_; i++)
		std::cout << "X[" << std::setw(2) << i + 1 << "] = " << std::setw(7) << std::setprecision(-4) << X[i] << std::endl;

	std::cout << "Epsilon" << std::endl;

	for (int i = 0; i < 5; i++) {
		double sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += A[i][j] * X[j];
		}
		std::cout << (sum - B[i]) << std::endl;
	}
	//--------Clear Memory-------------//

	for (int i = 0; i < n_; i++)
		delete[] A[i];

	for (int i = 0; i < m_; i++) {
		delete[] N[i];
		delete[] l[i];
		delete[] lt[i];
	}
	delete[] A;
	delete[] B;
	delete[] l;
	delete[] lt;
	delete[] N;
	delete[] C;

	//-----------END---------------//
}

void transposingmatrix(double** A, double** At, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			At[j][i] = A[i][j];
		}
	}
}

double det(double** A) {
		return (A[0][0] * A[1][1] * A[2][2] + A[0][1] * A[2][0] * A[1][2] + A[1][0] * A[2][1] * A[0][2] - (A[0][2] * A[1][1] * A[2][0] + A[0][1] * A[1][0] * A[2][2] + A[0][0] * A[1][2] * A[2][1]));
}

void printMatrix(double** A, double* B, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {

			char znak = '\0';

			if (j == m) {
				znak = '=';
				std::cout << znak << " ";
				std::cout << std::setw(3) << B[i];
			}
			else {
				if (j > 0) {
					((A[i][j]) >= 0) ? znak = '+' : znak = '\0';
				}
				std::cout << znak << " ";
				std::cout << std::setw(5) << A[i][j] << " ";
			}
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void printMatrix(double** A, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char znak = '\0';
				if (j > 0) {
					((A[i][j]) >= 0) ? znak = '+' : znak = '\0';
				}
				std::cout << znak << " ";
				std::cout << std::setw(5) << A[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << std::endl;
}
