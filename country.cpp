void create_country() {
	cout << "Введите название страны:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	cout << "Введите тип государственного устройства:" << endl;
  string tmpstate_device;
  cin >> tmpstate_device;
  const char* state_device = tmpstate_device.c_str();

  cout << "Введите ФИО главы:" << endl;
  string tmpleader_name;
  cin >> tmpleader_name;
  const char* leader_name = tmpleader_name.c_str();

  cout << "Введите площадь:" << endl;
  int square; cin >> square;

  cout << "Введите количество населения:" << endl;
  int population_density; cin >> population_density;
  cout << state_device << leader_name << square <<  population_density;

	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
  const char* ln = leader_name;
	const char* s = state_device;
  int sq = square;
  int pd = population_density;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL INSERT INTO country(name, state_device, leader_name, square, population_density ) VALUES(:n, :s, :ln, :sq, :pd);
	EXEC SQL COMMIT;
	return;
}
void show_country() {
	cout << "Введите название страны:\n";
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
  const char* n = name;
  char ln [256];
	char s [256] ;
  int sq ;
  int pd = -1;

	EXEC SQL END DECLARE SECTION;

	EXEC SQL SELECT name, state_device, leader_name, square, population_density INTO :n, :s, :ln, :sq, :pd FROM country WHERE name = :n;

	if (pd < 0)
	{cout << "Ничего не найдено" << endl; return;}

	cout << endl;
	cout << "Название: " << n << endl;
  cout << "Вид гос устройства: " << s << endl;
  cout << "ФИО лидера: " << ln << endl;
  cout << "Площадь: " << sq << endl;
  cout << "Количество населения: " << pd << endl;
	cout << endl;
	return;
}
void update_country() {

  cout << "Введите название страны:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

  cout << "Введите тип государственного устройства:" << endl;
  string tmpstate_device;
  cin >> tmpstate_device;
  const char* state_device = tmpstate_device.c_str();

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
	const char* s = state_device;
  int sq = square;
  int pd = population_density;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL UPDATE country SET state_device = :s, leader_name = :ln, square = :sq, population_density = :pd WHERE name = :n;

	EXEC SQL COMMIT;
	return;
}
void delete_country() {
  cout << "Введите название страны:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL DELETE FROM country WHERE name = :n;
	EXEC SQL COMMIT;
	return;
}
void printTable_country() {
	EXEC SQL BEGIN DECLARE SECTION;
  char n [256];
  char ln [256];
  char s [256] ;
  int sq;
  int pd;


	EXEC SQL END DECLARE SECTION;


	EXEC SQL DECLARE cursor CURSOR FOR
		SELECT  name, state_device, leader_name, square, population_density FROM country ORDER BY name;

	EXEC SQL OPEN cursor;

	while (true) {
		EXEC SQL FETCH cursor INTO :n, :s, :ln, :sq, :pd;

		if (sqlca.sqlcode == ECPG_NOT_FOUND) {
			break;
		}

    cout << endl;
  	cout << "Название: " << n << endl;
    cout << "Вид гос устройства: " << s << endl;
    cout << "ФИО лидера: " << ln << endl;
    cout << "Площадь: " << sq << endl;
    cout << "Количество населения: " << pd << endl;
  	cout << endl;
	}

	EXEC SQL CLOSE cursor;
	return;
	return;
}
void menu_country(){
	while (true) {
		cout << "Меню стран:" << endl;
		cout << "1. Создать страну" << endl;
		cout << "2. Найти страну" << endl;
		cout << "3. Модифицировать информацию о стране" << endl;
		cout << "4. Удалить страну" << endl;
		cout << "5. Показать все страны" << endl;
		cout << "0. Выйти" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				create_country();
				break;
			}
			case 2: {
				show_country();
				break;
			}
			case 3: {
				update_country();
				break;
			}
			case 4: {
				delete_country();
				break;
			}
			case 5: {
				printTable_country();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
