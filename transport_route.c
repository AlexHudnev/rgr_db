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
      
      
	    
	    
      
	    
	     

	
#line 85 "transport_route.cpp"
 const char * scn = start_country_name ;
 
#line 86 "transport_route.cpp"
 const char * ssn = start_state_name ;
 
#line 87 "transport_route.cpp"
 const char * sc = start_city ;
 
#line 88 "transport_route.cpp"
 const char * fcn = finish_country_name ;
 
#line 89 "transport_route.cpp"
 const char * fsn = finish_state_name ;
 
#line 90 "transport_route.cpp"
 const char * fc = finish_city ;
 
#line 91 "transport_route.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 93 "transport_route.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , number from transport_route where start_country_name = $1  and start_state_name = $2  and start_city = $3  and finish_country_name = $4  and finish_state_name = $5  and finish_city = $6  and number = $7 ", 
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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 95 "transport_route.cpp"



 	cout << endl;
	cout << " Название страны отправления:" << scn << endl;
	cout << " Название AE отправления:" << ssn << endl;
	cout << " Название Города отправления:" << sc << endl;
	cout << " Название страны прибытия:" << fcn << endl;
	cout << " Название AE прибытия:" << fsn << endl;
	cout << " Название Города прибытия:"<< fc << endl;
	cout << " Номер маршрута:" << trn <<  endl;
	cout << endl;
	return;
}
void update_transport_route() {
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
	    
	    
	    
	    
	    
	    
	     


	
#line 145 "transport_route.cpp"
 const char * scn = start_country_name ;
 
#line 146 "transport_route.cpp"
 const char * ssn = start_state_name ;
 
#line 147 "transport_route.cpp"
 const char * sc = start_city ;
 
#line 148 "transport_route.cpp"
 const char * fcn = finish_country_name ;
 
#line 149 "transport_route.cpp"
 const char * fsn = finish_state_name ;
 
#line 150 "transport_route.cpp"
 const char * fc = finish_city ;
 
#line 151 "transport_route.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 154 "transport_route.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update transport_route set start_country_name = $1  , start_state_name = $2  , start_city = $3  , finish_country_name = $4  , finish_state_name = $5  , finish_city = $6  , number = $7  where start_country_name = $8  and start_state_name = $9  and start_city = $10  and finish_country_name = $11  and finish_state_name = $12  and finish_city = $13  and number = $14 ", 
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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
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
#line 155 "transport_route.cpp"


	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 157 "transport_route.cpp"

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
      
	    
	    
	    
	    
	    
	     
	
#line 195 "transport_route.cpp"
 const char * scn = start_country_name ;
 
#line 196 "transport_route.cpp"
 const char * ssn = start_state_name ;
 
#line 197 "transport_route.cpp"
 const char * sc = start_city ;
 
#line 198 "transport_route.cpp"
 const char * fcn = finish_country_name ;
 
#line 199 "transport_route.cpp"
 const char * fsn = finish_state_name ;
 
#line 200 "transport_route.cpp"
 const char * fc = finish_city ;
 
#line 201 "transport_route.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 202 "transport_route.cpp"

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
#line 203 "transport_route.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 204 "transport_route.cpp"

	return;
}
void printTable_transport_route() {
	/* exec sql begin declare section */
	 
   
	  
	 
   
	  
	    


	
#line 209 "transport_route.cpp"
 char scn [ 256 ] ;
 
#line 210 "transport_route.cpp"
 char ssn [ 256 ] ;
 
#line 211 "transport_route.cpp"
 char sc [ 256 ] ;
 
#line 212 "transport_route.cpp"
 char fcn [ 256 ] ;
 
#line 213 "transport_route.cpp"
 char fsn [ 256 ] ;
 
#line 214 "transport_route.cpp"
 char fc [ 256 ] ;
 
#line 215 "transport_route.cpp"
 unsigned long long trn ;
/* exec sql end declare section */
#line 218 "transport_route.cpp"



	/* declare cursor_transport_route cursor for select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , number from transport_route order by number */
#line 222 "transport_route.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_transport_route cursor for select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , number from transport_route order by number", ECPGt_EOIT, ECPGt_EORT);}
#line 224 "transport_route.cpp"


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
#line 227 "transport_route.cpp"


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
#line 244 "transport_route.cpp"

	return;
}
void menu_transport_route(){
	while (true) {
		cout << "Меню управления Транспортных маршрутов:" << endl;
		cout << "1. Создать Транспортный маршрут" << endl;
		cout << "2. Найти Транспортный маршрут" << endl;
		cout << "3. Модифицировать информацию о Транспортном маршруте" << endl;
		cout << "4. Удалить Транспортный маршрут" << endl;
		cout << "5. Показать все Транспортные маршруты" << endl;
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
				update_transport_route();
				break;
			}
			case 4: {
				delete_transport_route();
				break;
			}
			case 5: {
				printTable_transport_route();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
