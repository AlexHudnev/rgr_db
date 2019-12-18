EXEC SQL WHENEVER SQLERROR SQLPRINT;

void create_passenger() {
	cout << "Введите ФИО пассажира:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

  cout << "Введите номер паспорта:" << endl;
  int passport_id; cin >> passport_id;

	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
  int pid = passport_id;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL INSERT INTO passenger(name, passport_id ) VALUES(:n, :pid);
	EXEC SQL COMMIT;
	return;
}
void show_passenger() {
	cout << "Введите номер паспорта:" << endl;
  int passport_id; cin >> passport_id;

	EXEC SQL BEGIN DECLARE SECTION;
  int pid = passport_id;
	char n [256];

	EXEC SQL END DECLARE SECTION;

	EXEC SQL SELECT name, passport_id INTO :n, :pid FROM passenger WHERE passport_id = :pid;

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
	{
		cout << "Не найдено\n";
		return;
	}

	cout << endl;
	cout << "ФИО: " << n << endl;
  cout << "Номер пасспорта: " << pid << endl;
	cout << endl;
	return;
}
void update_passenger() {

	cout << "Введите ФИО пассажира:" << endl;
	string tmpname;
	cin >> tmpname;
	const char* name = tmpname.c_str();

	cout << "Введите номер паспорта:" << endl;
	int passport_id; cin >> passport_id;


	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
  int pid = passport_id;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL UPDATE passenger SET name = :n WHERE passport_id = :pid;

	EXEC SQL COMMIT;
	return;
}
void delete_passenger() {
	cout << "Введите номер паспорта:" << endl;
	int passport_id; cin >> passport_id;

	EXEC SQL BEGIN DECLARE SECTION;
	int pid = passport_id;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL DELETE FROM passenger WHERE passport_id = :pid;
	EXEC SQL COMMIT;
	return;
}
void printTable_passenger() {
	EXEC SQL BEGIN DECLARE SECTION;
  char n [256];
  int pid;


	EXEC SQL END DECLARE SECTION;


	EXEC SQL DECLARE cursor_passenger CURSOR FOR
		SELECT  name, passport_id INTO :n, :pid FROM passenger ORDER BY name;

	EXEC SQL OPEN cursor_passenger;

	while (true) {
		EXEC SQL FETCH cursor_passenger INTO :n, :pid;

		if (sqlca.sqlcode == ECPG_NOT_FOUND) {
			break;
		}

		cout << endl;
		cout << "ФИО: " << n << endl;
		cout << "Номер пасспорта: " << pid << endl;
		cout << endl;
	}

	EXEC SQL CLOSE cursor_passenger;
	return;
}
void menu_passenger(){
	while (true) {
		cout << "Меню управления Пассажирами:" << endl;
		cout << "1. Создать запись пассажира" << endl;
		cout << "2. Найти пассажира по пасспарту" << endl;
		cout << "3. Модифицировать информацию о пассажире" << endl;
		cout << "4. Удалить запись пассажира" << endl;
		cout << "5. Показать всех пассажиров" << endl;
		cout << "0. Выйти" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				create_passenger();
				break;
			}
			case 2: {
				show_passenger();
				break;
			}
			case 3: {
				update_passenger();
				break;
			}
			case 4: {
				delete_passenger();
				break;
			}
			case 5: {
				printTable_passenger();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
