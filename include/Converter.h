#pragma once
#include <string>
#include <vector>

class Converter
{
public:
   std::string GetValueB64() const;
   std::string GetValueHex() const;
   std::vector<bool> GetValueBinary() const;

   void SetValueHex(const std::string& hexString);
   void SetValueB64(const std::string& b64String);
   void SetValueBinary(std::vector<unsigned char> data, unsigned int size);

private:
   
   std::vector<bool> m_dataBlob;
};
