/*
  @author Ashley Swanson

  Card counting program
*/


#include <stdio.h>
#include <stdlib.h>

/*Tests the value of the input and determines if the count
  should be incremented, decremented, or remain constant.

  count: keeps track of high and low cards drawn
  val: numeric value of most recently drawn card
*/
 int update_counter(int count, int val) {
   if((val>2)&&(val<7)) {
     count++;
   } else if(val==10) {
     count--;
   }
   return count;
 }

/*Correlates face cards with numerical values and typecasts
  numerical values to integers. Throws warning if input is invalid.

  card_name: first two characters of string entered by user.
*/
void get_val() {
  char card_name[3];
  int count = 0;
  do {
    int val = 0;
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
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
         if((val<1)||(val>10)) {
           puts("I don't understand that value!");
           continue;
         }
      }
      count = update_counter(count, val);
      printf("%i\n", count);
  } while (card_name[0]!='X');
}

 /*Calls function to prompts user for input and prints the
  resulting count. Continues until the user enters 'X'

   User input is truncated to two characters.
 */
 int main() {
   get_val();
   return 0;
 }
