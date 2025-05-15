#include "bus.h"
#include <iostream>

using namespace std;

void create_list_bus(list_bus &lb)
{
    lb.first = NULL;
    lb.last = NULL;
}

void create_list_terminal(list_terminal &lt)
{
    lt.first = NULL;
    lt.last = NULL;
}

adr_bus create_elm_bus(infotype_bus x)
{
    adr_bus p = new elm_bus;
    p->info = x;
    p->next = NULL;
    p->listPassenger = NULL;
    p->info.nPassenger = 0;
    return p;
}

adr_terminal create_elm_terminal(infotype_terminal x)
{
    adr_terminal p = new elm_terminal;
    p->info = x;
    p->next = NULL;
    return p;
}

adr_passenger create_elm_passenger(infotype_passenger x)
{
    adr_passenger p = new elm_passenger;
    p->info = x;
    p->next = NULL;
    p->pickup = NULL;
    p->drop = NULL;
    return p;
}

void insert_bus(list_bus &lb, adr_bus x)
{
    if (lb.first == NULL)
    {
        lb.first = x;
        lb.last = x;
    }
    else
    {
        lb.last->next = x;
        lb.last = x;
    }
}

void insert_passenger(adr_bus &ab, adr_terminal pickup, adr_terminal drop, adr_passenger x)
{
    x->pickup = pickup;
    x->drop = drop;
    if (ab->listPassenger == NULL)
    {
        ab->listPassenger = x;
    }
    else
    {
        adr_passenger q = ab->listPassenger;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = x;
    }
    ab->info.nPassenger++;
}

void insert_terminal(list_terminal &lt, adr_terminal x)
{
    if (lt.first == NULL)
    {
        lt.first = x;
        lt.last = x;
    }
    else
    {
        lt.last->next = x;
        lt.last = x;
    }
}


void delete_bus(list_bus &lb, adr_bus &p, adr_bus &q)
{
    delete_passenger_from_bus(p);
    if (p != NULL)
    {
        if (q == NULL)
        {

            lb.first = p->next;
            if (lb.first == NULL)
            {

                lb.last = NULL;
            }
        }
        else
        {
            q->next = p->next;
            if (q->next ==NULL)
            {

                lb.last = q;
            }
        }
    }
    delete p;
}

void delete_passenger_from_bus(adr_bus &ab)
{
    while (ab->listPassenger != NULL)
    {
        adr_passenger p = ab->listPassenger;
        ab->listPassenger = p->next;
        delete p;
    }
    ab->listPassenger = NULL;
    ab->info.nPassenger = 0;
}

void delete_passenger(adr_passenger &p, adr_passenger &q)
{
    if (q != NULL ){
        q->next = p->next;
    }
    delete p;
} //npassenger dikurangin di prosess


adr_bus search_bus(list_bus lb, string id, adr_bus &prec)
{
    adr_bus p = lb.first;
    prec = NULL;
    while(p != NULL)
    {
        if (p->info.id == id)
        {
            return p;
        }
        prec = p;
        p= p->next;
    }
    prec = NULL;
    return NULL;
}

adr_bus search_bus_location(list_bus lb, string loc)
{
    adr_bus p = lb.first;
    while(p != NULL)
    {
        if (p->info.location == loc && p->info.capacity >= p->info.nPassenger)
        {
            return p;
        }
        p= p->next;
    }
    return NULL;
}

adr_passenger search_passenger(list_bus lb, string id, adr_passenger &prec, adr_bus &bus)
{
    adr_bus p = lb.first;
    prec = NULL;
    while (p != NULL)
    {
        adr_passenger q = p->listPassenger;
        while (q != NULL)
        {
            if (q->info.id == id)
            {
                bus = p;
                return q;
            }
            prec = q;
            q = q->next;
        }
        p = p->next;
    }
    bus = NULL;
    prec = NULL;
    return NULL;
}

