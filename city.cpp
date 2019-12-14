
void create_city() {
	cout << "Введите название Города:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	cout << "Введите название AE:" << endl;
	string tmpstate_name;
	cin >> tmpstate_name;
	const char* state_name = tmpstate_name.c_str();

	cout << "Введите название страны:" << endl;
  string tmpcountry_name;
  cin >> tmpcountry_name;
  const char* country_name = tmpcountry_name.c_str();


  cout << "Введите ФИО главы:" << endl;
  string tmpleader_name;
  cin >> tmpleader_name;
  const char* leader_name = tmpleader_name.c_str();


  cout << "Введите количество населения:" << endl;
  int population_density; cin >> population_density;

	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
  const char* ln = leader_name;
	const char* s = country_name;
  const char* sn = state_name;
  int pd = population_density;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL INSERT INTO city(name, country_name, leader_name, state_name, population_density ) VALUES(:n, :s, :ln, :sn, :pd);
	EXEC SQL COMMIT;
	return;
}
void show_city() {
	cout << "Введите название Города:\n";
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
  const char* n = name;
  char ln [256];
	char s [256] ;
  char sn [256] ;
  int pd ;

	EXEC SQL END DECLARE SECTION;

	EXEC SQL SELECT name, country_name, leader_name, state_name, population_density INTO :n, :s, :ln, :sn, :pd FROM city WHERE name = :n;

	cout << endl;
	cout << "Название Города: " << n << endl;
	cout << "Название страны АЕ: " << sn << endl;
  cout << "Название страны: " << s << endl;
  cout << "ФИО лидера: " << ln << endl;
  cout << "Количество населения: " << pd << endl;
	cout << endl;
	return;
}
void update_city() {

	cout << "Введите название Города:" << endl;
	string tmpname;
	cin >> tmpname;
	const char* name = tmpname.c_str();

	cout << "Введите название AE:" << endl;
	string tmpstate_name;
	cin >> tmpstate_name;
	const char* state_name = tmpstate_name.c_str();

	cout << "Введите название страны:" << endl;
	string tmpcountry_name;
	cin >> tmpcountry_name;
	const char* country_name = tmpcountry_name.c_str();


	cout << "Введите ФИО главы:" << endl;
	string tmpleader_name;
	cin >> tmpleader_name;
	const char* leader_name = tmpleader_name.c_str();


	cout << "Введите количество населения:" << endl;
	int population_density; cin >> population_density;


	EXEC SQL BEGIN DECLARE SECTION;
  const char* n = name;
  const char* ln = leader_name;
	const char* s = country_name;
  const char* sn = country_name;
  int pd = population_density;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL UPDATE city SET country_name = :s, leader_name = :ln, state_name = :sn, population_density = :pd WHERE name = :n;

	EXEC SQL COMMIT;
	return;
}
void delete_city() {
  cout << "Введите название Города:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL DELETE FROM city WHERE name = :n;
	EXEC SQL COMMIT;
	return;
}
void printTable_city() {
	EXEC SQL BEGIN DECLARE SECTION;
  char n [256];
  char ln [256];
  char s [256] ;
  char sn [256] ;
  int pd;


	EXEC SQL END DECLARE SECTION;


	EXEC SQL DECLARE cursor_city CURSOR FOR
		SELECT  name, country_name, leader_name, state_name, population_density FROM city ORDER BY name;

	EXEC SQL OPEN cursor_city;

	while (true) {
		EXEC SQL FETCH cursor_city INTO :n, :s, :ln, :sn, :pd;

		if (sqlca.sqlcode == ECPG_NOT_FOUND) {
			break;
		}

		cout << endl;
		cout << "Название Города: " << n << endl;
		cout << "Название страны АЕ: " << sn << endl;
	  cout << "Название страны: " << s << endl;
	  cout << "ФИО лидера: " << ln << endl;
	  cout << "Количество населения: " << pd << endl;
		cout << endl;
	}

	EXEC SQL CLOSE cursor_city;
	return;
}
void menu_city(){
	while (true) {
		cout << "Меню управления Городами:" << endl;
		cout << "1. Создать Город" << endl;
		cout << "2. Найти Город" << endl;
		cout << "3. Модифицировать информацию об Городе" << endl;
		cout << "4. Удалить Город" << endl;
		cout << "5. Показать все Города" << endl;
		cout << "0. Выйти" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				create_city();
				break;
			}
			case 2: {
				show_city();
				break;
			}
			case 3: {
				update_city();
				break;
			}
			case 4: {
				delete_city();
				break;
			}
			case 5: {
				printTable_city();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
