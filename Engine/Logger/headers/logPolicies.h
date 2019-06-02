#pragma once
/*
 * ubiquityEngine -> Logger
 * 
 * LogPolicies:
 *	 classes with streams which write logs.
 *	 determines where the logs would be dumped
 * 
 */

#include <string.h>
#include <fstream>

using namespace std;

namespace ubiquityEngineLogger {

	class logStreamInterface{

		public:
			virtual void open_ostream(const std::string& name) = 0;
			virtual void open_ostream(const std::iostream) = 0;
			virtual void close_ostream() = 0;
			virtual void write(const std::string & msg) = 0;

	};

	/*
	 * Log to File
	 */
	class fileLogStream : public logStreamInterface {
		
		private:
			std::unique_ptr <std::ofstream> file_ouStream;
		
		public:
			fileLogStream() : file_ouStream (new std::ofstream){}

			void open_ostream(const std::string& name);
			void close_ostream();
			void write(const std::string& msg);
			~fileLogStream();

	};

	/*
	 * Log to console [stdout]
	 */
	class consoleLogStream : public logStreamInterface {

		private:
			std::unique_ptr <std::iostream> standard_outStream;
	
		public:
			consoleLogStream() : standard_outStream() {}
			void open_ostream(const std::iostream);
			void close_ostream();
			void write(const std::string& msg);
			~consoleLogStream();

	};

	/*
	 * Log to console [stdout]
	 */
	class networkLogStream : public logStreamInterface {

		private:
			std::unique_ptr< std::iostream> network_outStream;
		
		public:
			networkLogStream() : network_outStream() {};

			void open_ostream();
			void close_ostream();
			void write(const std::string& msg);
			~networkLogStream();

	};

}
/*
 * Egbewatt Kokou Mwangah.#kinfinity3.
 * ksupro1@gmail.com
 * @2019
 */