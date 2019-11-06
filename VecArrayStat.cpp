#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <algorithm>
#include "VecArrayStat.h"
using namespace std;

double ArrayStat::rms()const{

if (Array.size()<2) throw(1);
    else {
        double m = mean();
        double rms =(double)0;
        std::for_each (Array.begin(), Array.end(), [&](int n)->double {rms += (n - m) * (n - m);});
        return sqrt((rms)/((double)Array.size()-1));
    }
}



double ArrayStat::mean() const {

if (Array.size()<1) throw(1);
    else {
        double sum = std::accumulate(Array.begin(), Array.end(), (double)0);
        return (sum/(double)(Array.size()));
    }
}

double ArrayStat::max() const{

if (Array.size()<1) throw(1);
    else
        return Array[Array.size()-1];
}

size_t ArrayStat::countLarger(double a) const{
        int k = 0;
       k =Array.end()- lower_bound(Array.begin(),Array.end(), (a+1)) ;      /*std::for_each (Array.begin(), Array.end(), [&](int n)-> int{if (n>a)  k += 1;});*/
return k;
}


double ArrayStat::min() const{

if (Array.size()<1) throw(1);
    else
        return Array[0];
}



ArrayStat::ArrayStat(const char* filename){

ifstream  ifile(filename, ifstream::in);
if (!ifile.good()){
    throw 1;
}

double N;
ifile >> N;
int k = (int)N;
double o;
for (long int i=0; i < k; i++) {
    o=(double)0;
    for(int j=0; j<3; j++){
        ifile >> N;
        o+=N*N;
    }

    Array.push_back(sqrt(o));
    }
std::sort(Array.begin(),Array.end());

}


void ArrayStat::print() const{
for (int i=0; i < (Array.size()); i++) {
    cout << Array[i] <<" "<< endl;

}
}

/*int main(){

    ArrayStat wow("D:/VecArrayStat.txt.txt");
    wow.print();
    cout << "max is" << wow.max() << endl;
    cout <<wow.mean()<<"rms is"<< wow.rms()<< endl;
    cout <<">1.999 :"<< wow.countLarger(1.999) << endl;
    return 0;
}*/

