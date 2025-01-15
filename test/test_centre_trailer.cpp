#include <gtest/gtest.h>
#include <string>
#include "CentreTrailer.h"
#include "StringUtils.h"

TEST(CentreTrailerTest, ValidLength) {
  CommonFormatFile::CentreTrailer trailer{'A', "00000", "0000001", "010125"};
  std::string result = trailer.getRow();
  EXPECT_EQ(result.size(), 194);
}
