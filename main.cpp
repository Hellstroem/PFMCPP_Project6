/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n);   //1
    int value;
    std::string name;
};

T::T(int v, const char* n) : value(v), name(n) {}

struct Compare                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float waypoint1 { 0 }, waypoint2 { 0 };
    float reduceDistance(float* newValue)      //12
    {
        std::cout << "U's waypoint1 value: " << this->waypoint1 << std::endl;
        if(newValue != nullptr)
        {
            this->waypoint1 = *newValue;
        }
        std::cout << "U's waypoint1 updated value: " << this->waypoint1 << std::endl;
        while( std::abs(this->waypoint2 - this->waypoint1) > 0.001f )
        {           
            this->waypoint2 += 0.001f ;
        }
        std::cout << "U's waypoint2 updated value: " << this->waypoint2 << std::endl;
        return this->waypoint2 * this->waypoint1;
    }
};

struct UStatic
{
    static float reduceDistance(U* that, float* newValue )        //10
    {   
        if(that != nullptr)
        {
            std::cout << "U's waypoint1 value: " << that->waypoint1 << std::endl;
            if(newValue != nullptr)
            {
                that->waypoint1 = *newValue;
            }
            std::cout << "U's waypoint1 updated value: " << that->waypoint1 << std::endl;
            while( std::abs(that->waypoint2 - that->waypoint1) > 0.001f )
            {               
                that->waypoint2 += 0.001f;
            }
            std::cout << "U's waypoint2 updated value: " << that->waypoint2 << std::endl;
             return that->waypoint2 * that->waypoint1;  
        }
        return 0.0f;
    }
};
   
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T number1(3, "object Number 1");                                             //6
    T number2(2, "object Number 2");     //6
    
    Compare f;                                            //7
    auto* smaller = f.compare(&number1 ,&number2); //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "Compared values of objects are equal or pointer arguments of compare function are nullptr's" << '\n';
    }
 
    U one;
    float updatedValue = 5.f;
    UStatic::reduceDistance(nullptr, nullptr);
    std::cout << "[static func] one's multiplied values: " << UStatic::reduceDistance(&one, &updatedValue) << std::endl;                  //11
    
    U two;
    std::cout << "[member func] two's multiplied values: " << two.reduceDistance(&updatedValue) << std::endl;   
}
