#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;

void func()
{
	printf("%d\n", __LINE__);
	longjmp(buffer, 1);
	printf("%d\n", __LINE__);
}

int main(int argc, char const *argv[])
{
	if (setjmp(buffer))
	{
		printf("%d\n", __LINE__);
	}
	else
	{
		printf("%d\n", __LINE__);
		func();
	}
	return 0;
}