#include "Validator.h"

namespace Validator {
  void validateString(const std::string &input, const std::string &regexPattern) {
    std::regex pattern{regexPattern};
    if (!std::regex_match(input, pattern)) {
      throw std::invalid_argument("Input string: " + input + " does not match Regex: " + regexPattern);
    }
}

  void validateChar(const char input, const std::string &alloweChars) {
    if (alloweChars.find(input) == std::string::npos) {
      throw std::invalid_argument("Input Char: " + std::string(1, input) +
                                  " does not match Regex: " + alloweChars);
    }
  }
}
