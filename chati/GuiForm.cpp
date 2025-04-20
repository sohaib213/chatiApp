#include "GuiForm.h"
#include "Globals.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
	
int main(cli::array<String^>^ args) {
	 
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

	std::cout << "Console window initialized!" << std::endl;
	

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	chati::GuiForm form;
	Application::Run(% form);

	
	return 0;
}