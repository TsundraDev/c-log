# c-log

c-log is a C++ library which provides logging functionality.

## Module

This repo comes equipped with the c-log directory containing a self-contained module to be included in other C++ projects.
This module contains the following:
- an external header file (c-log.hpp)
- a Makefile which automatically builds the module

Projects using the c-log module can also choose where the library is built by modifying the OBJ target. However, do note that the relative filepath is considered from the c-log module directory

```
$(MAKE) -C c-log OBJ=[filepath]
```


## Usage

### Default logging

Default logging is done via the LogSystem class. Setting up requires a LogSystem object and setting the LogLevel. All subsequent calls to logging functions will start the logging process.

All logs are initially buffered. When an output call is made, the logs are then written to their destination. In the case of default logging, the destination is stderr. Logs are also outputted when a fatal or debug log call is made. Furthermore, on program exit, all logs are outputted as well.
```
// Setup default logging
LogSystem log = LogSystem();
log.setLogLevel(LogLevel::WARN);

// Log calls
log.fatal("Fatal error found");   // Should appear
log.error("Error found");         // Should appear
log.warn("Warning given");        // Should appear
log.info("Logging setup");        // Should not appear
log.debug("Debug call");          // Should not appear

log.output();                     // Force log output
```

### Custom logging

Custom logging allows to choose with more precision where the logs are written to.
To do this, LogBooks are generated to represent the logs. Loggers are also generated to represent the action of logging. Loggers have the ability to write to simultaneously write to multiple LogBooks, which allows for mixed and merged logging.

```
// Setup custom logging
LogSystem log     = LogSystem();
LogBookID logbook1 = log.addLogBook(LogLevel::WARN, "status.log");
LogBookID logbook2 = log.addLogBook(LogLevel::WARN, "test.log");
LoggerID  logger1  = log.addLogger();
LoggerID  logger2  = log.addLogger();
log.link(logbook1, logger1);    // logger1 -> logbook1
log.link(logbook2, logger1);    //         -> logbook2
log.link(logbook2, logger2);    // logger2 -> logbook2

// Log calls
log.fatal(logger1, "Log1 log"); // Automatically write to logbook1 and logbook2
log.fatal(logger2, "Log2 log"); // Automatically write to logbook2

log.output(logbook1);
log.output(logbook2);

// Final result
// status.log :
//   [FATAL] Log1 log
//
// test.log :
//   [FATAL] Log1 log
//   [FATAL] Log2 log

```

