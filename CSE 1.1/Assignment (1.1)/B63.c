#include <stdio.h>

int main()
{
  int Number, Reminder, Sum=0;

  printf("Enter any number:\n");
  scanf("%d", &Number);

  while(Number > 0)
  {
     Reminder = Number % 10;
     Sum = Sum+ Reminder;
     Number = Number / 10;
  }

  printf("Sum of the digits of Given Number = %d", Sum);

  return 0;
}
