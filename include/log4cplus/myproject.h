#ifndef MY_PROJECT_H_
#define MY_PROJECT_H_

#include <log4cplus/spi/loggerimpl.h>
#include <log4cplus/spi/loggerfactory.h>
#include <log4cplus/spi/loggingevent.h>
#include <log4cplus/logger.h>

namespace log4cplus {

class LOG4CPLUS_EXPORT MyLoggerImpl : public spi::LoggerImpl {
  public:
    MyLoggerImpl(const log4cplus::tstring& name, Hierarchy& h);
    void log(spi::InternalLoggingEvent const & ev);
};

class LOG4CPLUS_EXPORT MyLoggerFactory : public spi::LoggerFactory {
  public:
    MyLoggerFactory();
    Logger makeNewLoggerInstance(const log4cplus::tstring& name, Hierarchy& h);
};

LogLevel getLogLevelThreshold();

}

#endif
