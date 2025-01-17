#include "CentreHeader.h"
#include <sstream>
#include "StringUtils.h"
#include "Validator.h"

CommonFormatFile::CentreHeader::CentreHeader(
    char const data_type,
    const std::string& centre_number,
    const std::string& ao,
    const std::string& examination_series,
    const std::string& year,
    const std::string& sequence,
    const std::string& centre_postcode)
    : m_dataType{[&]() {
        Validator::validateChar(data_type, "AE");
        return data_type;
      }()},
      m_centreNumber{[&]() {
        Validator::validateString(centre_number,
                                  "(^[1-9ABC]{2}\\d{2}[B_]$)|(\\d{5})");
        return centre_number;
      }()},
      m_aO{[&]() {
        Validator::validateString(ao, "\\d{2}");
        return ao;
      }()},
      m_examinationSeries{[&]() {
        Validator::validateString(examination_series, "^[1-9ABC]{2}$");
        return examination_series;
      }()},
      m_year{[&]() {
        Validator::validateString(year, "\\d{2}");
        return year;
      }()},
      m_sequence{[&]() {
        Validator::validateString(sequence, "\\d{3}");
        return sequence;
      }()},
      m_centrePostcode{[&]() {
        Validator::validateString(centre_postcode, "^[A-Z0-9 ]{8}");
        return centre_postcode;
      }()} {
  std::ostringstream oss;
  oss << m_dataType << RECORD_TYPE << m_centreNumber << m_aO
      << m_examinationSeries << m_year << m_sequence << m_centrePostcode;
  m_row = rpad(oss.str());
}

const std::string& CommonFormatFile::CentreHeader::getRow() const {
  return m_row;
}
