#include <iostream>
#include <log4cplus/myproject.h>

using namespace std;

namespace log4cplus {

MyLoggerFactory::MyLoggerFactory() : spi::LoggerFactory() {
}

Logger MyLoggerFactory::makeNewLoggerInstance (const log4cplus::tstring & name,
    Hierarchy& h)
{
    return Logger (new MyLoggerImpl(name, h));
}

MyLoggerImpl::MyLoggerImpl(
	const log4cplus::tstring& name, Hierarchy& h) : spi::LoggerImpl(name, h) {
}

LogLevel getLogLevelThreshold() {
    return log4cplus::FATAL_LOG_LEVEL;
}

void MyLoggerImpl::log(spi::InternalLoggingEvent const & ev)
{
    if (ev.getLogLevel() == getLogLevelThreshold())
    {
        forcedLog(ev);
    }
}

}
