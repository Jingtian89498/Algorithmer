#include <iostream>

using namespace std;

long karatsuba(long num1, long num2);

int main()
{
	long x = 1234;
	long y = 5678;
	long z = karatsuba(x, y);
	cout << z << endl;
	cout << x * y << endl;
}

long karatsuba(long num1, long num2)
{
	if ((num1 < 10) || (num2 < 10))
		return num1 * num2;
	int i = 1;
	int j = 1;
	int max;
	long x1, x0, y1, y0, z2, z1,z0;
	long a = num1;
	long b = num2;
	while (a /= 10) i++;
	while (b /= 10) j++;
	if (i >= j)
		max = i;
	else
		max = j;

	int pow10 = int(pow(10, max / 2));

	x1 = num1 / pow10;
	x0 = num1 % pow10;
	y1 = num2 / pow10;
	y0 = num2 % pow10;

	z0 = karatsuba(x0, y0);
	z1 = karatsuba((x1 + x0), (y1 + y0));
	z2 = karatsuba(x1, y1);
	return (z2 * int(pow(10, (2 * (max / 2)))) + (z1 - z2 - z0) * int(pow(10, max / 2)) + z0);

}

