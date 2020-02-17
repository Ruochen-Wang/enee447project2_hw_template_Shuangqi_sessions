#define DEBUG_LOW 0
#define DEBUG_MED 1
#define DEBUG_HI 2
#define DEBUG_NONE 3

//
// set this to the level you want to print out --
// that level and higher will print to screen
//
#define DEBUG_LEVEL DEBUG_LOW

extern void	dont_call_directly( void *, char *, unsigned long);
#if DEBUG_LEVEL == DEBUG_NONE
#define debug(x,y,z);	
#else
#define debug(x,y,z);	if (x >= DEBUG_LEVEL) { dont_call_directly(GETPC(),y,z); }
#endif
extern void	log( char *, long);
extern void	panic( int, char *);
extern void init_errno( void );

enum err_numbers {
	ERRNO_NONE,
	ERRNO_ASSERT,
	ERRNO_SPACE,
	ERRNO_INTERRUPT,
	ERRNO_SYSCALL,
	/* add new ones above this line */
	ERRNO_MAX
};

#define NOVAL	0xbadf000d
