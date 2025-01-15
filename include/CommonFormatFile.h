#pragma once
#include <vector>
#include <memory>
#include <string>

class IRow;

namespace CommonFormatFile {
  /// @brief Constains the CommonFormatFile Entries and Ammendments file
  class CommonFormatFile {
  private:
    char m_dataType;
    std::string m_centreNumber;
    std::string m_aO;
    std::string m_examinationSeries;
    std::string m_year;
    std::string m_sequence;
    std::string m_centrePostcode;

    // Rows
    std::unique_ptr<IRow> m_fileHeader;
    std::unique_ptr<IRow> m_centreHeader;
    std::unique_ptr<IRow> m_centreTrailer;
    std::unique_ptr<IRow> m_fileTrailer;
    std::vector<std::unique_ptr<IRow>> m_detailRows;

  public:
    CommonFormatFile(char const data_type,
                     std::string const centre_number,
                     std::string const ao,
                     std::string const examination_series,
                     std::string const year,
                     std::string const sequence,
                     std::string const centre_postcode);
  };
}
