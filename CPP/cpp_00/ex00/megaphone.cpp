#include <iostream>

class Megaphone {
	private:
		std::string line;
	public:
		Megaphone(std::string line) {
			this->addToLine(line);
		};
		void addToLine(std::string line) {
			for(size_t i = 0; i < line.size(); i++)
				this->line += std::toupper(line[i]);
		};
		void shoutLine() {
			std::cout << this->line << std::endl;
		};
};

// void run() {
// 	system("leaks megaphone");
// }

int main(int argc, char **argv) {
	// atexit(run);
	Megaphone *m1;

	if(argc == 0)
		return -1;
	if(argc == 1)
		m1 = new Megaphone("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	else
		m1 = new Megaphone(argv[1]);
		for(int i = 2; i < argc; i++)
			m1->addToLine(argv[i]);
	m1->shoutLine();
	delete m1;
	return 0;
}
