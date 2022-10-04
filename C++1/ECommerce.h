#pragma once

namespace ECommerce
{
	class Guest
	{

		string fullname, connected_date;

	public:

		Guest(string& fullname, string& connected_date)
		{
			this->fullname = fullname;
			this->connected_date = connected_date;
		}


	};

	class Admin
	{
		int static staticId;

	public:
		int id;
		string password, username;

		Admin() {}

		Admin(string& username, string& password)
		{
			id = staticId;
			this->username = username;
			this->password = password;
		}
	};

	int Admin::staticId = 0;

	class Product
	{
		int static staticId;

	public:

		int id;
		string name, description;
		double price, discount, tax;

		Product()
		{
				
		}

		Product(string name, string description, double price, double discount, double tax)
		{
			id = ++staticId;
			this->name = name;
			this->description = description;
			this->price = price;
			this->discount = discount;
			this->tax = tax;
		}
	};

	int Product::staticId = 0;


	template<typename T>
	class DbSet
	{
		int itemsLength;
		T* items;

	public:

		DbSet(T*& items, int& itemsLength)
		{
			this->itemsLength = itemsLength;
			this->items = items;
		}

		void add(const T item)
		{
			T* temp = new T[itemsLength + 1];

			for (size_t i = 0; i < itemsLength; i++)
				temp[i] = items[i];

			delete[] items;
			temp[itemsLength++] = item;
			items = temp;
		}

		void deleteById(const int& id)
		{
			int c;
			T* temp = new T[itemsLength - 1];

			for (size_t i = 0; i < itemsLength; i++)
				if (items[i].id != id)
					temp[c++] = items[i];

			delete[] items;
			itemsLength--;
			items = temp;
		}

		T* getItem(const int& id)
		{
			for (size_t i = 0; i < itemsLength; i++)
				if (items[i].id == id)
					return items[i];
		}

		bool singIn(const string& username, const string& password)
		{
			bool checker = false, passChecker = false;;
			for (size_t i = 0; i < itemsLength; i++)
			{
				if (items[i].username == username)
				{
					checker = true;
					if (items[i].password == password)
					{
						passChecker = true;
						return true;
					}
				}
			}

			if (!checker && !passChecker)
			{
				throw exception("Wrong username");
			}
			else if (!passChecker)
			{
				throw exception("Wrong password");
			}


		}
	};

	class Database
	{
		DbSet<Product>products;
		DbSet<Admin>admins;
	};



	namespace Client
	{

	}

	void start()
	{

	}
}
