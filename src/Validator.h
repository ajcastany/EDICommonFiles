#include <string>
#include <regex>
#include <stdexcept>

namespace Validator {
  void validateString(const std::string &input, const std::string &regexPattern);
  void validateChar(const char input, const std::string &regexPattern);
}
