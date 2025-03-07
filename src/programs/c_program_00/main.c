// --------------------------------------------------------------------------------
// Author: Griesbacher Nic
// Description: Sortieren
// --------------------------------------------------------------------------------
// History:
//
// 2025/03/07: GriesB -- first version -- didn't work
//                    -- second version -- works
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
  int32_t array[10] = {1, 34, 3, 45, 7, 4, 12, 8, 77, 32};
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

  for(int8_t count = 0; count < 10; count++) {
    printf("%d \n", array[count]);
  }

  printf("Version 2:\n");

  int32_t array2[10] = {1, 653, 2, 34, 546, 3, 76, 34, 876, 65};

  for (int8_t count = 1; array2[count] <= array2[count ++]; count++) { 
    for (int8_t counting = 0; counting <= 0; counting ++) { 
      if (array2[counting] <= array2[counting ++]) {
        break;
      } else {
        Zwischenspeicher = array2[counting];
        array2[counting] = array2[counting++];
        array2[counting++] = Zwischenspeicher;
      }
    }
  }
  for(int8_t count = 0; count < 10; count++) {
    printf("%d \n", array2[count]);
  }
}

