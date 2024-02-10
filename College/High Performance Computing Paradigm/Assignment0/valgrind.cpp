#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to multiply a matrix with a vector
vector<double> multiply(const vector<vector<double>>& M, const vector<double>& v) {
	int size = v.size();
	vector<double> result(size, 0.0);

	for (int i = 0; i < size; ++i) {
    	for (int j = 0; j < size; ++j) {
        	result[i] += M[i][j] * v[j];
    	}
	}
	return result;
}

// Function to calculate the norm of a vector
double norm(const vector<double>& v) {
	double sum = 0.0;
	for (double i : v) {
    	sum += i * i;
	}
	return sqrt(sum);
}

// Power Iteration to find the largest eigenvalue and its eigenvector
void powerIteration(const vector<vector<double>>& M, vector<double>& eigenVector, double& eigenValue, int maxIterations, double tolerance) {
	vector<double> b_k = eigenVector;
	vector<double> b_k1;

	for (int i = 0; i < maxIterations; ++i) {
    	b_k1 = multiply(M, b_k);
    	eigenValue = norm(b_k1);
   	 
    	// Normalize b_k1
    	for (double& val : b_k1) {
        	val /= eigenValue;
    	}

    	// Check for convergence
    	double error = 0.0;
    	for (int j = 0; j < b_k.size(); ++j) {
        	error += abs(b_k1[j] - b_k[j]);
    	}

    	if (error < tolerance) {
        	break;
    	}

    	b_k = b_k1;
	}

	eigenVector = b_k1;
}

int main() {
	const int N = 5;  // Matrix size
	vector<vector<double>> M(N, vector<double>(N));
	srand(static_cast<unsigned>(time(nullptr)));

	// Initialize with random values
	for (int i = 0; i < N; ++i) {
    	for (int j = 0; j <= i; ++j) {
        	M[i][j] = M[j][i] = static_cast<double>(rand()) / RAND_MAX;
    	}
	}

	// Initial vector for Power Iteration
	vector<double> eigenVector(N);
	for (double& val : eigenVector) {
    	val = static_cast<double>(rand()) / RAND_MAX;
	}

	double eigenValue = 0.0;
	powerIteration(M, eigenVector, eigenValue, 1000, 1e-6);

	cout << "Approximate largest eigenvalue: " << eigenValue << endl;
	cout << "Corresponding eigenvector: [";
	for (int i = 0; i < N; ++i) {
    	cout << eigenVector[i];
    	if (i < N - 1) cout << ", ";
	}
	cout << "]" << endl;

	return 0;
}