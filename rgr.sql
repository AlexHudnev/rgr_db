CREATE DOMAIN name_type char(40) NOT NULL;
CREATE DOMAIN square_type real NOT NULL;
CREATE DOMAIN year_type integer NOT NULL;
CREATE DOMAIN state_device_type char(20) NOT NULL;
CREATE DOMAIN score_type char(5) NOT NULL;
CREATE DOMAIN density_type bigint NOT NULL;

CREATE TABLE country(
name name_type,
state_device state_device_type,
leader_name name_type,
square square_type,
population_density density_type,
PRIMARY KEY(name)

);

CREATE TABLE state (
name name_type,
country_name name_type,
leader_name name_type,
square square_type,
population_density density_type,
foreign key (country_name) references country (name),
PRIMARY KEY(name, country_name)
);

CREATE TABLE city (
name name_type,
country_name name_type,
state_name name_type,
leader_name name_type,
population_density density_type,
foreign key (country_name, state_name) references state (country_name, name),
PRIMARY KEY(name, country_name, state_name)
);

CREATE TABLE transport_route (
number integer,
start_city name_type,
start_country_name name_type,
start_state_name name_type,
finish_city name_type,
finish_country_name name_type,
finish_state_name name_type,
foreign key (start_city, start_country_name, start_state_name ) references city (name, country_name, state_name),
foreign key (finish_city, finish_country_name, finish_state_name ) references city (name, country_name, state_name),

PRIMARY KEY(number, start_city, start_country_name, start_state_name , finish_city, finish_country_name, finish_state_name )
);

CREATE TABLE passenger (
passport_id bigint,
name name_type,
PRIMARY KEY(passport_id)
);

CREATE TABLE trip (
date date,
transport_type name_type,
passenger_passport_id bigint,
transport_route_number integer,
start_city name_type,
start_country_name name_type,
start_state_name name_type,
finish_city name_type,
finish_country_name name_type,
finish_state_name name_type,
foreign key (transport_route_number, start_city, start_country_name, start_state_name, finish_city, finish_country_name, finish_state_name) references transport_route (number, start_city, start_country_name, start_state_name, finish_city, finish_country_name, finish_state_name),
foreign key (passenger_passport_id) references passenger (passport_id),
PRIMARY KEY(passenger_passport_id, transport_route_number, date )
);


insert into country(name ,state_device,leader_name ,square ,population_density)
values('Russsia', 'Монархия', 'Иван Грозный', 1234,1234);


insert into country(name ,state_device,leader_name ,square ,population_density)
values('Индия', 'Монархия', 'Иван Иванов', 4314,31234);


insert into country(name ,state_device,leader_name ,square ,population_density)
values('Голандия', 'Монархия', 'Антон Грозный',412234,15);


insert into state(name ,country_name,leader_name ,square ,population_density)
values('Забайкальский', 'Russsia', ' Грозный', 123434,126434);


insert into state(name ,country_name,leader_name ,square ,population_density)
values('Тверская_область', 'Russsia', 'Иван G Грозный', 121234,26434);

insert into state(name ,country_name,leader_name ,square ,population_density)
values('ghgh', 'Голандия', 'ИванGГрозный', 121234,10);

insert into city(name ,country_name,state_name, leader_name, population_density )
values('Тверь', 'Голандия','ghgh', 'Иван', 1244);

insert into city(name ,country_name,state_name, leader_name, population_density )
values('Тверь', 'Russsia','Тверская_область', 'Иван', 1244);


insert into city(name ,country_name,state_name, leader_name, population_density )
values('Торжок', 'Russsia','Тверская_область', 'ХЗ', 214);


insert into city(name ,country_name,state_name, leader_name, population_density )
values('Ржев', 'Russsia','Тверская_область', 'ХЗз', 14);


insert into city(name ,country_name,state_name, leader_name, population_density )
values('хз1', 'Russsia','Забайкальский', 'Иван', 315);


insert into city(name ,country_name,state_name, leader_name, population_density )
values('хз2', 'Russsia','Забайкальский', 'ХЗ', 341);

insert into state(name ,country_name,leader_name ,square ,population_density)
values('HOOO', 'Russsia', 'Иван G Грозный', 1214,234);

insert into city(name ,country_name,state_name, leader_name, population_density )
values('Hoo', 'Russsia','HOOO', 'ХЗ', 341);


insert into city(name ,country_name,state_name, leader_name, population_density )
values('хз3', 'Russsia','Забайкальский', 'ХЗз', 3451);


insert into transport_route(number,start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values(1,'хз3', 'Russsia','Забайкальский','хз2', 'Russsia','Забайкальский');

insert into transport_route(number,start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values(2,'хз3', 'Russsia','Забайкальский','Торжок', 'Russsia','Тверская_область');

insert into transport_route(number,start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values(3,'Торжок', 'Russsia','Тверская_область','Тверь', 'Russsia','Тверская_область');


insert into transport_route(number,start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values(4,'хз3', 'Russsia','Забайкальский','хз2', 'Russsia','Забайкальский');

insert into transport_route(number,start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values(5,'хз3', 'Russsia','Забайкальский','Торжок', 'Russsia','Тверская_область');

insert into transport_route(number,start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values(6,'Тверь', 'Голандия','ghgh','Торжок', 'Russsia','Тверская_область');

insert into trip(date, transport_type, passenger_passport_id, transport_route_number, start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values('2019-01-01','bus',1, 3,'Торжок', 'Russsia','Тверская_область','Тверь', 'Russsia','Тверская_область');

insert into trip(date, transport_type, passenger_passport_id, transport_route_number, start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values('2019-01-02', 'bus', 2, 4, 'хз3', 'Russsia','Забайкальский','хз2', 'Russsia','Забайкальский');

insert into trip(date, transport_type, passenger_passport_id, transport_route_number, start_city,start_country_name ,start_state_name,finish_city,finish_country_name,finish_state_name)
values('2019-01-02', 'bus', 3, 6, 'Тверь', 'Голандия','ghgh','Торжок', 'Russsia','Тверская_область');

insert into passenger(passport_id, name )
values(1, 'Ivanow');

insert into passenger(passport_id, name )
values(2, 'Petrov');

insert into passenger(passport_id, name )
values(3, 'Sidorov');
