
#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    std::string name;
    // 1 a
    Person(const std::string& n) : name(n) {
        std::cout << "Constructing  1a " << name << "\n";
    }
    // 1 b
    Person(std::string && n){
        name=std::move(n);
        std::cout << "Constructing using 1b " << name << "\n";
    }
    // 2 copy constructor 
    Person(const Person& other) {
        name = other.name;
        std::cout << "Copy constructing " << name << "\n";
    }
    //3 move constructor  
    Person(Person&& other) noexcept {
        name = std::move(other.name);
        std::cout << "Move constructing " << name << "\n";
    }
};

#define TRACE std::cout << __LINE__  <<"\n"; 


int main() {
    std::vector<Person> people;

    std::cout << "--- Using push_back ---\n";
    Person p1("Alice");
    TRACE  people.push_back(p1);         
    TRACE    people.push_back(Person("Bob"));     
    
    std::cout << "--- Using emplace_back ---\n";

    TRACE people.emplace_back("Charlie");    

    return 0;
}