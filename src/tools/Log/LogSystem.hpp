#ifndef __TOOLS__LOG__LOGSYSTEM_HPP__
#define __TOOLS__LOG__LOGSYSTEM_HPP__

#include <cassert>
#include <cstdint>
#include <format>
#include <string>
#include <vector>

#include <tools/Log/LogBook.hpp>
#include <tools/Log/Logger.hpp>

// -------------------------------------------------------------------------------------------------
// -- LogSystem class
// -------------------------------------------------------------------------------------------------
typedef int8_t LogBookID;
typedef int8_t LoggerID;

#define INVALID_LOGBOOK_ID -1;
#define INVALID_LOGGER_ID  -1;


class LogSystem {
private:
  std::vector<std::pair<bool, LogBook>> m_logbook_list;
  std::vector<std::pair<bool, Logger>>  m_logger_list;

public:
  LogSystem();
  ~LogSystem();

  // Manage LogBook list and Logger list
  LogBookID addLogBook(LogLevel level);
  LogBookID addLogBook(LogLevel level, std::string outfile);
  void removeLogBook(LogBookID logbook);
  void clearLogBookList();

  LoggerID addLogger();
  LoggerID addLogger(LogTag tag);
  void removeLogger(LoggerID logger);
  void clearLoggerList();

  bool link(LogBookID logbook, LoggerID logger);
  bool unlink(LogBookID logbook, LoggerID logger);

  // Manage LogEntry
  #define LOGSYSTEM_LOG_FUNCTION_DECLARATION(func_name) \
  template<typename... Args> \
  void func_name(LoggerID logger, const std::format_string<Args...> fmt, Args&&... args);

  LOGSYSTEM_LOG_FUNCTION_DECLARATION(fatal);
  LOGSYSTEM_LOG_FUNCTION_DECLARATION(error);
  LOGSYSTEM_LOG_FUNCTION_DECLARATION(warning);
  LOGSYSTEM_LOG_FUNCTION_DECLARATION(info);
  LOGSYSTEM_LOG_FUNCTION_DECLARATION(debug);

  bool output(LogBookID logbook);
  
};

// -------------------------------------------------------------------------------------------------
// -- LogSystem : Logging functions
// -------------------------------------------------------------------------------------------------
#define LOGSYSTEM_LOG_FUNCTION_IMPLEMENTATION(func_name, log_level) \
template<typename... Args> \
void LogSystem::func_name(LoggerID logger, const std::format_string<Args...> fmt, Args&&... args) { \
  assert(logger < (int64_t)m_logger_list.size()); \
  assert(m_logger_list[logger].first); \
  m_logger_list[logger].second.log(log_level, \
                                   std::vformat(fmt.get(), std::make_format_args(args...))); \
}

LOGSYSTEM_LOG_FUNCTION_IMPLEMENTATION(fatal,   LogLevel::FATAL);
LOGSYSTEM_LOG_FUNCTION_IMPLEMENTATION(error,   LogLevel::ERROR);
LOGSYSTEM_LOG_FUNCTION_IMPLEMENTATION(warning, LogLevel::WARNING);
LOGSYSTEM_LOG_FUNCTION_IMPLEMENTATION(info,    LogLevel::INFO);
LOGSYSTEM_LOG_FUNCTION_IMPLEMENTATION(debug,   LogLevel::DEBUG);

#endif
