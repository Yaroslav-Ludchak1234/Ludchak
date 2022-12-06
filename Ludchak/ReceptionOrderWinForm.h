#pragma once
#include "Patient.h"
#include "Doctor.h"
#include "Reception_Order.h"

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
	/// Summary for ReceptionOrderWinForm
	/// </summary>
	public ref class ReceptionOrderWinForm : public System::Windows::Forms::Form
	{
	public:
		MaskedTextBox^ maskedTextBox;
		DateTimePicker^ dtp;
	
	private:
		List<Patient^>^ group_patient;
		List<Doctor^>^ group_doctor;
		List<ReceptionOrder^>^ group_ReOr;
		System::Data::SqlServerCe::SqlCeConnection^ connect;
	public:
		ReceptionOrderWinForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SqlCeEngine^ dbEngine = gcnew SqlCeEngine();
			dbEngine->LocalConnectionString = "DataSource=C:\\Users\\Asus\\source\\repos\\Ludchak\\Ludchak\\MedecineCentre.sdf;";
			connect = gcnew SqlCeConnection(dbEngine->LocalConnectionString);
			group_patient = gcnew  List<Patient^>();
			group_doctor = gcnew  List<Doctor^>();
			group_ReOr = gcnew  List<ReceptionOrder^>();
		}

		void getReceptionOrder() {

			connect->Open();
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT * FROM Reception_Order";
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			group_ReOr->Clear();
			while (sqlRead->Read()) {
				group_ReOr->Add(gcnew ReceptionOrder(
					System::Convert::ToInt32(sqlRead["ro_num_id"]),
					System::Convert::ToDateTime(sqlRead["ro_date_time"]),
					System::Convert::ToDateTime(sqlRead["ro_date_time_limit"]),
					System::Convert::ToDecimal(sqlRead["ro_cost"]),
					System::Convert::ToInt32(sqlRead["ro_place"]),
					System::Convert::ToString(sqlRead["pay"]),
					System::Convert::ToInt32(sqlRead["Doctor"]),
					System::Convert::ToInt32(sqlRead["Patient_p_num_record"])					
				));
			}
			sqlRead->Close();
			connect->Close();
			this->updateTable();
		}		

		void execute(String^ query) {
			connect->Open();
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			command->ExecuteNonQuery();
			connect->Close();
		}
		void getQueryReceptionOrder(String^ query) {
			connect->Open();
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			group_patient->Clear();
			while (sqlRead->Read()) {
				group_ReOr->Add(gcnew ReceptionOrder(
					System::Convert::ToInt32(sqlRead["ro_num_id"]),
					System::Convert::ToDateTime(sqlRead["ro_date_time"]),
					System::Convert::ToDateTime(sqlRead["ro_date_time_limit"]),
					System::Convert::ToDecimal(sqlRead["ro_cost"]),
					System::Convert::ToInt32(sqlRead["ro_place"]),
					System::Convert::ToString(sqlRead["pay"]),
					System::Convert::ToInt32(sqlRead["Doctor"]),
					System::Convert::ToInt32(sqlRead["Patient_p_num_record"])
				));
			}
			sqlRead->Close();
			connect->Close();
			this->updateTable();
		}
		void updateTable() {
			int i = 0;
			bunifuDataGridView1->Rows->Clear();
			for each (ReceptionOrder ^ category_RO in group_ReOr) {
				this->bunifuDataGridView1->Rows->Add();
				this->bunifuDataGridView1->Rows[i]->Cells[0]->Value = category_RO->getId();
				this->bunifuDataGridView1->Rows[i]->Cells[1]->Value = category_RO->getDateTime();
				this->bunifuDataGridView1->Rows[i]->Cells[2]->Value = category_RO->getDateTimeLimit();
				this->bunifuDataGridView1->Rows[i]->Cells[3]->Value = category_RO->getCost();
				this->bunifuDataGridView1->Rows[i]->Cells[4]->Value = category_RO->getPlace();				
				this->bunifuDataGridView1->Rows[i]->Cells[5]->Value = category_RO->getPay();
				this->bunifuDataGridView1->Rows[i]->Cells[6]->Value = getValueFromComboBox(category_RO->getDoctor(), "D");
				this->bunifuDataGridView1->Rows[i]->Cells[7]->Value = getValueFromComboBox(category_RO->getPatient(), "P");				
				++i;
			}
		}

		void setComboBox() {
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
			connect->Close();
			for each (DataGridViewRow ^ row in bunifuDataGridView1->Rows)
			{
				((DataGridViewComboBoxCell^)row->Cells[7])->Items->Clear();
				for each (Patient ^ prod in group_patient)
				{
					((DataGridViewComboBoxCell^)row->Cells[7])->Items->Add(prod->getFullName());
				}
			}
			connect->Open();
			command = connect->CreateCommand();
			command->CommandText = "SELECT * FROM Doctor";
			sqlRead = command->ExecuteReader();
			group_doctor->Clear();
			while (sqlRead->Read()) {
				group_doctor->Add(gcnew Doctor(
					System::Convert::ToInt32(sqlRead["do_num"]),
					System::Convert::ToString(sqlRead["do_full"]),
					System::Convert::ToInt32(sqlRead["do_num_room"]),
					System::Convert::ToString(sqlRead["do_qualification"]),
					System::Convert::ToDateTime(sqlRead["do_birthday"]),
					System::Convert::ToString(sqlRead["do_spec"]),
					System::Convert::ToInt32(sqlRead["Departments_d_id"])
				));
			}
			connect->Close();
			for each (DataGridViewRow ^ row in bunifuDataGridView1->Rows)
			{
				((DataGridViewComboBoxCell^)row->Cells[6])->Items->Clear();
				for each (Doctor ^ prod in group_doctor)
				{
					((DataGridViewComboBoxCell^)row->Cells[6])->Items->Add(prod->getFull());
				}
			}
		}

		int getCurrComboBox(String^ str, String^ table)
		{
			if (table == "D") {
				int id;
				String^ queryS = "SELECT do_num FROM Doctor WHERE do_full LIKE '" + str + "';";
				SqlCeCommand^ commandS = connect->CreateCommand();
				commandS->CommandText = queryS;
				SqlCeDataReader^ sqlReadS = commandS->ExecuteReader();
				bool hasRow = sqlReadS->Read();
				if (hasRow) {
					id = System::Convert::ToInt32(sqlReadS["do_num"]);
				}
				sqlReadS->Close();
				return id;
			}

			if (table == "P") {
				int id;
				String^ queryS = "SELECT p_num_record FROM Patient WHERE p_full_name LIKE '" + str + "';";
				SqlCeCommand^ commandS = connect->CreateCommand();
				commandS->CommandText = queryS;
				SqlCeDataReader^ sqlReadS = commandS->ExecuteReader();
				bool hasRow = sqlReadS->Read();
				if (hasRow) {
					id = System::Convert::ToInt32(sqlReadS["p_num_record"]);
				}
				sqlReadS->Close();
				return id;
			}
		}

		String^ getValueFromComboBox(int id, String^ table)
		{
			if (table == "D") {
				connect->Open();
				String^ query = "SELECT do_full FROM Doctor WHERE do_num LIKE '" + id + "'; ";

				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = query;
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				String^ result;
				bool hasRow = sqlRead->Read();
				if (hasRow) {
					result = System::Convert::ToString(sqlRead["do_full"]);

				}
				connect->Close();
				sqlRead->Close();
				return result;
			}

			if (table == "P") {
				connect->Open();
				String^ query = "SELECT p_full_name FROM Patient WHERE p_num_record LIKE '" + id + "'; ";

				SqlCeCommand^ command = connect->CreateCommand();
				command->CommandText = query;
				SqlCeDataReader^ sqlRead = command->ExecuteReader();
				String^ result;
				bool hasRow = sqlRead->Read();
				if (hasRow) {
					result = System::Convert::ToString(sqlRead["p_full_name"]);

				}
				connect->Close();
				sqlRead->Close();
				return result;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReceptionOrderWinForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Bunifu::UI::WinForms::BunifuDataGridView^ bunifuDataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Column7;

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
			this->bunifuDataGridView1 = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
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
					this->Column2, this->Column3, this->Column4, this->Column6, this->Column5, this->Column8, this->Column7
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
			this->bunifuDataGridView1->TabIndex = 2;
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
			this->Column2->HeaderText = L"Дата та час";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"День закінчення дії";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Ціна";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Місце";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Безплатний/Платний";
			this->Column5->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Безплатний", L"Платний" });
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Лікар";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Пацієнт";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// ReceptionOrderWinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->ClientSize = System::Drawing::Size(1921, 983);
			this->Controls->Add(this->bunifuDataGridView1);
			this->Name = L"ReceptionOrderWinForm";
			this->Text = L"ReceptionOrderWinForm";
			this->Load += gcnew System::EventHandler(this, &ReceptionOrderWinForm::ReceptionOrderWinForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ReceptionOrderWinForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->getReceptionOrder();
		this->bunifuDataGridView1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &ReceptionOrderWinForm::bunifuDataGridView1_UserDeletingRow);
		this->bunifuDataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ReceptionOrderWinForm::bunifuDataGridView1_CellValueChanged);
		this->bunifuDataGridView1->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &ReceptionOrderWinForm::bunifuDataGridView1_RowsAdded);
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
		this->maskedTextBox = gcnew MaskedTextBox();
		maskedTextBox->Visible = false;
		this->bunifuDataGridView1->Controls->Add(maskedTextBox);
		this->bunifuDataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &ReceptionOrderWinForm::bunifuDataGridView1_CellBeginEdit);
		this->bunifuDataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ReceptionOrderWinForm::bunifuDataGridView1_CellEndEdit);
		this->bunifuDataGridView1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &ReceptionOrderWinForm::bunifuDataGridView1_Scroll);
		setComboBox();


		this->bunifuDataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ReceptionOrderWinForm::bunifuDataGridView1_CellClick);
		dtp = gcnew DateTimePicker();
		dtp->Format = DateTimePickerFormat::Custom;
		dtp->CustomFormat = "dd.MM.yyyy HH:mm";
		this->dtp->Visible = false;
		this->bunifuDataGridView1->Controls->Add(dtp);
	}
	private: System::Void bunifuDataGridView1_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e) {
		connect->Open();
		String^ query = "DELETE FROM Reception_Order WHERE [ro_num_id]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->Row->Index]->Cells[0]->Value);
		SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
		if (command->ExecuteNonQuery() > 0) {}
		connect->Close();
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
	}

	private: System::Void bunifuDataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		connect->Open();		
		String^ query = "UPDATE Reception_Order SET [ro_date_time]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[1]->Value) +
			"', [ro_date_time_limit]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[2]->Value) +
			/*"', [ro_cost]='" + System::Convert::ToDecimal(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[3]->Value) +*/
			"', [ro_place]='" + System::Convert::ToInt32(bunifuDataGridView1->Rows[e->RowIndex]->Cells[4]->Value) +
			"', [pay]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[5]->Value) +
			"', [Doctor]='" + getCurrComboBox(System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[6]->Value), "D") +
			"', [Patient_p_num_record]='" + getCurrComboBox(System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[7]->Value), "P") +
			"' WHERE [ro_num_id]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[0]->Value); +";";
		SqlCeCommand^ command = connect->CreateCommand();
		command->CommandText = query;
		if (command->ExecuteNonQuery() == 0) {
			MessageBox::Show("Updated!");
		}
		connect->Close();

		if (this->bunifuDataGridView1->CurrentCell->ColumnIndex == 3) {
			connect->Open();
			String^ query = "UPDATE Reception_Order SET [ro_cost]='" + System::Convert::ToDecimal(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[3]->Value) +
			"' WHERE [ro_num_id]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[0]->Value); +";";
			SqlCeCommand^ command = connect->CreateCommand();
			command->CommandText = query;
			if (command->ExecuteNonQuery() == 0) {
				MessageBox::Show("Updated!");
			}
			connect->Close();
		}
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
	}
	private: System::Void bunifuDataGridView1_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
		connect->Open();
		int zero = 8;
		DateTime dtNow = DateTime::Now;

		/*String^ query = "INSERT INTO [Doctor]([do_full], [do_num_room], [do_qualification], [do_birthday], [do_spec], [Departments_d_id])" + "VALUES('" + "0" + "','" + 1 +
			"'," + "0" + "," + 1 + "," + "09.09.2022 0:12:00" + "," + zero + "); ";*/
		String^ query = "INSERT INTO [Reception_Order]([ro_date_time], [ro_date_time_limit], [ro_cost], [ro_place], [pay], [Doctor], [Patient_p_num_record])"
			+ "VALUES('" + dtNow + "','" + dtNow + "'," + 1 + "," + 1 + ",'" + "Безплатний" + "'," + 1 + "," + 1 + ");";
		SqlCeCommand^ command = connect->CreateCommand(); 
		command->CommandText = query;
		if (command->ExecuteNonQuery() > 0) {}
		connect->Close();
		this->bunifuDataGridView1->Sort(this->bunifuDataGridView1->Columns[0], ListSortDirection::Ascending);
	}

	private: System::Void bunifuDataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		if (maskedTextBox->Visible)
		{
			if (e->ColumnIndex == 4) {
				this->bunifuDataGridView1->CurrentCell->Value = System::Convert::ToInt32(this->maskedTextBox->Text);
				this->maskedTextBox->Visible = false;
			}
			if (e->ColumnIndex == 3) {
				this->bunifuDataGridView1->CurrentCell->Value = System::Convert::ToDecimal(this->maskedTextBox->Text);
				this->maskedTextBox->Visible = false;
			}
		}

		if (this->dtp->Visible) {
			if (e->ColumnIndex == 1 || e->ColumnIndex == 2) {
				/*DateTime tmp = System::Convert::ToDateTime(this->dtp->ToString());*/
				CultureInfo^ pro = gcnew CultureInfo("uk-UA");
				this->bunifuDataGridView1->CurrentCell->Value = DateTime::ParseExact(dtp->Value.ToString(), "dd.MM.yyyy HH:mm:ss", pro);
				this->dtp->Visible = false;
			}
		}
	}

	private: System::Void bunifuDataGridView1_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
		if (this->bunifuDataGridView1->Rows->Count - 1 > this->bunifuDataGridView1->CurrentCell->RowIndex) {
			
			if (e->ColumnIndex == 3)
			{
				this->maskedTextBox->Mask = "####,##";
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

			if (e->ColumnIndex == 4)
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

			if (e->ColumnIndex == 1 || e->ColumnIndex == 2)
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
		if (e->ColumnIndex == 4)
		{
			// initialize DateTimePicker

		}
	}
};
}
