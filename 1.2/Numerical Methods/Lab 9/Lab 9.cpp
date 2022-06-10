#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<double>> TMatrix(vector<vector<double>> A) {
    vector<vector<double>> At(A.size(), vector<double>(A.size()));

    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[i].size(); j++) {
            At[j][i] = A[i][j];
        }
    }
    return At;
}

vector<double> SqrtRootMethod(vector<vector<double>> N) {
	const int size = N.size();

	vector<vector<double>> l(size, vector<double>(size));
	vector<vector<double>> lt(size, vector<double>(size));

	for(int i = 0; i < size; i++) {
		double tmp = 0;

		for(int k = 0; k < i; k++) {
			tmp += lt[k][i] * lt[k][i];
		}

		lt[i][i] = sqrt(N[i][i] - tmp);

		for(int j = i; j < size; j++) {
			tmp = 0;

			for(int k = 0; k < i; k++)
				tmp += lt[k][i] * lt[k][j];

			lt[i][j] = (N[i][j] - tmp) / lt[i][i];
		}
	}

	l = TMatrix(lt);

	vector<double> Y(size);					//search Y

	for(int i = 0; i < size; i++) {
		double sum = 0;
		for(unsigned j = 0; j < i; j++) {
			sum += Y[j] * l[i][j];
		}
		Y[i] = (N[i].back() - sum) / l[i][i];
	}
	
	vector<double> X(size);					//search X

	for(int i = 0; i < size; i++)
		X[i] = 0;

	for(int i = size-1; i >= 0; i--) {
		double sum = 0;

		for(int j = i + 1; j < size; j++) {
			sum += X[j] * l[j][i];
		}

		X[i] = (Y[i] - sum) / l[i][i];
	}

	return X;
}

void PrintMatrix(vector<vector<double>> E) {
	cout << noshowpos;
	for(int i = 0; i < E.size(); ++i) {
		for(int j = 0; j < E[i].size(); ++j)
			cout << fixed << setprecision(2) << setw(7) << E[i][j];
		cout << endl;
	}
}

void PrintPolinome(vector<double> pol) {
	cout << endl << fixed << setprecision(3) << setw(8) << "Polynome: ";

	for(int i = 0; i < pol.size(); i++)
		cout << showpos << pol[i] << " * X^" << noshowpos << i << " ";

	cout << noshowpos << endl;
}

void MinSqrtMethod(vector<double> X, vector<double> Y, int m) {

	int n = X.size();

    vector<vector<double>> slarNormal(m + 1, vector<double>(m+2));

	for(int k = 0; k < m + 1; k++) {
		for(int j = 0; j < m + 1; j++) {
			for(int i = 0; i < n; i++) {
				slarNormal[k][j] += pow(X[i], j + k);
			}
		}
		for(int i = 0; i < n; i++) {
			slarNormal[k][m + 1] += Y[i] * pow(X[i], k);
		}
	}
	cout << endl << "              [ Normal Matrix ]              " << endl;
	PrintMatrix(slarNormal);

	vector<double> pol = SqrtRootMethod(slarNormal);
	PrintPolinome(pol);
}

int main() {
    cout << "===========[ Tabular function V2 ]===========" << endl <<
            "X | 0.15 | 0.20 | 0.25 | 0.30 | 0.40 | 0.50 |" << endl <<
            "Y | 4.48 | 5.47 | 6.05 | 7.39 | 8.11 | 9.93 |" << endl <<
            "=============================================" << endl;

    vector<double> X = { 0.15, 0.20, 0.25, 0.30, 0.40, 0.50 };
    vector<double> Y = { 4.48, 5.47, 6.05, 7.39, 8.11, 9.93 };

	//vector<double> X = { -3, -1, 0, 1, 3};
	//vector<double> Y = { -4, -0.8, 1.6, 2.3, 1.5};

	cout << endl << "=============[ Linear Polynome ]=============" << endl;
	MinSqrtMethod(X, Y, 1);
	cout << "=============================================" << endl;

	cout << endl << "=============[ Square Polynome ]=============" << endl;
	MinSqrtMethod(X, Y, 2);
	cout << "=============================================" << endl;

	cout << endl << "=============[ Cubical Polynome ]============" << endl;
	MinSqrtMethod(X, Y, 3);
	cout << "=============================================" << endl;

    return 0;
}

