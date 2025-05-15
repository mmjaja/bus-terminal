#ifndef HEADER_TERMINAL_INCLUDED
#define HEADER_TERMINAL_INCLUDED
#include <iostream>
#include <conio.h>

using namespace std;

struct infotype_bus
{
    string name;
    string id;
    string location;
    int nPassenger;
    int capacity;
};

struct infotype_passenger
{
    string name;
    string id;
    int age;
};

struct infotype_terminal
{
    string name;
    string id;
    string location;
};

typedef struct elm_bus *adr_bus;
typedef struct elm_passenger *adr_passenger;
typedef struct elm_terminal *adr_terminal;

struct elm_bus
{
    infotype_bus info;
    adr_bus next;
    adr_passenger listPassenger;
};

struct elm_passenger
{
    infotype_passenger info;
    adr_passenger next;
    adr_terminal pickup;
    adr_terminal drop;
};

struct elm_terminal
{
    infotype_terminal info;
    adr_terminal next;
};

struct list_bus
{
    adr_bus first;
    adr_bus last;
};

struct list_terminal
{
    adr_terminal first;
    adr_terminal last;
};

//create
void create_list_bus(list_bus &lb);
void create_list_terminal(list_terminal &lo);
adr_bus create_elm_bus(infotype_bus x);
adr_terminal create_elm_terminal(infotype_terminal x);
adr_passenger create_elm_passenger(infotype_passenger x);

//insert
void insert_bus(list_bus &lb, adr_bus x);
void insert_passenger(adr_bus &ab, adr_terminal pickup, adr_terminal drop, adr_passenger x);
void insert_terminal(list_terminal &lo, adr_terminal x);

//delete
void delete_bus(list_bus &lb, adr_bus &p, adr_bus &q);
void delete_passenger_from_bus(adr_bus &ab);
void delete_passenger(adr_passenger &p, adr_passenger &q);
void delete_terminal(adr_terminal &p, adr_terminal &q);

//searching
adr_bus search_bus(list_bus lb, string id, adr_bus &prec);
adr_bus search_bus_location(list_bus lb, string loc);
adr_passenger search_passenger(list_bus lb, string id, adr_passenger &prec, adr_bus &bus);
adr_terminal search_terminal(list_terminal lt, string id);
adr_terminal search_terminal_name(list_terminal lt, string name);
adr_passenger search_passenger_from_bus(list_bus lb, string idpassenger, string idbus);

//printing
void print_all_bus_passenger(list_bus lb);
void print_all_bus(list_bus lb);
void print_bus_passenger(list_bus lp, string id);
void print_all_terminal(list_terminal lt);
void print_main_menu();

//processaaaaargghhh
void process_bus_input(list_bus &lb);
void process_terminal_input(list_terminal &lt);
void process_passenger_input(list_bus &lb, list_terminal lt);
void process_delete_bus(list_bus &lb);
void process_delete_passenger(list_bus &lb);
void process_search_bus(list_bus &lb);
void process_search_terminal(list_terminal &lt);
void process_search_passenger(list_bus &lb);
void process_search_passenger_from_bus(list_bus &lb);


#endif
