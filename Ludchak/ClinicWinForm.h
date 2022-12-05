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
					System::Convert::ToString(sqlRead["�_country"]),
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
					System::Convert::ToString(sqlRead["�_country"]),
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

		/*void getOnlySymbol(String^ str) {
			String^ tmp = "";
			for (int i = 0; i < str->Length; i++)
				if (isdigit(str[i])) str.era = System::Convert::ToString(tmp);


			connect->Open();
			SqlCeCommand^ command = gcnew SqlCeCommand(query, connect);
			SqlCeDataReader^ sqlRead = command->ExecuteReader();
			group_clinic->Clear();
			while (sqlRead->Read()) {
				group_clinic->Add(gcnew Clinic(
					System::Convert::ToInt32(sqlRead["c_id_clinic"]),
					System::Convert::ToString(sqlRead["�_country"]),
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
		}*/

		void updateTable() {
			int i = 0;
			bunifuDataGridView1->Rows->Clear();
			for each (Clinic ^ category_clinic in group_clinic) {
				this->bunifuDataGridView1->Rows->Add();
				this->bunifuDataGridView1->Rows[i]->Cells[0]->Value = category_clinic->getId();
				this->bunifuDataGridView1->Rows[i]->Cells[1]->Value = category_clinic->getCountry();
				this->bunifuDataGridView1->Rows[i]->Cells[2]->Value = category_clinic->get�ity();
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
			this->bunifuDataGridView1 = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->Column2->HeaderText = L"�����";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"̳���";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"�����";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"��\'�";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"�������� ˳���";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"������������";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"��������� ��������� �.";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			// 
			// ClinicWinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->ClientSize = System::Drawing::Size(1921, 983);
			this->Controls->Add(this->bunifuDataGridView1);
			this->Name = L"ClinicWinForm";
			this->Text = L"ClinicWinForm";
			this->Load += gcnew System::EventHandler(this, &ClinicWinForm::ClinicWinForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->EndInit();
			this->ResumeLayout(false);

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

		String^ query = "UPDATE Clinic SET [�_country]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[1]->Value) +
			"', [c_city]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[2]->Value) + 
			"', [c_area]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[3]->Value) + 
			"', [c_name]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[4]->Value) + 
			"', [c_general_doctor]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[5]->Value) + 
			"', [c_general_register]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[6]->Value) + 
			"', [c_deputy_g_doctor]='" + System::Convert::ToString(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[7]->Value) + "' WHERE [c_id_clinic]=" + System::Convert::ToInt32(this->bunifuDataGridView1->Rows[e->RowIndex]->Cells[0]->Value); +";";
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
		String^ query = "INSERT INTO Clinic([�_country])" + "VALUES('" + "0" + "');";
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
	
};
}