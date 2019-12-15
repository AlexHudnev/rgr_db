
void create_transport_route() {
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

	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;

	EXEC SQL BEGIN DECLARE SECTION;
	const char* scn = start_country_name;
  const char* ssn = start_state_name;
	const char* sc = start_city;
	const char* fcn = finish_country_name;
  const char* fsn = finish_state_name;
	const char* fc = finish_city;
	unsigned long long trn = transport_route_number;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL INSERT INTO transport_route(start_country_name, start_state_name, start_city, finish_country_name, finish_state_name, finish_city, number) VALUES(:scn, :ssn, :sc, :fcn, :fsn, :fc, :trn);
	EXEC SQL COMMIT;
	return;
}
void show_transport_route() {
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

  cout << "Введите номер маршрута:" << endl;
  unsigned long long transport_route_number; cin >> transport_route_number;

	EXEC SQL BEGIN DECLARE SECTION;
  const char* scn = start_country_name;
  const char* ssn = start_state_name;
	const char* sc = start_city;
	const char* fcn = finish_country_name;
  const char* fsn = finish_state_name;
	const char* fc = finish_city;
	unsigned long long trn = transport_route_number;

	EXEC SQL END DECLARE SECTION;

	EXEC SQL SELECT start_country_name, start_state_name, start_city, finish_country_name, finish_state_name, finish_city, number INTO :scn, :ssn, :sc, :fcn, :fsn, :fc, :trn FROM transport_route WHERE start_country_name = :scn AND start_state_name = :ssn AND start_city = :sc AND finish_country_name = :fcn AND finish_state_name = :fsn AND finish_city = :fc AND number = :trn;


 	cout << endl;
	cout << " Название страны отправления:" << scn << endl;
	cout << " Название AE отправления:" << ssn << endl;
	cout << " Название Города отправления:" << sc << endl;
	cout << " Название страны прибытия:" << fcn << endl;
	cout << " Название AE прибытия:" << fsn << endl;
	cout << " Название Города прибытия:"<< fc << endl;
	cout << " Номер маршрута:" << trn <<  endl;
	cout << endl;
	return;
}
void update_transport_route() {
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

  cout << "Введите номер маршрута:" << endl;
  unsigned long long transport_route_number; cin >> transport_route_number;


	EXEC SQL BEGIN DECLARE SECTION;
	const char* scn = start_country_name;
	const char* ssn = start_state_name;
	const char* sc = start_city;
	const char* fcn = finish_country_name;
	const char* fsn = finish_state_name;
	const char* fc = finish_city;
	unsigned long long trn = transport_route_number;


	EXEC SQL END DECLARE SECTION;
	EXEC SQL UPDATE transport_route SET start_country_name = :scn, start_state_name = :ssn, start_city = :sc, finish_country_name = :fcn, finish_state_name = :fsn, finish_city = :fc, number = :trn WHERE start_country_name = :scn AND start_state_name = :ssn AND start_city = :sc AND finish_country_name = :fcn AND finish_state_name = :fsn AND finish_city = :fc AND number = :trn;

	EXEC SQL COMMIT;
	return;
}
void delete_transport_route() {
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

  cout << "Введите номер маршрута:" << endl;
  unsigned long long transport_route_number; cin >> transport_route_number;

	EXEC SQL BEGIN DECLARE SECTION;
  const char* scn = start_country_name;
	const char* ssn = start_state_name;
	const char* sc = start_city;
	const char* fcn = finish_country_name;
	const char* fsn = finish_state_name;
	const char* fc = finish_city;
	unsigned long long trn = transport_route_number;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL DELETE FROM transport_route WHERE start_country_name = :scn AND start_state_name = :ssn AND start_city = :sc AND finish_country_name = :fcn AND finish_state_name = :fsn AND finish_city = :fc AND number = :trn;
	EXEC SQL COMMIT;
	return;
}
void printTable_transport_route() {
	EXEC SQL BEGIN DECLARE SECTION;
	char scn[256];
  char ssn[256];
	char sc [256];
	char fcn[256];
  char fsn[256];
	char fc [256];
	unsigned long long trn ;


	EXEC SQL END DECLARE SECTION;


	EXEC SQL DECLARE cursor_transport_route CURSOR FOR
		SELECT  start_country_name, start_state_name, start_city, finish_country_name, finish_state_name, finish_city, number FROM transport_route ORDER BY number;

	EXEC SQL OPEN cursor_transport_route;

	while (true) {
		EXEC SQL FETCH cursor_transport_route INTO :scn, :ssn, :sc, :fcn, :fsn, :fc, :trn;

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
  	cout << " Номер маршрута:" << trn <<  endl;
		cout << endl;
	}

	EXEC SQL CLOSE cursor_transport_route;
	return;
}
void menu_transport_route(){
	while (true) {
		cout << "Меню управления Транспортных маршрутов:" << endl;
		cout << "1. Создать Транспортный маршрут" << endl;
		cout << "2. Найти Транспортный маршрут" << endl;
		cout << "3. Модифицировать информацию о Транспортном маршруте" << endl;
		cout << "4. Удалить Транспортный маршрут" << endl;
		cout << "5. Показать все Транспортные маршруты" << endl;
		cout << "0. Выйти" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				create_transport_route();
				break;
			}
			case 2: {
				show_transport_route();
				break;
			}
			case 3: {
				update_transport_route();
				break;
			}
			case 4: {
				delete_transport_route();
				break;
			}
			case 5: {
				printTable_transport_route();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
