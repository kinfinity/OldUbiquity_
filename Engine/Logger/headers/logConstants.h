#pragma once
/*
 * ubiquityEngine -> Logger
 *
 * LogConstants: 
 *	 logger types and datascope
 *
 */

namespace ubiquityEngineLogger {

	struct logObject
	{
		// process/thread name
		//

	};

	struct logMessage
	{

	};

	enum class logLevel
	{
		errors = 1,
		exceptions,
		verbose,
		full

	};

	enum class logSeverity
	{
		normal = 1,
		error,
		exception,
		warning,

	};
	template <typename logObject, typename logMessage> struct logDataObject {};

}

/*
 * Egbewatt Kokou Mwangah.#kinfinity3.
 * ksupro1@gmail.com
 * @2019
 */