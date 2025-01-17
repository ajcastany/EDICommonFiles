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
    CentreTrailer(const char data_type,
                  const std::string& centre_number,
                  const std::string& number_records,
                  const std::string& created_date);
    // overrides
    const std::string &getRow() const override;

    // delete copy and move operator
    CentreTrailer(const CentreTrailer&) = delete;
    CentreTrailer& operator=(const CentreTrailer&) = delete;
    CentreTrailer(const CentreTrailer&&) = delete;
    CentreTrailer&& operator=(const CentreTrailer) = delete;
  };
} // namespace CommonFormatFile
