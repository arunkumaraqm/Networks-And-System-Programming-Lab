#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		const char* src = argv[1];
		const char* dst = argv[2];
		
		int status = link(src, dst);
		
		if (status != 0)
		{
			printf("Hard link failed");
			return -1;
		}
	}
	else if (argc == 4 && strcmp(argv[1], "-s") == 0)
	{
		const char* src = argv[2];
		const char* dst = argv[3];
		
		int status = symlink(src, dst);
		
		if (status != 0)
		{
			printf("Symbolic link failed");
			return -1;
		}
	}
	else
	{
		printf("Invalid usage");
		return -1;
	}
	
}
