#pragma once
#include "IRow.h"

namespace CommonFormatFile {
  class CentreHeader : public IRow {
  private:
    char m_dataType;
    static constexpr char RECORD_TYPE = '3';
    std::string m_centreNumber;
    std::string m_aO;
    std::string m_examinationSeries;
    std::string m_year;
    std::string m_sequence;
    std::string m_centrePostcode;

  public:
    CentreHeader(char const data_type,
                 std::string const centre_number,
                 std::string const ao,
                 std::string const examination_series,
                 std::string const year,
                 std::string const sequence,
                 std::string const centre_postcode);

    // overrides
    const std::string& getRow() const override;

    // delete copy constructor and operator;
    CentreHeader(const CentreHeader&) = delete;
    CentreHeader& operator=(const CentreHeader&) = delete;
    // delete move
    CentreHeader(const CentreHeader&&) = delete;
    CentreHeader& operator=(const CentreHeader&&) = delete;
  };
}
