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
    T(int v, const char* n);   
    int value;
    std::string name;
};

T::T(int v, const char* n) : value(v), name(n) {}

struct Compare                                
{
    const T* compare(const T& a, const T& b) 
    {
        const T* ptr {nullptr};
        
        if( a.value < b.value ) return (ptr = &a);
        if( a.value > b.value ) return (ptr = &b);

        return ptr;
    }
};

struct U
{
    float waypoint1 { 0 }, waypoint2 { 0 };
    float reduceDistance(const float& newValue)      
    {
        std::cout << "U's waypoint1 value: " << this->waypoint1 << std::endl;

        this->waypoint1 = newValue;

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
    static float reduceDistance(U& that,const float& newValue )       
    {   
        std::cout << "U's waypoint1 value: " << that.waypoint1 << std::endl;
        that.waypoint1 = newValue;

        std::cout << "U's waypoint1 updated value: " << that.waypoint1 << std::endl;
        while( std::abs(that.waypoint2 - that.waypoint1) > 0.001f )
        {               
            that.waypoint2 += 0.001f;
        }
        std::cout << "U's waypoint2 updated value: " << that.waypoint2 << std::endl;
        return that.waypoint2 * that.waypoint1;  
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
    T number1(2, "object Number 1");                                             
    T number2(2, "object Number 2");     
    
    Compare f;                                            
    auto* smaller = f.compare(number1 ,number2);
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; 
    }
    else
    {
        std::cout << "Compared values of objects are equal" << '\n';
    }
 
    U one;
    const float updatedValue = 5.f;
    std::cout << "[static func] one's multiplied values: " << UStatic::reduceDistance(one, updatedValue) << std::endl;                  
    
    U two;
    std::cout << "[member func] two's multiplied values: " << two.reduceDistance(updatedValue) << std::endl; 
}
