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
    FileTrailer(const char data_type,
                const std::string& centre_number,
                const std::string& number_records,
                const std::string& number_centres);
    const std::string& getRow() const override;

    // delete copy and move
    FileTrailer(const FileTrailer&) = delete;
    FileTrailer& operator=(FileTrailer&) = delete;
    FileTrailer(const FileTrailer&&) = delete;
    FileTrailer& operator=(FileTrailer&&) = delete;

  };
} // namespace CommonFormatFile
