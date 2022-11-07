#include "guiMain.h"

int main() {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	SearchTMUGUI::guiMain guiMain;
	System::Windows::Forms::Application::Run(% guiMain);
	return 0;
}