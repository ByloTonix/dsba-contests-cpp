/*! \file       solution.h
 *  \author     Pavlov Arkady
 *  \version    0.1
 *  \date       20.06.2024
 *
 *  Final Exam. Solution module. Put ALL the declarations and definitions right here.
 *  All the class methods must be defined here (do not put their in a separated
 *  file). If you need to create a non-member auxilliary function, put its defintion
 *  here as well.
 *
 *                                     → Press F ←
 *
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

class Teacher {
public:
    Teacher(const std::string& name)
    : _name(name){}
    virtual ~Teacher() {}
    const std::string& getName() const { return _name; }
    virtual double calcWages() const = 0;
    virtual Teacher* cloneMe() const = 0;
protected:
    std::string _name;
};

class AssociateTeacher : public Teacher {
public:
    static const int BASE_SALARY = 1500;
    AssociateTeacher(const std::string& name, int bonus): Teacher(name), _bonus(bonus) {}

    int getBonus(){
        return _bonus;
    }

    double calcWages() const override {
        return BASE_SALARY + _bonus;
    }

    Teacher* cloneMe() const override {
        return new AssociateTeacher(*this);
    };

private:
    int _bonus;
};

class InvitedTeacher : public Teacher {
public:
    static const int GROUP_TAX = 2000;
    InvitedTeacher(const std::string& name, int stuGroups): Teacher(name), _stuGroups(stuGroups) {}

    int getStuGroups(){
        return _stuGroups;
    }

    double calcWages() const override {
        return GROUP_TAX * _stuGroups;
    }

    Teacher* cloneMe() const override {
        return new InvitedTeacher(*this);
    };
    
private:
    int _stuGroups;
};

class TArray {
public:
    TArray() = default;
    TArray(const TArray& other) { copier(other); }

    TArray& operator=(const TArray& other) {
        if (this != &other) {
            destructor();
            copier(other);
        }
        return *this;
    }
    ~TArray() { destructor(); }

    size_t getSize() const { return _arr.size(); }
        
    AssociateTeacher* addAssociateTeacher(const std::string& name, int bonus) {
        AssociateTeacher* uselessTeacher = new AssociateTeacher(name, bonus);
        _arr.push_back(uselessTeacher);
        return uselessTeacher;
    }
    InvitedTeacher* addInvitedTeacher(const std::string& name, int bonus) {
        InvitedTeacher* uselessTeacher = new InvitedTeacher(name, bonus);
        _arr.push_back(uselessTeacher);
        return uselessTeacher;
    }
    Teacher* operator[](size_t index) const {
        if (index > _arr.size()-1)
            throw std::out_of_range("Absolutely useless text");
        else
            return _arr[index];
    }

protected:
    std::vector<Teacher*> _arr;
private:
    void copier(const TArray& other) {
        for (Teacher* teacher : other._arr)
            _arr.push_back(teacher->cloneMe());
    }
    
    void destructor() {
        for (Teacher* teacher: _arr)
            delete teacher;
        _arr.clear();
    }
};

std::ostream& operator << (std::ostream& os, const TArray& tArr) {
    for (size_t i = 0; i < tArr.getSize(); i++) {
        os << tArr[i]->getName() << "," << tArr[i]->calcWages() << std::endl;
    }
    return os;
}

std::pair<int,int> totalWagesOfTopTeachers(const TArray& tArr, int minGroups, int minBonus) {
    size_t totalInvited = 0, totalAssociate = 0;

    for (size_t i = 0; i < tArr.getSize(); i++) {
        Teacher* uselessTeacher = tArr[i];
        
        if (InvitedTeacher* invited = dynamic_cast<InvitedTeacher*>(uselessTeacher)) {
            if (invited->getStuGroups() >= minGroups)
                totalInvited += invited->calcWages();
        }
        else if (AssociateTeacher* associate = dynamic_cast<AssociateTeacher*>(uselessTeacher)) {
            if (associate->getBonus() >= minBonus)
                totalAssociate += associate->calcWages();
        }
    }

    return std::make_pair(totalInvited, totalAssociate);
}
#endif
