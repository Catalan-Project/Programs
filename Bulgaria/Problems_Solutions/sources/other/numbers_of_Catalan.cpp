#include <iostream>
#include "./gmp/gmpxx.h"

using namespace std;

using T = mpz_class;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	string str;
	cin >> str;

	T X (str);

	for (T n = 1 ; n <= X ; n = n + 1)
	{
		T current_number = 1;
		for (T i = n + 2 ; i <= 2 * n ; i = i + 1)
			current_number = current_number * i;
		for (T i = 2 ; i <= n ; i ++)
			current_number = current_number / i;
		
		cout << n << ") " << current_number << "\n";
	}
}

//g++ name.cpp -o name.exe -std=c++11 -lgmpxx -lgmp
