#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int n;

string arr [1000];

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

void print (string a)
{
	for (int i = 0 ; i < n + 5 ; i ++)
		arr [i] = string (2 * n, ' ');
	int x = 0, y = 0;
	arr [0][0] = a [0];
	for (int i = 1 ; i < (int)a.size () ; i ++)
	{
		if (a [i - 1] == '/')
		{
			if (a [i] == '/')
			{
				x ++, y ++;
			}
			else if (a [i] == '\\')
			{
				x ++;
			}
		}
		else if (a [i - 1] == '\\')
		{
			if (a [i] == '\\')
			{
				x ++, y --;
			}
			else if (a [i] == '/')
			{
				x ++;
			}
		}
		arr [y][x] = a [i];
	}
	for (int i = n - 1 ; i >= 0 ; i --)
		cout << arr [i] << endl;
	for (int i = 0 ; i < 2*n ; i ++)
	   cout << '#';
	cout << endl;
	char AA;
	cin.get (AA);
	clear_screen ();
}

void all (int opened, int closed, string a)
{ 
	if (opened == n and closed == n)
	{
		print (a);
		return ;
	}
	if (opened + closed == 2 * n)
	{
		return ;
	}
	if (opened == closed)
		all (opened + 1, closed, a + "/");
	if (opened < closed)
		return ;
	if (opened > closed)
	{
		all (opened + 1, closed, a + "/");
		all (opened, closed + 1, a + "\\");
	}
}

int main ()
{
	cout << "How many scopes have to using? ";
	cin >> n;
	string a;
	getline (cin, a);
	all (0, 0, "");
}
