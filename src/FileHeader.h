#pragma once
#include <string_view>
#include "IRow.h"

/// @namespace CommonFormatFile
/// @brief Provides the headers, trailers and detail rows for JCQ Common Format Files
///
/// This namespace contains all the rows to create Common Format Files
namespace CommonFormatFile {

  /// @brief Validates and contains a File Header for JCQ Common Format Files
  class FileHeader : public IRow {
  private:
    char m_dataType;
    static constexpr char RECORD_TYPE = '1';
    std::string m_centreNumber;
    std::string m_aO;
    std::string m_examinationSeries;
    std::string m_year;
    char m_distType;
    static constexpr std::string_view SOFTWARE_PACKAGE = "QTCXX  ";
    static constexpr std::string_view SOFTWARE_VERSION = "01";
    static constexpr std::string_view FORMATS_VERSION = "14";

  public:
    FileHeader(char const data_type,
               std::string const centre_number,
               std::string const ao,
               std::string const examination_series,
               std::string const year,
               char const dist_type);
    // overrides
    const std::string& getRow() const override;

    // delete copy and move constructor
    FileHeader(const FileHeader&) = delete;
    FileHeader& operator=(const FileHeader&) = delete;
    // delete move operator and constructor
    FileHeader(const FileHeader&&) = delete;
    FileHeader& operator=(const FileHeader&&) = delete;
};
} // namespace CommonFormatFile
