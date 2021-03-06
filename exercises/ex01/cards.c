/*
@author Ashley Swanson

Card counting program.
*/

#include <stdio.h>
#include <stdlib.h>

/*Prompts the user to enter a card and updates the contents
  of card name.

  card_name: pointer to array where most recent card is stored
*/
void get_input(char* card_name) {
  puts("Enter the card: ");
  scanf("%2s", card_name);
}


/*Tests the value of the input and determines if the count
  should be incremented, decremented, or remain constant.

  count: keeps track of high and low cards drawn
  val: numeric value of most recently drawn card
*/
int get_value(int count, int val) {
  if ((val>2)&&(val<7)) {
    count++;
  } if (val==10) {
    count--;
  }
  return count;
}

/*Asks user for playing card and prints a counter indicating
  how many high or low cards have been drawn. Loops until
  user enters 'X'

  User input is truncated to two characters
*/
int main() {
  int count = 0;
  int val = 0;
  char card_name[3];

  do {
    get_input(card_name);

    switch(card_name[0]) {
      case 'K':
      case 'Q':
      case 'J':
        val = 10;
        break;
      case 'A':
        val = 11;
        break;
      case 'X':
        continue;
      default:
        val = atoi(card_name);
        if ((val<1) || (val>10)) {
          puts("I don't understnad that value!");
          continue;
        }
    }
    printf("Input: %c  Val: %i\n", card_name[0], val);
    count = get_value(count, val);
    printf("%i\n", count);

  } while (card_name[0]!='X');
}

/*
int x = 5 corresponds to: 	movl	$5, -4(%rbp)
After -O2 optimization, this line appears to be gone

When printing x
Without optimization, 	movl	$5, -4(%rbp) still apears along
with a call to printf

With ptimization, the line becomes 	movl	$5, %edx and printf
disapears

When printing y
Without optimization 5 is stored as 	movl	$5, -8(%rbp)and
printf is invoked

With optimization 5 does not even appear outside of Ubuntu
versions and printf is gone

This may suggest that optimization does not store unecessary
variables like x, because it determines that the value of y
will always be 5 anyways. It also suggests that it replaces
functions like printf with lighter weight versions when
possible. 
*/
