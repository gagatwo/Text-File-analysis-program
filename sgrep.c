#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* for skeleton code */
#include <unistd.h> /* for getopt */
#include "str.h"

#define MAX_STR_LEN 1023

#define FALSE 0
#define TRUE  1

void PrintUsage(const char* argv0)
{
  const static char *fmt =
	  "Simple Grep (sgrep) Usage:\n"
	  "%s pattern [stdin]\n";

  printf(fmt, argv0);
}

/*-------------------------------------------------------------------*/
//Function to search a word in a text file
int SearchPattern(const char *pattern)
{
  char buf[MAX_STR_LEN + 2];

  
  //Check if pattern is too long
  if(StrGetLength(pattern)>1023)//compare pattern length with 1023
  {
    fprintf(stderr, "Error: pattern is too long\n");
    return FALSE;
  }

  /* Read one line at a time from stdin, and process each line */
  while (fgets(buf, sizeof(buf), stdin)) 
  {
    if(StrGetLength(buf)>1023)//compare buf length with 1023
    {
      fprintf(stderr, "Error: input line is too long\n");
      return FALSE;
    } 
    
    const char* read=buf;
    const char* temp=buf;
    while(*pattern == '*')//when * is first of pattern, it is not important
        pattern++;
    
    while(*read)
    {
      if(*pattern == *read)//when first char is same
      {
        const char* x=pattern;
        const char* y=read;
        x++;
        y++;
        while(*x)
        {

          if(*x=='*')// * is don't care about what is on buf
          {
            while(*x == '*')//continous * is not important
              x++;
            while(*y)// find same char(that next of *) on buf 
            {
              if(*y==*x)
              {
                x++;
                y++;
                break;
              }
	      else if(*y == ' ')
                break;
              y++;
            }     
            if(*y=='\0')
              break;
          }

          else if(*x==*y)//case that same char on pattern and buf
          {
            x++;
            y++;
          } 
          else// differnt char means there no smae pattern in this situation 
            break;
        }
        if(*x=='\0')//x pointing '\0' means loop reapeated until end of pattern. It means there is same pattern in buf
        {

          printf("%s",temp);//Then, print buf
          break;
        }
      }
      read++;
    }
  }
  return TRUE;
}
/*-------------------------------------------------------------------*/
int main(const int argc, const char *argv[])
{
  /* Do argument check and parsing */
  if (argc < 2) {
	  fprintf(stderr, "Error: argument parsing error\n");
	  PrintUsage(argv[0]);
	  return (EXIT_FAILURE);
  }

  return SearchPattern(argv[1]) ? EXIT_SUCCESS:EXIT_FAILURE;
}
