#include "Gui.h"

int main() {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	SearchTMUGUI::Gui gui;
	System::Windows::Forms::Application::Run(% gui);
	return 0;
}