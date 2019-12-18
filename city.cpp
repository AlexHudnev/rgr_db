EXEC SQL WHENEVER SQLERROR SQLPRINT;

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

void search_city(){
	cout << "Введите название AE:" << endl;
	string tmpname;
	cin >> tmpname;
	const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
	const char* sn = name;
	char s [256];
	char ln [256];
	char n [256];
	int pd = -1;

	EXEC SQL END DECLARE SECTION;


		EXEC SQL DECLARE cursor_city_show CURSOR FOR
			SELECT  name, country_name, leader_name, population_density FROM city WHERE state_name = :sn  ORDER BY name;

		EXEC SQL OPEN cursor_city_show;
    int count = 0;
		while (true) {
			EXEC SQL FETCH cursor_city_show INTO  :n, :s, :ln, :pd;

			if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
			{
				cout << "Не найдено\n";
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

		EXEC SQL CLOSE cursor_city_show;
		return;

}

void search_city_pd(){
	cout << "Введите количество населения:" << endl;
  int population_density; cin >> population_density;

	EXEC SQL BEGIN DECLARE SECTION;
	char n [256];
	char s [256];
	char ln [256];
	char sn [256];
	int pd = population_density;
	int real_pd;
	int coutry_pd;

	EXEC SQL END DECLARE SECTION;

		// EXEC SQL DECLARE cursor_city_show_pd CURSOR FOR
		// 		WITH tt AS (SELECT name, population_density  FROM country WHERE population_density <=  :pd)
		// 				SELECT  name, country_name, leader_name, state_name, population_density FROM city WHERE country_name NOT IN (Select name from tt);
		EXEC SQL DECLARE cursor_city_show_pd CURSOR FOR
				WITH tt AS (SELECT name, population_density  FROM country WHERE population_density >=  :pd)
						SELECT  ci.name, ci.country_name, ci.leader_name, ci.state_name, ci.population_density, ty.population_density FROM city ci JOIN tt ty on ty.name = ci.country_name;


		EXEC SQL OPEN cursor_city_show_pd;
    int count = 0;
		while (true) {
			EXEC SQL FETCH cursor_city_show_pd INTO  :n, :s, :ln, :sn, :real_pd, :coutry_pd;

			if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
			{
				if (count == 0) cout << "Таких нет\n";
				break;
			}
			count ++;

			cout << endl;
			cout << "Название Города: " << n << endl;
			cout << "Название страны АЕ: " << sn << endl;
			cout << "Название страны: " << s << endl;
			cout << "Количество населения в стране: " << coutry_pd << endl;
			cout << "ФИО лидера: " << ln << endl;
			cout << "Количество населения: " << real_pd << endl;
			cout << endl;
		}

		EXEC SQL CLOSE cursor_city_show_pd;
		return;

}

void show_city() {
	cout << "Введите название Города:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
  const char* n = name;
	char s [256];
  char ln [256];
  char sn [256];
  int pd = -1;

	EXEC SQL END DECLARE SECTION;


		EXEC SQL DECLARE cursor_city_search CURSOR FOR
			SELECT  country_name, leader_name, state_name, population_density FROM city WHERE name = :n  ORDER BY name;

		EXEC SQL OPEN cursor_city_search;
    int count = 0;
		while (true) {
			EXEC SQL FETCH cursor_city_search INTO  :s, :ln, :sn, :pd;

			if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
			{
				if (count == 0) cout << "Таких нет\n";
				break;
			}
			count ++;

			cout << endl;
			cout << "Название Города: " << n << endl;
			cout << "Название страны АЕ: " << sn << endl;
		  cout << "Название страны: " << s << endl;
		  cout << "ФИО лидера: " << ln << endl;
		  cout << "Количество населения: " << pd << endl;
			cout << endl;
		}

		EXEC SQL CLOSE cursor_city_search;
		return;
}


void show_country_with_city() {
	cout << "Введите название Города:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	EXEC SQL BEGIN DECLARE SECTION;
  const char* n = name;
	char nc [256]  ;
  char ln [256];
	char s [256] ;
  int sq ;
  int pd;

	EXEC SQL END DECLARE SECTION;


		EXEC SQL DECLARE cursor_city_country_search CURSOR FOR
			SELECT co.name, co.state_device, co.leader_name, co.square, co.population_density FROM country co JOIN city ci ON co.name = ci.country_name  WHERE ci.name = :n ;

		EXEC SQL OPEN cursor_city_country_search;

		cout << "\n Страны в которых есть " << name << "\n";

		int count = 0;
		while (true) {
			EXEC SQL FETCH cursor_city_country_search INTO :nc, :s, :ln, :sq, :pd;

			if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
			{
				if (count == 0) cout << "Таких нет\n";
				break;
			}
      count ++;
			cout << endl;
			cout << "Название: " << nc << endl;
			cout << "Вид гос устройства: " << s << endl;
			cout << "ФИО лидера: " << ln << endl;
			cout << "Площадь: " << sq << endl;
			cout << "Количество населения: " << pd << endl;
			cout << endl;
		}

		EXEC SQL CLOSE cursor_city_country_search;
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
  const char* sn = state_name;
  int pd = population_density;

	EXEC SQL END DECLARE SECTION;
	EXEC SQL UPDATE city SET country_name = :s, leader_name = :ln, state_name = :sn, population_density = :pd  WHERE name = :n AND country_name = :s AND state_name = :sn;
	EXEC SQL COMMIT;
	return;
}
void delete_city() {
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

	EXEC SQL BEGIN DECLARE SECTION;
	const char* n = name;
	const char* s = country_name;
  const char* sn = state_name;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL DELETE FROM city WHERE name = :n AND country_name = :s AND state_name = :sn;
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
		cout << "2. Найти Город  по названию" << endl;
		cout << "3. Модифицировать информацию об Городе" << endl;
		cout << "4. Удалить Город" << endl;
		cout << "5. Показать все Города" << endl;
		cout << "6. Найти город в АЕ" << endl;
		cout << "7. Найти страны с указанным городом" << endl;
		cout << "8. Найти города в странах с населением больше чем: " << endl;
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
			case 6: {
				search_city();
				break;}
			case 7:{
				show_country_with_city();
				break;
			}
      case 8: {
				 search_city_pd();
				break;}
			case 0: {
				return;
			}
		}
	}
}
