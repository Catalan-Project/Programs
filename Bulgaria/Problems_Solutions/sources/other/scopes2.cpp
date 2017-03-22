#include <iostream>
#include <string>

using namespace std;

int n;
int variant = 1;

void all (int opened, int closed, string a)
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
		all (opened + 1, closed, a + "(");
	}
	if (opened < closed)
		return ;
	if (opened > closed)
	{
		all (opened + 1, closed, a + "(");
		all (opened, closed + 1, a + ")");
	}
}

int main ()
{
	cout << "How many scopes have to using? ";
	cin >> n;
	all (0, 0, "");
}
