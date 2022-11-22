//
// Copyright (c) 2013-2022 The SRS Authors
//
// SPDX-License-Identifier: MIT or MulanPSL-2.0
//

#include <srs_core_platform.hpp>

int gettimeofday(struct timeval* tp, void* tzp)
{
    time_t clock;
    struct tm tm;
    SYSTEMTIME wtm;
    GetLocalTime(&wtm);
    tm.tm_year = wtm.wYear - 1900;
    tm.tm_mon = wtm.wMonth - 1;
    tm.tm_mday = wtm.wDay;
    tm.tm_hour = wtm.wHour;
    tm.tm_min = wtm.wMinute;
    tm.tm_sec = wtm.wSecond;
    tm.tm_isdst = -1;
    clock = mktime(&tm);
    tp->tv_sec = clock;
    tp->tv_usec = wtm.wMilliseconds * 1000;
    return (0);
}

struct tm* gmtime_r(const long* timer, struct tm* buf) {
    struct tm* ret = nullptr;
    const time_t _time = *timer;
    if (0 == gmtime_s(buf, &_time)) {
        ret = buf;
    }
    return ret;
}

struct tm* localtime_r(const long* timer, struct tm* buf) {
    struct tm* ret = nullptr;
    const time_t _time = *timer;
    if (0 == localtime_s(buf, &_time)) {
        ret = buf;
    }
    return ret;
}