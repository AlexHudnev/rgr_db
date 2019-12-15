/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "trip.cpp"

void create_trip() {
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

	cout << "Введите вид транспорта:" << endl;
	string tmptransport_type;
	cin >> tmptransport_type;
	const char* transport_type = tmptransport_type.c_str();

	cout << "Введите дату поездки" << endl;
	string tmpdate;
	cin >> tmpdate;
	const char* date = tmpdate.c_str();

	cout << "Введите номер паспорта:" << endl;
	unsigned long long passenger_passport_id; cin >> passenger_passport_id;


	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;




	/* exec sql begin declare section */
	    
      
	    
	    
      
	    
	    
      
	     
	     

	
#line 54 "trip.cpp"
 const char * scn = start_country_name ;
 
#line 55 "trip.cpp"
 const char * ssn = start_state_name ;
 
#line 56 "trip.cpp"
 const char * sc = start_city ;
 
#line 57 "trip.cpp"
 const char * fcn = finish_country_name ;
 
#line 58 "trip.cpp"
 const char * fsn = finish_state_name ;
 
#line 59 "trip.cpp"
 const char * fc = finish_city ;
 
#line 60 "trip.cpp"
 const char * tt = transport_type ;
 
#line 61 "trip.cpp"
 const char * d = date ;
 
#line 62 "trip.cpp"
 unsigned long long pid = passenger_passport_id ;
 
#line 63 "trip.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 65 "trip.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into trip ( start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , transport_type , date , passenger_passport_id , transport_route_number ) values ( $1  , $2  , $3  , $4  , $5  , $6  , $7  , $8  , $9  , $10  )", 
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
	ECPGt_char,&(tt),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(d),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(pid),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 66 "trip.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 67 "trip.cpp"

	return;
}
void show_trip() {
	cout << "Введите дату поездки" << endl;
	string tmpdate;
	cin >> tmpdate;
	const char* date = tmpdate.c_str();

	cout << "Введите номер паспорта:" << endl;
	unsigned long long passenger_passport_id; cin >> passenger_passport_id;


	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;

	/* exec sql begin declare section */
	 
   
	  
	 
   
	  
	  
      
	     
	     

	
#line 84 "trip.cpp"
 char scn [ 256 ] ;
 
#line 85 "trip.cpp"
 char ssn [ 256 ] ;
 
#line 86 "trip.cpp"
 char sc [ 256 ] ;
 
#line 87 "trip.cpp"
 char fcn [ 256 ] ;
 
#line 88 "trip.cpp"
 char fsn [ 256 ] ;
 
#line 89 "trip.cpp"
 char fc [ 256 ] ;
 
#line 90 "trip.cpp"
 char tt [ 256 ] ;
 
#line 91 "trip.cpp"
 const char * d = date ;
 
#line 92 "trip.cpp"
 unsigned long long pid = passenger_passport_id ;
 
#line 93 "trip.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 95 "trip.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , transport_type , date , passenger_passport_id , transport_route_number from trip where passenger_passport_id = $1  and transport_route_number = $2  and date = $3 ", 
	ECPGt_unsigned_long_long,&(pid),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(d),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
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
	ECPGt_char,(tt),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(d),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(pid),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 97 "trip.cpp"



 	cout << endl;
	cout << " Название страны отправления:" << scn << endl;
	cout << " Название AE отправления:" << ssn << endl;
	cout << " Название Города отправления:" << sc << endl;
	cout << " Название страны прибытия:" << fcn << endl;
	cout << " Название AE прибытия:" << fsn << endl;
	cout << " Название Города прибытия:"<< fc << endl;
	cout << " Вид транспорта:" << tt <<endl;
	cout << " Дата поездки" << d <<endl;
	cout << " Номер паспорта:" << pid << endl;
	cout << " Номер маршрута:" << trn <<  endl;
	cout << endl;
	return;
}
void update_trip() {
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

	cout << "Введите вид транспорта:" << endl;
	string tmptransport_type;
	cin >> tmptransport_type;
	const char* transport_type = tmptransport_type.c_str();

	cout << "Введите дату поездки" << endl;
	string tmpdate;
	cin >> tmpdate;
	const char* date = tmpdate.c_str();

	cout << "Введите номер паспорта:" << endl;
	unsigned long long passenger_passport_id; cin >> passenger_passport_id;


	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;



	/* exec sql begin declare section */
	    
	    
	    
	    
	    
	    
	    
	    
	     
	     


	
#line 165 "trip.cpp"
 const char * scn = start_country_name ;
 
#line 166 "trip.cpp"
 const char * ssn = start_state_name ;
 
#line 167 "trip.cpp"
 const char * sc = start_city ;
 
#line 168 "trip.cpp"
 const char * fcn = finish_country_name ;
 
#line 169 "trip.cpp"
 const char * fsn = finish_state_name ;
 
#line 170 "trip.cpp"
 const char * fc = finish_city ;
 
#line 171 "trip.cpp"
 const char * tt = transport_type ;
 
#line 172 "trip.cpp"
 const char * d = date ;
 
#line 173 "trip.cpp"
 unsigned long long pid = passenger_passport_id ;
 
#line 174 "trip.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 177 "trip.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update trip set start_country_name = $1  , start_state_name = $2  , start_city = $3  , finish_country_name = $4  , finish_state_name = $5  , finish_city = $6  , transport_type = $7  , date = $8  , passenger_passport_id = $9  , transport_route_number = $10  where passenger_passport_id = $11  and transport_route_number = $12  and date = $13 ", 
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
	ECPGt_char,&(tt),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(d),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(pid),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(pid),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(d),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 178 "trip.cpp"


	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 180 "trip.cpp"

	return;
}
void delete_trip() {
	cout << "Введите дату поездки" << endl;
	string tmpdate;
	cin >> tmpdate;
	const char* date = tmpdate.c_str();

	cout << "Введите номер паспорта:" << endl;
	unsigned long long passenger_passport_id; cin >> passenger_passport_id;


	cout << "Введите номер маршрута:" << endl;
	unsigned long long transport_route_number; cin >> transport_route_number;

	/* exec sql begin declare section */
	    
	     
	     
	
#line 197 "trip.cpp"
 const char * d = date ;
 
#line 198 "trip.cpp"
 unsigned long long pid = passenger_passport_id ;
 
#line 199 "trip.cpp"
 unsigned long long trn = transport_route_number ;
/* exec sql end declare section */
#line 200 "trip.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from trip where passenger_passport_id = $1  and transport_route_number = $2  and date = $3 ", 
	ECPGt_unsigned_long_long,&(pid),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(d),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 201 "trip.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 202 "trip.cpp"

	return;
}
void printTable_trip() {
	/* exec sql begin declare section */
	 
   
	  
	 
   
	  
	  
    
	    
	    
	
#line 207 "trip.cpp"
 char scn [ 256 ] ;
 
#line 208 "trip.cpp"
 char ssn [ 256 ] ;
 
#line 209 "trip.cpp"
 char sc [ 256 ] ;
 
#line 210 "trip.cpp"
 char fcn [ 256 ] ;
 
#line 211 "trip.cpp"
 char fsn [ 256 ] ;
 
#line 212 "trip.cpp"
 char fc [ 256 ] ;
 
#line 213 "trip.cpp"
 char tt [ 256 ] ;
 
#line 214 "trip.cpp"
 char d [ 256 ] ;
 
#line 215 "trip.cpp"
 unsigned long long pid ;
 
#line 216 "trip.cpp"
 unsigned long long trn ;
/* exec sql end declare section */
#line 217 "trip.cpp"


	/* declare cursor_trip cursor for select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , transport_type , date , passenger_passport_id , transport_route_number from trip order by date */
#line 220 "trip.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_trip cursor for select start_country_name , start_state_name , start_city , finish_country_name , finish_state_name , finish_city , transport_type , date , passenger_passport_id , transport_route_number from trip order by date", ECPGt_EOIT, ECPGt_EORT);}
#line 222 "trip.cpp"


	while (true) {
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_trip", ECPGt_EOIT, 
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
	ECPGt_char,(tt),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(d),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(pid),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_unsigned_long_long,&(trn),(long)1,(long)1,sizeof(unsigned long long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 225 "trip.cpp"


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
		cout << " Вид транспорта:" << tt <<endl;
		cout << " Дата поездки" << d <<endl;
		cout << " Номер паспорта:" << pid << endl;
		cout << " Номер маршрута:" << trn <<  endl;
		cout << endl;
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_trip", ECPGt_EOIT, ECPGt_EORT);}
#line 245 "trip.cpp"

	return;
}
void menu_trip(){
	while (true) {
		cout << "Меню управления Поездки:" << endl;
		cout << "1. Создать Поездку" << endl;
		cout << "2. Найти Поездку" << endl;
		cout << "3. Модифицировать информацию о Поездке" << endl;
		cout << "4. Удалить Поездку" << endl;
		cout << "5. Показать все Поездки" << endl;
		cout << "0. Выйти" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				create_trip();
				break;
			}
			case 2: {
				show_trip();
				break;
			}
			case 3: {
				update_trip();
				break;
			}
			case 4: {
				delete_trip();
				break;
			}
			case 5: {
				printTable_trip();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
