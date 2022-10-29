#pragma once
#include <time.h>
#include "TimerCustom.h"

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
	private: System::Windows::Forms::Button^ btnGenerate;
	private: System::Windows::Forms::Button^ btnSchedule;




	private: System::Windows::Forms::Button^ btnSettings;

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
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->btnSchedule = (gcnew System::Windows::Forms::Button());
			this->btnSettings = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblInfo
			// 
			this->lblInfo->AutoSize = true;
			this->lblInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.1F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInfo->ForeColor = System::Drawing::Color::Black;
			this->lblInfo->Location = System::Drawing::Point(217, 177);
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
			// btnGenerate
			// 
			this->btnGenerate->BackColor = System::Drawing::Color::White;
			this->btnGenerate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGenerate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGenerate->Location = System::Drawing::Point(12, 445);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(173, 65);
			this->btnGenerate->TabIndex = 6;
			this->btnGenerate->Text = L"Generate";
			this->btnGenerate->UseVisualStyleBackColor = false;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &guiMain::btnGenerate_Click);
			// 
			// btnSchedule
			// 
			this->btnSchedule->BackColor = System::Drawing::Color::White;
			this->btnSchedule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSchedule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSchedule->Location = System::Drawing::Point(207, 445);
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
			this->btnSettings->Location = System::Drawing::Point(402, 445);
			this->btnSettings->Name = L"btnSettings";
			this->btnSettings->Size = System::Drawing::Size(173, 65);
			this->btnSettings->TabIndex = 8;
			this->btnSettings->Text = L"Settings";
			this->btnSettings->UseVisualStyleBackColor = false;
			// 
			// guiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(587, 426);
			this->Controls->Add(this->btnSettings);
			this->Controls->Add(this->btnSchedule);
			this->Controls->Add(this->btnGenerate);
			this->Controls->Add(this->lblInfo);
			this->Controls->Add(this->lblTitle);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"guiMain";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SearchTMU";
			this->Shown += gcnew System::EventHandler(this, &guiMain::guiMain_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance);
		System::Void guiMain_Shown(System::Object^ sender, System::EventArgs^ e);
		System::Void btnGenerate_Click(System::Object^ sender, System::EventArgs^ e) {
			information::timer->start();
			information::grid = generateMaze(information::x, information::y, information::debrisChance);
			information::timer->stop();
		}
};
}
