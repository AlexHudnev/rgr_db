/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "state.cpp"
/* exec sql whenever sqlerror  sqlprint ; */
#line 1 "state.cpp"


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

	/* exec sql begin declare section */
	    
      
	    
     
     

	
#line 27 "state.cpp"
 const char * n = name ;
 
#line 28 "state.cpp"
 const char * ln = leader_name ;
 
#line 29 "state.cpp"
 const char * s = country_name ;
 
#line 30 "state.cpp"
 int sq = square ;
 
#line 31 "state.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 33 "state.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into state ( name , country_name , leader_name , square , population_density ) values ( $1  , $2  , $3  , $4  , $5  )", 
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
#line 34 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 34 "state.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 35 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 35 "state.cpp"

	return;
}
void show_state() {
	cout << "Введите название АЕ:\n";
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	/* exec sql begin declare section */
	    
    
     
   
   

	
#line 45 "state.cpp"
 const char * n = name ;
 
#line 46 "state.cpp"
 char ln [ 256 ] ;
 
#line 47 "state.cpp"
 char s [ 256 ] ;
 
#line 48 "state.cpp"
 int sq ;
 
#line 49 "state.cpp"
 int pd ;
/* exec sql end declare section */
#line 51 "state.cpp"



	ECPGset_var( 0, &( n ), __LINE__);\
 /* declare cursor_state_find cursor for select country_name , leader_name , square , population_density from state where name = $1  order by name */
#line 55 "state.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_state_find cursor for select country_name , leader_name , square , population_density from state where name = $1  order by name", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 57 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 57 "state.cpp"

  int count = 0;
	while (true) {
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_state_find", ECPGt_EOIT, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 60 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 60 "state.cpp"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
		{
			if (count == 0) cout << "Не найдено\n";
			break;
		}
    count ++ ;
    cout << endl;
  	cout << "Название АЕ: " << n << endl;
    cout << "Название страны: " << s << endl;
    cout << "ФИО лидера: " << ln << endl;
    cout << "Площадь: " << sq << endl;
    cout << "Количество населения: " << pd << endl;
  	cout << endl;
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_state_find", ECPGt_EOIT, ECPGt_EORT);
#line 77 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 77 "state.cpp"

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

	/* exec sql begin declare section */
      
      
	    
     
     

	
#line 104 "state.cpp"
 const char * n = name ;
 
#line 105 "state.cpp"
 const char * ln = leader_name ;
 
#line 106 "state.cpp"
 const char * s = country_name ;
 
#line 107 "state.cpp"
 int sq = square ;
 
#line 108 "state.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 110 "state.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update state set country_name = $1  , leader_name = $2  , square = $3  , population_density = $4  where name = $5  and country_name = $6 ", 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(ln),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 111 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 111 "state.cpp"


	{ ECPGtrans(__LINE__, NULL, "commit");
#line 113 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 113 "state.cpp"

	return;
}
void delete_state() {
  cout << "Введите название АЕ:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	cout << "Введите название страны:" << endl;
  string tmpcountry_name;
  cin >> tmpcountry_name;
  const char* country_name = tmpcountry_name.c_str();

	/* exec sql begin declare section */
	    
	    
	
#line 128 "state.cpp"
 const char * n = name ;
 
#line 129 "state.cpp"
 const char * s = country_name ;
/* exec sql end declare section */
#line 130 "state.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from state where name = $1  and country_name = $2 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 131 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 131 "state.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 132 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 132 "state.cpp"

	return;
}
void printTable_state() {
	/* exec sql begin declare section */
    
    
     
   
   


	
#line 137 "state.cpp"
 char n [ 256 ] ;
 
#line 138 "state.cpp"
 char ln [ 256 ] ;
 
#line 139 "state.cpp"
 char s [ 256 ] ;
 
#line 140 "state.cpp"
 int sq ;
 
#line 141 "state.cpp"
 int pd ;
/* exec sql end declare section */
#line 144 "state.cpp"



	/* declare cursor_state cursor for select name , country_name , leader_name , square , population_density from state order by name */
#line 148 "state.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_state cursor for select name , country_name , leader_name , square , population_density from state order by name", ECPGt_EOIT, ECPGt_EORT);
#line 150 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 150 "state.cpp"


	while (true) {
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_state", ECPGt_EOIT, 
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
#line 153 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 153 "state.cpp"


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

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_state", ECPGt_EOIT, ECPGt_EORT);
#line 168 "state.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 168 "state.cpp"

	return;
}
void menu_state(){
	while (true) {
		cout << "Меню управления Административными единицами (АЕ):" << endl;
		cout << "1. Создать АЕ" << endl;
		cout << "2. Найти АЕ по названию" << endl;
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
