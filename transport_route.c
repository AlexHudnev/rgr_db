/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "transport_route.cpp"

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

	/* exec sql begin declare section */
	    
      
	    
	    
      
	    
	     

	
#line 37 "transport_route.cpp"
 const char * scn = start_country_name ;
 
#line 38 "transport_route.cpp"
 const char * ssn = start_state_name ;
 
#line 39 "transport_route.cpp"
 const char * sc = start_city ;
 
#line 40 "transport_route.cpp"
 const char * fcn = finish_country_name ;
 
#line 41 "transport_route.cpp"
 const char * fsn = finish_state_name ;
 
#line 42 "transport_route.cpp"
 const char * fc = finish_city ;
 
#line 43 "transport_route.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 45 "transport_route.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into transport_route ( start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , number ) values ( $1  , $2  , $3  , $4  , $5  , $6  , $7  )", 
	ECPGt_char,&(scn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(ssn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sc),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(fcn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(fsn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(fc),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 46 "transport_route.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 47 "transport_route.cpp"

	return;
}
void show_transport_route() {
	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;

	/* exec sql begin declare section */
	 
   
	  
	 
   
	  
	     


	
#line 55 "transport_route.cpp"
 char scn [ 256 ] ;
 
#line 56 "transport_route.cpp"
 char ssn [ 256 ] ;
 
#line 57 "transport_route.cpp"
 char sc [ 256 ] ;
 
#line 58 "transport_route.cpp"
 char fcn [ 256 ] ;
 
#line 59 "transport_route.cpp"
 char fsn [ 256 ] ;
 
#line 60 "transport_route.cpp"
 char fc [ 256 ] ;
 
#line 61 "transport_route.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 64 "transport_route.cpp"



	ECPGset_var( 0, &( trn ), __LINE__);\
 /* declare cursor_transport_route_show cursor for select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , number from transport_route where number = $1  order by number */
#line 68 "transport_route.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_transport_route_show cursor for select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , number from transport_route where number = $1  order by number", 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 70 "transport_route.cpp"


	while (true) {
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_transport_route_show", ECPGt_EOIT, 
	ECPGt_char,(scn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ssn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(sc),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fcn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fsn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fc),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 73 "transport_route.cpp"


		if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
		{
			cout << "Не найдено\n";
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
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_transport_route_show", ECPGt_EOIT, ECPGt_EORT);}
#line 91 "transport_route.cpp"

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

	/* exec sql begin declare section */
      
	    
	    
	    
	    
	    
	     
	
#line 130 "transport_route.cpp"
 const char * scn = start_country_name ;
 
#line 131 "transport_route.cpp"
 const char * ssn = start_state_name ;
 
#line 132 "transport_route.cpp"
 const char * sc = start_city ;
 
#line 133 "transport_route.cpp"
 const char * fcn = finish_country_name ;
 
#line 134 "transport_route.cpp"
 const char * fsn = finish_state_name ;
 
#line 135 "transport_route.cpp"
 const char * fc = finish_city ;
 
#line 136 "transport_route.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 137 "transport_route.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from transport_route where start_country_name = $1  and start_state_name = $2  and start_city = $3  and finish_country_name = $4  and finish_state_name = $5  and finish_city = $6  and number = $7 ", 
	ECPGt_char,&(scn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(ssn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sc),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(fcn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(fsn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(fc),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 138 "transport_route.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 139 "transport_route.cpp"

	return;
}
void printTable_transport_route() {
	/* exec sql begin declare section */
	 
   
	  
	 
   
	  
	    


	
#line 144 "transport_route.cpp"
 char scn [ 256 ] ;
 
#line 145 "transport_route.cpp"
 char ssn [ 256 ] ;
 
#line 146 "transport_route.cpp"
 char sc [ 256 ] ;
 
#line 147 "transport_route.cpp"
 char fcn [ 256 ] ;
 
#line 148 "transport_route.cpp"
 char fsn [ 256 ] ;
 
#line 149 "transport_route.cpp"
 char fc [ 256 ] ;
 
#line 150 "transport_route.cpp"
 unsigned long long trn ;
/* exec sql end declare section */
#line 153 "transport_route.cpp"



	/* declare cursor_transport_route cursor for select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , number from transport_route order by number */
#line 157 "transport_route.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_transport_route cursor for select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , number from transport_route order by number", ECPGt_EOIT, ECPGt_EORT);}
#line 159 "transport_route.cpp"


	while (true) {
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_transport_route", ECPGt_EOIT, 
	ECPGt_char,(scn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ssn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(sc),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fcn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fsn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fc),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 162 "transport_route.cpp"


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

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_transport_route", ECPGt_EOIT, ECPGt_EORT);}
#line 179 "transport_route.cpp"

	return;
}
void menu_transport_route(){
	while (true) {
		cout << "Меню управления Транспортных маршрутов:" << endl;
		cout << "1. Создать Транспортный маршрут" << endl;
		cout << "2. Найти Транспортный маршрут по номеру" << endl;
		cout << "3. Удалить Транспортный маршрут" << endl;
		cout << "4. Показать все Транспортные маршруты" << endl;
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
				delete_transport_route();
				break;
			}
			case 4: {
				printTable_transport_route();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
