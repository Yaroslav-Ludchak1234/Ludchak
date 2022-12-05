#pragma once
#include <stdexcept>
#include <String.h>
// ���������� �������� ���� std � System
using namespace std;
using namespace System;
// ���������� �����
ref class Patient {

	int p_num_record;
	String^ p_full_name;
	DateTime^ p_birthday;
	String^ p_complaints;
	String^ p_diognosis;
	String^ p_num_tel;
	String^ p_card_bank;
	int p_col_day;
	int Clinic_c_id_clinic;

public: // ������ ����� �����
	Patient() {}// ������� �����������
	// ����������� ����������� ���� �ᒺ��� �����
	Patient(int num_record, String^ full_name, DateTime^ birthday, String^ complaints, String^ diognosis, String^ num_tel, String^ card_bank, int pc, int cicc) {
		this->p_full_name = full_name;
		this->p_birthday = birthday;
		this->p_complaints = complaints;
		this->p_diognosis = diognosis;
		this->p_num_tel = num_tel;
		this->p_card_bank = card_bank;

		if (pc > 0) {
			this->p_num_record = num_record;
		}

		if (pc > 0) {
			this->p_col_day = pc;
		}
		if (cicc > 0) {
			this->Clinic_c_id_clinic = cicc;
		}
		else throw invalid_argument("Wrong id");
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}
	
	String^ getFullName() {	return this->p_full_name; }
	DateTime^ getBirthday() { return this->p_birthday; }
	String^ getComplaints() { return this->p_complaints; }
	String^ getDiognosis() { return this->p_diognosis; }
	String^ getTelephone() { return this->p_num_tel; }
	String^ getBank() { return this->p_card_bank; }
	int getColDay() { return this->p_col_day; }
	int getClinicCIdClinic() { return this->Clinic_c_id_clinic;	}
	int getId() { return this->p_num_record; }
};