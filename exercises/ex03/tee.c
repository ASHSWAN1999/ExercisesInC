/*
@author Ashley Swanson

Implementation of tee function. Writes program output to terminal as well as
specified files, with options to overwrite/append.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {

  int ch;
  char* append = "w";
  int i;
  FILE *names[argc-1];
  char input[200];

  //checks for flag behaviors
  while((ch = getopt(argc, argv, "ai"))!=EOF)
    switch(ch) {
      case 'a':
        append = "a";
        break;
      case 'i':
        (void)signal(SIGINT, SIG_IGN);
        break;
      default:
        append = "w";
      }

  // skips over flags so they do not become file names
  argc -= optind;
  argv += optind;

  //creates an array of pointers for each file
  for(i=0; i<argc; i++) {
    names[i] = fopen(argv[i], append);
  }

  //reads standard input
  while(fgets(input, 200, stdin)!=NULL) {
    //prints to terminal
    printf("%s", input);

    //prints to all files
    for(i=0; i<argc; i++) {
      fprintf(names[i], "%s", input);
      fclose(names[i]);
    }
  }

  return 0;
}

// 3.) In my development process, I drew out the elements I needed and marked
// places where I had holes in my knowledge. This gave me a starting point to
// tackle all of the questions I had and the seek out the newer material syntax
// I had not implemented before. I also found it very helpful to look up an
// article/man pages/tutorials to understand a piece of functionality,
// and then look at stack overflow for syntactical examples.
//    The biggest thing to slow me down was my understanding of scanf(), because I
// attempted to use it to read full lines but found a strange one-line-behind
// behavior that I spent around an hour trying to understand. I eventually
// switched to fgets() but am still unsure why my first implementation was
// unsuccessful. Aside from that, overcoming the fear of transitioning from
// reading about a topic to actually attempting it took up a lot of time. This
// is definitely aomething I can improve upon.
//    Next time, I will attempt to try things as I look them up rather than
// trying to curate all of the information before diving in. I would also
// try to work with others because pooled knowledge is really helpful when
// you don't know what you don't know.
//
// 4.) The professional implementation has a case '?':  which, upon further
// research, seems to be a catch case for if a user types an unknown option.
// In general there is a ton more error checking and handling.
