#pragma once
#include <stdexcept>
#include <String.h>
// підключення просторів імен std і System
using namespace std;
using namespace System;
// оголошення класу
ref class Doctor {

	int do_num;
	String^ do_full;
	int do_num_room;
	String^ do_qualification;
	DateTime^ do_birthday;	
	String^ do_spec;
	int Departments_d_id; 


public: // відкриті члени класу
	Doctor() {}// порожній конструктор
	// конструктор ініціалізаціі полів об’єктів класу
	Doctor(int dm, String^ full, int dmr, String^ qualification, DateTime^ birthday, String^ spec, int ddi) {
		this->do_full = full;
		this->do_qualification = qualification;
		this->do_birthday = birthday;		
		this->do_spec = spec;
		if (dm > 0) { this->do_num = dm; }
		else throw invalid_argument("Wrong id");
		if (dmr > 0) { this->do_num_room = dmr;	}
		else throw invalid_argument("Wrong id");
		if (ddi > 0) { this->Departments_d_id = ddi; }
		else throw invalid_argument("Wrong id");
		// обробка помилки при спробі ввести код запису, менший або рівний 0
	}

	String^ getFull() { return this->do_full; }
	String^ getQualification() { return this->do_qualification; }
	DateTime^ getBirthday() { return this->do_birthday;	}
	String^ getSpecialist() { return this->do_spec;	}
	int getDepartaments() { return this->Departments_d_id;	}
	int getNumRoom() { return this->do_num_room; }
	int getId() { return this->do_num; }
};