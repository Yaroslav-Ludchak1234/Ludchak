#pragma once
#include "Clinic.h"
#include "stdlib.h"

namespace Ludchak {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Data::SqlServerCe;

	/// <summary>
	/// Summary for ClinicWinForm
	/// </summary>
	public ref class ClinicWinForm : public System::Windows::Forms::Form
	{
	public:
		MaskedTextBox^ maskedTextBox;
	public:
		ClinicWinForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "DataSource=C:\\Users\\Asus\\source\\repos\\Ludchak\\Ludchak\\MedecineCentre.sdf;";
			connect = gcnew SqlCeConnection(dbEngine->LocalConnectionString);
			group_clinic = gcnew List<Clinic^>();
		}
		void getClinic() {
			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT * FROM Clinic";
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			group_clinic->Clear();
			while (sqlRead->Read()) {
				group_clinic->Add(gcnew Clinic(
					System::Convert::ToInt32(sqlRead["c_id_clinic"]),
					System::Convert::ToString(sqlRead["с_country"]),
					System::Convert::ToString(sqlRead["c_city"]),
					System::Convert::ToString(sqlRead["c_area"]),
					System::Convert::ToString(sqlRead["c_name"]),
					System::Convert::ToString(sqlRead["c_general_doctor"]),
					System::Convert::ToString(sqlRead["c_general_register"]),
					System::Convert::ToString(sqlRead["c_deputy_g_doctor"])
				));
			}
			connect->Close();
			this->updateTable();
		}
		void execute(String^ query) {
			connect->Open();
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			command->ExecuteNonQuery();
			connect->Close();
		}
		void getQueryClinic(String^ query) {
			connect->Open();
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			group_clinic->Clear();
			while (sqlRead->Read()) {
				group_clinic->Add(gcnew Clinic(
					System::Convert::ToInt32(sqlRead["c_id_clinic"]),
					System::Convert::ToString(sqlRead["с_country"]),
					System::Convert::ToString(sqlRead["c_city"]),
					System::Convert::ToString(sqlRead["c_area"]),
					System::Convert::ToString(sqlRead["c_name"]),
					System::Convert::ToString(sqlRead["c_general_doctor"]),
					System::Convert::ToString(sqlRead["c_general_register"]),
					System::Convert::ToString(sqlRead["c_deputy_g_doctor"])
				));
			}
			sqlRead->Close();
			connect->Close();
			this->updateTable();
		}

		void updateTable() {
			int i = 0;
			bunifuDataGridView1->Rows->Clear();
			for each (Clinic ^ category_clinic in group_clinic) {
				this->bunifuDataGridView1->Rows->Add();
				this->bunifuDataGridView1->Rows[i]->Cells[0]->Value = category_clinic->getId();
				this->bunifuDataGridView1->Rows[i]->Cells[1]->Value = category_clinic->getCountry();
				this->bunifuDataGridView1->Rows[i]->Cells[2]->Value = category_clinic->getСity();
				this->bunifuDataGridView1->Rows[i]->Cells[3]->Value = category_clinic->getArea();
				this->bunifuDataGridView1->Rows[i]->Cells[4]->Value = category_clinic->getName();
				this->bunifuDataGridView1->Rows[i]->Cells[5]->Value = category_clinic->getGeneralDoctor();
				this->bunifuDataGridView1->Rows[i]->Cells[6]->Value = category_clinic->getGeneralRegister();
				this->bunifuDataGridView1->Rows[i]->Cells[7]->Value = category_clinic->getDeputyGDoctor();
				++i;
			}
		}

private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
public:
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
public: System::Windows::Forms::TextBox^ textBox1;
public: System::Windows::Forms::TextBox^ textBox2;
public: System::Windows::Forms::TextBox^ textBox3;
public: System::Windows::Forms::TextBox^ textBox4;
public: System::Windows::Forms::TextBox^ textBox5;
public: System::Windows::Forms::TextBox^ textBox6;
public: System::Windows::Forms::TextBox^ textBox7;
private: Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton21;


	public:
private:
	private: List<Clinic^>^ group_clinic;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ClinicWinForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Bunifu::UI::WinForms::BunifuDataGridView^ bunifuDataGridView1;
	protected:








