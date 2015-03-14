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

string Converter::GetValueHex() const
{
   return "HelloHex!";
}

unsigned char hexCharToBin(unsigned char hexChar)
{
   if (hexChar < 'A') return hexChar - '0';

   return hexChar - 'A' + 10;
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

