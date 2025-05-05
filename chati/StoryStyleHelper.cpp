#include <string>
#include <msclr/marshal_cppstd.h>
using namespace System;
using namespace System::Drawing;
using namespace System::Globalization;

public ref class StoryStyleHelper
{
public:
   // Load the font and the color again
   static void LoadFontAndColor(std::string fontName, float fontSize, int fontStyleAsInt, std::string colorHex,
       System::Drawing::Font^% font, System::Drawing::Color% color)
   {
       String^ fontNameString = msclr::interop::marshal_as<String^>(fontName);
       String^ colorHexString = msclr::interop::marshal_as<String^>(colorHex);

       FontStyle fontStyle = (FontStyle)fontStyleAsInt;
       font = gcnew Font(fontNameString, fontSize, fontStyle);
       color = ColorTranslator::FromHtml(colorHexString);
   }
};
