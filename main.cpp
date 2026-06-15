#include <print>
#include <iostream>
#include <string>
#include <vector>
#include <array>

auto multiply(int a, int b) -> int {
    // Implementation for multiplication
    return a * b;
}

std::optional<int> returnIfCool(int a) {
    if (a % 2 == 1 && a > 5) {
        return a; // Return the value if it's odd and greater than 5
    }else{
        return std::nullopt; // Return nullopt if the value is not "cool"
    }
}


int main() {
 // 1) basic console i/o
 std::println("Hello {}!", "print") ;  //la til ln for linje skifte
// set unitbuf for å flush output buffer etter hver output operasjon
 std::cout << "Hello, cout!"  << std::endl; // la til std::endl for linje skifte og flusher console output buffer

 //2) variabler og data types
 [[maybe_unused]] // fordi variablene ikke brukes senere i koden, unngår vi compiler warnings ved å bruke [[maybe_unused]] attributten
 int a { 42 }; // integer variable
 a = 100;  // reassigning a new value to the integer variable 
[[maybe_unused]]
unsigned  b { 100 }; // unsigned integer variable
int c {20};
[[maybe_unused]]
char letter { 'A' }; // char variable
[[maybe_unused]]
float floaty { 3.14f }; // float variable
[[maybe_unused]]
double doubly { 4.342345432 }; // double variable
[[maybe_unused]]
std::string name ( "Alice" ); // string variable
[[ maybe_unused]]
bool isWrong {true}; // boolean variable


// 4) control structures
if(isWrong){
    std::cout << "this is wrong!" << std::endl;
}else if(not isWrong){
    std::cout << "this is right!" << std::endl;
} else {
    std::cout << "this is neither right nor wrong!" << std::endl;
}

// 5) loops
for(int counter{0} ; counter < 100 ; counter+=1){
    // noe code her 
    std::cout << counter << std::endl;
} 

while(isWrong){
    // noe code her
    std::cout << "this is wrong!" << std::endl;
    isWrong = false; // for å unngå en evig loop
}

// 6) functions
int result = multiply(a, c);
std::println("the result of multiplying {} and {} is {}", a, c, result); // la til en print statement for å vise resultatet av multiplikasjonen

auto add = [](int a, int b) -> int { // lambda function for addition
    return a + b;
};

result = add(a, c);
std::println("result {}",result); // la til en print statement for å vise resultatet av addisjonen

// 7) arrays and vectors
int array[5] {1, 2, 3, 4, 5}; // array of integers
array[2] = 6;

std::array<int, 5> modernArray {1, 2, 3, 4, 5}; // modern array using std::array
modernArray.at(2) = 6; // using at() method to access and modify elements in std::array

std::vector <int> numVector {1, 2, 3, 4, 5}; // vector of integers
numVector.push_back(6); // adding an element to the end of the vector

for(auto element : numVector){
    std::print("{} ", element); // range-based for loop to print elements of the vector
}
std::println("\nEnd!");


// 8) optional (as return types)
auto numOptional = returnIfCool(3456789);
if(numOptional.has_value()){
    std::println("the number {} is cool!", numOptional.value()); // using value() method to access the value of the optional
} else {
    std::println("the number is not cool!"); // handling the case where the optional does not have a value
}

//refferences

int zulu { 7 };
int& refToZulu = zulu; // refToZulu is a reference to zulu

refToZulu = 10; // changing the value of zulu through the reference

std::println("zulu is now {}", zulu); // printing the updated value of zulu

// 9) pointers and smart pointers
int* ptr {&a}; // pointer to an integer
std::println("Value of a through pointer: {}", *ptr); // dereferencing the pointer to get the value of a

}
