#ifndef MY_PROJECT_H_
#define MY_PROJECT_H_

#include <log4cplus/spi/loggerimpl.h>
#include <log4cplus/spi/loggerfactory.h>
#include <log4cplus/spi/loggingevent.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

namespace log4cplus {

class LOG4CPLUS_EXPORT MyLoggerImpl : public spi::LoggerImpl {
  public:
    MyLoggerImpl(const log4cplus::tstring& name, Hierarchy& h);
    virtual void log(spi::InternalLoggingEvent const & ev);
    virtual void log(LogLevel ll, const log4cplus::tstring& message,
                       const char* file=nullptr, int line=-1,
                       const char* function=nullptr);
};

class LOG4CPLUS_EXPORT MyLoggerFactory : public DefaultLoggerFactory {
  public:
    MyLoggerFactory();
    spi::LoggerImpl * makeNewLoggerImplInstance(const log4cplus::tstring& name, Hierarchy& h);
};

LogLevel getLogLevelThreshold();

}

#endif
