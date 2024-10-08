#include "LogSystem.hpp"

#include <cassert>
#include <cstdint>
#include <format>
#include <string>
#include <vector>

#include "LogBook.hpp"
#include "Logger.hpp"

// -------------------------------------------------------------------------------------------------
// -- LogSystem default logging
// -------------------------------------------------------------------------------------------------
bool    LogSystem::m_init    = false;
LogBook LogSystem::m_logbook = LogBook(LogLevel::INFO);
Logger  LogSystem::m_logger  = Logger();

void LogSystem::setLogLevel(LogLevel level) {
  m_logbook.setLevel(level);
}


// -------------------------------------------------------------------------------------------------
// -- LogSystem constructor and destructor
// -------------------------------------------------------------------------------------------------
LogSystem::LogSystem() :
  m_logbook_list(std::vector<std::pair<bool, LogBook>>()),
  m_logger_list(std::vector<std::pair<bool, Logger>>()) {
  if (!m_init) {
    m_logger.addLogBook(&m_logbook);
    m_init = true;
  }
}

LogSystem::~LogSystem() {
  this->clearLoggerList();
  this->clearLogBookList();
}


// -------------------------------------------------------------------------------------------------
// -- Manage LogBook list
// -------------------------------------------------------------------------------------------------
LogBookID LogSystem::addLogBook(LogLevel level) {
  // Check for LogBook with duplicate outfile
  for (uint64_t i = 0; i < m_logbook_list.size(); i++) {
    if (m_logbook_list[i].first && m_logbook_list[i].second.outfile() == "") {
      fprintf(stderr,
              "[ WARN] [C-LOG] [LOGSYSTEM] Attempted to add LogBook with duplicate outfile \"\"\n");
      return INVALID_LOGBOOK_ID;
    }
  }
  m_logbook_list.push_back(std::pair<bool, LogBook>(true, LogBook(level)));
  return { (int8_t)(m_logbook_list.size() - 1) };
}

LogBookID LogSystem::addLogBook(LogLevel level, std::string outfile) {
  // Check for LogBook with duplicate outfile
  for (uint64_t i = 0; i < m_logbook_list.size(); i++) {
    if (m_logbook_list[i].first && m_logbook_list[i].second.outfile() == outfile) {
      fprintf(stderr,
              "[ WARN] [C-LOG] [LOGSYSTEM] Attempted to add LogBook with duplicate outfile \"%s\"\n",
              outfile.c_str());
      return INVALID_LOGBOOK_ID;
    }
  }
  m_logbook_list.push_back(std::pair<bool, LogBook>(true, LogBook(level, outfile)));
  return { (int8_t)(m_logbook_list.size() - 1) };
}

void LogSystem::removeLogBook(LogBookID logbook) {
  // Sanity check
  assert(logbook.id < (int64_t)m_logbook_list.size());

  m_logbook_list[logbook.id].first = false;
  m_logbook_list[logbook.id].second.~LogBook();
}

void LogSystem::clearLogBookList() {
  m_logbook_list.clear();
}


// -------------------------------------------------------------------------------------------------
// -- Manage Logger list
// -------------------------------------------------------------------------------------------------
LoggerID LogSystem::addLogger() {
  m_logger_list.push_back(std::pair<bool, Logger>(true, Logger()));
  return { (int8_t)(m_logger_list.size() - 1) };
}
LoggerID LogSystem::addLogger(LogTag tag) {
  m_logger_list.push_back(std::pair<bool, Logger>(true, Logger(tag)));
  return { (int8_t)(m_logger_list.size() - 1) };
}

void LogSystem::removeLogger(LoggerID logger) {
  // Sanity check
  assert(logger.id < (int64_t)m_logger_list.size());

  m_logger_list[logger.id].first = false;
  m_logger_list[logger.id].second.~Logger();
}

void LogSystem::clearLoggerList() {
  m_logger_list.clear();
}


// -------------------------------------------------------------------------------------------------
// -- Linking Logger to LogBook
// -------------------------------------------------------------------------------------------------
bool LogSystem::link(LogBookID logbook, LoggerID logger) {
  // Sanity check
  assert(logbook.id < (int64_t)m_logbook_list.size());
  assert(logger.id < (int64_t)m_logger_list.size());

  return m_logger_list[logger.id].second.addLogBook(&(m_logbook_list[logbook.id].second));
}

bool LogSystem::unlink(LogBookID logbook, LoggerID logger) {
  // Sanity check
  assert(logbook.id < (int64_t)m_logbook_list.size());
  assert(logger.id < (int64_t)m_logger_list.size());

  return m_logger_list[logger.id].second.removeLogBook(&(m_logbook_list[logbook.id].second));
}


// -------------------------------------------------------------------------------------------------
// -- Manage LogEntry
// -------------------------------------------------------------------------------------------------
bool LogSystem::output() {
  assert(m_init);

  return m_logbook.output();
}

bool LogSystem::output(LogBookID logbook) {
  assert(logbook.id < (int64_t)m_logbook_list.size());

  return m_logbook_list[logbook.id].second.output();
}

