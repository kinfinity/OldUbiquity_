/*
 *logTask header:
 *	different logging macros which spawn tasks and detaches them.
 *
 */

#ifndef ENABLE_LOG_TASKS
#define ENABLE_LOG_TASKS

#pragma once

#include <thread>
#include <string>

#include "logConstants.h"
#include "logBuffer.h"

using namespace std;
using namespace uLogger;

namespace uLogger {

	class logTask{

		public:
			logTask();
			~logTask();

			// Log functions overload strings | JSON
			void info();
			void error();
			void warning();

	};

}
	
	uLogger::logTask::logTask() {
		// init datastructures for pushing logs

	}

	uLogger::logTask::~logTask() {
		// flush and destroy dataStructures

	}

	void logTask::messageLog() {
		std::thread logTaskThread0(std::bind(&lTask0, this), msg);
		if (logTaskThread0.joinable) {
			logTaskThread0.detach();
		}
	}

	void logTask::objectLog(logObject obj) {
		std::thread logTaskThread1(std::bind(&lTask1, this), obj);
		if (logTaskThread1.joinable) {
			logTaskThread1.detach();
		}
	}


	void logTask::lTask0(logMessage msg) {
		// add new node to logBuffer
		;
	}
	void logTask::lTask1(logObject obj) {
		// add new node to logBuffer

	}


#endif
/*
 * Egbewatt Kokou Mwangah.#kinfinity3.
 * ksupro1@gmail.com
 * @2019
 */

 /*
	 notes :
	 You will need to provide a bound version to allow the thread to call it:
	 std::bind(&Test, this).
	 Be aware that you MUST make sure the thread does not exist for longer than the object itself or you will cause undefined behavior
	 (It will execute a function on a non-existant object)
  */