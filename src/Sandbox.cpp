#include "Buffer.h"
#include <iostream>

using namespace std;

int main()
{
   Buffer buffer;
   const string hexString = "49276d206b696c6c696e6720796f7"
                            "57220627261696e206c696b6520612"
                            "0706f69736f6e6f7573206d757368726f6f6d";

   buffer.SetValueHex(hexString);
   string b64String = buffer.GetValueB64();

   cout << b64String << endl;
}