		  System::Data::SqlServerCe::SqlCeConnection^ connect;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClinicWinForm::typeid));
			this->bunifuDataGridView1 = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->bunifuThinButton21 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// bunifuDataGridView1
			// 
			this->bunifuDataGridView1->AllowCustomTheming = true;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(223)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(191)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->bunifuDataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->bunifuDataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuDataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bunifuDataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->bunifuDataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::Maroon;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->bunifuDataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->bunifuDataGridView1->ColumnHeadersHeight = 40;
			this->bunifuDataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8
			});
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(223)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(191)));
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(102)));
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->SelectionForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->CurrentTheme->BackColor = System::Drawing::Color::Maroon;
			this->bunifuDataGridView1->CurrentTheme->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)),
				static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->BackColor = System::Drawing::Color::Maroon;
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->ForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->SelectionForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->CurrentTheme->Name = nullptr;
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(102)));
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(102)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->bunifuDataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->bunifuDataGridView1->EnableHeadersVisualStyles = false;
			this->bunifuDataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(216)),
				static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->bunifuDataGridView1->HeaderBackColor = System::Drawing::Color::Maroon;
			this->bunifuDataGridView1->HeaderBgColor = System::Drawing::Color::Empty;
			this->bunifuDataGridView1->HeaderForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->Location = System::Drawing::Point(12, 12);
			this->bunifuDataGridView1->Name = L"bunifuDataGridView1";
			this->bunifuDataGridView1->RowHeadersVisible = false;
			this->bunifuDataGridView1->RowHeadersWidth = 51;
			this->bunifuDataGridView1->RowTemplate->Height = 40;
			this->bunifuDataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->bunifuDataGridView1->Size = System::Drawing::Size(1897, 701);
			this->bunifuDataGridView1->TabIndex = 0;
			this->bunifuDataGridView1->Theme = Bunifu::UI::WinForms::BunifuDataGridView::PresetThemes::Maroon;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Visible = false;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Країна";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Місто";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Район";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Ім\'я";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Головний Лікар";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Адміністратор";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Заступник Головного Л.";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 737);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(214, 56);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ClinicWinForm::search);
			this->textBox1->Leave += gcnew System::EventHandler(this, &ClinicWinForm::Leave);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(232, 737);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(214, 56);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &ClinicWinForm::searcCity);
			this->textBox2->Leave += gcnew System::EventHandler(this, &ClinicWinForm::Leave);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(452, 737);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(214, 56);
			this->textBox3->TabIndex = 3;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &ClinicWinForm::textBox3_TextChanged);
			this->textBox3->Leave += gcnew System::EventHandler(this, &ClinicWinForm::Leave);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(672, 737);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(214, 56);
			this->textBox4->TabIndex = 4;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &ClinicWinForm::textBox4_TextChanged);
			this->textBox4->Leave += gcnew System::EventHandler(this, &ClinicWinForm::Leave);
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(892, 737);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(214, 56);
			this->textBox5->TabIndex = 5;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &ClinicWinForm::textBox5_TextChanged);
			this->textBox5->Leave += gcnew System::EventHandler(this, &ClinicWinForm::Leave);
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(1112, 737);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(214, 56);
			this->textBox6->TabIndex = 6;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &ClinicWinForm::textBox6_TextChanged);
			this->textBox6->Leave += gcnew System::EventHandler(this, &ClinicWinForm::Leave);
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(1332, 737);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(214, 56);
			this->textBox7->TabIndex = 7;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &ClinicWinForm::textBox7_TextChanged);
			this->textBox7->Leave += gcnew System::EventHandler(this, &ClinicWinForm::Leave);
			// 
			// bunifuThinButton21
			// 
			this->bunifuThinButton21->ActiveBorderThickness = 1;
			this->bunifuThinButton21->ActiveCornerRadius = 30;
			this->bunifuThinButton21->ActiveFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuThinButton21->ActiveForecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuThinButton21->ActiveLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuThinButton21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuThinButton21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton21.BackgroundImage")));
			this->bunifuThinButton21->ButtonText = L"Очистити";
			this->bunifuThinButton21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuThinButton21->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton21->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuThinButton21->IdleBorderThickness = 1;
			this->bunifuThinButton21->IdleCornerRadius = 30;
			this->bunifuThinButton21->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuThinButton21->IdleForecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuThinButton21->IdleLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->bunifuThinButton21->Location = System::Drawing::Point(1602, 737);
			this->bunifuThinButton21->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton21->Name = L"bunifuThinButton21";
			this->bunifuThinButton21->Size = System::Drawing::Size(271, 56);
			this->bunifuThinButton21->TabIndex = 8;
			this->bunifuThinButton21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton21->Click += gcnew System::EventHandler(this, &ClinicWinForm::bunifuThinButton21_Click);
			// 
			// ClinicWinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->ClientSize = System::Drawing::Size(1921, 983);
			this->Controls->Add(this->bunifuThinButton21);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->bunifuDataGridView1);
			this->Name = L"ClinicWinForm";
			this->Text = L"ClinicWinForm";
			this->Load += gcnew System::EventHandler(this, &ClinicWinForm::ClinicWinForm_Load);
			this->Click += gcnew System::EventHandler(this, &ClinicWinForm::search);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ClinicWinForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->getClinic();
		this->bunifuDataGridView1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &ClinicWinForm::bunifuDataGridView1_UserDeletingRow);
		this->bunifuDataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ClinicWinForm::bunifuDataGridView1_CellValueChanged);
		this->bunifuDataGridView1->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
		this->maskedTextBox = gcnew MaskedTextBox();
		maskedTextBox->Visible = false;
		this->bunifuDataGridView1->Controls->Add(maskedTextBox);
		this->bunifuDataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &ClinicWinForm::bunifuDataGridView1_CellBeginEdit);
		this->bunifuDataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ClinicWinForm::bunifuDataGridView1_CellEndEdit);
		this->bunifuDataGridView1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &ClinicWinForm::bunifuDataGridView1_Scroll);

	}

	private: System::Void bunifuDataGridView1_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e) {
		connect->Open();
		String^ query = "DELETE FROM Clinic WHERE [c_id_clinic]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->Row->Index]->Cells[0]->Value);
		SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
		if (command->ExecuteNonQuery() > 0) {}
		connect->Close();
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
	}
	private: System::Void bunifuDataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		connect->Open();
		int i = e->RowIndex;
		System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[0]->Value);

		String^ query = "UPDATE Clinic SET [с_country]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[1]->Value) +
			"', [c_city]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[2]->Value) + 
			"', [c_area]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[3]->Value) + 
			"', [c_name]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[4]->Value) + 
			"', [c_general_doctor]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[5]->Value) + 
			"', [c_general_register]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[6]->Value) + 
			"', [c_deputy_g_doctor]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[7]->Value) + 
			"' WHERE [c_id_clinic]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[0]->Value); +";";
		SqlCeCommand^ command = connect->CreateCommand();
		command->CommandText = query;
		if (command->ExecuteNonQuery() == 0) {
			MessageBox::Show("Updated!");
		}
		connect->Close();
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
	}
	private: System::Void bunifuDataGridView1_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
		connect->Open();
		String^ query = "INSERT INTO Clinic([с_country])" + "VALUES('" + "0" + "');";
		SqlCeCommand^ command = connect->CreateCommand();
		command->CommandText = query;
		if (command->ExecuteNonQuery() > 0) {}
		connect->Close();
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
	}
	private: System::Void bunifuDataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (maskedTextBox->Visible)
		{
			this->bunifuDataGridView1->CurrentCell->Value = this->maskedTextBox->Text;
			this->maskedTextBox->Visible = false;
		}
	}
	private: System::Void bunifuDataGridView1_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
		if (this->bunifuDataGridView1->Rows->Count - 1 > this->bunifuDataGridView1->CurrentCell->RowIndex) {
			this->maskedTextBox->Mask = "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";
			typedef System::Drawing::Rectangle R;
			R rect = this->bunifuDataGridView1->GetCellDisplayRectangle(e->ColumnIndex, e->RowIndex, true);
			this->maskedTextBox->Location = rect.Location;
			this->maskedTextBox->Size = bunifuDataGridView1->CurrentCell->Size;
			this->maskedTextBox->Text = "";
			if (this->bunifuDataGridView1[e->ColumnIndex, e->RowIndex]->Value != nullptr) {
				this->maskedTextBox->Text = this->bunifuDataGridView1[e->ColumnIndex, e->RowIndex]->Value->ToString();
			}
			this->maskedTextBox->Visible = true;
		}
	}
	private: System::Void bunifuDataGridView1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		if (this->maskedTextBox->Visible) {
			typedef System::Drawing::Rectangle R;
			R rect = this->bunifuDataGridView1->GetCellDisplayRectangle(this->bunifuDataGridView1->CurrentCell->ColumnIndex, this->bunifuDataGridView1->CurrentCell->RowIndex, true);
			this->maskedTextBox->Location = rect.Location;
		}
	}
	
