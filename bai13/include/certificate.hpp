#ifndef _ECERTIFICATE_HPP_
#define _ECERTIFICATE_HPP_
#include <string>

class Certificate {
private:
    int id;
    std::string name;
    std::string rank;
    std::string date;

public:
    Certificate() = default;

    Certificate(const int& id, const std::string& name, const std::string& rank, const std::string& date);

    int getId() const;

    void setId(const int& id);

    std::string getName() const;

    void setName(const std::string& name);

    std::string getRank() const;

    void setRank(const std::string& rank);

    std::string getDate() const;

    void setDate(const std::string& date);
};

#endif //_ECERTIFICATE_HPP_