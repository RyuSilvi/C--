#include <print>
#include <iostream>
#include <string>


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

}