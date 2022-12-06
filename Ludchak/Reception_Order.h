#pragma once
#include <stdexcept>
#include <String.h>
// підключення просторів імен std і System
using namespace std;
using namespace System;
// оголошення класу
ref class ReceptionOrder {
	//закриті поля класу для збереження даних про ім’я, прізвище, номер телефону,
	//категорії контактів та номер контакту у записнику
	int ro_num_id;
	DateTime^ ro_date_time;
	DateTime^ ro_date_time_limit;
	Decimal^ ro_cost;
	int ro_place;
	String^ pay;
	int Doctor;
	int Patient_p_num_record;

public: // відкриті члени класу
	ReceptionOrder() {}// порожній конструктор
	// конструктор ініціалізаціі полів об’єктів класу
	ReceptionOrder(int num_id, DateTime^ rdt, DateTime^ rdtl, Decimal rc, int rp, String^ p, int Doc ,int Patient) {
		this->ro_date_time = rdt;
		this->ro_date_time_limit = rdtl;
		this->pay = p;
		this->Doctor = Doc;
		if (num_id > 0) { this->ro_num_id = num_id;	}
		else throw invalid_argument("Wrong id");
		if (rc > -1) { this->ro_cost = rc; }
		else throw invalid_argument("Wrong id");
		if (Patient > 0) { this->Patient_p_num_record = Patient; }
		else throw invalid_argument("Wrong id");
		if (rp > 0) { this->ro_place = rp; }
		else throw invalid_argument("Wrong id");
		// обробка помилки при спробі ввести код запису, менший або рівний 0
	}
	
	DateTime^ getDateTime() { return this->ro_date_time; }
	DateTime^ getDateTimeLimit() { return this->ro_date_time_limit; }
	String^ getPay() { return this->pay; }
	int getId() { return this->ro_num_id; }	
	int getPlace() { return this->ro_place; }	
	int getPatient() { return this->Patient_p_num_record; }	
	int getDoctor() { return this->Doctor; }
	Decimal^ getCost() { return this->ro_cost; }
};