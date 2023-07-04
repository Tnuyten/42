#include <string>
#include <stdexcept>

class Contact {
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
	public:
		Contact(){};
		Contact(Contact& c) {
			this->_first_name = c._first_name;
			this->_last_name = c._last_name;
			this->_nickname = c._nickname;
			this->_phone_number = c._phone_number;
			this->_darkest_secret = c._darkest_secret;
		};
		Contact& operator= (const Contact& c) {
			this->_first_name = c._first_name;
			this->_last_name = c._last_name;
			this->_nickname = c._nickname;
			this->_phone_number = c._phone_number;
			this->_darkest_secret = c._darkest_secret;
			return *this;
		};
		Contact(std::string fn, std::string ln, std::string nn,
			std::string pn, std::string ds) {
				std::string EMPTY_FIELD = "Contact fields cannot be empty. ";
				if(fn.size() == 0 || ln.size() == 0 || nn.size() == 0 \
				|| pn.size() == 0 || ds.size() == 0)
					throw std::invalid_argument(EMPTY_FIELD);
				this->_first_name = fn;
				this->_last_name = ln;
				this->_nickname = nn;
				this->_phone_number = pn;
				this->_darkest_secret = ds;
			}
		void setFirstName(std::string name) {
			this->_first_name = name;
		}
		void setLastName(std::string name) {
			this->_last_name = name;
		}
		void setNickname(std::string name) {
			this->_nickname = name;
		}
		void setPhoneNumber(std::string num) {
			this->_phone_number = num;
		}
		void setDarkestSecret(std::string secret) {
			this->_darkest_secret = secret;
		}
		std::string getFirstName() {
			return this->_first_name;
		}
		std::string getLastName() {
			return this->_last_name;
		}
		std::string getNickname() {
			return this->_nickname;
		}
		std::string getPhoneNumber() {
			return this->_phone_number;
		}
		std::string getDarkestSecret() {
			return this->_darkest_secret;
		}
};
