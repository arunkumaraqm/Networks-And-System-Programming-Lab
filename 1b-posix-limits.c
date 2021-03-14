// #define _POSIX_SOURCE
// #define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>

// TIP: $ man sysconf $ man pathconf

// fpathconf, pathconf - get configuration values for filesx
//        _PC_PATH_MAX
//               returns the maximum length of a relative pathname when
//               path or fd is the current working directory.  The cor‐
//               responding macro is _POSIX_PATH_MAX.
// long pathconf(const char *path, int name);

int main(int argc, char const *argv[])
{
	// #ifdef _POSIX_VERSION
	// 	printf("Posix version: %ld\n", _POSIX_VERSION);
	// #endif

	int max_path_size = pathconf("/home/Documents", _PC_PATH_MAX);
	if (max_path_size < 0)
	{
		perror("error with pathconf");
	}
	else
	{
		// prints 4096; path doesn't actually matter
		printf("max_path_size: %d\n", max_path_size);
	}

	int max_child_processes = sysconf(_SC_CHILD_MAX);
	if (max_child_processes < 0)
	{
		perror("error with sysconf");
	}
	else
	{
		printf("max_child_processes: %d\n", max_child_processes);
	}

	int max_fname_size = pathconf("/home", _PC_NAME_MAX);
	if (max_fname_size < 0)
	{
		// if you get an error here, change your path name
		perror("error with pathconf");
	}
	else
	{
		// prints 255
		printf("max_fname_size: %d\n", max_fname_size);
	}

	int max_files_opened_simultaneously_by_one_process = sysconf(_SC_OPEN_MAX);
	if (max_files_opened_simultaneously_by_one_process < 0)
	{
		// if you get an error here, change your path name
		perror("error with sysconf");
	}
	else
	{
		// prints 255
		printf("max_files_opened_simultaneously_by_one_process: %d\n", max_files_opened_simultaneously_by_one_process);
	}

	int nf_ticks_per_sec = sysconf(_SC_CLK_TCK);
	if (nf_ticks_per_sec < 0)
	{
		// if you get an error here, change your path name
		perror("error with sysconf");
	}
	else
	{
		// prints 255
		printf("nf_ticks_per_sec: %d\n", nf_ticks_per_sec);
	}

	return 0;
}

/*max_path_size: 4096
max_child_processes: 15211
max_fname_size: 255
max_files_opened_simultaneously_by_one_process: 1024
nf_ticks_per_sec: 100*/