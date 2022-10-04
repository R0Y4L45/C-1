#include <iostream>
#include <Windows.h>

using namespace std;

#include "ECommerce.h"

#include "Notify.h"

using namespace ECommerce;


int main()
{
	short choice;
	int itemsLenght = 0, productCount = 0;


	Admin* admin = new Admin[itemsLenght];
	Product* products = new Product[productCount]
	{
		Product("apple", "fruit", 1.2, 0, 0.2),
		Product("sugar", "sugar", 1.50, 0.40, 0.2)
	};

	DbSet<Admin> admins(admin, itemsLenght);

	while (true)
	{
		cout << "\t\tMenu\n\n1. Sing up as Admin\n2. Sing in as Admin\n3. Sing in as Guest\n\n";
		cout << "Enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string username, password;
			cout << "Enter Username : ";
			cin >> username;
			cout << "Enter Password : ";
			cin >> password;

			Admin a(username, password);
			admins.add(a);
			cout << "\n\nSuccesfully Complete " << endl;

			break;
		}
		case 2:
		{
			string username, password;
			cout << "Enter Username : ";
			cin >> username;
			cout << "Enter Password : ";
			cin >> password;
			try
			{
				if (admins.singIn(username, password))
				{
					cout << "\n\nWELCOME..)" << endl;
					Sleep(1500);
					system("cls");
				}
			}
			catch (const exception& ex)
			{
				cout << ex.what();
			}
			

			break;
		}
		case 3:

			break;
		case 0:

			exit(0);
			break;

		default:
			cout << "Wrong choice..(";
			Sleep(1500);
			system("cls");
			break;
		}
		
		Sleep(1500);
		system("cls");
	}
}
