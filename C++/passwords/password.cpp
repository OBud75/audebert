#include "password.hpp"

Password::Password(const std::string &password, bool is_encrypted){
	// if is_encrypted == false -> encrypt()
	if (!is_encrypted){
		// check(password) > 6char, 1 maj, 1 char special
		if (!is_valid(password)) {
			printf("Warning: Password it not valid. (not strong enough)\n");
		}
		_raw_value = password;
		encrypt();
	} else { // else {_encrypted_value = password;}
		_encrypted_value = password;
	}
}


bool Password::is_valid(const std::string &password) const {
	// if < 6 chars 
	if (password.length() < 6) {
		return false;
	}

	// if not cap letters
	int start = 'A';
	for (char c : password) {
		for (int j = 0; j < 26; j++) {
			if (c == (start+j) ) {
				return true;
			}
		}
	}
	return false;
}

void Password::encrypt() {
	_encrypted_value = "ENC(" + _raw_value + ")";
}

std::string Password::str() {
  return _encrypted_value;
}

bool Password::operator==(const std::string &str) const {
  return str == _encrypted_value;
}

bool Password::operator==(const Password &other) const {
  return other._encrypted_value == _encrypted_value;
}

std::ostream &operator<<(std::ostream &os, const Password &p) {
  os << p._encrypted_value;
  return os;
}
