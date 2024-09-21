#ifndef __TOOLS__LOG__LOGGER_HPP__
#define __TOOLS__LOG__LOGGER_HPP__

#include <list>
#include <string>

#include <tools/Log/LogBook.hpp>
#include <tools/Log/LogLevel.hpp>
#include <tools/Log/LogTag.hpp>

// -------------------------------------------------------------------------------------------------
// -- Logger class
// -------------------------------------------------------------------------------------------------
class Logger {
private:
  LogTag m_tag;

  std::list<LogBook*> m_logbook_list;

private:
  // Logger constructor and destructor
  Logger();
  Logger(LogTag tag);
  ~Logger();

  // Manage LogBook list
  bool addLogBook(LogBook* logbook);
  bool removeLogBook(LogBook* logbook);
  void clearLogBookList();

  // Logging
  void log(LogLevel level, std::string message);
};
#endif
