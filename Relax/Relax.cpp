#include <iostream>
#include <math.h>
#include "TMatrix.h"
#include "DirichleT.h"
#include <vector>

//  Переправить парсер
//  Размерность, границы по х и у

int main()
{
	system("chcp 1251");
	system("cls");
	//  Границы по х и у
	TVector<double> xBorder(2), yBorder(2);
	//  Размерности х и у соответсвенно
	int n, m;
	xBorder[0] = 1;
	xBorder[1] = 2;
	yBorder[0] = 2;
	yBorder[1] = 3;
	cout << "Введите размерность сетки (сначала по x, потом по y)\n";
	cin >> n;
	cin >> m;




	DirichleT subject(n, m, xBorder, yBorder, 4);
	TVector<double> eps(2);
	TVector<int> iterations(2);
	eps[0] = pow(10, -8);
	eps[1] = pow(10, -8);
	iterations[0] = 1000;
	iterations[1] = 1000;

	eps = subject.MethodAccuracy(eps, iterations);
	//eps = subject.MethodError(eps[0], iterations[0]);

	

	cout << eps << endl;

	subject.OutputFile(n, m, xBorder, yBorder);

	system("pause");
	return 0;
}
