/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "city.cpp"

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

	/* exec sql begin declare section */
	    
      
	    
      
     

	
#line 29 "city.cpp"
 const char * n = name ;
 
#line 30 "city.cpp"
 const char * ln = leader_name ;
 
#line 31 "city.cpp"
 const char * s = country_name ;
 
#line 32 "city.cpp"
 const char * sn = state_name ;
 
#line 33 "city.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 35 "city.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into city ( name , country_name , leader_name , state_name , population_density ) values ( $1  , $2  , $3  , $4  , $5  )", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(ln),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 36 "city.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 37 "city.cpp"

	return;
}
void show_city() {
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

	/* exec sql begin declare section */
      
    
	    
      
     

	
#line 57 "city.cpp"
 const char * n = name ;
 
#line 58 "city.cpp"
 char ln [ 256 ] ;
 
#line 59 "city.cpp"
 const char * s = country_name ;
 
#line 60 "city.cpp"
 const char * sn = state_name ;
 
#line 61 "city.cpp"
 int pd = - 1 ;
/* exec sql end declare section */
#line 63 "city.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select name , country_name , leader_name , state_name , population_density from city where name = $1  and country_name = $2  and state_name = $3 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 65 "city.cpp"


  if (pd < 0)
	{cout << "Ничего не найдено" << endl; return;}

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


	/* exec sql begin declare section */
      
      
	    
      
     

	
#line 108 "city.cpp"
 const char * n = name ;
 
#line 109 "city.cpp"
 const char * ln = leader_name ;
 
#line 110 "city.cpp"
 const char * s = country_name ;
 
#line 111 "city.cpp"
 const char * sn = country_name ;
 
#line 112 "city.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 114 "city.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update city set country_name = $1  , leader_name = $2  , state_name = $3  , population_density = $4  where name = $5  and country_name = $6  and state_name = $7 ", 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(ln),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 115 "city.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 116 "city.cpp"

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

	/* exec sql begin declare section */
	    
	    
      
	
#line 136 "city.cpp"
 const char * n = name ;
 
#line 137 "city.cpp"
 const char * s = country_name ;
 
#line 138 "city.cpp"
 const char * sn = state_name ;
/* exec sql end declare section */
#line 139 "city.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from city where name = $1  and country_name = $2  and state_name = $3 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 140 "city.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 141 "city.cpp"

	return;
}
void printTable_city() {
	/* exec sql begin declare section */
    
    
     
     
   


	
#line 146 "city.cpp"
 char n [ 256 ] ;
 
#line 147 "city.cpp"
 char ln [ 256 ] ;
 
#line 148 "city.cpp"
 char s [ 256 ] ;
 
#line 149 "city.cpp"
 char sn [ 256 ] ;
 
#line 150 "city.cpp"
 int pd ;
/* exec sql end declare section */
#line 153 "city.cpp"



	/* declare cursor_city cursor for select name , country_name , leader_name , state_name , population_density from city order by name */
#line 157 "city.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_city cursor for select name , country_name , leader_name , state_name , population_density from city order by name", ECPGt_EOIT, ECPGt_EORT);}
#line 159 "city.cpp"


	while (true) {
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_city", ECPGt_EOIT, 
	ECPGt_char,(n),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(sn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 162 "city.cpp"


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

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_city", ECPGt_EOIT, ECPGt_EORT);}
#line 177 "city.cpp"

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
