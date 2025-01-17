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
    CentreHeader(const char data_type, std::string const centre_number,
                 const std::string& ao, std::string const examination_series,
                 const std::string& year, std::string const sequence,
                 const std::string& centre_postcode);

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
