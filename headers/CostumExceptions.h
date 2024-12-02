//
// Created by mihne on 12/2/2024.
//

#ifndef COSTUMEXCEPTIONS_H
#define COSTUMEXCEPTIONS_H
#include <exception>
#include <iostream>
class AbilityAlreadyThere : public std::exception {

private:
    int currlevel;
    std::string msg;
public:
    AbilityAlreadyThere(int level);
    [[nodiscard]] const char* what() const noexcept override;
};

class AbilityMaxLevelExceeded : public std::exception {
private:
    int currlevel;
    std::string msg;
public:
    AbilityMaxLevelExceeded(int level);
    [[nodiscard]] const char* what() const noexcept override;
};

class OutOfBounds : public std::exception {

public:
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //COSTUMEXCEPTIONS_H
