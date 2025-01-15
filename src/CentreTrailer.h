#pragma once
#include "IRow.h"

/// @namespace CommonFormatFile
/// @brief Provides the headers, trailers and detail rows for JCQ Common Format
/// Files
///
/// This namespace contains all the rows to create Common Format Files
namespace CommonFormatFile {
  /// @brief Validates and contains the Centre Trailer
  class CentreTrailer : public IRow {
  private:
    char const m_dataType;
    static constexpr char RECORD_TYPE = '7';
    std::string m_centreNumber;
    std::string m_numberRecords;
    std::string m_createdDate; // ddmmyy
  public:
    CentreTrailer(char const data_type, std::string const centre_number,
                  std::string const number_records,
                  std::string const created_date);
    // overrides
    const std::string &getRow() const override;
  };
} // namespace CommonFormatFile
