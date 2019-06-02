#pragma once
/*
 * time header
 * gets and adjusts time format based on platform
 * kv_1.0.0
 */

 // check for duplicated definitions
#ifndef TIME_H
#define TIME_H
#endif

#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

// get platform
#include "platform.h"

#ifdef PLATFORM_WIN32
#include <time.h>
#endif
#ifdef PLATFORM_LINUX
#include <>
#endif
#ifdef PLATFORM_MACOSX
#include <>
#endif

// time class with static getters which format the time(/ Date)
class Time
{
public:
	Time();
	~Time();
	std::string getTime();
	std::string getDate();
private:
	static std::ostringstream td_oss;
	time_t currTime = time(NULL);
};

Time::Time()
{
}

Time::~Time()
{
}

inline std::string Time::getTime()
{

#ifdef PLATFORM_WIN32
	tm* local_time = localtime(&currTime);
	Time::td_oss << local_time->tm_hour
		<< ":"
		<< local_time->tm_min
		<< ":"
		<< local_time->tm_sec;
#endif
#ifdef PLATFORM_LINUX
#endif
#ifdef PLATFORM_MACOSX
#endif
	return Time::td_oss.str();
}

inline std::string Time::getDate()
{

#ifdef PLATFORM_WIN32
	Time::td_oss.flush;
	time_t rawtime;
	time(&rawtime);
	Time::td_oss << ctime(&rawtime);
#endif
#ifdef PLATFORM_LINUX
#endif
#ifdef PLATFORM_MACOSX
#endif
	return Time::td_oss.str();
}

/*
 * Egbewatt Kokou Mwangah.#kinfinity3.
 * ksupro1@gmail.com
 * @2019
 */
+
