/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

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
	    
      
	    
     
     

	
#line 25 "country.cpp"
 const char * n = name ;
 
#line 26 "country.cpp"
 const char * ln = leader_name ;
 
#line 27 "country.cpp"
 const char * s = state_device ;
 
#line 28 "country.cpp"
 int sq = square ;
 
#line 29 "country.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 31 "country.cpp"

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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 32 "country.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 33 "country.cpp"

	return;
}
void show_country() {
	cout << "Введите название страны:\n";
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	/* exec sql begin declare section */
      
    
	   
    
     

	
#line 43 "country.cpp"
 const char * n = name ;
 
#line 44 "country.cpp"
 char ln [ 256 ] ;
 
#line 45 "country.cpp"
 char s [ 256 ] ;
 
#line 46 "country.cpp"
 int sq ;
 
#line 47 "country.cpp"
 int pd = - 1 ;
/* exec sql end declare section */
#line 49 "country.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select name , state_device , leader_name , square , population_density from country where name = $1 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 51 "country.cpp"


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

	/* exec sql begin declare section */
      
      
	    
     
     

	
#line 89 "country.cpp"
 const char * n = name ;
 
#line 90 "country.cpp"
 const char * ln = leader_name ;
 
#line 91 "country.cpp"
 const char * s = state_device ;
 
#line 92 "country.cpp"
 int sq = square ;
 
#line 93 "country.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 95 "country.cpp"

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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 96 "country.cpp"


	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 98 "country.cpp"

	return;
}
void delete_country() {
  cout << "Введите название страны:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	/* exec sql begin declare section */
	    
	
#line 108 "country.cpp"
 const char * n = name ;
/* exec sql end declare section */
#line 109 "country.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from country where name = $1 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 110 "country.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 111 "country.cpp"

	return;
}
void printTable_country() {
	/* exec sql begin declare section */
    
    
     
   
   


	
#line 116 "country.cpp"
 char n [ 256 ] ;
 
#line 117 "country.cpp"
 char ln [ 256 ] ;
 
#line 118 "country.cpp"
 char s [ 256 ] ;
 
#line 119 "country.cpp"
 int sq ;
 
#line 120 "country.cpp"
 int pd ;
/* exec sql end declare section */
#line 123 "country.cpp"



	/* declare cursor cursor for select name , state_device , leader_name , square , population_density from country order by name */
#line 127 "country.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor cursor for select name , state_device , leader_name , square , population_density from country order by name", ECPGt_EOIT, ECPGt_EORT);}
#line 129 "country.cpp"


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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 132 "country.cpp"


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

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor", ECPGt_EOIT, ECPGt_EORT);}
#line 147 "country.cpp"

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
