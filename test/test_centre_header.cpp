#include <gtest/gtest.h>
#include "CentreHeader.h"
#include "StringUtils.h"

TEST(CentreHeaderTest, ValidLength) {
  CommonFormatFile::CentreHeader header {'A', "00000", "40", "AA", "25", "001", "CF24 3QX"};
  std::string result = header.getRow();
  EXPECT_EQ(result.size(), 194);
}
