#include <stdio.h>
#include <setjmp.h>

int main(int argc, char const *argv[])
{
	jmp_buf env;
	int ret = setjmp(env);
	printf("ret = %d\n", ret);

	if (ret)
	{
		return 0;
	}

	longjmp(env, 200);
	printf("here\n");;

	return 0;
}