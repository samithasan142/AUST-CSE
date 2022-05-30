#include <stdio.h>

int main()
{
  int Number, Count=0;

  printf("Enter any number:\n");
  scanf("%d", &Number);

  while(Number > 0)
  {
     Number = Number / 10;
     Count = Count + 1;
  }

  printf("Number of Digits in a Given Number = %d", Count);
  return 0;
}
