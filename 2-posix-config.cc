// posix configuration

#include <unistd.h>
#include <iostream>

// TIP: go look at /usr/include/unistd.h

/* Get values of POSIX options:

   If these symbols are defined, the corresponding features are
   always available.  If not, they may be available sometimes.
   The current values can be obtained with `sysconf'.

   _POSIX_JOB_CONTROL		Job control is supported.
   _POSIX_SAVED_IDS		Processes have a saved set-user-ID
				and a saved set-group-ID.
   _POSIX_REALTIME_SIGNALS	Real-time, queued signals are supported.
   _POSIX_PRIORITY_SCHEDULING	Priority scheduling is supported.
   _POSIX_TIMERS		POSIX.4 clocks and timers are supported.
   _POSIX_ASYNCHRONOUS_IO	Asynchronous I/O is supported.
   _POSIX_PRIORITIZED_IO	Prioritized asynchronous I/O is supported.
   _POSIX_SYNCHRONIZED_IO	Synchronizing file data is supported.
   _POSIX_FSYNC			The fsync function is present.
   _POSIX_MAPPED_FILES		Mapping of files to memory is supported.
   _POSIX_MEMLOCK		Locking of all memory is supported.
   _POSIX_MEMLOCK_RANGE		Locking of ranges of memory is supported.
   _POSIX_MEMORY_PROTECTION	Setting of memory protections is supported.
   _POSIX_MESSAGE_PASSING	POSIX.4 message queues are supported.
   _POSIX_SEMAPHORES		POSIX.4 counting semaphores are supported.
   _POSIX_SHARED_MEMORY_OBJECTS	POSIX.4 shared memory objects are supported.
   _POSIX_THREADS		POSIX.1c pthreads are supported.
   _POSIX_THREAD_ATTR_STACKADDR	Thread stack address attribute option supported.
   _POSIX_THREAD_ATTR_STACKSIZE	Thread stack size attribute option supported.
   _POSIX_THREAD_SAFE_FUNCTIONS	Thread-safe functions are supported.
   _POSIX_THREAD_PRIORITY_SCHEDULING
				POSIX.1c thread execution scheduling supported.
   _POSIX_THREAD_PRIO_INHERIT	Thread priority inheritance option supported.
   _POSIX_THREAD_PRIO_PROTECT	Thread priority protection option supported.
   _POSIX_THREAD_PROCESS_SHARED	Process-shared synchronization supported.
   _POSIX_PII			Protocol-independent interfaces are supported.
   _POSIX_PII_XTI		XTI protocol-indep. interfaces are supported.
   _POSIX_PII_SOCKET		Socket protocol-indep. interfaces are supported.
   _POSIX_PII_INTERNET		Internet family of protocols supported.
   _POSIX_PII_INTERNET_STREAM	Connection-mode Internet protocol supported.
   _POSIX_PII_INTERNET_DGRAM	Connectionless Internet protocol supported.
   _POSIX_PII_OSI		ISO/OSI family of protocols supported.
   _POSIX_PII_OSI_COTS		Connection-mode ISO/OSI service supported.
   _POSIX_PII_OSI_CLTS		Connectionless ISO/OSI service supported.
   _POSIX_POLL			Implementation supports `poll' function.
   _POSIX_SELECT		Implementation supports `select' and `pselect'.

   _XOPEN_REALTIME		X/Open realtime support is available.
   _XOPEN_REALTIME_THREADS	X/Open realtime thread support is available.
   _XOPEN_SHM			Shared memory interface according to XPG4.2.

   _XBS5_ILP32_OFF32		Implementation provides environment with 32-bit
				int, long, pointer, and off_t types.
   _XBS5_ILP32_OFFBIG		Implementation provides environment with 32-bit
				int, long, and pointer and off_t with at least
				64 bits.
   _XBS5_LP64_OFF64		Implementation provides environment with 32-bit
				int, and 64-bit long, pointer, and off_t types.
   _XBS5_LPBIG_OFFBIG		Implementation provides environment with at
				least 32 bits int and long, pointer, and off_t
				with at least 64 bits.

   If any of these symbols is defined as -1, the corresponding option is not
   true for any file.  If any is defined as other than -1, the corresponding
   option is true for all files.  If a symbol is not defined at all, the value
   for a specific file can be obtained from `pathconf' and `fpathconf'.

   _POSIX_CHOWN_RESTRICTED	Only the super user can use `chown' to change
				the owner of a file.  `chown' can only be used
				to change the group ID of a file to a group of
				which the calling process is a member.
   _POSIX_NO_TRUNC		Pathname components longer than
				NAME_MAX generate an error.
   _POSIX_VDISABLE		If defined, if the value of an element of the
				`c_cc' member of `struct termios' is
				_POSIX_VDISABLE, no character will have the
				effect associated with that element.
   _POSIX_SYNC_IO		Synchronous I/O may be performed.
   _POSIX_ASYNC_IO		Asynchronous I/O may be performed.
   _POSIX_PRIO_IO		Prioritized Asynchronous I/O may be performed.

   */

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef _POSIX_JOB_CONTROL
		cout << "Job control supported." << '\n';
	#endif
	#ifdef _POSIX_SAVED_IDS
		cout << "Processes have a saved set-user-ID and a saved set-group-ID." << '\n';
	#endif
	#ifdef _POSIX_CHOWN_RESTRICTED
		cout << "Only superuser can change owner of file" << '\n';
	#endif
	#ifdef _POSIX_NO_TRUNC
		cout << "Path name components longer than max value will produce error." << '\n';
	#endif
	#ifdef _POSIX_VDISABLE
		if (_POSIX_VDISABLE != -1)
		{
			cout << "Terminals can disable special keys." << '\n';
		}
		else
		{
			cout << "Terminals cannot disable special keys." << '\n';
		}
	#endif

	return 0;
}

/*
Vdisable explanation
My terminal has special keys, like ^C to interrupt, ^\ to dump core, ^W to erase a word, and ^U to erase a line. Special keys exist in xterm and other terminal emulators, but they are not the same in every terminal. POSIX apps can call tcgetattr() or tcsetattr() in <termios.h> to get or set these special keys. They can also disable some keys, for example:

tcgetattr(fd, tp);
tp->c_lflag &= ~ISIG;                // disable all the signal keys 
tp->c_cc[WERASE] = _POSIX_VDISABLE;  // disable the word-erase key 
tcsetattr(fd, tp);
Before POSIX.1-2001, support for _POSIX_VDISABLE was optional. There were 3 possibilities:

_POSIX_VDISABLE was defined and not -1. Then any terminal can use _POSIX_VDISABLE to disable a special key.
_POSIX_VDISABLE was defined and -1. Then no terminal can use _POSIX_VDISABLE.
_POSIX_VDISABLE was not defined. Then the value to disable a special key might be different for each terminal. A call like pathconf("/dev/tty", _PC_VDISABLE) would return the value for that terminal, or -1 if that terminal doesn't have a value to disable a special key.
When systems added <termios.h>, all or almost all systems made _POSIX_VDISABLE defined and not -1. I looked at some old systems in the Unix tree. All of Minix 1.5 (1989), Linux 0.96c (1992), and 4.4BSD (1993) have _POSIX_VDISABLE defined and not -1. (Before POSIX, <termios.h> did not exist, and systems used another header like <sgtty.h> to configure the terminal.)
*/