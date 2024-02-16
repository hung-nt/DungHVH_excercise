#include"certificate.hpp"


Certificate::Certificate(const int& id, const std::string& name, const std::string& rank, const std::string& date)
    : id(id), name(name), rank(rank), date(date) {}

int Certificate::getId() const {
    return id;
}

void Certificate::setId(const int& id) {
    this->id = id;
}

std::string Certificate::getName() const {
    return name;
}

void Certificate::setName(const std::string& name) {
    this->name = name;
}

std::string Certificate::getRank() const {
    return rank;
}

void Certificate::setRank(const std::string& rank) {
    this->rank = rank;
}

std::string Certificate::getDate() const {
    return date;
}

void Certificate::setDate(const std::string& date) {
    this->date = date;
}
