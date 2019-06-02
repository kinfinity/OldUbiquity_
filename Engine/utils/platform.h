/*
 * platform header
 * checks and sets Macros for the running platform
 * kv_1.0.0
 */
#pragma once


 // Windows

#ifdef _WIN64
#define PLATFORM_WIN64
#define PLATFORM_NAME "Windows64"
#endif
#if defined _WIN32 || defined WIN32 
#define PLATFORM_WIN32
#define PLATFORM_NAME "Windows32"
#endif


// Linux
#if defined linux || defined __linux__ || defined __unix__
#define PLATFORM_LINUX
#define PLATFORM_NAME "Linux"
#endif


// MacOS X
#if ( defined __MWERKS__ && defined __powerc && !defined macintosh ) || defined __APPLE_CC__ || defined macosx
#define PLATFORM_MACOSX
#define PLATFORM_NAME "MacOS X"
#endif

/*
 * Egbewatt Kokou Mwangah.#kinfinity3.
 * ksupro1@gmail.com
 * @2019
 */