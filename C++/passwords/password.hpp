#include <string>
#include <iostream>

class Password {
  private:
    std::string _raw_value;
    std::string _encrypted_value;
    void encrypt();
    bool is_valid(const std::string &password) const;

  public:
    Password(const std::string &password, bool is_encrypted = false);
    //Password(std::string &password, bool is_encrypted=false);
    std::string str();

    bool operator==(const std::string &str) const;
    bool operator==(const Password &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Password &p);
};
