#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

#ifdef _WIN32
   #define clear_screen() system ("cls")
   #ifdef _WIN64
   #endif
#elif __APPLE__
    #if TARGET_OS_MAC
		#define clear_screen() system ("clear")
    #endif
#elif __linux__
	#define clear_screen() system ("clear")
#elif __unix__
	#define clear_screen() system ("clear")
#endif

set < string > binary_trees (int n)
{
	string leafNode = "(.)";
	vector < set < string > > dp;
	set < string > newset;
	newset.insert (leafNode);
	dp.push_back (newset);

	for (int i = 1 ; i < n ; i ++)
	{
		newset.clear ();
		for (int j = 0 ; j < i ; j ++)
		{
			for (set < string > ::iterator it1 = dp [j].begin () ; it1 != dp [j].end () ; it1 ++)
			{
			        string leftChild = *it1;
				for (set < string >:: iterator it2 = dp [i - j - 1].begin () ; it2 != dp [i - j - i].end () ; it2 ++)
				{
				        string rightChild = *it2;
					newset.insert ("(" + leftChild + "." + rightChild + ")");
				}
			}
		}
		dp.push_back (newset);
	}
	return dp [n - 1];
}

void print (string x, int n)
{
	char** for_print = new char* [n];
	for (int i = 0 ; i < n ; i ++)
		for_print [i] = new char [2 * n];
	for (int i = 0 ; i < 2 * n - 1 ; i ++)
		for_print [n - 1][i] = (char ('A' + i));
	for_print [n - 1][2 * n - 1] = ('\0');

	for (int i = 0 ; i < n - 1 ; i ++)
	{
		for (int j = 0 ; j < 2 * n - 1 ; j ++)
			for_print [i][j] = (' ');
		for_print [i][2 * n - 1] = ('\0');
	}

	int element = 0;
	int up = n + 1;

	for (int i = 0 ; i < (int)x.size () ; i ++)
	{
//		cout << i << " " << x [i] << endl;
////////for (int i = 0 ; i < n ; i ++)
////////	cout << for_print [i] << endl;
////////cout << "-------------------\n";
		if (x [i] == '(')
			up --;
		else if (x [i] == ')')
			up ++;
		else if (x [i] == '.')
		{
//			cout << i << " " << x [i] << " " << up - 1 << endl;
			swap (for_print [up - 1][element], for_print [n - 1][element]);
			element ++;
//			cout << i << " " << x [i] << " " << up - 1 << endl;
		}
	}

	element = 0;
	for (int i = 0 ; i < (int)x.size () ; i ++)
        if (x [i] == '.')
            x [i] = (char)('A' + (element ++));
    cout << x << endl;
	for (int i = n - 1 ; i >= 0 ; i --)
	{
		cout << for_print [i] << endl;
		delete[] for_print [i];
	}
	delete[] for_print;
	char A;
	cin.get (A);
	clear_screen ();
	return;
	int spaces = -1;
	char letter = 'A';
	for (int i = 0 ; i < (int)x.size () ; i ++)
	{
		if (x [i] == '(')
			spaces ++;
		else if (x [i] == ')')
			spaces --;
		else if (x [i] == '.')
		{
			for (int i = 0 ; i < spaces ; i ++)
				cout << " ";
			cout << letter << "\n";
			letter ++;
		}
	}
	cout << "--------------------------\n";
}

int main ()
{
	int n;
	cin >> n;
	char A;
	cin.get (A);
	set < string > X = binary_trees (n);
	for (set <string>::iterator it = X.begin () ; it != X.end () ; it ++)
		print (*it, n);
}
