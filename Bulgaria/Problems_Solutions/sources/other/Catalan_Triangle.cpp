#include "catalan_triangle/catalan_triangle_row.h"
#include <iostream>
int main() {
  int n, m;
  std::cout << "Number of last line: ";
  std::cin >> n;
  std::cout << "\n";
  std::cout << "Length of first line: ";
  std::cin >> m;
  std::cout << "\n";
  std::vector<mpz_class> row;
  mpz_class _0 = 0;
  mpz_class _1 = 1;
  for (int i = 0 ; i < m ; i ++)
    row.push_back (_1);
  for (int i = m ; i <= n + m ; i ++)
    row.push_back (_0);
  for (int NR = 0; NR <= n ; NR ++)
  {
    for (int i = 0; i < (int)row.size(); i++)
      if (row [i] == _0)
        break;
      else
      {
        std::cout << row [i] << "  ";
      }
    std::cout << std::endl;
    
    for (int i = 1 ; i <= NR + m ; i ++)
      row [i] = row [i] + row [i - 1];

  }
  return 0;
}
