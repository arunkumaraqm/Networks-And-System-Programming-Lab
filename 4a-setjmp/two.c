#include <stdio.h>
#include <setjmp.h>

int proc1(jmp_buf env, int i)
{
	if (i == 0)
	{
		longjmp(env, i);
	}
	else
	{
		return i;
	}
}

int main(int argc, char const *argv[])
{
	int i = -1;
	jmp_buf env;
	int sj = setjmp(env);
	if (sj)
	{
		printf("zero %d\n", i);
		return 0;
	}
	i ++;
	printf("%d\n", proc1(env, i));
	return 0;
}