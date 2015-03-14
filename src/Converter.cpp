#include "Converter.h"
#include <algorithm>
#include <iostream>

using namespace std;

Converter::Converter():
   m_lastCharSize(0),
   m_data()
{
}

string Converter::GetValueB64() const
{
   return "Hello!";
}

unsigned char BinToHexChar(unsigned char bin)
{
   if (bin < 10) return '0' + bin;

   return 'A' + bin - 10;
}

unsigned char hexCharToBin(unsigned char hexChar)
{
   if (hexChar < 'A') return hexChar - '0';

   return hexChar - 'A' + 10;
}

string Converter::GetValueHex() const
{
   string hexString;
   for(auto index = 0; index < m_data.size(); ++index)
   {
      unsigned char leastSignificantNibble = m_data[index] & 0xF;
      unsigned char mostSignificantNibble = (m_data[index] & 0xF << 4) >> 4;

      hexString += BinToHexChar(mostSignificantNibble);
      if (index < m_data.size() -1 || !m_lastCharSize)
         hexString += BinToHexChar(leastSignificantNibble);
   }

   return hexString;
}

void Converter::SetValueHex(const string& hexString)
{
   m_data.clear();
   m_lastCharSize = 0;

   for_each(hexString.begin(),
            hexString.end(),
            [this](const unsigned char c) mutable
             {
                 if (m_lastCharSize)
                 {
                    m_data.back() += ((hexCharToBin(c)));
                    m_lastCharSize = 0;
                 }
                 else
                 {
                    m_data.push_back(hexCharToBin(c) << 4);
                    m_lastCharSize = 4;
                 }
             });
}

vector<unsigned char> Converter::GetValueBinary() const
{
   return m_data;
}

