#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void file_copy(int source, int dest)
{
    char buffer[2048];
    int count;

    while (true)
    {
        count = read(source, buffer, sizeof(buffer));
        if (!count)
        {
            break;
        }
        write(dest, buffer, count);
    }
}
main(int argc, char* argv[])
{
	int fd_one, fd_two;
	if (argc != 3)
	{
		printf("Need two file names.\n");
        return 1;
	}

	fd_one = open(argv[1], O_RDONLY);
	if (fd_one < 0)
    {
        printf("Unable to open %s", argv[1]);
    }

    fd_two = creat(argv[2], 
            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    
	if (fd_two < 0)
    {
        printf("Unable to create %s", argv[2]);
        return 1;
    }

    file_copy(fd_one, fd_two);
		
}
