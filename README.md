# ThorsLogging

![ThorsLogging](img/ThorsLogging.jpg)

ThorsLogging provides a very thin wrapper over [loguru](https://github.com/emilk/loguru).

Logging commands only do work if they are lower (or equal) to the current logging level. This is contralled via the global:

````C++
    loguru::g_stderr_verbosity = 0; // Default verbosity 0 (or Info)
````

## Log Interface:

To log an error message use one of the following commands.

````C++
ThorsLogFatal(<Class Name>, <Method Name>, <Error Message>)
ThorsLogError(<Class Name>, <Method Name>, <Error Message>)
ThorsLogWarning(<Class Name>, <Method Name>, <Error Message>)
ThorsLogInfo(<Class Name>, <Method Name>, <Error Message>)
ThorsLogDebug(<Class Name>, <Method Name>, <Error Message>)
ThorsLogTrack(<Class Name>, <Method Name>, <Error Message>)
ThorsLogTrace(<Class Name>, <Method Name>, <Error Message>)
ThorsLogAll(<Class Name>, <Method Name>, <Error Message>)
````

### Note:
ThorsLogFatal:  This will log and then force the application to shutdown.


### Error Message

This can be any set of parameters that can be sent to a stream. i.e. any number of parameters can be passed.

## Log and Throw

To log an error and use the same message in an throw exception.


````C++
ThorsLogAndThrowError(<Exceptiopn Type>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogAndThrowWarning(<Exceptiopn Type>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogAndThrowInfo(<Exceptiopn Type>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogAndThrowDebug(<Exceptiopn Type>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogAndThrowTrack(<Exceptiopn Type>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogAndThrowTrace(<Exceptiopn Type>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogAndThrowAll(<Exceptiopn Type>, <Class Name>, <Method Name>, <Error Message>)
````

### ThorsSerializer Extension

````C++
ThorsLogFatalWithData(<data>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogWarningWithData(<data>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogInfoWithData(<data>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogDebugWithData(<data>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogTrackWithData(<data>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogTraceWithData(<data>, <Class Name>, <Method Name>, <Error Message>)
ThorsLogAllWithData(<data>, <Class Name>, <Method Name>, <Error Message>)
````

This are basically equivalant to the `ThorsLogXXX()` the difference is that `data` is converted into a JSON object and attached to the end of the message.





