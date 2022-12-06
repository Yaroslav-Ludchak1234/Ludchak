#pragma once
#include "Patient.h"
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
	using namespace System::Globalization;

	/// <summary>
	/// Summary for PatientWinForm
	/// </summary>
	public ref class PatientWinForm : public System::Windows::Forms::Form
	{
	public:
		MaskedTextBox^ maskedTextBox;
		DateTimePicker^ dtp;
	private: String^ photoPath = "";
	private:
		List<Patient^>^ group_patient;
		List<Clinic^>^ group_clinic;
	private: Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton21;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;
		   System::Data::SqlServerCe::SqlCeConnection^ connect;
		
	public:
		PatientWinForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "DataSource=C:\\Users\\Asus\\source\\repos\\Ludchak\\Ludchak\\MedecineCentre.sdf;";
			connect = gcnew SqlCeConnection(dbEngine->LocalConnectionString);
			group_patient = gcnew  List<Patient^>();
			group_clinic = gcnew  List<Clinic^>();
		}

		void getPatient() {

			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT * FROM Patient";
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			group_patient->Clear();
			while (sqlRead->Read()) {
				group_patient->Add(gcnew Patient(
					System::Convert::ToInt32(sqlRead["p_num_record"]),
					System::Convert::ToString(sqlRead["p_full_name"]),
					System::Convert::ToDateTime(sqlRead["p_birthday"]),
					System::Convert::ToString(sqlRead["p_complaints"]),
					System::Convert::ToString(sqlRead["p_diognosis"]),
					System::Convert::ToString(sqlRead["p_num_tel"]),
					System::Convert::ToString(sqlRead["p_card_bank"]),					
					System::Convert::ToInt32(sqlRead["p_col_day"]),
					System::Convert::ToInt32(sqlRead["Clinic_c_id_clinic"]),
					System::Convert::ToString(sqlRead["pathP"])
				));
			}
			sqlRead->Close();
			connect->Close();
			this->updateTable();
		}

		int getSelectedGroupIndex() {
			connect->Open();
			String^ query = "SELECT c_id_clinic FROM Clinic WHERE c_name LIKE '" + System::Convert::ToString(this->bunifuDataGridView1->Rows[0]->Cells[5]->Value) + "'; ";

			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			int result = -1;
			bool hasRow = sqlRead->Read();
			if (hasRow)
			{
				result = System::Convert::ToInt32(sqlRead["c_id_clinic"]);
			}
			connect->Close();
			sqlRead->Close();
			return result;
		}

		void execute(String^ query) {
			connect->Open();
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			command->ExecuteNonQuery();
			connect->Close();
		}
		void getQueryPatient(String^ query) {
			connect->Open();
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			group_patient->Clear();
			while (sqlRead->Read()) {
				group_patient->Add(gcnew Patient(
					System::Convert::ToInt32(sqlRead["p_num_record"]),
					System::Convert::ToString(sqlRead["p_full_name"]),
					System::Convert::ToDateTime(sqlRead["p_birthday"]),
					System::Convert::ToString(sqlRead["p_complaints"]),
					System::Convert::ToString(sqlRead["p_diognosis"]),
					System::Convert::ToString(sqlRead["p_num_tel"]),
					System::Convert::ToString(sqlRead["p_card_bank"]),
					System::Convert::ToInt32(sqlRead["p_col_day"]),
					System::Convert::ToInt32(sqlRead["Clinic_c_id_clinic"]),
					System::Convert::ToString(sqlRead["pathP"])
				));				
			}
			sqlRead->Close();
			connect->Close();
			this->updateTable();
		}
		void updateTable() {
			int i = 0;
			bunifuDataGridView1->Rows->Clear();
			for each (Patient ^ category_Pet in group_patient) {
				this->bunifuDataGridView1->Rows->Add();
				this->bunifuDataGridView1->Rows[i]->Cells[0]->Value = category_Pet->getId();
				this->bunifuDataGridView1->Rows[i]->Cells[1]->Value = category_Pet->getFullName();
				this->bunifuDataGridView1->Rows[i]->Cells[2]->Value = category_Pet->getBirthday();
				this->bunifuDataGridView1->Rows[i]->Cells[3]->Value = category_Pet->getComplaints();
				this->bunifuDataGridView1->Rows[i]->Cells[4]->Value = category_Pet->getDiognosis();
				this->bunifuDataGridView1->Rows[i]->Cells[5]->Value = category_Pet->getTelephone();
				this->bunifuDataGridView1->Rows[i]->Cells[6]->Value = category_Pet->getBank();
				this->bunifuDataGridView1->Rows[i]->Cells[7]->Value = category_Pet->getColDay();
				this->bunifuDataGridView1->Rows[i]->Cells[8]->Value = getValueFromComboBox(category_Pet->getClinicCIdClinic());
				this->bunifuDataGridView1->Rows[i]->Cells[9]->Value = category_Pet->getPath();				
				++i;
			}
		}

		void setComboBox() {
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
			for each (DataGridViewRow ^ row in bunifuDataGridView1->Rows)
			{
				((DataGridViewComboBoxCell^)row->Cells[8])->Items->Clear();
				for each (Clinic ^ prod in group_clinic)
				{
					((DataGridViewComboBoxCell^)row->Cells[8])->Items->Add(prod->getName());
				}
			}
		}

		int getCurrComboBox(String^ str)
		{
			int id;
			String^ queryS = "SELECT c_id_clinic FROM Clinic WHERE c_name LIKE '" + str + "';";
			SqlCeCommand^ commandS = connect->CreateCommand();
			commandS->CommandText = queryS;
			SqlCeDataReader^ sqlReadS = commandS->ExecuteReader();
			bool hasRow = sqlReadS->Read();
			if (hasRow) {
				id = System::Convert::ToInt32(sqlReadS["c_id_clinic"]);
			}
			sqlReadS->Close();
			return id;
		}

		String^ getValueFromComboBox(int id)
		{
			connect->Open();
			String^ query = "SELECT c_name FROM Clinic WHERE c_id_clinic LIKE '" + id + "'; ";

			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			String^ result;
			bool hasRow = sqlRead->Read();
			if (hasRow) {
				result = System::Convert::ToString(sqlRead["c_name"]);

			}
			connect->Close();
			sqlRead->Close();
			return result;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PatientWinForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Bunifu::UI::WinForms::BunifuDataGridView^ bunifuDataGridView1;










	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PatientWinForm::typeid));
			this->bunifuDataGridView1 = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->bunifuThinButton21 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->bunifuDataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->Column1,
					this->Column2, this->Column6, this->Column3, this->Column4, this->Column5, this->Column8, this->Column9, this->Column7, this->Column10
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
			this->bunifuDataGridView1->Size = System::Drawing::Size(1897, 558);
			this->bunifuDataGridView1->TabIndex = 3;
			this->bunifuDataGridView1->Theme = Bunifu::UI::WinForms::BunifuDataGridView::PresetThemes::Maroon;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(45, 576);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(340, 320);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// bunifuThinButton21
			// 
			this->bunifuThinButton21->ActiveBorderThickness = 1;
			this->bunifuThinButton21->ActiveCornerRadius = 20;
			this->bunifuThinButton21->ActiveFillColor = System::Drawing::Color::SeaGreen;
			this->bunifuThinButton21->ActiveForecolor = System::Drawing::Color::White;
			this->bunifuThinButton21->ActiveLineColor = System::Drawing::Color::SeaGreen;
			this->bunifuThinButton21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->bunifuThinButton21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton21.BackgroundImage")));
			this->bunifuThinButton21->ButtonText = L"ThinButton";
			this->bunifuThinButton21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuThinButton21->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton21->ForeColor = System::Drawing::Color::SeaGreen;
			this->bunifuThinButton21->IdleBorderThickness = 1;
			this->bunifuThinButton21->IdleCornerRadius = 20;
			this->bunifuThinButton21->IdleFillColor = System::Drawing::Color::White;
			this->bunifuThinButton21->IdleForecolor = System::Drawing::Color::SeaGreen;
			this->bunifuThinButton21->IdleLineColor = System::Drawing::Color::SeaGreen;
			this->bunifuThinButton21->Location = System::Drawing::Point(45, 893);
			this->bunifuThinButton21->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton21->Name = L"bunifuThinButton21";
			this->bunifuThinButton21->Size = System::Drawing::Size(340, 52);
			this->bunifuThinButton21->TabIndex = 5;
			this->bunifuThinButton21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton21->Click += gcnew System::EventHandler(this, &PatientWinForm::bunifuThinButton21_Click);
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
			this->Column2->HeaderText = L"Повне Ім\'я";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"День Народження";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Симптоми";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Діагноз";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Номер Тел.";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Банківська Карта";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Кількість в Клініці";
			this->Column9->MinimumWidth = 6;
			this->Column9->Name = L"Column9";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Клініка";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Фото";
			this->Column10->MinimumWidth = 6;
			this->Column10->Name = L"Column10";
			this->Column10->Visible = false;
			// 
			// PatientWinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->ClientSize = System::Drawing::Size(1921, 983);
			this->Controls->Add(this->bunifuThinButton21);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->bunifuDataGridView1);
			this->Name = L"PatientWinForm";
			this->Text = L"PatientWinForm";
			this->Load += gcnew System::EventHandler(this, &PatientWinForm::PatientWinForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PatientWinForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->getPatient();
		this->bunifuDataGridView1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &PatientWinForm::bunifuDataGridView1_UserDeletingRow);
		this->bunifuDataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PatientWinForm::bunifuDataGridView1_CellValueChanged);
		this->bunifuDataGridView1->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &PatientWinForm::bunifuDataGridView1_RowsAdded);
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
		this->maskedTextBox = gcnew MaskedTextBox();
		maskedTextBox->Visible = false;
		this->bunifuDataGridView1->Controls->Add(maskedTextBox);
		this->bunifuDataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &PatientWinForm::bunifuDataGridView1_CellBeginEdit);
		this->bunifuDataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PatientWinForm::bunifuDataGridView1_CellEndEdit);
		this->bunifuDataGridView1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &PatientWinForm::bunifuDataGridView1_Scroll);
		setComboBox();


		this->bunifuDataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PatientWinForm::bunifuDataGridView1_CellClick);
		dtp = gcnew DateTimePicker();
		dtp->Format = DateTimePickerFormat::Custom;
		dtp->CustomFormat = "dd.MM.yyyy HH:mm";
		this->dtp->Visible = false;
		this->bunifuDataGridView1->Controls->Add(dtp);
	}
	private: System::Void bunifuDataGridView1_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e) {
		connect->Open();
		String^ query = "DELETE FROM Patient WHERE [p_num_record]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->Row->Index]->Cells[0]->Value);
		SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
		if (command->ExecuteNonQuery() > 0) {}
		connect->Close();
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
	}

	private: System::Void bunifuDataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		connect->Open();
		int i = e->RowIndex;
		System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[0]->Value);
		/*String^ str = bunifuDataGridView1->Rows[e->RowIndex]->Cells[4]->Value->ToString();
		DateTime tmpdt = DateTime::Parse(str);*/
		String^ query = "UPDATE Patient SET [p_full_name]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[1]->Value) +
			"', [p_birthday]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[2]->Value) +
			"', [p_complaints]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[3]->Value) +
			"', [p_diognosis]='" + System::Convert::ToString(bunifuDataGridView1->Rows[e->RowIndex]->Cells[4]->Value) +
			"', [p_num_tel]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[5]->Value) +
			"', [p_card_bank]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[6]->Value) +
			"', [p_col_day]='" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[7]->Value) +
			"', [Clinic_c_id_clinic]='" + getCurrComboBox(System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[8]->Value)) +
			"', [pathP]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[9]->Value) +
			"' WHERE [p_num_record]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[0]->Value); +";";
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
		int zero = 1;
		DateTime dtNow = DateTime::Now;

		/*String^ query = "INSERT INTO [Doctor]([do_full], [do_num_room], [do_qualification], [do_birthday], [do_spec], [Departments_d_id])" + "VALUES('" + "0" + "','" + 1 +
			"'," + "0" + "," + 1 + "," + "09.09.2022 0:12:00" + "," + zero + "); ";*/
		String^ query = "INSERT INTO [Patient]([p_full_name], [p_birthday], [p_complaints], [p_diognosis], [p_num_tel], [p_card_bank], [p_col_day], [Clinic_c_id_clinic], [pathP])"
			+ "VALUES('" + "0" + "','" + dtNow + "','" + "0" + "','" + "0" + "','" + "0" + "','" + "0" + "'," + 1 +"," + 1 + ",'" + "0" +"'); ";
		SqlCeCommand^ command = connect->CreateCommand();
		command->CommandText = query;
		if (command->ExecuteNonQuery() > 0) {}
		connect->Close();
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
	}

	private: System::Void bunifuDataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		if (maskedTextBox->Visible)
		{
			if (e->ColumnIndex == 7) {
				this->bunifuDataGridView1->CurrentCell->Value = System::Convert::ToInt32(this->maskedTextBox->Text);
				this->maskedTextBox->Visible = false;
			}
			if (e->ColumnIndex == 1 || e->ColumnIndex == 3 || e->ColumnIndex == 4 || e->ColumnIndex == 5 || e->ColumnIndex == 6) {
				
				this->bunifuDataGridView1->CurrentCell->Value = this->maskedTextBox->Text;
				this->maskedTextBox->Visible = false;
			}
		}

		if (this->dtp->Visible) {
			if (e->ColumnIndex == 2) {
				/*DateTime tmp = System::Convert::ToDateTime(this->dtp->ToString());*/
				CultureInfo^ pro = gcnew CultureInfo("uk-UA");
				this->bunifuDataGridView1->CurrentCell->Value = DateTime::ParseExact(dtp->Value.ToString(), "dd.MM.yyyy HH:mm:ss", pro);
				this->dtp->Visible = false;
			}
		}
	}

	private: System::Void bunifuDataGridView1_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
		if (this->bunifuDataGridView1->Rows->Count - 1 > this->bunifuDataGridView1->CurrentCell->RowIndex) {
			if (e->ColumnIndex == 1 || e->ColumnIndex == 3 || e->ColumnIndex == 4)
			{
				this->maskedTextBox->Mask = "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";
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

			if (e->ColumnIndex == 5)
			{
				this->maskedTextBox->Mask = "+38(###)-###-##-##";
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

			if (e->ColumnIndex == 6)
			{
				this->maskedTextBox->Mask = "#### #### #### ####";
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

			if (e->ColumnIndex == 7)
			{
				this->maskedTextBox->Mask = "####";
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

			if (e->ColumnIndex == 2)
			{
				// set size and location
				typedef System::Drawing::Rectangle R;
				R rect = this->bunifuDataGridView1->GetCellDisplayRectangle(this->bunifuDataGridView1->CurrentCell->ColumnIndex, this->bunifuDataGridView1->CurrentCell->RowIndex, true);
				dtp->Visible = true;
				CultureInfo^ pro = gcnew CultureInfo("uk-UA");
				dtp->Value = DateTime::ParseExact(this->bunifuDataGridView1->CurrentCell->Value->ToString(), "dd.MM.yyyy HH:mm:ss", pro);
				dtp->Size = this->bunifuDataGridView1->CurrentCell->Size;
				dtp->Location = rect.Location;
				// attach events
				/*CultureInfo provider = CultureInfo.InvariantCulture;*/
				this->bunifuDataGridView1->CurrentCell->Value = DateTime::ParseExact(dtp->Value.ToString(), "dd.MM.yyyy HH:mm:ss", pro);
			}
			/*else {
				dtp->Visible = false;
			}*/
		}
	}
	private: System::Void bunifuDataGridView1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		if (this->maskedTextBox->Visible) {
			typedef System::Drawing::Rectangle R;
			R rect = this->bunifuDataGridView1->GetCellDisplayRectangle(this->bunifuDataGridView1->CurrentCell->ColumnIndex, this->bunifuDataGridView1->CurrentCell->RowIndex, true);
			this->maskedTextBox->Location = rect.Location;
		}
		if (this->dtp->Visible) {
			typedef System::Drawing::Rectangle R;
			R rect = this->bunifuDataGridView1->GetCellDisplayRectangle(this->bunifuDataGridView1->CurrentCell->ColumnIndex, this->bunifuDataGridView1->CurrentCell->RowIndex, true);
			this->dtp->Location = rect.Location;
		}
	}
	private: System::Void bunifuDataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (this->bunifuDataGridView1->Rows->Count - 1 > this->bunifuDataGridView1->CurrentCell->RowIndex && this->bunifuDataGridView1->Rows[this->bunifuDataGridView1->CurrentCell->RowIndex]->Cells[9]->Value->ToString() != "" && this->bunifuDataGridView1->Rows[this->bunifuDataGridView1->CurrentCell->RowIndex]->Cells[9]->Value->ToString() != "0") {
			pictureBox1->Image = Image::FromFile(System::Convert::ToString(this->bunifuDataGridView1->Rows[this->bunifuDataGridView1->CurrentCell->RowIndex]->Cells[9]->Value));
		}
	}
private: System::Void bunifuThinButton21_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Filter = "png files (*.png)|*.png|jpeg files (*.jpg) | *.jpg";
	if (System::Windows::Forms::DialogResult::OK == openFileDialog->ShowDialog())
	{
		photoPath = openFileDialog->FileName;
		pictureBox1->Image = Image::FromFile(photoPath);
	}
	else
	{
		MessageBox::Show("Фото не вибране!");
	}
	connect->Open();
	String^ query = "UPDATE Patient SET [pathP]='" + System::Convert::ToString(photoPath) + "' WHERE [p_num_record]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[this->bunifuDataGridView1->CurrentCell->RowIndex]->Cells[0]->Value); +";";
	SqlCeCommand^ command = connect->CreateCommand();
	command->CommandText = query;
	if (command->ExecuteNonQuery() == 0) {
		MessageBox::Show("Updated!");
	}
	connect->Close();
}
};
}
