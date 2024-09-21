#include <cstdio>

#include <tools/Log.hpp>

int main() {

  printf("c-log\n");

  LogSystem log = LogSystem();

  log.setLogLevel(LogLevel::FATAL);
  log.warn("Warning warning");

  return 0;
}
