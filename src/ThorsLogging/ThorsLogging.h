#ifndef THORS_ANVIL_LOGGING_THORS_LOGGING_H
#define THORS_ANVIL_LOGGING_THORS_LOGGING_H

#include "loguru.hpp"
#include "ThorsIOUtil/Utility.h"
#include <stdexcept>
#include <string>


namespace ThorsAnvil::Logging
{
    class Critical: std::runtime_error
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
while(false)

#define ThorsLogAndThrow(...)          ThorsLogAndThrowAction(2, std::runtime_error, __VA_ARGS__)
#define ThorsLogAndThrowCrytical(...)  ThorsLogAndThrowAction(FATAL, ThorsAnvil::Logging::Critical, __VA_ARGS__)


#endif
