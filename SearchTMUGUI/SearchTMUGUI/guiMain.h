#pragma once
#include <time.h>
#include "TimerCustom.h"
#include "coordinate.h"
#include "Image.h"
#include <fstream>

struct information {
	static unsigned int x;
	static unsigned int y;
	static unsigned int debrisChance;
	static char** grid;
	static TimerCustom* timer;
};

namespace SearchTMUGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for guiMain
	/// </summary>
	public ref class guiMain : public System::Windows::Forms::Form
	{
	public:
		guiMain(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~guiMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblInfo;
	protected:
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Button^ btnSolve;

	private: System::Windows::Forms::Button^ btnSchedule;




	private: System::Windows::Forms::Button^ btnSettings;
	private: System::Windows::Forms::Button^ btnSet;
	private: System::Windows::Forms::NumericUpDown^ nUDX;
	private: System::Windows::Forms::NumericUpDown^ nUDY;
	private: System::Windows::Forms::Label^ lblX;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::PictureBox^ pbMain;





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnSolve = (gcnew System::Windows::Forms::Button());
			this->btnSchedule = (gcnew System::Windows::Forms::Button());
			this->btnSettings = (gcnew System::Windows::Forms::Button());
			this->btnSet = (gcnew System::Windows::Forms::Button());
			this->nUDX = (gcnew System::Windows::Forms::NumericUpDown());
			this->nUDY = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblX = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->pbMain = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMain))->BeginInit();
			this->SuspendLayout();
			// 
			// lblInfo
			// 
			this->lblInfo->AutoSize = true;
			this->lblInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.1F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInfo->ForeColor = System::Drawing::Color::Black;
			this->lblInfo->Location = System::Drawing::Point(217, 155);
			this->lblInfo->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(144, 31);
			this->lblInfo->TabIndex = 5;
			this->lblInfo->Text = L"Loading...";
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::Black;
			this->lblTitle->Location = System::Drawing::Point(177, -70);
			this->lblTitle->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(242, 46);
			this->lblTitle->TabIndex = 4;
			this->lblTitle->Text = L"SearchTMU";
			// 
			// btnSolve
			// 
			this->btnSolve->BackColor = System::Drawing::Color::White;
			this->btnSolve->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSolve->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSolve->Location = System::Drawing::Point(11, 445);
			this->btnSolve->Name = L"btnSolve";
			this->btnSolve->Size = System::Drawing::Size(173, 65);
			this->btnSolve->TabIndex = 6;
			this->btnSolve->Text = L"Solve";
			this->btnSolve->UseVisualStyleBackColor = false;
			this->btnSolve->Click += gcnew System::EventHandler(this, &guiMain::btnSolve_Click);
			// 
			// btnSchedule
			// 
			this->btnSchedule->BackColor = System::Drawing::Color::White;
			this->btnSchedule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSchedule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSchedule->Location = System::Drawing::Point(205, 445);
			this->btnSchedule->Name = L"btnSchedule";
			this->btnSchedule->Size = System::Drawing::Size(173, 65);
			this->btnSchedule->TabIndex = 7;
			this->btnSchedule->Text = L"Schedule";
			this->btnSchedule->UseVisualStyleBackColor = false;
			// 
			// btnSettings
			// 
			this->btnSettings->BackColor = System::Drawing::Color::White;
			this->btnSettings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSettings->Location = System::Drawing::Point(401, 445);
			this->btnSettings->Name = L"btnSettings";
			this->btnSettings->Size = System::Drawing::Size(173, 65);
			this->btnSettings->TabIndex = 8;
			this->btnSettings->Text = L"Settings";
			this->btnSettings->UseVisualStyleBackColor = false;
			this->btnSettings->Click += gcnew System::EventHandler(this, &guiMain::btnSettings_Click);
			// 
			// btnSet
			// 
			this->btnSet->BackColor = System::Drawing::Color::White;
			this->btnSet->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSet->Location = System::Drawing::Point(608, 92);
			this->btnSet->Name = L"btnSet";
			this->btnSet->Size = System::Drawing::Size(156, 66);
			this->btnSet->TabIndex = 9;
			this->btnSet->Text = L"Set";
			this->btnSet->UseVisualStyleBackColor = false;
			this->btnSet->Click += gcnew System::EventHandler(this, &guiMain::btnSet_Click);
			// 
			// nUDX
			// 
			this->nUDX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->nUDX->Location = System::Drawing::Point(608, 55);
			this->nUDX->Margin = System::Windows::Forms::Padding(1);
			this->nUDX->Name = L"nUDX";
			this->nUDX->Size = System::Drawing::Size(45, 30);
			this->nUDX->TabIndex = 10;
			// 
			// nUDY
			// 
			this->nUDY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->nUDY->Location = System::Drawing::Point(719, 55);
			this->nUDY->Margin = System::Windows::Forms::Padding(1);
			this->nUDY->Name = L"nUDY";
			this->nUDY->Size = System::Drawing::Size(45, 30);
			this->nUDY->TabIndex = 11;
			// 
			// lblX
			// 
			this->lblX->AutoSize = true;
			this->lblX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.1F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblX->ForeColor = System::Drawing::Color::Black;
			this->lblX->Location = System::Drawing::Point(674, 53);
			this->lblX->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->lblX->Name = L"lblX";
			this->lblX->Size = System::Drawing::Size(33, 31);
			this->lblX->TabIndex = 12;
			this->lblX->Text = L"X";
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::White;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBack->Location = System::Drawing::Point(608, 224);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(156, 66);
			this->btnBack->TabIndex = 13;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &guiMain::btnBack_Click);
			// 
			// pbMain
			// 
			this->pbMain->BackColor = System::Drawing::Color::Red;
			this->pbMain->Location = System::Drawing::Point(300, 200);
			this->pbMain->Name = L"pbMain";
			this->pbMain->Size = System::Drawing::Size(0, 0);
			this->pbMain->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbMain->TabIndex = 14;
			this->pbMain->TabStop = false;
			// 
			// guiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(584, 361);
			this->Controls->Add(this->pbMain);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->lblX);
			this->Controls->Add(this->nUDY);
			this->Controls->Add(this->nUDX);
			this->Controls->Add(this->btnSet);
			this->Controls->Add(this->btnSettings);
			this->Controls->Add(this->btnSchedule);
			this->Controls->Add(this->btnSolve);
			this->Controls->Add(this->lblInfo);
			this->Controls->Add(this->lblTitle);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"guiMain";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SearchTMU";
			this->Shown += gcnew System::EventHandler(this, &guiMain::guiMain_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMain))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance);
		System::Void guiMain_Shown(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSolve_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSettings_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSet_Click(System::Object^ sender, System::EventArgs^ e);

		char** readGrid(std::string fname, int* w, int* h) {
			*w = 0;
			std::vector<std::string> lines;
			std::fstream myfile;
			myfile.open(fname, std::ios::in);
			if (myfile.is_open()) {
				std::string line;
				while (getline(myfile, line)) {
					lines.push_back(line);
					if (line.length() > *w) {
						*w = line.length();
					}
				}
				myfile.close();
			}
			char** grid = new char* [lines.size()];
			for (int i = 0; i < lines.size(); i++) {
				grid[i] = new char[lines[0].length()];
				for (int j = 0; j < lines[0].length(); j++) {
					grid[i][j] = lines[i][j];
				}
			}
			*h = lines.size();
			return grid;
		}
};
}
