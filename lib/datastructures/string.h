#ifndef STRING_H
#define STRING_H

#include <ostream>

namespace ctci {

class string {
    public:
        string();
        string(char* s);
        string(const char* s);
        string(const string& s);

        typedef size_t pos;

        ~string();

        size_t size() const;

        string substr(pos start, pos len);

        friend std::ostream& operator<<(std::ostream&, const string&);
        friend string operator+(const string& s1, const string& s2);
        friend string operator+=(string& s1, const string& s2);
        friend bool operator==(const string& s1, const string& s2);
        friend bool operator!=(const string& s1, const string& s2);
        char& operator[](const unsigned int ind);
        const char& operator[](const unsigned int ind) const;
        string& operator=(const string& other);
        //string& operator=(string&& other);

    private:
        char* buf;
};
}

#endif // STRING_H

