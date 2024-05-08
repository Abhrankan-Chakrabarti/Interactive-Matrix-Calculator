#include <iostream>
using namespace std;
class matrix
{
  public:
	int m, n, arr[10][10];
	void readorder();
	friend ostream &operator<<(ostream &, const matrix &);
	friend istream &operator>>(istream &, matrix &);
	matrix operator+(matrix);
	matrix operator-(matrix);
	matrix operator*(matrix);
	matrix operator*(int scalar);
	matrix operator/(int scalar);
	matrix transpose();
};
void printchar(char c, int n)
{
	for (; n > 0; --n)
		cout << c;
}
void printjoin(char c, const char *s)
{
	cout << *s;
	for (++s; *s != '\0'; ++s)
		cout << c << *s;
}
void printchoices(const char *choices)
{
	int i;
	for (i = 0; *choices != '\0'; ++choices)
	{
		if (!i)
			cout << ++i << ". " << *choices;
		else if (*choices == '.')
			cout << '.' << endl
				 << ++i << ". ";
		else
			cout << *choices;
	}
	cout << '.' << endl;
}
int main()
{
	matrix A, B, result;
	int ch, scalar;
	do
	{
		printchar('*', 13);
		cout << " ";
		printjoin(' ', "MATRIX");
		cout << "  ";
		printjoin(' ', "CALCULATOR");
		cout << " ";
		printchar('*', 13);
		cout << endl;
		printchoices("Matrix addition.Matrix subtraction.Matrix multiplication.Multiply by a scalar.Divide by a scalar.Transpose of a matrix.Exit");
		cout << "Enter your choice :\t";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "For matrix A :" << endl;
			A.readorder();

			cout << "For matrix B :" << endl;
			B.readorder();

			if (A.m != B.m || A.n != B.n)
			{
				cout << "Matrices must be of the same size for addition." << endl;
				break;
			}

			cout << "For matrix A :" << endl;
			cin >> A;

			cout << "For matrix B :" << endl;
			cin >> B;

			cout << "Matrix A :" << endl;
			cout << A;

			cout << "Matrix B :" << endl;
			cout << B;

			cout << "Result of addition :" << endl;
			result = A + B;
			cout << result;
			break;

		case 2:
			cout << "For matrix A :" << endl;
			A.readorder();

			cout << "For matrix B :" << endl;
			B.readorder();

			if (A.m != B.m || A.n != B.n)
			{
				cout << "Matrices must be of the same size for subtraction." << endl;
				break;
			}

			cout << "For matrix A :" << endl;
			cin >> A;

			cout << "For matrix B :" << endl;
			cin >> B;

			cout << "Matrix A :" << endl;
			cout << A;

			cout << "Matrix B :" << endl;
			cout << B;

			cout << "Result of subtraction :" << endl;
			result = A - B;
			cout << result;
			break;

		case 3:
			cout << "For matrix A :" << endl;
			A.readorder();

			cout << "For matrix B :" << endl;
			B.readorder();

			if (A.n != B.m)
			{
				cout << "The number of columns in matrix A must be equal to the number of rows in matrix B for multiplication." << endl;
				break;
			}

			cout << "For matrix A :" << endl;
			cin >> A;

			cout << "For matrix B :" << endl;
			cin >> B;

			cout << "Matrix A :" << endl;
			cout << A;

			cout << "Matrix B :" << endl;
			cout << B;

			cout << "Result of multiplication :" << endl;
			result = A * B;
			cout << result;
			break;

		case 4:
			cout << "For matrix A :" << endl;
			A.readorder();

			cout << "Enter the scalar :\t";

			cin >> scalar;

			cout << "For matrix A :" << endl;
			cin >> A;

			cout << "Matrix A :" << endl;
			cout << A;

			cout << "Result of scalar multiplication :" << endl;
			result = A * scalar;
			cout << result;
			break;

		case 5:
			cout << "For matrix A :" << endl;
			A.readorder();

			cout << "Enter the scalar :\t";

			cin >> scalar;

			if (scalar == 0)
			{
				cout << "Cannot divide by zero." << endl;
				break;
			}

			cout << "For matrix A :" << endl;
			cin >> A;

			cout << "Matrix A :" << endl;
			cout << A;

			cout << "Result of scalar division :" << endl;
			result = A / scalar;
			cout << result;
			break;

		case 6:
			cout << "For matrix A :" << endl;
			A.readorder();
			cin >> A;

			cout << "Matrix A :" << endl;
			cout << A;

			cout << "Result of transposition :" << endl;
			result = A.transpose();
			cout << result;
			break;

		case 7:
			cout << "Exiting..." << endl;
			break;

		default:
			cout << "Invalid choice." << endl;
		}
	} while (ch != 7);
	return 0;
}

void matrix::readorder()
{
	cout << "Enter the no. of rows :\t";
	cin >> m;
	cout << "Enter the no. columns :\t";
	cin >> n;
}

istream &operator>>(istream &os, matrix &ptr)
{
	int i, j;
	cout << "Enter the items :" << endl;
	for (i = 0; i < ptr.m; i++)
	{
		for (j = 0; j < ptr.n; j++)
		{
			os >> ptr.arr[i][j];
		}
	}
	return os;
}

ostream &operator<<(ostream &ob, const matrix &pt)
{
	int i, j;

	for (i = 0; i < pt.m; i++)
	{
		for (j = 0; j < pt.n; j++)
		{
			ob << "\t" << pt.arr[i][j];
		}
		ob << endl;
	}
	return ob;
}

matrix matrix::operator+(matrix B)
{
	int i, j;
	matrix result;
	result.m = m, result.n = n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			result.arr[i][j] = arr[i][j] + B.arr[i][j];
		}
	}
	return result;
}

matrix matrix::operator-(matrix B)
{
	int i, j;
	matrix result;
	result.m = m, result.n = n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			result.arr[i][j] = arr[i][j] - B.arr[i][j];
		}
	}
	return result;
}

matrix matrix::operator*(matrix B)
{
	int i, j, k;
	matrix result;
	result.m = m, result.n = B.n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < B.n; j++)
		{
			result.arr[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				result.arr[i][j] += arr[i][k] * B.arr[k][j];
			}
		}
	}
	return result;
}

matrix matrix::operator*(int scalar)
{
	int i, j;
	matrix result;
	result.m = m, result.n = n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			result.arr[i][j] = arr[i][j] * scalar;
		}
	}
	return result;
}

matrix matrix::operator/(int scalar)
{
	int i, j;
	matrix result;
	result.m = m, result.n = n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			result.arr[i][j] = arr[i][j] / scalar;
		}
	}
	return result;
}

matrix matrix::transpose()
{
	int i, j;
	matrix result;
	result.m = n, result.n = m;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			result.arr[j][i] = arr[i][j];
		}
	}
	return result;
}