adr_terminal search_terminal(list_terminal lt, string id)
{
    adr_terminal p = lt.first;

    while(p != NULL)
    {
        if (p->info.id == id)
        {
            return p;
        }

        p= p->next;
    }

    return NULL;
}

adr_terminal search_terminal_name(list_terminal lt, string name)
{
    adr_terminal p = lt.first;
    while(p)
    {
        if (p->info.name == name)
        {
            return p;
        }
        p= p->next;
    }
    return NULL;
}

adr_passenger search_passenger_from_bus(list_bus lb, string idpassenger, string idbus)
{
    adr_bus prec = NULL;
    adr_bus p = search_bus(lb, idbus, prec);
    if (p == NULL)
    {
        cout << "No such bus ID listed" << endl;
        return NULL;
    }

    adr_passenger q = p->listPassenger;
    while (q != NULL)
    {
        if (q->info.id == idpassenger)
        {
            return q;
        }
        q = q->next;
    }

    cout << "No such passenger ID listed" << endl;
    return NULL;
}

void print_all_bus_passenger(list_bus lb)
{
    adr_bus p = lb.first;

    cout << "-------------------------------------" << endl;
    cout << "List of All Buses and Passengers:" << endl;

    while (p != NULL)
    {
        cout << p->info.name << ":" << endl;

        adr_passenger q = p->listPassenger;
        while (q != NULL)
        {
            cout << "   - " << q->info.name << endl;
            q = q->next;
        }

        p = p->next;
    }

    cout << "-------------------------------------" << endl;
}


void print_all_bus(list_bus lb)
{
    adr_bus p = lb.first;
    int count = 1;

    cout << "-------------------------------------" << endl;
    cout << "List of All Buses:" << endl;

    while (p != NULL)
    {
        cout << count << ". " << "Bus Name: " << p->info.name << endl;
        cout << "   Bus ID: " << p->info.id << endl;
        cout << "   Location: " << p->info.location << endl;
        cout << "   Number of Passengers: " << p->info.nPassenger << " / Capacity: " << p->info.capacity << endl;
        cout << "-------------------------------------" << endl;
        count++;
        p = p->next;
    }
}

void print_bus_passenger(adr_bus ab)
{
    cout << "Bus Name: " << ab->info.name << " (Bus ID: " << ab->info.id << ")" << endl;

    adr_passenger q = ab->listPassenger;

    if (q == NULL)
    {
        cout << "No passengers registered for this bus." << endl;
    }
    else
    {
        cout << "Passengers on board:" << endl;
        while ( q!= NULL)
        {
            cout << "     Passenger ID: " << q->info.id << endl;
            cout << "     Name: " << q->info.name << endl;
            cout << "     Age: " << q->info.age << endl;
            cout << "     Pickup Terminal: " << q->pickup->info.name << endl;
            cout << "     Drop Terminal: " << q->drop->info.name << endl;
            cout << "-------------------------" << endl;
            q = q->next;
        }
    }
}


void print_all_terminal(list_terminal lt)
{
    adr_terminal p = lt.first;
    int count = 1;

    cout << "-------------------------------------" << endl;
    cout << "List of All Terminals:" << endl;

    while (p != NULL)
    {
        cout << count << ". " << "Terminal Name: " << p->info.name << endl;
        cout << "   Terminal ID: " << p->info.id << endl;
        cout << "   Location: " << p->info.location << endl;
        cout << "-------------------------------------" << endl;
        count++;
        p = p->next;
    }
}


void print_main_menu()
{
    cout << "---------------- MENU ---------------" << endl;
    cout << "1. Insert bus" << endl;
    cout << "2. Insert terminal" << endl;
    cout << "3. Register passenger" << endl;
    cout << "4. Delete bus" << endl;
    cout << "5. Delete passenger" << endl;
    cout << "6. Search bus" << endl;
    cout << "7. Search terminal" << endl;
    cout << "8. Search passenger" << endl;
    cout << "9. Search passenger from bus" << endl;
    cout << "10. Print all bus data" << endl;
    cout << "11. Print all bus" << endl;
    cout << "12. Print all terminal" << endl;
    cout << "0. Exit" << endl;
    cout << "-------------------------------------" << endl;
    cout << "input : ";
}

