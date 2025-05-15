#include <iostream>
#include "bus.h"

using namespace std;

int main()
{
    list_bus lb;
    list_terminal lt;

    create_list_bus(lb);
    create_list_terminal(lt);

    int input;
    do
    {
        print_main_menu();
        cin >> input;
        if (input == 1)
        {
            process_bus_input(lb);

        }
        else if (input == 2)
        {
            process_terminal_input(lt);

        }
        else if (input == 3)
        {
            process_passenger_input(lb, lt);

        }
        else if (input == 4)
        {
            process_delete_bus(lb);
            system("pause");
        }
        else if (input == 5)
        {
            process_delete_passenger(lb);
            system("pause");
        }
        else if (input == 6)
        {
            process_search_bus(lb);
            system("pause");
        }
        else if (input == 7)
        {
            process_search_terminal(lt);
            system("pause");
        }
        else if (input == 8)
        {
            process_search_passenger(lb);
            system("pause");
        }
        else if (input == 9)
        {
            process_search_passenger_from_bus(lb);
            system("pause");
        }
        else if (input == 10)
        {
            print_all_bus_passenger(lb);
            system("pause");
        }
        else if (input == 11)
        {
            print_all_bus(lb);
            system("pause");
        }
        else if (input == 12)
        {
            print_all_terminal(lt);
            system("pause");
        }
        else if (input == 0)
        {
            cout << "Exiting program" << endl;
        }
        else
        {
            cout << "Unknown input" << endl;
        }

    } while (input != 0);

}