private: System::Void bunifuThinButton21_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
	textBox5->Text = "";
	textBox6->Text = "";
	textBox7->Text = "";	
}
private: System::Void search(System::Object^ sender, System::EventArgs^ e)
	   {
		   this->bunifuDataGridView1->RowsAdded -= gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
		   String^ query = "SELECT * FROM Clinic WHERE [с_country] LIKE'%" + textBox1->Text + "%';";
		   this->getQueryClinic(query);
	   }
private: System::Void searcCity(System::Object^ sender, System::EventArgs^ e)
{
	this->bunifuDataGridView1->RowsAdded -= gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
	String^ query = "SELECT * FROM Clinic WHERE [c_city] LIKE'%" + textBox2->Text + "%';";
	this->getQueryClinic(query);
}

private: System::Void Leave(System::Object^ sender, System::EventArgs^ e) {
	this->bunifuDataGridView1->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->bunifuDataGridView1->RowsAdded -= gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
	String^ query = "SELECT * FROM Clinic WHERE [c_area] LIKE'%" + textBox3->Text + "%';";
	this->getQueryClinic(query);
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->bunifuDataGridView1->RowsAdded -= gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
	String^ query = "SELECT * FROM Clinic WHERE [c_name] LIKE'%" + textBox4->Text + "%';";
	this->getQueryClinic(query);
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->bunifuDataGridView1->RowsAdded -= gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
	String^ query = "SELECT * FROM Clinic WHERE [c_general_doctor] LIKE'%" + textBox5->Text + "%';";
	this->getQueryClinic(query);
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->bunifuDataGridView1->RowsAdded -= gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
	String^ query = "SELECT * FROM Clinic WHERE [c_general_register] LIKE'%" + textBox6->Text + "%';";
	this->getQueryClinic(query);
}
private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->bunifuDataGridView1->RowsAdded -= gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ClinicWinForm::bunifuDataGridView1_RowsAdded);
	String^ query = "SELECT * FROM Clinic WHERE [c_deputy_g_doctor] LIKE'%" + textBox7->Text + "%';";
	this->getQueryClinic(query);
}
};
}