void process_bus_input(list_bus &lb)
{
    infotype_bus busInfo;

    cout << "Enter bus name: ";
    cin >> busInfo.name;

    cout << "Enter bus ID: ";
    cin >> busInfo.id;

    cout << "Enter bus capacity: ";
    cin >> busInfo.capacity;

    cout << "Enter bus operating location: ";
    cin >> busInfo.location;

    adr_bus prec = NULL;
    adr_bus check = search_bus(lb, busInfo.id,prec);

    if (check != NULL)
    {
        cout << "Existing ID found, cancel input" << endl;
        return;
    }

    adr_bus newBus = create_elm_bus(busInfo);

    insert_bus(lb, newBus);

    cout << "Bus added to the list." << endl;
}

void process_terminal_input(list_terminal &lt)
{
    infotype_terminal terminalInfo;

    cout << "Enter terminal name: ";
    cin >> terminalInfo.name;

    cout << "Enter terminal ID: ";
    cin >> terminalInfo.id;

    cout << "Enter terminal location: ";
    cin >> terminalInfo.location;

    adr_terminal check = search_terminal(lt, terminalInfo.id);

    if (check != NULL)
    {
        cout << "Existing ID found, cancel input" << endl;
        return;
    }

    adr_terminal newTerminal = create_elm_terminal(terminalInfo);

    insert_terminal(lt, newTerminal);

    cout << "Terminal added to the list." << endl;
}

void process_passenger_input(list_bus &lb, list_terminal lt)
{
    infotype_passenger passengerInfo;
    string pickup, drop;

    cout << "Enter passenger name: ";
    cin >> passengerInfo.name;

    cout << "Enter passenger ID: ";
    cin >> passengerInfo.id;

    cout << "Enter passenger age: ";
    cin >> passengerInfo.age;

    adr_passenger prec = NULL;
    adr_bus bus = NULL;
    adr_passenger check = search_passenger(lb, passengerInfo.id,prec, bus);

    if (check != NULL)
    {
        cout << "Existing ID found, cancel input" << endl;
        return;
    }

    cout << "Enter pickup terminal: ";
    cin >> pickup;

    cout << "Enter drop terminal: ";
    cin >> drop;

    adr_terminal from = search_terminal_name(lt, pickup);
    adr_terminal to = search_terminal_name(lt, drop);

    if (from == NULL || to == NULL )
    {
        cout << "No terminal with such name" << endl;
        return;
    }
    else if (from->info.location != to->info.location)
    {
        cout << "The 2 terminal are from different operating locations" << endl;
        return;
    }

    bus = search_bus_location(lb, from->info.location);
    if (bus == NULL)
    {
        cout << "No bus available" << endl;
        return;
    }

    adr_passenger newPassenger = create_elm_passenger(passengerInfo);
    insert_passenger(bus, from, to, newPassenger);

    cout << "Passenger added to " << bus->info.name << endl;
}

void process_delete_bus(list_bus &lb)
{
    string busIdToDelete;
    cout << "Enter the ID of the bus to delete: ";
    cin >> busIdToDelete;

    adr_bus prec = NULL;
    adr_bus busToDelete = search_bus(lb, busIdToDelete, prec);

    if (busToDelete != NULL)
    {

        delete_bus(lb, busToDelete, prec);
        cout << "Bus with ID " << busIdToDelete << " has been deleted.\n";
    }
    else
    {
        cout << "Bus with ID " << busIdToDelete << " not found.\n";
    }
}


