#include <sys/stat.h>
#include <errno.h>

extern "C" {

// 1. Memory Allocation Stub
// We return -1 to fail standard malloc. The firmware usually uses 
// chHeapAlloc (ChibiOS) instead of standard new/malloc.
void* _sbrk(int incr) {
    return (void*)-1;
}

// 2. Cleanup Stub
void _fini() { }

// 3. I/O Stubs (File/Terminal)
// These allow code to "print" or "read" without crashing, 
// even though there is no console attached.

int _write(int file, char *ptr, int len) {
    return len; // Pretend we wrote everything successfully
}

int _read(int file, char *ptr, int len) {
    return 0; // EOF
}

int _close(int file) {
    return -1;
}

int _lseek(int file, int ptr, int dir) {
    return 0;
}

int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR; // Pretend everything is a character device
    return 0;
}

int _isatty(int file) {
    return 1; // Pretend we are a TTY
}

} // extern "C"
