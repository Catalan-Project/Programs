#include <iostream>
#include <string>

using namespace std;

int n;
int variant = 1;

void all (int opened, int closed, string a, string letter = "A")
{ 
//	cout << opened << " " << closed << " " << a << ";" << endl;
	if (opened == n and closed == n)
	{
		cout << variant ++ << ") " << a << "\n";
		return ;
	}
	if (opened + closed == 2 * n)
	{
		return ;
	}
	if (opened == closed)
	{
		string next = letter;
		next [0] ++;
		all (opened + 1, closed, a + "(" + letter, next);
	}
	if (opened < closed)
		return ;
	if (opened > closed)
	{
		string next = letter;
		next [0] ++;
		all (opened + 1, closed, a + "(" + letter, next);
		all (opened, closed + 1, a + ")", letter);
	}
}

int main ()
{
	cout << "How many scopes have to using? ";
	cin >> n;
	all (0, 0, "");
}
