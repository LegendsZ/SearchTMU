#include "guiLoading.h"

System::Void SearchTMUGUI::guiLoading::guiLoading_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SearchTMUGUI::guiMain guiMain;
	guiMain.ShowDialog();
}
