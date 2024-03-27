// Disable compiler warnings
// Marked as weak if some other library will define them
extern "C" void __attribute__((weak)) _close() {}
extern "C" void __attribute__((weak)) _fstat() {}
extern "C" void __attribute__((weak)) _getpid() {}
extern "C" void __attribute__((weak)) _isatty() {}
extern "C" void __attribute__((weak)) _kill() {}
extern "C" void __attribute__((weak)) _lseek() {}
extern "C" void __attribute__((weak)) _open() {}
extern "C" void __attribute__((weak)) _read() {}
extern "C" void __attribute__((weak)) _write() {}