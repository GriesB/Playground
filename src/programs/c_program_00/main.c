// --------------------------------------------------------------------------------
// Author: Griesbacher Nic
// Description: Sortieren
// --------------------------------------------------------------------------------
// History:
//
// 2025/03/07: GriesB -- first version -- didn't work
// ..
// --------------------------------------------------------------------------------

#include <stdio.h>
#include <stdint.h>

int32_t compare(int32_t a, int32_t b)
{
  if (a < b)
  {
    return 1; // TRUE
  }
  else
  {
    return 0; // FALSE
  }
}

int32_t check(int32_t array[10])
{
  int32_t position1 = 0;
  int32_t position2 = 1;

  while (position2 <= 10)
  {
    if (array[position1] >= array[position2])
    {
      position1++;
      position2++;
    }
    else
    {
      return 0;
    }
  }

  return 1;
}

int main(int argc, char **argv)
{
  int32_t array[10] = {321, 6, 2143, 56, 32, 65, 274, 65, 3, 546};
  int32_t Zwischenspeicher = 0;
  int32_t positionx = 0;
  int32_t positiony = 1;
  
  while (check(array) == 0)
  { // Bis array fertig sortiert wurde
    while (positiony <= 10)
    { // eine Runde
      if (compare(array[positionx], array[positiony]) != 1)
      {
        positionx++;
        positiony++;
      }
      else
      {
        Zwischenspeicher = array[positionx];
        array[positionx] = array[positiony];
        array[positiony] = Zwischenspeicher;
        positionx++;
        positiony++;
      }
    }

    positionx = 0;
    positiony = 1;
  }
}
