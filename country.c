/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "country.cpp"
/* exec sql whenever sqlerror  sqlprint ; */
#line 1 "country.cpp"


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

	/* exec sql begin declare section */
	    
      
	    
     
     

	
#line 27 "country.cpp"
 const char * n = name ;
 
#line 28 "country.cpp"
 const char * ln = leader_name ;
 
#line 29 "country.cpp"
 const char * s = state_device ;
 
#line 30 "country.cpp"
 int sq = square ;
 
#line 31 "country.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 33 "country.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into country ( name , state_device , leader_name , square , population_density ) values ( $1  , $2  , $3  , $4  , $5  )", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(ln),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 34 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 34 "country.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 35 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 35 "country.cpp"

	return;
}
void show_country() {
	cout << "Введите название страны:\n";
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	/* exec sql begin declare section */
      
    
	   
    
    

	
#line 45 "country.cpp"
 const char * n = name ;
 
#line 46 "country.cpp"
 char ln [ 256 ] ;
 
#line 47 "country.cpp"
 char s [ 256 ] ;
 
#line 48 "country.cpp"
 int sq ;
 
#line 49 "country.cpp"
 int pd ;
/* exec sql end declare section */
#line 51 "country.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select state_device , leader_name , square , population_density from country where name = $1 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 53 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 53 "country.cpp"


	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
	{
		cout << "Не найдено\n";
		return;
	}

	cout << endl;
	cout << "Название: " << n << endl;
  cout << "Вид гос устройства: " << s << endl;
  cout << "ФИО лидера: " << ln << endl;
  cout << "Площадь: " << sq << endl;
  cout << "Количество населения: " << pd << endl;
	cout << endl;
	return;
}

void full_stat_country() {
	cout << "Введите название страны:\n";
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	/* exec sql begin declare section */
      
    
	   
    
    
	 
	 
	 

	
#line 78 "country.cpp"
 const char * n = name ;
 
#line 79 "country.cpp"
 char ln [ 256 ] ;
 
#line 80 "country.cpp"
 char s [ 256 ] ;
 
#line 81 "country.cpp"
 int sq ;
 
#line 82 "country.cpp"
 int pd ;
 
#line 83 "country.cpp"
 int state_count ;
 
#line 84 "country.cpp"
 int city_count ;
 
#line 85 "country.cpp"
 int active_pass ;
/* exec sql end declare section */
#line 87 "country.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select state_device , leader_name , square , population_density , ( with pass as ( select passenger_passport_id from trip where start_country_name = $1  or finish_country_name = $2  ) select count ( * ) from pass ) from country where name = $3 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(active_pass),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 90 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 90 "country.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from state where country_name = $1 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(state_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 92 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 92 "country.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from city where country_name = $1 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(city_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 94 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 94 "country.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from city where country_name = $1 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(city_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 96 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 96 "country.cpp"



	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
	{
		cout << "Не найдено\n";
		return;
	}

	cout << endl;
	cout << "Название: " << n << endl;
  cout << "Вид гос устройства: " << s << endl;
  cout << "ФИО лидера: " << ln << endl;
  cout << "Площадь: " << sq << endl;
  cout << "Количество населения: " << pd << endl;
	cout << "Количество АЕ: " << state_count << endl;
	cout << "Количество городов: " << city_count << endl;
	cout << "Количество активных пассажиров " << active_pass << endl;
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

	/* exec sql begin declare section */
      
      
	    
     
     

	
#line 142 "country.cpp"
 const char * n = name ;
 
#line 143 "country.cpp"
 const char * ln = leader_name ;
 
#line 144 "country.cpp"
 const char * s = state_device ;
 
#line 145 "country.cpp"
 int sq = square ;
 
#line 146 "country.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 148 "country.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update country set state_device = $1  , leader_name = $2  , square = $3  , population_density = $4  where name = $5 ", 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(ln),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 149 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 149 "country.cpp"


	{ ECPGtrans(__LINE__, NULL, "commit");
#line 151 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 151 "country.cpp"

	return;
}
void delete_country() {
  cout << "Введите название страны:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	/* exec sql begin declare section */
	    
	
#line 161 "country.cpp"
 const char * n = name ;
/* exec sql end declare section */
#line 162 "country.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from country where name = $1 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 163 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 163 "country.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 164 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 164 "country.cpp"

	return;
}
void printTable_country() {
	/* exec sql begin declare section */
    
    
     
   
   


	
#line 169 "country.cpp"
 char n [ 256 ] ;
 
#line 170 "country.cpp"
 char ln [ 256 ] ;
 
#line 171 "country.cpp"
 char s [ 256 ] ;
 
#line 172 "country.cpp"
 int sq ;
 
#line 173 "country.cpp"
 int pd ;
/* exec sql end declare section */
#line 176 "country.cpp"



	/* declare cursor cursor for select name , state_device , leader_name , square , population_density from country order by name */
#line 180 "country.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor cursor for select name , state_device , leader_name , square , population_density from country order by name", ECPGt_EOIT, ECPGt_EORT);
#line 182 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 182 "country.cpp"


	while (true) {
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor", ECPGt_EOIT, 
	ECPGt_char,(n),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 185 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 185 "country.cpp"


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

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor", ECPGt_EOIT, ECPGt_EORT);
#line 200 "country.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 200 "country.cpp"

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
		cout << "6. Расширенная информация о стране" << endl;
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
			case 6: {
				full_stat_country();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
