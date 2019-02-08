#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
  Gets user input with a buffer size of 8 digits
  Returns -1 to indicate EOD or -2 to indicate buffer overflow

  returns: integer user input or error code
*/
int get_input() {
  int buffer_size = 10;
  char buffer[buffer_size];
  char* input;
  int i;
  int null_flag = 0;
  //gets user input
  input = fgets(buffer, sizeof(buffer), stdin);
  //tests for EOD
  if(input==NULL){
    return -1;
  }
  //ensures multiple null values appear to indicate valid input
  for(i=0; i<buffer_size; i++) {
    if(input[i]=='\0') {
      null_flag++;
    }
  }
  if(null_flag==1) {
    return -2;
  }
  // printf("%i\n", null_flag);

  return atoi(buffer);
}


/*
  Adds the values inside the completed list of user input.

  returns: none
*/
void add(char* list, int counter) {
  int i;
  int count = 0;

  for(i=0; i<counter; i++) {
    count += list[i];
    // printf("Count: %i\n", count);
    // printf("List[i]%i\n", list[i]);
  }

  printf("Total: %i\n", count);
}


int main() {
  char list[10];
  int i;
  int j;
  int result;
  int counter = 0;
  int count = 0;

  for(i=0; i<sizeof(list); i++) {
    result = get_input();
    // printf("%i\n", result);

    //adds ints in list and terminates program for EOD
    if(result==-1) {
      add(list, counter);
      return -1;
    }
    //indicates buffer overflow and doesn't record input
    else if(result==-2) {
      printf("Too many digits\n");
    }
    //adds valid input to list
    else {
      list[i]=result;
      counter++;
    }
  }
  //adds if user exceeds max number of inputs entered
  add(list, counter);

  return 0;
}
