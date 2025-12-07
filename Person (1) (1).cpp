#include "Person.h"
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iomanip>
Person::Person(): exam(0.0), finalGrade(0.0) {}
Person::Person(const std::string& n,const std::string& s): name(n),surname(s),exam(0.0),finalGrade(0.0) {}
Person::Person(const Person& o)=default;
Person& Person::operator=(const Person& o)=default;
Person::~Person()=default;
std::istream& operator>>(std::istream& is,Person& p){
    p.homeworks.clear();p.finalGrade=0.0;
    if(!(is>>p.name>>p.surname))return is;
    std::string line;std::getline(is,line);if(line.empty())return is;
    std::istringstream ss(line);double v;std::vector<double> vals;while(ss>>v)vals.push_back(v);
    if(vals.empty()){p.exam=0.0;}else{p.exam=vals.back();vals.pop_back();p.homeworks=vals;}
    return is;
}
std::ostream& operator<<(std::ostream& os,const Person& p){
    os<<p.name<<" "<<p.surname<<" "<<std::fixed<<std::setprecision(2)<<p.finalGrade;return os;
}
double Person::computeAverage()const noexcept{
    if(homeworks.empty())return 0.0;
    double s=std::accumulate(homeworks.begin(),homeworks.end(),0.0);
    return s/homeworks.size();
}
double Person::computeMedian()const noexcept{
    if(homeworks.empty())return 0.0;
    auto v=homeworks;std::sort(v.begin(),v.end());size_t n=v.size();
    return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
}
void Person::calculateFinal(bool m)noexcept{
    double hw=m?computeMedian():computeAverage();
    finalGrade=0.4*hw+0.6*exam;
}
