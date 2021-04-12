#include <stdio.h>
#include <setjmp.h>

int fone(jmp_buf env)
{
	int sj = setjmp(env);
	printf("inside fone\n");
	return sj;
}
int ftwo(jmp_buf env)
{
	printf("inside ftwo\n");
	longjmp(env, 100);
}
int main(int argc, char const *argv[])
{
	jmp_buf env;
	if (fone(env))
	{
		return 0;	
	}
	ftwo(env);
}