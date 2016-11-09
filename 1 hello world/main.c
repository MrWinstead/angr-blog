/*
 * file: main.c
 * author: Mike Winstead
 * 
 * compile command line:
 *  $ gcc -fno-stack-protector -g main.c
 *
 */
#include <stdio.h>

/*
 *   This function will be the one whose return value will be overwritten in an
 * unconstrained path to be found using Angr. The VERY basic buffer overflow
 * may be found on in the scanf writing into the buf variable.
 */
void func(void)
{
  char buf[12];
  printf("What is your name? ");
  
  scanf("%s", &buf);
  printf("Hello, %s\n", buf);
}

/*
 * Main function whose only purpose is to call the function to be exploited 
 *
 */ 
int main(void)
{
  func();
  
  return 0;
}
