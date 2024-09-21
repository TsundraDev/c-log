#include <cstdio>

#include <tools/Log.hpp>

int main() {

  printf("c-log\n");

  LogSystem log = LogSystem();
  LogBookID logbook = log.addLogBook(LogLevel::INFO);
  LoggerID  logger  = log.addLogger();
  log.link(logbook, logger);
  log.warning(logger, "Hello");

  return 0;
}
