#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.cpp"
#include <string>

int my_atoi(std::string s);

class Phonebook {
	private:
		Contact contacts[8];
		int num_contacts;
	public:
		Phonebook() : num_contacts(0) {};
		std::string askDetail(std::string detail_name) {
			std::string detail;
			if(std::cin.fail() || std::cin.eof())
				throw std::runtime_error("Input stream is closed. \n");
			std::cout << "Enter the Contact's " << detail_name << ": ";
			std::getline(std::cin, detail);

			return detail;
		}
		void enterContact() {
			std::string first_name;
			std::string last_name;
			std::string nick_name;
			std::string phone_number;
			std::string darkest_secret;
			try {
				first_name = this->askDetail("first name");
				last_name = this->askDetail("last name");
				nick_name = this->askDetail("nickname");
				phone_number = this->askDetail("phone number");
				darkest_secret = this->askDetail("darkest secret");
			}
			catch(const std::runtime_error &e) {
				std::cout << e.what();
				return;
			}
			try {
				Contact c(first_name, last_name, nick_name, phone_number, darkest_secret);
				this->insertContact(c);
			}
			catch(const std::invalid_argument &e) {
				std::cout << e.what() << std::endl;
			}
		};
		void insertContact(Contact &c) {
			if(this->num_contacts == 8)
			{
				std::cout << "Phonebook is full. Deleting oldest contact." << std::endl;
				this->deleteOldestContact();
			}
			this->contacts[this->num_contacts] = c;
			this->num_contacts++;
		}
		void deleteOldestContact() {
			for(int i = 0; i < this->num_contacts - 1; i++)
			{
				contacts[i] = contacts[i + 1];
			}
			this->num_contacts--;
		}
		void searchContact() {
			std::string contact_num_str;
			if(this->num_contacts == 0) {
				std::cout << "No contacts to display or search yet. ";
				std::cout << "Add a contact first with ADD. (Or PREFILL)" << std::endl;
				return;
			}
			else {
				this->displayContacts();
			}
			do {
				if(std::cin.fail() || std::cin.eof())
					return;
				std::cout << "Choose a contact's index: ";
				std::getline(std::cin, contact_num_str);
				try {
					int num = my_atoi(contact_num_str);
					this->displayContact(num);
				}
				catch (const std::exception &e) {
					std::cout << e.what() << std::endl;
					std::cout << "Try again" << std::endl;
					continue;
				};
				break;
			} while(1);
		}
		void printTableLine(std::string *strs, int size) {
			for(int i = 0; i < size; i++)
			{
				std::cout.width(10);
				std::cout << std::setiosflags(std::ios_base::right);
				if (strs[i].size() > 10)
					strs[i] = strs[i].substr(0,9) + ".";
				std::cout << strs[i] << "|";
			}
			std::cout << std::endl;
		}
		void displayContacts() {
			std::string strs[4] = {"INDEX","FIRSTNAME","LASTNAME","NICKNAME"};
			this->printTableLine(strs, 4);
			for(int i = 0; i < this->num_contacts; i++)
			{
				Contact c = this->contacts[i];
				std::stringstream ss;
				ss << 8 - i;
				std::string line[4] = {ss.str(), c.getFirstName(), c.getLastName(), c.getNickname()};
				this->printTableLine(line, 4);
			}
		}
		void displayContact(int num) {
			if(num <= 0 || num > this->num_contacts) {
				throw std::out_of_range("Given index is out of range.");
			}
			Contact c = this->contacts[num - 1];
			std::cout << "====================" << std::endl;
			std::cout << "First Name: " << c.getFirstName() << std::endl;
			std::cout << "Last Name: " << c.getLastName() << std::endl;
			std::cout << "Nickname: " << c.getNickname() << std::endl;
			std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
		}
};