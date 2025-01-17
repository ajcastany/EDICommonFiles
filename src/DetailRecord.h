#pragma once
#include "IRow.h"
#include <string>
#include <vector>

namespace CommonFormatFile {
  /// @brief Contains Detail Record data and builds the string row
  class DetailRecord : public IRow {
  private:
    char m_dataType;
    static constexpr char RECORD_TYPE = '5';
    char m_candidateStatus; //'C' or 'P'
    std::string m_centreNumber;
    std::string m_candidateNumber;
    std::string m_candidateName;
    char m_sex;
    std::string m_UCI;
    std::string m_UPN;
    std::string m_ULN;
    char m_qualifierFlag; // 'G', 'P' or ' '
    std::string m_optionalCentreNumber;
    std::string m_optionalCandidateNumber;
    std::string m_documentationGroup;
    std::vector<std::string> m_entries;
  public:
    DetailRecord(const char dataType,
                 const char candidateStatus,
                 const std::string& centreNumber,
                 const std::string& candidateName,
                 const char sex,
                 const std::string& uci,
                 const std::string& upn,
                 std::string const uln,
                 const char qualifierFlag,
                 const std::string& optionalCentreNumber,
                 const std::string& optionalCandidateNumber,
                 const std::string& documentationGroup,
                 const std::vector<std::string&> entries
                 );
    const std::string& getRow() const override;

    //Delete copy and move
    DetailRecord(const DetailRecord&) = delete;
    DetailRecord& operator=(const DetailRecord&) = delete;
    DetailRecord(const DetailRecord &&) = delete;
    DetailRecord &operator=(const DetailRecord&&) = delete;
  };
}
