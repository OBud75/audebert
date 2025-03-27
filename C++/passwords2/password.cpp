#include "password.hpp"

Password::Password(const std::string &password, bool is_encrypted) {
    if (!is_encrypted) {
        if (!is_valid(password)) {
            // on aura tendance à mettre le message d'erreur dans la fonction is_valid pour le garder à côté de la règle
		std::cout << "Password must be at least 6 characters long, contain one uppercase letter, and one special character." << std::endl;
        }
        // Si le mot de passe n'est pas valide ici vous appelez quand même la fonction encrypt.
        // On peut return ou throw une exception throw std::invalid_argument("Invalid password");
        raw_value = password;
        encrypt();
    } else {
        encrypted_value = password;
    }
}

bool Password::is_valid(const std::string &password) const {
    if (password.length() < 6) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[A-Z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[!@#$%^&*(),.?\":{}|<>]"))) {
        return false;
    }
    return true;
}

void Password::encrypt() {
    // Simple encryption logic for demonstration purposes
    encrypted_value = "ENC(" + raw_value + ")";
}

std::string Password::str() const {
    return encrypted_value;
}

bool Password::operator==(const std::string &str) const {
    return str == encrypted_value;
}

bool Password::operator==(const Password &other) const {
    return encrypted_value == other.encrypted_value;
}

std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p.encrypted_value;
    return os;
}

