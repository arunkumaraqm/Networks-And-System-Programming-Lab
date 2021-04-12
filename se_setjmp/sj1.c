// http://web.eecs.utk.edu/~huangj/cs360/360/notes/Setjmp/lecture.html
#include <setjmp.h>

main()
{
  jmp_buf env;
  int i;

  i = setjmp(env);
  printf("i = %d\n", i);

  if (i != 0) exit(0);

  longjmp(env, 2);
  printf("Does this line get printed?\n");

}
