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

TEST_F(ConversionTests, converter_reads_and_outputs_right_hex_value)
{
   // Given
   const string hexString = "CAFE";
   const vector<unsigned char> expectedData = { 0b11001010,0b11111110 };
   
   m_converter->SetValueHex(hexString);

   //When
   //Then
   ASSERT_EQ(expectedData,m_converter->GetValueBinary());
   ASSERT_EQ(hexString,m_converter->GetValueHex());
}

TEST_F(ConversionTests, converter_outputs_right_hex_value)
{
   //
}
