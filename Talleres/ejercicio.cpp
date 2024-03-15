#include<iostream>
#include<list>
using namespace std;
int main(){
list<string> Frutas={};
Frutas.push_back("manzana");
Frutas.push_back("pera");
Frutas.push_back("uva");
Frutas.push_back("melon");
Frutas.push_back("fresa");
for (const auto & elemento:Frutas){
    cout<<elemento<<"";
}
auto it=next(Frutas.begin(),1);
Frutas.insert(it,"arandanos");
for (const auto & elemento:Frutas){
    cout<<elemento<<"";
}
Frutas.pop_front();
for (const auto & elemento:Frutas){
    cout<<elemento<<"";
}
auto it1=next(Frutas.begin(),2);
Frutas.erase(it1);
Frutas.remove("uva");
//Frutas.front();
//Frutas.back();
auto it2=next(Frutas.begin(),3);
cout<<*it2;
Frutas.clear();
Frutas.resize(10);
//Frutas.empty();
//Frutas.size();
//Frutas.max_size();
return 0;
}
//crear una lista de reproduccion de spotify de canciones con sus generos 
//y que el usuario pued crear su propia lista de reproducciones 
//crear una lista enlasada con un amigo (llamado jam en spotyfy)
