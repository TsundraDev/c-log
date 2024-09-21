#ifndef __TOOLS__LOG__LOGENTRY_HPP__
#define __TOOLS__LOG__LOGENTRY_HPP__

#include <string>

#include <tools/Log/LogLevel.hpp>
#include <tools/Log/LogTag.hpp>

// -------------------------------------------------------------------------------------------------
// -- LogEntry enum
// -------------------------------------------------------------------------------------------------
typedef struct {
  LogLevel level;
  LogTag   tag;
  std::string message;
} LogEntry;


#endif
