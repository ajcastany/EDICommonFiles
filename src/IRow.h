#pragma once
#include <string>

namespace CommonFormatFile {
  class IRow {
  protected:
    std::string m_row;
  public:
    virtual ~IRow() = default;
    virtual const std::string& getRow() const = 0;
  };
} // namespace CommonFormatFile
