#include <stdio.h>

int main() {
  // Take user input for the number of seconds
  int seconds;
  char name [80];
  printf("\n\tPlease enter your first name: "); // Entering the name of user
  scanf("%s", name);
  printf("\n\tEnter number of second/s: "); // Entering the input seconds of user
  scanf("%d", &seconds);

  // Calculate the number of hours, minutes, and seconds
  int hours = seconds / 3600;
  int minutes = (seconds % 3600) / 60;
  seconds = (seconds % 3600) % 60;

  // Print the result
  printf("\n\t\tHour/s:\t\t %d\n", hours);
  printf("\t\tMinute/s:\t %d\n", minutes);
  printf("\t\tSecond/s:\t %d\n", seconds);

  // Print the time in the format "00:01:05"
  printf("\n\t%s, The seconds you entered is converted to: %02d:%02d:%02d\n",name, hours, minutes, seconds);
  printf("\tThank you for using the program!");

  return 0;
}