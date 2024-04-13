#pragma once

#include <string>

#ifndef PROGRAMMING_METHODS_GRADUATE_H
#define PROGRAMMING_METHODS_GRADUATE_H

#endif //PROGRAMMING_METHODS_GRADUATE_H

#define EMPTY "-"

using namespace std;

class Graduate {

public:
    Graduate(string& fio, int& graduateYear, string& workPlace, string& studyPlace);
    Graduate(string& fio, int gradYear);

    void setFio(string fio);
    void setGraduateYear(int graduateYear);
    void setWorkPlace(string workPlace);
    void setStudyPlace(string studyPlace);

    int getGraduationYear() const;
    
    string getFio() const;
    string getWorkPlace() const;
    string getStudyPlace() const;

    operator string() const;

private:
    string fio;
    int graduateYear;
    string workPlace;
    string studyPlace;

};