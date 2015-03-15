#include "Converter.h"
#include <algorithm>
#include <iostream>

using namespace std;

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
   return "HELLOHEX";
}

void Converter::SetValueHex(const string& hexString)
{
   for_each(hexString.begin(),
            hexString.end(),
            [this](unsigned char c) mutable
            {
               for(auto i = 3; i >= 0; --i)
               {
                  m_dataBlob.push_back((hexCharToBin(c) >> i) & 1);
               }
            });
}

vector<bool> Converter::GetValueBinary() const
{
   return m_dataBlob;
}

