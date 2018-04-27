#include <iostream>
#include <log4cplus/myproject.h>
#include <log4cplus/helpers/pointer.h>
#include <log4cplus/consoleappender.h>

using namespace std;

namespace log4cplus {

MyLoggerFactory::MyLoggerFactory() : DefaultLoggerFactory() {
}

spi::LoggerImpl * MyLoggerFactory::makeNewLoggerImplInstance (const log4cplus::tstring & name,
    Hierarchy& h)
{
    return new MyLoggerImpl(name, h);
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

void MyLoggerImpl::log(LogLevel ll, const log4cplus::tstring& message, const char* file, int line, const char* function)
{
    if(ll == getLogLevelThreshold()) 
    {
        forcedLog(ll, message, file, line, function ? function : "");
    }
}

}

int main(int argc, char *argv[])
{
	log4cplus::spi::LoggerFactory * myfactory = new log4cplus::MyLoggerFactory();
    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("log"), *myfactory);


    logger.addAppender(log4cplus::helpers::SharedObjectPtr<log4cplus::Appender>(new log4cplus::ConsoleAppender()));
    //LOG4CPLUS_FATAL(logger, "This is a FATAL message!");
    //LOG4CPLUS_WARN(logger, "This is a WARNING message!");
    logger.log(log4cplus::FATAL_LOG_LEVEL, "LOGGING WITH FATAL LEVEL");
    logger.log(log4cplus::INFO_LOG_LEVEL, "LOGGING WITH INFO LEVEL");
}
