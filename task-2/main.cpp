#include <iostream>
#include <vector>
#include <map>
#include "Graduate.h"

using namespace std;

Graduate randGraduate();

int randYear(int min, int max);
int currYear();

vector<string> mostPopStudyPlace(vector<Graduate>&);
vector<string> mostPopWorkPlace(vector<Graduate>&);
vector<string> keyMaxValues(map<string, int>, int);

string randFio();
inline string randEl(string* arr, int len);


int main(){
    setlocale(0, "");
    int minlen = 15;
    int diap = 10;

    srand(time(NULL));
    vector<Graduate> grs = vector<Graduate>();

    for (size_t i=0; i< rand()%minlen+diap; i++) {
        grs.push_back(randGraduate());
    }

    for (auto gr : grs){
        cout << (string)gr << endl;
    }

    cout << "most pop work places: " << endl;
    for (const auto& el : mostPopWorkPlace(grs)){
        cout << el << endl;
    }
    cout << endl;

    cout << "most pop study places: " << endl;
    for (const auto& el : mostPopStudyPlace(grs)){
        cout << el << endl;
    }
    cout << endl;
}

string names[] = {"Константин", "Валерьян", "Абоба", "Михаил", "Алексей", "Артем", "Виктор", "Дмитрий", "Всеслав", "Добрыня", "Кшиштоф", "Эдвард"};
string patronymics[] = {"Александрович", "Абобович", "Петрович", "Алексеич", "Артемович", "Викторович", "Дмитриевич", "Всеславович", "Добрынич"};
string surnames[] = {"Иванов", "Михаилов", "Алексеев", "Петров", "Суровый", "Бобров", "Батонов", "Гвоздев"};
string studyPlaces[] = {"Школа 1", "Школа 2", "Школа 3", "Школа 4", "Гимназия 1", "Гимназия 2", "Гимназия 3", "Гимназия 4"};
string workPlaces[] = {"Ерат", "Атлант", "Интеграл", "МАЗ", "БелАЗ", "БГУИР", "БГУ", "БНТУ"};


Graduate randGraduate(){

    int year = randYear(2000, 2026);

    string fio = randFio();

    Graduate gr = Graduate(fio, year);
    cout << currYear() << endl;

    if (abs(currYear()-year) > 4){
        gr.setWorkPlace(randEl(workPlaces, sizeof(workPlaces)/sizeof(workPlaces[0])));
        gr.setStudyPlace(EMPTY);
    } else {
        gr.setStudyPlace(randEl(studyPlaces, sizeof(studyPlaces)/sizeof(studyPlaces[0])));
        gr.setWorkPlace(EMPTY);
    }
    return gr;
}

string randFio(){
    return randEl(surnames, sizeof(surnames)/sizeof(surnames[0]))
            + " "
            + randEl(names, sizeof(names)/sizeof(names[0]))
            + " "
            + randEl(patronymics, sizeof(patronymics)/sizeof(patronymics[0]));
}

int randYear(int min, int max){
    if (min < 0 || max < 0){
        throw "Invalid min or max!";
    }

    if (min >= max){
        throw "Max year must be > min!";
    }

    return rand()%(max-min+1)+min;
}

int currYear() {
    time_t now = time(0);

    tm *ltm = localtime(&now);

    return ltm->tm_year+1900;
}

inline string randEl(string* arr, int len){
    return arr[rand()%len];
}

void sortByKey(vector<pair<string, int>>& v){
    for (size_t i=0; i< v.size(); i++){
        for (size_t j=i; j< v.size(); j++){
            if(v[i].second > v[j].second){
                swap(v[i], v[j]);
            }
        }
    }
}

vector<string> keyMaxValues(map<string, int> m, int size){
    int maxRepeats = 0;
    vector<string> places = vector<string>();

    vector<pair<string, int>> pls = vector<pair<string, int>>();

    for (auto& el : m){
        pls.push_back(el);
        }

    sortByKey(pls);

    for(int i=0; i<size; i++){
        if(pls.size()-i>0){
            places.push_back(pls.at(pls.size()-1-i).first);
        } else break;
    }

    return places;
}

vector<string> mostPopStudyPlace(vector<Graduate>& grs){
    map<string, int> placecount = map<string, int>();

    for (const auto& gr : grs){
        string place = gr.getStudyPlace();
        if (place == EMPTY) continue;

        if(!placecount.count(place)){
            placecount[place] = 1;
        } else {
            placecount[place] += 1;
        }
    }

    return keyMaxValues(placecount, 3);
}

vector<string> mostPopWorkPlace(vector<Graduate>& grs){
    map<string, int> placecount = map<string, int>();
    for (const auto& gr : grs){
        string place = gr.getWorkPlace();
        if (place == EMPTY) continue;

        if(!placecount.count(place)){
            placecount[place] = 1;
        } else {
            placecount[place] += 1;
        }
    }


    return keyMaxValues(placecount, 3);
}
