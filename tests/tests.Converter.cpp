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
   const vector<bool> expectedData = { 1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0 };
   
   m_converter->SetValueHex(hexString);

   //When
   //Then
   ASSERT_EQ(expectedData,m_converter->GetValueBinary());
   ASSERT_EQ(hexString,m_converter->GetValueHex());
}

TEST_F(ConversionTests, converter_reads_and_outputs_right_b64_value)
{
   // Given
   const string b64String = "SSdt";
   const vector<bool> expectedData = {0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,1,0,1};

   m_converter->SetValueB64(b64String);
   //When
   //Then
   ASSERT_EQ(expectedData,m_converter->GetValueBinary());
   ASSERT_EQ(b64String,m_converter->GetValueB64());
}
