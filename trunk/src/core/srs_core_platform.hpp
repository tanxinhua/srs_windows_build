//
// Copyright (c) 2013-2022 The SRS Authors
//
// SPDX-License-Identifier: MIT or MulanPSL-2.0
//

#ifndef SRS_CORE_PLATFORM_HPP
#define SRS_CORE_PLATFORM_HPP

// For 32bit os, 2G big file limit for unistd io,
// ie. read/write/lseek to use 64bits size for huge file.
#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif

// For int64_t print using PRId64 format.
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

// For RTC/FFMPEG build.
#if defined(SRS_RTC) && !defined(__STDC_CONSTANT_MACROS)
#define __STDC_CONSTANT_MACROS
#endif

// For srs-librtmp, @see https://github.com/ossrs/srs/issues/213
#ifndef _WIN32
#include <inttypes.h>
#else
#include <stdint.h>
#include <basetsd.h>
#include <inttypes.h>
#include <Winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <winerror.h>
#include <process.h>
#define getpid _getpid
#define gettid GetCurrentThreadId
typedef SSIZE_T ssize_t;
#include <time.h>
#include <windows.h>
#include <direct.h>
#include <io.h>
#include <WS2tcpip.h>
int gettimeofday(struct timeval* tp, void* tzp);

struct tm* gmtime_r(const long* timer, struct tm* buf);
struct tm* localtime_r(const long* timer, struct tm* buf);
typedef uint8_t u_int8_t;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
#endif

#include <stddef.h>
#include <sys/types.h>

// For CentOS 6 or C++98, @see https://github.com/ossrs/srs/issues/2815
#ifndef UINT32_MAX
#define UINT32_MAX (4294967295U)
#endif

#endif

