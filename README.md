# c-log

c-log is a C++ library which provides logging functionality.

## Usage

This library provides a LogSystem class which handles all of the logging.

Logging in this context is more focused on merging logs rather than efficiency.
Logs are written by Loggers to LogBooks. These LogBooks have a 1-1 correspondent with an external files. Loggers have the possibility to write to multiple LogBooks.

c-log contains a LogSystem class which handles logging operation.
The LogSystem is a class which manages LogBooks and Loggers, responsible for accumulating logs and writing logs.

Contains 5 level of logging (DEBUG, INFO, WARN, ERROR, FATAL)
Has the ability to choose where logs are outputed.
Merge logs together.

```
LogSystem log = LogSystem();
log.setLogLevel(LogLevel::WARNING);

log.fatal("fatal error found");
log.error("error found");
log.warn("warning given")
log.info("info given");
log.debug("debug info")
```
