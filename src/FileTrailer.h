#pragma once
#include "IRow.h"

namespace CommonFormatFile {
  /// @brief Contains the File Trailer for JCQ Common Formats File
  class FileTrailer : public IRow {
  private:
    char m_dataType;
    static constexpr char RECORD_TYPE = '9';
    std::string m_centreNumber;
    std::string m_numberRecords;
    std::string m_numberCentres;

  public:
    FileTrailer(char const data_type, std::string const centre_number,
                std::string const number_records,
                std::string const number_centres);
    const std::string& getRow() const override;
  };
} // namespace CommonFormatFile
