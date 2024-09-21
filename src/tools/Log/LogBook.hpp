#ifndef __TOOLS__LOG__LOGBOOK_HPP__
#define __TOOLS__LOG__LOGBOOK_HPP__

#include <list>
#include <queue>
#include <string>

#include <tools/Log/LogEntry.hpp>
#include <tools/Log/LogLevel.hpp>

class Logger;

// -------------------------------------------------------------------------------------------------
// -- LogBook class
// -------------------------------------------------------------------------------------------------
class LogBook {
private:
  LogLevel m_level;
  std::string m_outfile;

  std::list<Logger*> m_logger_list;
  std::queue<LogEntry> m_logbook;

public:
  // LogBook constructor and destructor
  LogBook(LogLevel level);
  LogBook(LogLevel level, std::string outfile);
  ~LogBook();

  // Manage Logger list
  bool addLogger(Logger* logger);
  bool removeLogger(Logger* logger);

  // Manage LogEntry
  void log(LogLevel level, LogTag tag, std::string message);
  bool output();

private:
  std::string logEntryString(LogEntry log_entry);
};

#endif
