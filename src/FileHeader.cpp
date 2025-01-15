#include "FileHeader.h"
#include <sstream>
#include "StringUtils.h"
#include "Validator.h"

/// @brief Constructor that validates the params, and builds the File Header row with rpad of 194 spaces
CommonFormatFile::FileHeader::FileHeader(char const data_type,
                                         std::string const centre_number,
                                         std::string const ao,
                                         std::string const examination_series,
                                         std::string const year,
                                         char const dist_type)
  : m_dataType{[&]() {
    Validator::validateChar(data_type, "AE");
    return data_type;
  }()},
    m_centreNumber{[&]() {
      if (dist_type == 'S') {
        Validator::validateString(centre_number, "\\d{5}");
        return centre_number;
      }
      else {
        Validator::validateString(centre_number, "^[1-9ABC]{2}\\d{2}[B_]$");
        return centre_number;
      }
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
    m_distType{[&]() {
      Validator::validateChar(dist_type, "SBM");
      return dist_type;
    }()} {
  std::ostringstream oss;
  oss << m_dataType << RECORD_TYPE << m_centreNumber << m_aO
      << m_examinationSeries << m_year << m_distType << SOFTWARE_PACKAGE
      << SOFTWARE_VERSION << FORMATS_VERSION;
  m_row = rpad(oss.str());
}

const std::string &CommonFormatFile::FileHeader::getRow() const {
  return m_row;
    }
