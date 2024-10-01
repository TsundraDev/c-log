#include <cstdio>

#include "Log/Log.hpp"

int main() {

  printf("c-log\n");

  LogSystem log = LogSystem();

  log.setLogLevel(LogLevel::INFO);
  log.warn("Warning warning");

  return 0;
}
