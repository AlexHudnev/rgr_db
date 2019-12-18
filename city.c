/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "city.cpp"
/* exec sql whenever sqlerror  sqlprint ; */
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
	    
      
	    
      
     

	
#line 30 "city.cpp"
 const char * n = name ;
 
#line 31 "city.cpp"
 const char * ln = leader_name ;
 
#line 32 "city.cpp"
 const char * s = country_name ;
 
#line 33 "city.cpp"
 const char * sn = state_name ;
 
#line 34 "city.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 36 "city.cpp"

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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 37 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 37 "city.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 38 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 38 "city.cpp"

	return;
}

void search_city(){
	cout << "Введите название AE:" << endl;
	string tmpname;
	cin >> tmpname;
	const char* name = tmpname.c_str();

	/* exec sql begin declare section */
	    
	  
	  
	  
	   

	
#line 49 "city.cpp"
 const char * sn = name ;
 
#line 50 "city.cpp"
 char s [ 256 ] ;
 
#line 51 "city.cpp"
 char ln [ 256 ] ;
 
#line 52 "city.cpp"
 char n [ 256 ] ;
 
#line 53 "city.cpp"
 int pd = - 1 ;
/* exec sql end declare section */
#line 55 "city.cpp"



		ECPGset_var( 0, &( sn ), __LINE__);\
 /* declare cursor_city_show cursor for select name , country_name , leader_name , population_density from city where state_name = $1  order by name */
#line 59 "city.cpp"


		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_city_show cursor for select name , country_name , leader_name , population_density from city where state_name = $1  order by name", 
	ECPGt_char,&(sn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 61 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 61 "city.cpp"

    int count = 0;
		while (true) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_city_show", ECPGt_EOIT, 
	ECPGt_char,(n),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 64 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 64 "city.cpp"


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

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_city_show", ECPGt_EOIT, ECPGt_EORT);
#line 81 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 81 "city.cpp"

		return;

}

void search_city_pd(){
	cout << "Введите количество населения:" << endl;
  int population_density; cin >> population_density;

	/* exec sql begin declare section */
	  
	  
	  
	  
	   
	 
	 

	
#line 91 "city.cpp"
 char n [ 256 ] ;
 
#line 92 "city.cpp"
 char s [ 256 ] ;
 
#line 93 "city.cpp"
 char ln [ 256 ] ;
 
#line 94 "city.cpp"
 char sn [ 256 ] ;
 
#line 95 "city.cpp"
 int pd = population_density ;
 
#line 96 "city.cpp"
 int real_pd ;
 
#line 97 "city.cpp"
 int coutry_pd ;
/* exec sql end declare section */
#line 99 "city.cpp"


		// EXEC SQL DECLARE cursor_city_show_pd CURSOR FOR
		// 		WITH tt AS (SELECT name, population_density  FROM country WHERE population_density <=  :pd)
		// 				SELECT  name, country_name, leader_name, state_name, population_density FROM city WHERE country_name NOT IN (Select name from tt);
		ECPGset_var( 1, &( pd ), __LINE__);\
 /* declare cursor_city_show_pd cursor for with tt as ( select name , population_density from country where population_density >= $1  ) select ci . name , ci . country_name , ci . leader_name , ci . state_name , ci . population_density , ty . population_density from city ci join tt ty on ty . name = ci . country_name */
#line 106 "city.cpp"



		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_city_show_pd cursor for with tt as ( select name , population_density from country where population_density >= $1  ) select ci . name , ci . country_name , ci . leader_name , ci . state_name , ci . population_density , ty . population_density from city ci join tt ty on ty . name = ci . country_name", 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 109 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 109 "city.cpp"

    int count = 0;
		while (true) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_city_show_pd", ECPGt_EOIT, 
	ECPGt_char,(n),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(sn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(real_pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(coutry_pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 112 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 112 "city.cpp"


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

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_city_show_pd", ECPGt_EOIT, ECPGt_EORT);
#line 131 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 131 "city.cpp"

		return;

}

void show_city() {
	cout << "Введите название Города:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	/* exec sql begin declare section */
      
	  
    
    
     

	
#line 143 "city.cpp"
 const char * n = name ;
 
#line 144 "city.cpp"
 char s [ 256 ] ;
 
#line 145 "city.cpp"
 char ln [ 256 ] ;
 
#line 146 "city.cpp"
 char sn [ 256 ] ;
 
#line 147 "city.cpp"
 int pd = - 1 ;
/* exec sql end declare section */
#line 149 "city.cpp"



		ECPGset_var( 2, &( n ), __LINE__);\
 /* declare cursor_city_search cursor for select country_name , leader_name , state_name , population_density from city where name = $1  order by name */
#line 153 "city.cpp"


		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_city_search cursor for select country_name , leader_name , state_name , population_density from city where name = $1  order by name", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 155 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 155 "city.cpp"

    int count = 0;
		while (true) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_city_search", ECPGt_EOIT, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(sn),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 158 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 158 "city.cpp"


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

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_city_search", ECPGt_EOIT, ECPGt_EORT);
#line 176 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 176 "city.cpp"

		return;
}


void show_country_with_city() {
	cout << "Введите название Города:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

	/* exec sql begin declare section */
      
	    
    
	   
    
   

	
#line 188 "city.cpp"
 const char * n = name ;
 
#line 189 "city.cpp"
 char nc [ 256 ] ;
 
#line 190 "city.cpp"
 char ln [ 256 ] ;
 
#line 191 "city.cpp"
 char s [ 256 ] ;
 
#line 192 "city.cpp"
 int sq ;
 
#line 193 "city.cpp"
 int pd ;
/* exec sql end declare section */
#line 195 "city.cpp"



		ECPGset_var( 3, &( n ), __LINE__);\
 /* declare cursor_city_country_search cursor for select co . name , co . state_device , co . leader_name , co . square , co . population_density from country co join city ci on co . name = ci . country_name where ci . name = $1  */
#line 199 "city.cpp"


		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_city_country_search cursor for select co . name , co . state_device , co . leader_name , co . square , co . population_density from country co join city ci on co . name = ci . country_name where ci . name = $1 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 201 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 201 "city.cpp"


		cout << "\n Страны в которых есть " << name << "\n";

		int count = 0;
		while (true) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_city_country_search", ECPGt_EOIT, 
	ECPGt_char,(nc),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(s),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ln),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sq),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pd),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 207 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 207 "city.cpp"


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

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_city_country_search", ECPGt_EOIT, ECPGt_EORT);
#line 224 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 224 "city.cpp"

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
      
      
	    
      
     

	
#line 257 "city.cpp"
 const char * n = name ;
 
#line 258 "city.cpp"
 const char * ln = leader_name ;
 
#line 259 "city.cpp"
 const char * s = country_name ;
 
#line 260 "city.cpp"
 const char * sn = state_name ;
 
#line 261 "city.cpp"
 int pd = population_density ;
/* exec sql end declare section */
#line 263 "city.cpp"

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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 264 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 264 "city.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 265 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 265 "city.cpp"

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
	    
	    
      
	
#line 285 "city.cpp"
 const char * n = name ;
 
#line 286 "city.cpp"
 const char * s = country_name ;
 
#line 287 "city.cpp"
 const char * sn = state_name ;
/* exec sql end declare section */
#line 288 "city.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from city where name = $1  and country_name = $2  and state_name = $3 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(s),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sn),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 289 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 289 "city.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 290 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 290 "city.cpp"

	return;
}
void printTable_city() {
	/* exec sql begin declare section */
    
    
     
     
   


	
#line 295 "city.cpp"
 char n [ 256 ] ;
 
#line 296 "city.cpp"
 char ln [ 256 ] ;
 
#line 297 "city.cpp"
 char s [ 256 ] ;
 
#line 298 "city.cpp"
 char sn [ 256 ] ;
 
#line 299 "city.cpp"
 int pd ;
/* exec sql end declare section */
#line 302 "city.cpp"



	/* declare cursor_city cursor for select name , country_name , leader_name , state_name , population_density from city order by name */
#line 306 "city.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_city cursor for select name , country_name , leader_name , state_name , population_density from city order by name", ECPGt_EOIT, ECPGt_EORT);
#line 308 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 308 "city.cpp"


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
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 311 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 311 "city.cpp"


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

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_city", ECPGt_EOIT, ECPGt_EORT);
#line 326 "city.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 326 "city.cpp"

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
