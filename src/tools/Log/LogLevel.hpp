#ifndef __TOOLS__LOG__LOGLEVEL_HPP__
#define __TOOLS__LOG__LOGLEVEL_HPP__

// -------------------------------------------------------------------------------------------------
// -- LogLevel enum
// -------------------------------------------------------------------------------------------------
class LogLevel {
public:
  enum Enum {FATAL, ERROR, WARNING, INFO, DEBUG};

  LogLevel(Enum e) : m_e(e) {}
  operator Enum() const { return m_e; }
  explicit operator bool() const = delete;


private:
  Enum m_e;

public:
  bool important(Enum log_check) {
    return m_e <= log_check;
  }
};

#endif
