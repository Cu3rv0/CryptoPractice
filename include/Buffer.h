#pragma once
#include <string>
#include <vector>

class Buffer
{
public:
   Buffer(std::vector<bool>);
   Buffer();

   std::string GetValueB64() const;
   std::string GetValueHex() const;
   const std::vector<bool>& GetValueBinary() const;
   unsigned int Size() const;

   void SetValueHex(const std::string& hexString);
   void SetValueB64(const std::string& b64String);
   void SetValueBinary(std::vector<unsigned char> data, unsigned int size);

private:
   
   std::vector<bool> m_dataBlob;
};
