#include "CentreTrailer.h"
#include <sstream>
#include "StringUtils.h"
#include "Validator.h"

CommonFormatFile::CentreTrailer::CentreTrailer(char data_type,
                                               std::string const centre_number,
                                               std::string const number_records,
                                               std::string const created_date)
    : m_dataType{[&]() {
        Validator::validateChar(data_type, "AE");
        return data_type;
      }()},
      m_centreNumber{[&]() {
        Validator::validateString(centre_number,
                                  "(^[1-9ABC]{2}\\d{2}[B_]$)|(\\d{5})");
        return centre_number;
      }()},
      m_numberRecords{[&]() {
          Validator::validateString(number_records, "\\d{7}");
          return number_records;
      }()},
      m_createdDate{[&]() {
        Validator::validateString(created_date, "\\d{6}");
        return created_date;
      }()} {
  std::ostringstream oss;
  oss << m_dataType << RECORD_TYPE << m_centreNumber << m_numberRecords << m_createdDate;
  m_row = rpad(oss.str());
}

const std::string& CommonFormatFile::CentreTrailer::getRow() const {
  return m_row;
}
