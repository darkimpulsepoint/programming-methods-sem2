#include <string>
#include "Graduate.h"


Graduate::Graduate(string& fio, int gradYear) {
    setFio(fio);
    setGraduateYear(gradYear);
}

Graduate::Graduate(string& fio, int& graduateYear, string& workPlace, string& studyPlace) {
    setFio(fio);
    setGraduateYear(graduateYear);
    setWorkPlace(workPlace);
    setStudyPlace(studyPlace);
}

void Graduate::setFio(string newfio) {
    if (newfio.empty()){
        throw "Can't assign empty name!";
    }

    this->fio = newfio;
}

void Graduate::setGraduateYear(int gradYear) {
    if (gradYear < 1900){
        throw "Invalid year!";
    }

    this->graduateYear = gradYear;

}

void Graduate::setWorkPlace(string workPlace) {
    if (workPlace.empty()){
        throw "Can't assign empty work place!";
    }

    this->workPlace = workPlace;
}

void Graduate::setStudyPlace(string studyPlace) {
    if (studyPlace.empty()){
        throw "Can't assign empty study place!";
    }

    this->studyPlace = studyPlace;
}

string Graduate::getFio() const {
    return this->fio;
}

int Graduate::getGraduationYear() const {
    return this->graduateYear;
}

string Graduate::getWorkPlace() const {
    return this->workPlace;
}

string Graduate::getStudyPlace() const {
    return this->studyPlace;
}

Graduate::operator string() const {
    string str = "FIO: " + this->getFio() + "\ngrad. year: " + to_string(this->getGraduationYear()) + "\n";

    if (this->getWorkPlace() == EMPTY){
        str += "study place: " + this->getStudyPlace();
    } else {
        str += "work place: " + this->getWorkPlace();
    }
    str += "\n";

    return str;
}
