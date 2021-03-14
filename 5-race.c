#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

/*
 If BUF is NULL, make STREAM unbuffered.
   Else make it use buffer BUF, of size BUFSIZ.  
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __THROW;
*/

void print_unbuffered(const char* str)
{
	setbuf(stdout, NULL);
	while(true)
	{
		char ch = *str;
		if (ch == '\0') break;
		printf("%c", ch);
		str++;
	}
}

int main()
{
	if (fork())
	{
		print_unbuffered("parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent parent");
	}
	else
	{
		print_unbuffered("child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child child");
	}
}
