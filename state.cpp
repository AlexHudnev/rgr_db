
void create_state() {
	cout << "Введите название АЕ:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	cout << "Введите название страны:" << endl;
  string tmpcountry_name;
  cin >> tmpcountry_name;
  const char* country_name = tmpcountry_name.c_str();

  cout << "Введите ФИО главы:" << endl;
  string tmpleader_name;
  cin >> tmpleader_name;
  const char* leader_name = tmpleader_name.c_str();

  cout << "Введите площадь:" << endl;
  int square; cin >> square;

  cout << "Введите количество населения:" << endl;
  int population_density; cin >> population_density;
  cout << country_name << leader_name << square <<  population_density;

	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
  const char* ln = leader_name;
	const char* s = country_name;
  int sq = square;
  int pd = population_density;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL INSERT INTO state(name, country_name, leader_name, square, population_density ) VALUES(:n, :s, :ln, :sq, :pd);
	EXEC SQL COMMIT;
	return;
}
void show_state() {
	cout << "Введите название АЕ:\n";
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
  const char* n = name;
  char ln [256];
	char s [256] ;
  int sq ;
  int pd ;

	EXEC SQL END DECLARE SECTION;

	EXEC SQL SELECT name, country_name, leader_name, square, population_density INTO :n, :s, :ln, :sq, :pd FROM state WHERE name = :n;

	cout << endl;
	cout << "Название АЕ: " << n << endl;
  cout << "Название страны: " << s << endl;
  cout << "ФИО лидера: " << ln << endl;
  cout << "Площадь: " << sq << endl;
  cout << "Количество населения: " << pd << endl;
	cout << endl;
	return;
}
void update_state() {

  cout << "Введите название АЕ:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

  cout << "Введите название страны:" << endl;
  string tmpcountry_name;
  cin >> tmpcountry_name;
  const char* country_name = tmpcountry_name.c_str();

  cout << "Введите ФИО главы:" << endl;
  string tmpleader_name;
  cin >> tmpleader_name;
  const char* leader_name = tmpleader_name.c_str();

  cout << "Введите площадь:" << endl;
  int square; cin >> square;

  cout << "Введите количество населения:" << endl;
  int population_density; cin >> population_density;

	EXEC SQL BEGIN DECLARE SECTION;
  const char* n = name;
  const char* ln = leader_name;
	const char* s = country_name;
  int sq = square;
  int pd = population_density;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL UPDATE state SET country_name = :s, leader_name = :ln, square = :sq, population_density = :pd WHERE name = :n;

	EXEC SQL COMMIT;
	return;
}
void delete_state() {
  cout << "Введите название АЕ:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL DELETE FROM state WHERE name = :n;
	EXEC SQL COMMIT;
	return;
}
void printTable_state() {
	EXEC SQL BEGIN DECLARE SECTION;
  char n [256];
  char ln [256];
  char s [256] ;
  int sq;
  int pd;


	EXEC SQL END DECLARE SECTION;


	EXEC SQL DECLARE cursor_state CURSOR FOR
		SELECT  name, country_name, leader_name, square, population_density FROM state ORDER BY name;

	EXEC SQL OPEN cursor_state;

	while (true) {
		EXEC SQL FETCH cursor_state INTO :n, :s, :ln, :sq, :pd;

		if (sqlca.sqlcode == ECPG_NOT_FOUND) {
			break;
		}

    cout << endl;
  	cout << "Название АЕ: " << n << endl;
    cout << "Название страны: " << s << endl;
    cout << "ФИО лидера: " << ln << endl;
    cout << "Площадь: " << sq << endl;
    cout << "Количество населения: " << pd << endl;
  	cout << endl;
	}

	EXEC SQL CLOSE cursor_state;
	return;
	return;
}
void menu_state(){
	while (true) {
		cout << "Меню управления Административными единицами (АЕ):" << endl;
		cout << "1. Создать АЕ" << endl;
		cout << "2. Найти АЕ" << endl;
		cout << "3. Модифицировать информацию об АЕ" << endl;
		cout << "4. Удалить АЕ" << endl;
		cout << "5. Показать все АЕ" << endl;
		cout << "0. Выйти" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				create_state();
				break;
			}
			case 2: {
				show_state();
				break;
			}
			case 3: {
				update_state();
				break;
			}
			case 4: {
				delete_state();
				break;
			}
			case 5: {
				printTable_state();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}