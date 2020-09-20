#ifndef THORS_ANVIL_LOGGING_THORS_LOGGING_H
#define THORS_ANVIL_LOGGING_THORS_LOGGING_H

#ifndef LOGURU_WITH_STREAMS
#define LOGURU_WITH_STREAMS 1
#endif

#include "loguru.hpp"
#include "ThorsIOUtil/Utility.h"
#include <stdexcept>
#include <string>


namespace ThorsAnvil::Logging
{
    // This is for data/application corruption that requires the
    // application to immediately quit.
    class FatalException: std::runtime_error
    {
        public:
            using std::runtime_error::runtime_error;
    };
    // This is for situations that "should not" happen.
    // Use this exception for code paths that should not be reachable.
    //
    // This will help find issues that can be corrected by unit tests.
    // But occasionally will happen in production. You should only
    // catch this type of error at an action type level to abandon the
    // action.
    //
    // Note: This does not mean there has been data corruptions so we
    //       can potentially continue. The application writer must
    //       make that determination.
    class CriticalException: std::runtime_error
    {
        public:
            using std::runtime_error::runtime_error;
    };
    // This is for situations where you don't want to happen
    // but is caused because the input data does not conform
    // to expect patterns.
    class LogicalException: std::runtime_error
    {
        public:
            using std::runtime_error::runtime_error;
    };
}

#define ThorsLogAndThrowAction(Level, Exception, Scope, Function, ...)  \
do                                                                      \
{                                                                       \
    std::string message = ThorsAnvil::Utility::buildErrorMessage(       \
                                            Scope,                      \
                                            Function,                   \
                                            __VA_ARGS__);               \
    LOG_F(Level, "%s", message.c_str());                                \
    throw Exception(message);                                           \
}                                                                       \
while (false)

#define ThorsLogAndThrowFatal(...)      ThorsLogAndThrowAction(FATAL,   ThorsAnvil::Logging::FatalException, __VA_ARGS__)
#define ThorsLogAndThrowCritical(...)   ThorsLogAndThrowAction(ERROR,   ThorsAnvil::Logging::CriticalException, __VA_ARGS__)
#define ThorsLogAndThrowLogical(...)    ThorsLogAndThrowAction(WARNING, ThorsAnvil::Logging::LogicalException, __VA_ARGS__)
#define ThorsLogAndThrow(...)           ThorsLogAndThrowAction(2, std::runtime_error, __VA_ARGS__)


#endif
