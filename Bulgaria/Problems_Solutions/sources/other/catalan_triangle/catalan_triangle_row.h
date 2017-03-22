// GNU General Public License Agreement
// Copyright (C) 2004-2010 CodeCogs, Zyba Ltd, Broadwood, Holford, TA5 1DU, England.
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by CodeCogs. 
// You must retain a copy of this licence in all copies. 
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU General Public License for more details.
// ---------------------------------------------------------------------------------
//! Computes the row of the given order in Catalan's triangle.

#ifndef MATHS_COMBINATORICS_SEQUENCES_CATALAN_TRIANGLE_ROW_H
#define MATHS_COMBINATORICS_SEQUENCES_CATALAN_TRIANGLE_ROW_H

#include <assert.h>

#include <vector>
#include "../gmp/gmpxx.h"

namespace Maths
{

namespace Combinatorics
{

namespace Sequences
{

//! Computes the row of the given order in Catalan's triangle.

std::vector<mpz_class> catalan_triangle_row(int n, int m = 0, bool first = true)
{
  assert(n >= 0);
  assert(m >= 0);
  mpz_class _0 ("0");
  mpz_class _1 ("1");
  std::vector<mpz_class> row;
  for (int i = 0 ; i < n + m + 1 ; i ++)
    row.push_back (_0);

  if (first)
  {
    for (int i = 0 ; i <= m ; i ++)
      row[i] = _1;
    for (int i = m + 1; i <= n + m; row[i] = row[i - 1], i++)
      for (int j = m + 1; j < i; row[j] = row [j] + row[j - 1], j++);
  }
  else
  {
    row [0] = _1;
    for (int j = m + 1; j < n + m; row[j] = row [j] + row[j - 1], j++);
    if (n + m > 0) row[n + m] = row[n + m - 1];
  }

  return row;
}

}

}

}

#endif

