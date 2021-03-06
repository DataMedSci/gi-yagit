/*********************************************************************************************************************
 * This file is part of 'yet Another Gamma Index Tool'.
 *
 * 'yet Another Gamma Index Tool' is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * 'yet Another Gamma Index Tool' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 'yet Another Gamma Index Tool'; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *********************************************************************************************************************/

#include "comparator.h"
#include <math.h>

bool GPRComparator::compare(double* gammaS, double* gammaC, double epsilon, int size)
{
  // std::cout << "Using GPRComparator" << std::endl;

  double gprS = 0;
  double gprC = 0;

  for(int i=0; i<size; i++)
  {
    if(gammaS[i] < 1)
    {
      gprS++;
    }

    if(gammaC[i] < 1)
    {
      gprC++;
    }
  }

  gprS = gprS * 100 / size;
  gprC = gprC * 100 / size;

  double gprDiff = gprS - gprC;

  return fabs(gprDiff) <= epsilon;
}

string GPRComparator::name()
{
  return "GPRComparator";
}
