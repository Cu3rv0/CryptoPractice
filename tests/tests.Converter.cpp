#include <iostream>
#include "gtest/gtest.h"
#include "Converter.h"
#include <memory>

using namespace std;

class ConversionTests : public ::testing::Test 
{
public:
   unique_ptr<Converter> m_converter;

   ConversionTests():
      m_converter(make_unique<Converter>())
   {

   }
      
};

TEST_F(ConversionTests, converter_reads_right_hex_value)
{
   // Given

   const string hexString = "CAFE";
   const vector<unsigned int> expectedData = { 0b11001010,0b11111110 };

   //const unsigned int binaryValue = 0b1100101011111110;


}
