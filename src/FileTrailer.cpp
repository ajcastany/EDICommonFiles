#include "FileTrailer.h"
#include <sstream>
#include "StringUtils.h"
#include "Validator.h"

CommonFormatFile::FileTrailer::FileTrailer(char const data_type,
                                           std::string const centre_number,
                                           std::string const number_records,
                                           std::string const number_centres)
  : m_dataType{data_type},
    m_centreNumber{centre_number},
    m_numberRecords{[&]() {
      Validator::validateString(number_records, "\\d{7}");
      return number_records;
    }()},
    m_numberCentres{number_centres} {
  std::ostringstream oss;
  oss << m_dataType << RECORD_TYPE << m_centreNumber << m_numberRecords << m_numberCentres;
  m_row = rpad(oss.str());
}

const std::string& CommonFormatFile::FileTrailer::getRow() const {
  return m_row;}
