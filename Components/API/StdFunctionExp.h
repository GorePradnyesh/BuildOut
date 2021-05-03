/****************************************************************
 *****************************************************************/
#include <iostream>
#include <functional>
#include <typeinfo>

namespace
{

// Strongly typed function, alias and invoker
std::uint32_t Adder_typed(std::uint32_t inFirst, std::uint32_t inSecond)
{
    return inFirst + inSecond;
}

using EvalOperation_t = std::function<std::uint32_t(std::uint32_t, std::uint32_t)>;
std::uint32_t Evaluator_typed(
                                  std::uint32_t inFirst,
                                  std::uint32_t inSecond,
                                  const EvalOperation_t& inEvalOperation)
{
    return inEvalOperation(inFirst, inSecond);
}


// Generic operation, alias and invoker
template<typename T>
T Adder_T(const T& inFirst, const T& inSecond)
{
    return static_cast<T>(inFirst + inSecond);
}

template<typename T>
using EvalOperation_T = std::function<T(
                                        const T&,
                                        const T&)>;

template <typename T>
T Evaluator(
            const T& inFirst,
            const T& inSecond,
            const EvalOperation_T<T>& inEvalOperation)
{
    return inEvalOperation(inFirst, inSecond);  // RVO ?
}


} // unnamed

namespace Components {

void SimpleFuntionalCallerTyped()
{
    auto res = Evaluator_typed(44, 66, Adder_typed);
    std::cout << "Strongly Typed Eval res : " << res << std::endl;
    
    {
        auto res = Evaluator<float>(44.5, 22.5, Adder_T<float>);
        std::cout << "Generic Eval res : " << res << std::endl;
    }
    
    {
        auto res = Evaluator<float>(44.5, 22.5, Adder_T<int>);
        std::cout << "Generic Eval res : " << res << std::endl;
    }
    
    {
        std::string first = "Part 1 <-";
        std::string second = "-> Part 2";
        auto res = Evaluator<decltype(first)>(first, second, Adder_T<decltype(first)>);
        std::cout << "Generic Eval res : " << res << std::endl;
    }
} // SimpleFuntionalCallerTyped

}   // Components
