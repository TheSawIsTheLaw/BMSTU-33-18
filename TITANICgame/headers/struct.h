#ifndef STRUCT_H

#define STRUCT_H

#define MAX_STRING_LEN 256

typedef enum
{
	FALSE,
	TRUE
} bool;

/*
Numeric
PassengerId Unique ID of the passenger
Survived Survived (1) or died (0)
Pclass Passenger's class (1st, 2nd, or 3rd)
Name Passenger's name
Sex Passenger's sex
Age Passenger's age
SibSp Number of siblings/spouses aboard the Titanic
Parch Number of parents/children aboard the Titanic
Ticket Ticket number
Fare Fare paid for ticket
Cabin Cabin number
Embarked Where the passenger got on the ship 
(C - Cherbourg, S - Southampton, Q = Queenstown)
*/
typedef struct
{
	unsigned int passenger_id;	// id пассажира.
	int survived;				  // Признак (1 - выжил / 0 - не выжил).
	int pclass;					  // Класс пассажира (1, 2, 3).
	char name[MAX_STRING_LEN];	// Имя.
	char surname[MAX_STRING_LEN]; // фамилия.
	char status;				  // Mr, Mrs
	char sex;					  // w - Девочка, m - Мальчик.
	float age;					  // Возраст.
	unsigned int siblings_sp;	 // Кол-во братьев или сестер (в сумме) на корабле.
	unsigned int parch;			  // Кол-во детей/родителей на корабле.
	char ticket[MAX_STRING_LEN];  // Билет.
	float fare;
	char cabin[MAX_STRING_LEN];
	char embarked; // Место (C - Cherbourg, S - Southampton, Q = Queenstown)
} passenger;

typedef struct node
{
	struct node *yes;
	struct node *no;
	bool (*decision)(passenger);
} node;

#endif