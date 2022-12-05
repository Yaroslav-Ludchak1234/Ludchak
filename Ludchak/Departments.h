#pragma once
#include <stdexcept>
#include <String.h>
using namespace std;
using namespace System;
// ���������� �����
ref class Departments {

	int d_id;	
	String^ d_name;
	String^ d_deputy;
	int d_col_worker;	
	int d_col_best_worker_mounth;
	int Clinic_c_id_clinic;

public: // ������ ����� �����
	Departments() {}// ������� �����������
	// ����������� ����������� ���� �ᒺ��� �����
	Departments(int id, String^ dn, String^ dd, int dcw, int dcbwm, int ccic) {
		this->d_name = dn;
		this->d_deputy = dd;		
		if (id > 0) { this->d_id = id;	}
		else throw invalid_argument("Wrong id");
		if (dcw > 0) { this->d_col_worker = dcw; }
		else throw invalid_argument("Wrong id");
		if (dcbwm > 0) { this->d_col_best_worker_mounth = dcbwm; }
		else throw invalid_argument("Wrong id");
		if (ccic > 0) { this->Clinic_c_id_clinic = ccic; }
		else throw invalid_argument("Wrong id");
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}
	String^ getDeputy() { return this->d_deputy; }
	String^ getName() { return this->d_name; }	
	int getColWorker() { return this->d_col_worker; }
	int getColBestWorkerMounth() { return this->d_col_best_worker_mounth; }
	int getClinicCIdClinic() { return this->Clinic_c_id_clinic;	}
	int getId() { return this->d_id; }
};