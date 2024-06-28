#include "13440function.h"
#include <string>

Animal::Animal(){};
Animal::Animal(string n, string s){
    name = n;
    species = s;
    HP = 0;
}
Animal::~Animal(){};
int Animal::get_HP(){
    return HP;
}
string Animal::get_name(){
    return name;
}
string Animal::get_species(){
    return species;
}
void Animal::update_HP(int x){
    HP = x;
}
void Animal::turn_HP_into_zero(){
    HP = 0;
}
void Animal::Talk(){}
void Animal::Breath(int x){
    HP += x;
}
void Animal::Sleep(int x){
    if(HP<=100) HP *= x;
}
void Animal::Eat(Animal *animal){}
void Animal::Eaten(Animal *animal){}

Cat::Cat(string n):Animal(n, "cat"){}
Fish::Fish(string n):Animal(n, "fish"){}
Bird::Bird(string n):Animal(n, "bird"){}
Human::Human(string n):Animal(n, "human"){}

void Cat::Talk(){
    std::cout<<"Meow\n";
}
void Fish::Talk(){
    std::cout<<"?\n";
}
void Bird::Talk(){
    std::cout<<"Suba\n";
}
void Human::Talk(){
    std::cout<<"Hello, world\n";
}

void Cat::Eat(Animal *animal){
    if(animal->get_species() == "fish"){
        this->update_HP(this->get_HP()+animal->get_HP());
        animal->turn_HP_into_zero();
    }
}
void Bird::Eat(Animal *animal){
    if(animal->get_species() == "fish"){
        this->update_HP(this->get_HP()+animal->get_HP());
        animal->turn_HP_into_zero();
    }
}
void Human::Eat(Animal *animal){
    if(animal->get_species() == "fish"||animal->get_species() == "bird"){
        this->update_HP(this->get_HP()+animal->get_HP());
        animal->turn_HP_into_zero();
    }
    else if(animal->get_species() == "cat"){
        this->turn_HP_into_zero();
    }
}

void Fish::Eaten(Animal *animal){}
void Bird::Eaten(Animal *animal){}

