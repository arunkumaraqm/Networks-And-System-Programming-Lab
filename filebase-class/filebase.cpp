#include <fstream>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cstdlib>
#include <sys/stat.h> // chmod
#include <utime.h>

using namespace std;

namespace FileTypes
{
	auto REG_FILE = "R"; // regular file
	auto DIR_FILE = "D"; // directory file
	auto CHAR_FILE = "C"; // character device file
	auto PIPE_FILE = "P"; // piped/fifo file
	auto SYM_FILE = "S"; // symbolic link file
	auto BLK_FILE = "B"; // block device file
	auto UNKNOWN_FILE = "?";
} 

class Filebase: public fstream
{
protected:
	char* fname;

public:
	Filebase(): fname(nullptr) {}
	Filebase(const char* given_fname, std::ios_base::openmode flags, int prot=664)
		: fstream(given_fname, flags)
	{
		fname = new char[strlen(given_fname) + 1];
		strcpy(fname, given_fname);
	}

	int chmod(mode_t mode)
	{
		return ::chmod(fname, mode);
	}
	int chown(uid_t uid, gid_t gid)
	{
		return ::chown(fname, uid, gid);
	}
	int link(const char *link_path)
	{
		return ::link(fname, link_path);
	}
	int unlink_current()
	{
		return ::unlink(fname);
	}
	int utime(const struct utimbuf* given_times = nullptr)
	{
		return ::utime(fname, given_times);
	}
	auto get_file_type()
	{
		struct stat statv;
		if (stat(fname, &statv) == 0)	
		{
			switch (statv.st_mode & 
					S_IFMT // filters out bits for file type details
			)
			{
				case S_IFREG: return FileTypes::REG_FILE;
				case S_IFIFO: return FileTypes::PIPE_FILE;
				case S_IFCHR: return FileTypes::CHAR_FILE;
				case S_IFBLK: return FileTypes::BLK_FILE;
				case S_IFDIR: return FileTypes::DIR_FILE;
				case S_IFLNK: return FileTypes::SYM_FILE;
			}
		}
		return FileTypes::UNKNOWN_FILE;
	}
	~Filebase()
	{
		delete [] fname;
	}
};


int main(int argc, char const *argv[])
{
	Filebase fout("something.txt", ios::app, 777); // to make sure this file exists
	fout << "somthing here\nsomething else";
	fout.close();

	Filebase file("something.txt", ios::in); 
	cout << file.get_file_type() << '\n';
	// file.chmod(770);
	cout << file.chown(1000, 1000) << '\n'; // I only have one user and one group on my system so (1000, 1000) is the only valid ids.
	file.utime(); // changes last accessed and last modified times to now; check by running $ stat something.txt before and after running this program.
	file.link("another.txt"); // create a hard link
	// file.unlink_current();
	cout << file.get_file_type() << '\n'; // should be ? since file has been deleted
	file.close();

	return 0;
}