#pragma once
#include <stdexcept>
#include <String.h>
using namespace std;
using namespace System;
// оголошення класу
ref class Clinic {

	int c_id_clinic;
	String^ с_country;
	String^ c_city;
	String^ c_area;
	String^ c_name;
	String^ c_general_doctor;
	String^ c_general_register;
	String^ c_deputy_g_doctor;

public: // відкриті члени класу
	Clinic() {}// порожній конструктор
	// конструктор ініціалізаціі полів об’єктів класу
	Clinic(int ic, String^ cco, String^ cci, String^ ca, String^ cn, String^ cgd, String^ cgr, String^ cdgd) {
		this->с_country = cco;
		this->c_city = cci;
		this->c_area = ca;
		this->c_name = cn;
		this->c_general_doctor = cgd;
		this->c_general_register = cgr;
		this->c_deputy_g_doctor = cdgd;
		if (ic > 0) {
			this->c_id_clinic = ic;
		}
		else throw invalid_argument("Wrong id");
		// обробка помилки при спробі ввести код запису, менший або рівний 0
	}
	String^ getCountry() {	return this->с_country;	}
	String^ getСity() {	return this->c_city; }
	String^ getArea() {	return this->c_area; }
	String^ getName() {	return this->c_name; }
	String^ getGeneralDoctor() { return this->c_general_doctor;	}
	String^ getGeneralRegister() { return this->c_general_register;	}
	String^ getDeputyGDoctor() { return this->c_deputy_g_doctor; }
	int getId() { return this->c_id_clinic;	}
};