void process_delete_passenger(list_bus &lb)
{
    string passengerIdToDelete;
    cout << "Enter the ID of the passenger to delete: ";
    cin >> passengerIdToDelete;

    adr_passenger prec = NULL;
    adr_bus bus = NULL;
    adr_passenger passengerToDelete = search_passenger(lb, passengerIdToDelete, prec, bus);

    if (passengerToDelete != NULL)
    {
        if (prec == NULL && passengerToDelete->next == NULL)
        {
            bus->listPassenger = NULL;
        }
        else if (passengerToDelete == bus->listPassenger)
        {
            bus->listPassenger = bus->listPassenger->next;
        }
        bus->info.nPassenger--;
        delete_passenger(passengerToDelete, prec);
        cout << "Passenger with ID " << passengerIdToDelete << " has been deleted.\n";
    }
    else
    {
        cout << "Passenger with ID " << passengerIdToDelete << " not found.\n";
    }
}


void process_search_bus(list_bus &lb)
{
    if (lb.first == NULL)
    {
        cout << "Bus list is empty. No buses to search." << endl;
        return;
    }

    string busId;
    cout << "Enter the ID of the bus to search: ";
    cin >> busId;


    adr_bus prec = NULL;
    adr_bus bus = search_bus(lb, busId, prec);

    if(bus == NULL)
    {
        cout << "Bus not found" << endl;
        return;
    }

    print_bus_passenger(bus);

}

void process_search_terminal(list_terminal &lt)
{
    if (lt.first == NULL)
    {
        cout << "Terminal list is empty. No terminals to search." << endl;
        return;
    }

    string terminalId;
    cout << "Enter the ID of the terminal to search: ";
    cin >> terminalId;

    adr_terminal foundTerminal = search_terminal(lt, terminalId);

    if (foundTerminal != NULL)
    {
        cout << "Terminal found:" << endl;
        cout << "Name: " << foundTerminal->info.name << endl;
        cout << "ID: " << foundTerminal->info.id << endl;
        cout << "Location: " << foundTerminal->info.location << endl;
    }
    else
    {
        cout << "Terminal with ID " << terminalId << " not found." << endl;
    }
}

void process_search_passenger(list_bus &lb)
{
    if (lb.first == NULL)
    {
        cout << "Bus list is empty. No passengers to search." << endl;
        return;
    }

    string passengerId;
    cout << "Enter the ID of the passenger to search: ";
    cin >> passengerId;

    adr_bus currBus;
    adr_passenger prec = NULL;
    adr_passenger foundPassenger = search_passenger(lb, passengerId, prec, currBus);

    if (foundPassenger != NULL)
    {
        cout << "Passenger found:" << endl;
        cout << "Name: " << foundPassenger->info.name << endl;
        cout << "ID: " << foundPassenger->info.id << endl;
        cout << "Age: " << foundPassenger->info.age << endl;
        cout << "Bus: " << currBus->info.name << endl;
    }
    else
    {
        cout << "Passenger with ID " << passengerId << " not found." << endl;
    }
}

void process_search_passenger_from_bus(list_bus &lb)
{
    if (lb.first == NULL)
    {
        cout << "Bus list is empty. No buses to search." << endl;
        return;
    }

    string busId, passengerId;
    cout << "Enter the ID of the bus to search from: ";
    cin >> busId;
    cout << "Enter the ID of the passenger to search: ";
    cin >> passengerId;

    adr_passenger foundPassenger = search_passenger_from_bus(lb, passengerId, busId);

    if (foundPassenger != NULL)
    {
        cout << "Passenger found:" << endl;
        cout << "Name: " << foundPassenger->info.name << endl;
        cout << "ID: " << foundPassenger->info.id << endl;
        cout << "Age: " << foundPassenger->info.age << endl;
        cout << "Pickup Terminal: " << foundPassenger->pickup->info.name << endl;
        cout << "Drop Terminal: " << foundPassenger->drop->info.name << endl;
    }
    else
    {
        cout << "Passenger with ID " << passengerId << " not found on bus with ID " << busId << "." << endl;
    }
}

