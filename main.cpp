#include <print>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>

namespace myNamespace {
    int multiply( int a, int b) {
        return a * a * b;
    }
}

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

std::unique_ptr<int> smartPtr{std::make_unique<int>(42)}; // unique pointer to an integer
std::println("Value through smart pointer: {}", *smartPtr); // dereferencing the smart

// 10) classes and objects

class House {
    protected: 
       int price;
       int height;
       int width;
       int numberOfRooms;
    public:
        House(int price,int height, int width, int numberOfRooms) 
        :price{price}, height{height}, width{width}, numberOfRooms{numberOfRooms}
         {
            std::println("another house has been built!");
        }

        void printInfo(){
            std::println("House info: price {}\n, height {}\n, width {}\n, number of rooms {}", price, height, width, numberOfRooms);
         }
        };

        House myHome(100000,10,20,5); // creating an object of the House class
        myHome.printInfo(); // calling the printInfo method to display the information about the house

        //10) Inheritance

        class SpecialHouse : public House { // SpecialHouse inherits from House
            public:
                SpecialHouse(int mult) : House(mult*100000, mult*10, mult*20, mult*5) { // constructor for SpecialHouse that calls the constructor of House with modified parameters
                    std::println("a special house has been built!");
                }

                void jump(){
                    std::println("the special house is jumping!");
                }

    
                void priceValue(int amount){
                    price += amount; // modifying the price of the house through a method in the derived class
                }

        };

        SpecialHouse minVilla(100);
        minVilla.printInfo(); // calling the printInfo method inherited from House to display the information about the special house
        minVilla.jump(); // calling the jump method of the SpecialHouse class
        minVilla.priceValue(50000); // modifying the price of the special house using the priceValue method
        minVilla.printInfo(); // calling printInfo again to see the updated price of the special

        House* house;
        if(!isWrong){
            house = &myHome; // pointing to myHome if isWrong is true
        } else {
            house = &minVilla; // pointing to minVilla if isWrong is false
        }
        house->printInfo(); // calling printInfo through the pointer to see the information of the house being pointed to}


        // 11) STL algorithms
        std::vector<int> anotherVector {5, 3, 8, 1,5, 2};
        std::sort(anotherVector.begin(), anotherVector.end()); // sorting the vector using std::sort algorithm

        for(auto num : anotherVector){
            std::print("{}", num);
        }
        std::println("\nvector has been sorted!");

        // 12 error handling with exceptions
        try {
            // do some stuff
            throw std::runtime_error("something went wrong!"); // throwing a runtime error exception

            std::println("this will not be printed because an exception has been thrown!"); // this line will not be executed
        } catch(const std::exception& e){
            std::cerr << "Caught an exception: " << e.what() << std::endl; // catching the exception and printing
        }catch(...){
            std::cerr << "Caught an unknown exception!" << std::endl; // catching any other types of exceptions
        }

        // 13 ) auto
       const auto& test = std::string("this is a test string"); // using auto to deduce the type of the variable test

        // 13) File I/O
        std::ofstream file("output.txt"); // creating an output file stream to write to a file named "output.txt"
        file << "Test data" << std::endl;
        file.close(); // closing the file stream

        std::ifstream inFile("output.txt"); // creating an input file stream to read from the file "output.txt"
        std::string line;
        while(std::getline(inFile, line)){
            std::println("[READ] \"{}\"", line); // printing each line read from the file
        }


        // maps
        std::map<std::string, int > ageMap {
            {"Alice", 30},
            {"Bob", 25},
            {"Charlie", 35}
        };
        auto key = "Alice";
        std::println("{} is {} years old",key,ageMap[key]); 
        

        //set
        std::set uniqueSet {1, 2, 3, 4, 5, 4,3,2,1,}; // creating a set of unique integers
        for(auto element : uniqueSet){
            std::print("{} ", element); // printing the unique elements of the set
        }

        // tuples
        std::tuple<std::string, int, double> person {"Alice", 30, 5.5}; // creating a tuple to store a person's name, age, and height
        std::println("Name: {}, Age: {}, Height: {}", std::get<0>(person), std::get<1>(person), std::get<2>(person)); // accessing the elements of the tuple using std::get

        // function objects
        struct Square {
            int operator()(int x) const { // defining the function call operator to make Square a function object
                return x * x; // returning the square of the input
            }
        };
        Square square; // creating an instance of the Square function object
        std::println("The square of 5 is {}", square(5)); // calling the function object to calculate the square of 5

        // type inheritance
        decltype(square) anotherSquare; // using decltype to declare another variable of the same type as square
        anotherSquare(66);

        // namespace
        myNamespace::multiply(3, 4); // calling the multiply function from myNamespace

        // enumerations
        enum class Color { Red, Green, Blue }; // defining a scoped enumeration for colors
        Color color = Color::Blue;


    switch(color){
        case Color::Red:
        //if its Red
        std::println("the color is red!"); // adding a print statement to indicate that the color is red
        break;
        case Color::Green:
        //if its Green
        std::println("the color is green!"); // adding a print statement to indicate that the color is green
        break;
        case Color::Blue:
        //if its Blue
        std::println("the color is blue!"); // adding a print statement to indicate that the color is blue
        break;
        default:
        //if its not Red,Green or Blue
        break;
    }
}


