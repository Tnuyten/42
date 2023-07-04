#include <iostream>
#include "Phonebook.cpp"

std::string COMMANDS_AVAILABLE = "Available commands: [SEARCH, ADD, EXIT]";
std::string COMMAND_NOT_RECOGNIZE = "Command not recognized: [";
std::string DONE_MESSAGE = "Done. Hope you had a good time. Now GTFO.";

void prefill(Phonebook &pb);

int main() {
	Phonebook pb;
	std::string command;

	do {
		if(std::cin.eof() || std::cin.fail())
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}

		std::cout << COMMANDS_AVAILABLE << std::endl;
		std::getline(std::cin, command);

		if(command.compare("") == 0)
			continue;
		if(command.compare("ADD") == 0)
			pb.enterContact();
		else if(command.compare("SEARCH") == 0)
			pb.searchContact();
		else if(command.compare("PREFILL") == 0)
			prefill(pb);
		else if(command.compare("EXIT") != 0)
			std::cout << COMMAND_NOT_RECOGNIZE << command << "]" << std::endl;

		std::cout << std::endl;
	} while(command.compare("EXIT") != 0);

	std::cout << DONE_MESSAGE << std::endl;
	return 0;
}

void prefill(Phonebook& pb) {
	Contact a("Tony","Tarnished","TT","1","Maidenless");
	Contact b("Dung","Eater","Dickhead","666","Defiles corpses");
	Contact c("Ranni","The Witch","Waifu","2","Ghost twin");
	Contact d("Blackguard","Big Boggart","Shrimp guy","3","Steals jewelry");
	Contact e("Blaidd","_","Wolf","furaffinity.net","Simps for Ranni");
	Contact f("Rya","_","Quasimodo","4","Snek");
	Contact g("Radagon","Of the Golden Order","Marigon","5","Marika's other half");
	Contact h("Malenia","the Severed","Melania","6","Let Me Solo Her");

	pb.insertContact(a);
	pb.insertContact(b);
	pb.insertContact(c);
	pb.insertContact(d);
	pb.insertContact(e);
	pb.insertContact(f);
	pb.insertContact(g);
	pb.insertContact(h);

	std::cout << "Filled phonebook with 8 premade entries." << std::endl;
}