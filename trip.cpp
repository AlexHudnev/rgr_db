
void create_trip() {
	cout << "Введите название страны отправления:" << endl;
	string tmpstart_country_name;
	cin >> tmpstart_country_name;
	const char* start_country_name = tmpstart_country_name.c_str();

	cout << "Введите название AE отправления:" << endl;
	string tmpstart_state_name;
	cin >> tmpstart_state_name;
	const char* start_state_name = tmpstart_state_name.c_str();

	cout << "Введите название Города отправления:" << endl;
	string tmpstart_name;
	cin >> tmpstart_name;
	const char* start_city = tmpstart_name.c_str();

	cout << "Введите название страны прибытия:" << endl;
	string tmpfinish_country_name;
	cin >> tmpfinish_country_name;
	const char* finish_country_name = tmpfinish_country_name.c_str();

	cout << "Введите название AE прибытия:" << endl;
	string tmpfinish_state_name;
	cin >> tmpfinish_state_name;
	const char* finish_state_name = tmpfinish_state_name.c_str();

	cout << "Введите название Города прибытия:" << endl;
	string tmpfinish_name;
	cin >> tmpfinish_name;
	const char* finish_city = tmpfinish_name.c_str();

	cout << "Введите вид транспорта:" << endl;
	string tmptransport_type;
	cin >> tmptransport_type;
	const char* transport_type = tmptransport_type.c_str();

	cout << "Введите дату поездки" << endl;
	string tmpdate;
	cin >> tmpdate;
	const char* date = tmpdate.c_str();

	cout << "Введите номер паспорта:" << endl;
	unsigned long long passenger_passport_id; cin >> passenger_passport_id;


	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;




	EXEC SQL BEGIN DECLARE SECTION;
	const char* scn = start_country_name;
  const char* ssn = start_state_name;
	const char* sc = start_city;
	const char* fcn = finish_country_name;
  const char* fsn = finish_state_name;
	const char* fc = finish_city;
	const char* tt = transport_type;
  const char* d = date;
	unsigned long long pid = passenger_passport_id;
	unsigned long long trn = transport_route_number;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL INSERT INTO trip(start_country_name, start_state_name, start_city, finish_country_name, finish_state_name, finish_city, transport_type, date, passenger_passport_id, transport_route_number) VALUES(:scn, :ssn, :sc, :fcn, :fsn, :fc, :tt, :d, :pid, :trn);
	EXEC SQL COMMIT;
	return;
}
void show_trip() {
	cout << "Введите дату поездки" << endl;
	string tmpdate;
	cin >> tmpdate;
	const char* date = tmpdate.c_str();

	cout << "Введите номер паспорта:" << endl;
	unsigned long long passenger_passport_id; cin >> passenger_passport_id;


	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;

	EXEC SQL BEGIN DECLARE SECTION;
	char scn[256];
  char ssn[256];
	char sc [256];
	char fcn[256];
  char fsn[256];
	char fc [256];
	char tt [256];
  const char* d = date;
	unsigned long long pid = passenger_passport_id;
	unsigned long long trn = transport_route_number;

	EXEC SQL END DECLARE SECTION;

	EXEC SQL DECLARE cursor_trip_show CURSOR FOR
		SELECT  start_country_name, start_state_name, start_city, finish_country_name, finish_state_name, finish_city, transport_type  FROM trip WHERE passenger_passport_id = :pid AND transport_route_number = :trn AND date = :d ORDER BY date;

	EXEC SQL OPEN cursor_trip_show;

	while (true) {
		EXEC SQL FETCH cursor_trip_show INTO :scn, :ssn, :sc, :fcn, :fsn, :fc, :tt;

		if (sqlca.sqlcode == ECPG_NOT_FOUND) {
			break;
		}

		cout << endl;
		cout << " Название страны отправления:" << scn << endl;
		cout << " Название AE отправления:" << ssn << endl;
		cout << " Название Города отправления:" << sc << endl;
		cout << " Название страны прибытия:" << fcn << endl;
		cout << " Название AE прибытия:" << fsn << endl;
		cout << " Название Города прибытия:"<< fc << endl;
		cout << " Вид транспорта:" << tt <<endl;
		cout << " Дата поездки" << d <<endl;
		cout << " Номер паспорта:" << pid << endl;
		cout << " Номер маршрута:" << trn <<  endl;
		cout << endl;
	}

	EXEC SQL CLOSE cursor_trip_show;
	return;
}
void update_trip() {
	cout << "Введите название страны отправления:" << endl;
	string tmpstart_country_name;
	cin >> tmpstart_country_name;
	const char* start_country_name = tmpstart_country_name.c_str();

	cout << "Введите название AE отправления:" << endl;
	string tmpstart_state_name;
	cin >> tmpstart_state_name;
	const char* start_state_name = tmpstart_state_name.c_str();

	cout << "Введите название Города отправления:" << endl;
	string tmpstart_name;
	cin >> tmpstart_name;
	const char* start_city = tmpstart_name.c_str();

	cout << "Введите название страны прибытия:" << endl;
	string tmpfinish_country_name;
	cin >> tmpfinish_country_name;
	const char* finish_country_name = tmpfinish_country_name.c_str();

	cout << "Введите название AE прибытия:" << endl;
	string tmpfinish_state_name;
	cin >> tmpfinish_state_name;
	const char* finish_state_name = tmpfinish_state_name.c_str();

	cout << "Введите название Города прибытия:" << endl;
	string tmpfinish_name;
	cin >> tmpfinish_name;
	const char* finish_city = tmpfinish_name.c_str();

	cout << "Введите вид транспорта:" << endl;
	string tmptransport_type;
	cin >> tmptransport_type;
	const char* transport_type = tmptransport_type.c_str();

	cout << "Введите дату поездки" << endl;
	string tmpdate;
	cin >> tmpdate;
	const char* date = tmpdate.c_str();

	cout << "Введите номер паспорта:" << endl;
	unsigned long long passenger_passport_id; cin >> passenger_passport_id;


	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;



	EXEC SQL BEGIN DECLARE SECTION;
	const char* scn = start_country_name;
	const char* ssn = start_state_name;
	const char* sc = start_city;
	const char* fcn = finish_country_name;
	const char* fsn = finish_state_name;
	const char* fc = finish_city;
	const char* tt = transport_type;
	const char* d = date;
	unsigned long long pid = passenger_passport_id;
	unsigned long long trn = transport_route_number;


	EXEC SQL END DECLARE SECTION;
	EXEC SQL UPDATE trip SET start_country_name = :scn, start_state_name = :ssn, start_city = :sc, finish_country_name = :fcn, finish_state_name = :fsn, finish_city = :fc, transport_type = :tt, date = :d, passenger_passport_id = :pid, transport_route_number = :trn WHERE passenger_passport_id = :pid AND transport_route_number = :trn AND date = :d;

	EXEC SQL COMMIT;
	return;
}
void delete_trip() {
	cout << "Введите дату поездки" << endl;
	string tmpdate;
	cin >> tmpdate;
	const char* date = tmpdate.c_str();

	cout << "Введите номер паспорта:" << endl;
	unsigned long long passenger_passport_id; cin >> passenger_passport_id;


	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;

	EXEC SQL BEGIN DECLARE SECTION;
	const char* d = date;
	unsigned long long pid = passenger_passport_id;
	unsigned long long trn = transport_route_number;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL DELETE FROM trip WHERE passenger_passport_id = :pid AND transport_route_number = :trn AND date = :d;
	EXEC SQL COMMIT;
	return;
}
void printTable_trip() {
	EXEC SQL BEGIN DECLARE SECTION;
	char scn[256];
  char ssn[256];
	char sc [256];
	char fcn[256];
  char fsn[256];
	char fc [256];
	char tt [256];
  char d [256];
	unsigned long long pid ;
	unsigned long long trn ;
	EXEC SQL END DECLARE SECTION;

	EXEC SQL DECLARE cursor_trip CURSOR FOR
		SELECT  start_country_name, start_state_name, start_city, finish_country_name, finish_state_name, finish_city, transport_type, date, passenger_passport_id, transport_route_number FROM trip ORDER BY date;

	EXEC SQL OPEN cursor_trip;

	while (true) {
		EXEC SQL FETCH cursor_trip INTO :scn, :ssn, :sc, :fcn, :fsn, :fc, :tt, :d, :pid, :trn;

		if (sqlca.sqlcode == ECPG_NOT_FOUND) {
			break;
		}

		cout << endl;
		cout << " Название страны отправления:" << scn << endl;
		cout << " Название AE отправления:" << ssn << endl;
		cout << " Название Города отправления:" << sc << endl;
		cout << " Название страны прибытия:" << fcn << endl;
		cout << " Название AE прибытия:" << fsn << endl;
		cout << " Название Города прибытия:"<< fc << endl;
		cout << " Вид транспорта:" << tt <<endl;
		cout << " Дата поездки" << d <<endl;
		cout << " Номер паспорта:" << pid << endl;
		cout << " Номер маршрута:" << trn <<  endl;
		cout << endl;
	}

	EXEC SQL CLOSE cursor_trip;
	return;
}
void menu_trip(){
	while (true) {
		cout << "Меню управления Поездки:" << endl;
		cout << "1. Создать Поездку" << endl;
		cout << "2. Найти Поездку" << endl;
		cout << "3. Модифицировать информацию о Поездке" << endl;
		cout << "4. Удалить Поездку" << endl;
		cout << "5. Показать все Поездки" << endl;
		cout << "0. Выйти" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				create_trip();
				break;
			}
			case 2: {
				show_trip();
				break;
			}
			case 3: {
				update_trip();
				break;
			}
			case 4: {
				delete_trip();
				break;
			}
			case 5: {
				printTable_trip();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
