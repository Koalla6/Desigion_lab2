#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int read_file(double x[14]) {
	ifstream in("condition.txt");
	if (in.is_open())
	{

		//Считаем матрицу из файла
		for (int i = 0; i < 14; i++)
				in >> x[i];

		//Выведем матрицу
		for (int i = 0; i < 14; i++)
		{
				cout << x[i] << "\t";
		}
		cout << endl << endl;
		in.close();//под конец закроем файла
		return *x;
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Файл не знайдено.";
	}
}

int OV(double x[14], int *i, double res1[2]) {
	double ov;
	//cout << *i << endl;
	ov = (x[1] * x[12] + x[3] * x[13]) * 4 - x[0];
	res1[*i] = ov;
	//cout << "(" <<x[1] <<" * " <<x[12] << " + " <<x[8] <<" * "<< x[13] <<") *"<< 4 <<" - " << x[0] << endl;
	cout << "Очiкування i великий завод: \t" << res1[*i] << endl;
	*i=*i+1;
	//cout << *i << endl;
	return 0;
}

int OM(double x[14], int *i, double res1[2]) {
	//cout << *i << endl;
	double om;
	om = (x[6] * x[12] + x[8] * x[13]) * 4 - x[5];
	res1[*i] = om;
	cout << "Очiкування i маленький завод: \t" << res1[*i] << endl;
	*i = *i + 1;
	return 0;
}

int better_o(double res1[2], double *max) {
	if (res1[0] >= res1[1])
		*max = res1[0];
	else
		*max = res1[1];
	return 0;
}

int V(double x[14], int *j, double res[3]) {
	double v;
	v = (x[1] * x[2] + x[8] * x[4]) * 5 - x[0];
	res[*j] = v;
	cout << "Великий завод: \t\t\t" << res[*j] << endl;
	*j = *j + 1;
	return 0;
}

int M(double x[14], int *j, double res[3]) {
	double v;
	v = (x[6] * x[2] + x[3] * x[4]) * 5 - x[5];
	res[*j] = v;
	cout << "Маленький завод: \t\t" << res[*j] << endl;
	*j = *j + 1;
	return 0;
}

int O(double x[14], int *j, double res[3], double max) {
	double v;
	v = max + (x[10] * 0 * 1 + x[11] * 0 * 1) - 0;
	res[*j] = v;
	cout << "Очiкування i збiр iнформацiї: \t" << res[*j] << endl;
	*j = *j + 1;
	return 0;
}

int better_all(double res[3]) {
	double max=0;
	for (int i = 0; i < 3; i++) {
		if (max < res[i])
			max = res[i];
	}
	cout << max << endl << endl;
	return 0;
}

void main()
{
	setlocale(LC_ALL, "Ukrainian");
	double x[14], res1[2], res[3], max=0;
	int i = 0, j  =0;

	read_file(x);
	OV(x, &i, res1);
	//cout << i << endl;
	OM(x, &i, res1);
	V(x, &j, res);
	M(x, &j, res);
	better_o(res1, &max);
	O(x, &j, res, max);
	cout << endl << "Найбiльш оптимальним рiшенням даної задачi є : ";
	better_all(res);

	system("pause");
}
