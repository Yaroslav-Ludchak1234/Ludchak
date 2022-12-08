#define NULL nullptr
#include "ClinicWinForm.h"
#include "DepartmentsWinForm.h"
#include "DoctorWinForm.h"
#include "PatientWinForm.h"
#include "ReceptionOrderWinForm.h"
#pragma once


namespace Ludchak {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: Bunifu::Framework::UI::BunifuTileButton^ bunifuTileButton1;
	private: System::Windows::Forms::Panel^ panelDesktopPanel;

	private: Bunifu::Framework::UI::BunifuTileButton^ bunifuTileButton2;
	private: Bunifu::Framework::UI::BunifuTileButton^ bunifuTileButton3;
	private: Bunifu::Framework::UI::BunifuTileButton^ bunifuTileButton4;
	private: Bunifu::Framework::UI::BunifuTileButton^ bunifuTileButton5;
	private: Bunifu::Framework::UI::BunifuTileButton^ bunifuTileButton6;
	public:Form^ activeForm;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bunifuTileButton1 = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->panelDesktopPanel = (gcnew System::Windows::Forms::Panel());
			this->bunifuTileButton2 = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->bunifuTileButton3 = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->bunifuTileButton4 = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->bunifuTileButton5 = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->bunifuTileButton6 = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1924, 43);
			this->panel1->TabIndex = 2;
			// 
			// bunifuTileButton1
			// 
			this->bunifuTileButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->bunifuTileButton1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bunifuTileButton1->color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton1->colorActive = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(124)));
			this->bunifuTileButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuTileButton1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F));
			this->bunifuTileButton1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuTileButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTileButton1.Image")));
			this->bunifuTileButton1->ImagePosition = 20;
			this->bunifuTileButton1->ImageZoom = 50;
			this->bunifuTileButton1->LabelPosition = 41;
			this->bunifuTileButton1->LabelText = L"";
			this->bunifuTileButton1->Location = System::Drawing::Point(0, 43);
			this->bunifuTileButton1->Margin = System::Windows::Forms::Padding(6);
			this->bunifuTileButton1->Name = L"bunifuTileButton1";
			this->bunifuTileButton1->Size = System::Drawing::Size(128, 129);
			this->bunifuTileButton1->TabIndex = 3;
			this->bunifuTileButton1->Click += gcnew System::EventHandler(this, &MyForm::bunifuTileButton1_Click);
			// 
			// panelDesktopPanel
			// 
			this->panelDesktopPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->panelDesktopPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelDesktopPanel.BackgroundImage")));
			this->panelDesktopPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panelDesktopPanel->Location = System::Drawing::Point(128, 43);
			this->panelDesktopPanel->Name = L"panelDesktopPanel";
			this->panelDesktopPanel->Size = System::Drawing::Size(1931, 1018);
			this->panelDesktopPanel->TabIndex = 4;
			// 
			// bunifuTileButton2
			// 
			this->bunifuTileButton2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bunifuTileButton2->color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton2->colorActive = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(124)));
			this->bunifuTileButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuTileButton2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bunifuTileButton2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuTileButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTileButton2.Image")));
			this->bunifuTileButton2->ImagePosition = 25;
			this->bunifuTileButton2->ImageZoom = 50;
			this->bunifuTileButton2->LabelPosition = 26;
			this->bunifuTileButton2->LabelText = L"";
			this->bunifuTileButton2->Location = System::Drawing::Point(0, 168);
			this->bunifuTileButton2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->bunifuTileButton2->Name = L"bunifuTileButton2";
			this->bunifuTileButton2->Size = System::Drawing::Size(128, 125);
			this->bunifuTileButton2->TabIndex = 5;
			this->bunifuTileButton2->Click += gcnew System::EventHandler(this, &MyForm::bunifuTileButton2_Click);
			// 
			// bunifuTileButton3
			// 
			this->bunifuTileButton3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->bunifuTileButton3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bunifuTileButton3->color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton3->colorActive = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(124)));
			this->bunifuTileButton3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuTileButton3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->bunifuTileButton3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuTileButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTileButton3.Image")));
			this->bunifuTileButton3->ImagePosition = 25;
			this->bunifuTileButton3->ImageZoom = 50;
			this->bunifuTileButton3->LabelPosition = 26;
			this->bunifuTileButton3->LabelText = L"";
			this->bunifuTileButton3->Location = System::Drawing::Point(0, 290);
			this->bunifuTileButton3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->bunifuTileButton3->Name = L"bunifuTileButton3";
			this->bunifuTileButton3->Size = System::Drawing::Size(128, 125);
			this->bunifuTileButton3->TabIndex = 6;
			this->bunifuTileButton3->Click += gcnew System::EventHandler(this, &MyForm::bunifuTileButton3_Click);
			// 
			// bunifuTileButton4
			// 
			this->bunifuTileButton4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->bunifuTileButton4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bunifuTileButton4->color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton4->colorActive = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(124)));
			this->bunifuTileButton4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuTileButton4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->bunifuTileButton4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuTileButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTileButton4.Image")));
			this->bunifuTileButton4->ImagePosition = 25;
			this->bunifuTileButton4->ImageZoom = 50;
			this->bunifuTileButton4->LabelPosition = 26;
			this->bunifuTileButton4->LabelText = L"";
			this->bunifuTileButton4->Location = System::Drawing::Point(0, 412);
			this->bunifuTileButton4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->bunifuTileButton4->Name = L"bunifuTileButton4";
			this->bunifuTileButton4->Size = System::Drawing::Size(128, 125);
			this->bunifuTileButton4->TabIndex = 7;
			this->bunifuTileButton4->Click += gcnew System::EventHandler(this, &MyForm::bunifuTileButton4_Click);
			// 
			// bunifuTileButton5
			// 
			this->bunifuTileButton5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->bunifuTileButton5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bunifuTileButton5->color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton5->colorActive = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(124)));
			this->bunifuTileButton5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuTileButton5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->bunifuTileButton5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuTileButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTileButton5.Image")));
			this->bunifuTileButton5->ImagePosition = 25;
			this->bunifuTileButton5->ImageZoom = 50;
			this->bunifuTileButton5->LabelPosition = 26;
			this->bunifuTileButton5->LabelText = L"";
			this->bunifuTileButton5->Location = System::Drawing::Point(0, 535);
			this->bunifuTileButton5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->bunifuTileButton5->Name = L"bunifuTileButton5";
			this->bunifuTileButton5->Size = System::Drawing::Size(128, 125);
			this->bunifuTileButton5->TabIndex = 8;
			this->bunifuTileButton5->Click += gcnew System::EventHandler(this, &MyForm::bunifuTileButton5_Click);
			// 
			// bunifuTileButton6
			// 
			this->bunifuTileButton6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->bunifuTileButton6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bunifuTileButton6->color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuTileButton6->colorActive = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(124)));
			this->bunifuTileButton6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuTileButton6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9));
			this->bunifuTileButton6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuTileButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTileButton6.Image")));
			this->bunifuTileButton6->ImagePosition = 25;
			this->bunifuTileButton6->ImageZoom = 50;
			this->bunifuTileButton6->LabelPosition = 26;
			this->bunifuTileButton6->LabelText = L"EXIT";
			this->bunifuTileButton6->Location = System::Drawing::Point(0, 874);
			this->bunifuTileButton6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->bunifuTileButton6->Name = L"bunifuTileButton6";
			this->bunifuTileButton6->Size = System::Drawing::Size(128, 125);
			this->bunifuTileButton6->TabIndex = 9;
			this->bunifuTileButton6->Click += gcnew System::EventHandler(this, &MyForm::bunifuTileButton6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(1924, 982);
			this->Controls->Add(this->bunifuTileButton6);
			this->Controls->Add(this->bunifuTileButton4);
			this->Controls->Add(this->bunifuTileButton5);
			this->Controls->Add(this->bunifuTileButton3);
			this->Controls->Add(this->bunifuTileButton2);
			this->Controls->Add(this->panelDesktopPanel);
			this->Controls->Add(this->bunifuTileButton1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	public:	void OpenChildForm(Form^ childForm, Object^ sender) {
		if (this->activeForm != nullptr)
		{
			this->activeForm->Close();
		}
		/*if (childForm == gcnew DataViewer(log, "PERSONNEL")) {
			log->setreturnForm(this->activeForm);
		}*/
		this->activeForm = childForm;
		childForm->TopLevel = false;
		childForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		childForm->Dock = DockStyle::Fill;
		panelDesktopPanel->Controls->Add(childForm);
		panelDesktopPanel->Tag = childForm;
		childForm->BringToFront();
		childForm->Show();
	}
	private: System::Void bunifuTileButton6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void bunifuTileButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenChildForm(gcnew ClinicWinForm(), sender);
	
}
private: System::Void bunifuTileButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenChildForm(gcnew DepartmentsWinForm(), sender); 
}
private: System::Void bunifuTileButton3_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenChildForm(gcnew DoctorWinForm(), sender);
}
private: System::Void bunifuTileButton4_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenChildForm(gcnew PatientWinForm(), sender);
}
private: System::Void bunifuTileButton5_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenChildForm(gcnew ReceptionOrderWinForm(), sender);
}
};
}
