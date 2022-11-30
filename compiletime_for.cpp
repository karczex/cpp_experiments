#include <utility>
#include <tuple>
#include <string>
#include <iostream>

template <int start, int end, template <int> class OperatorType, typename... Args>
void compile_time_for(Args... args)
{
  if constexpr (start < end)
         {
           OperatorType<start>()(std::forward<Args>(args)...);
           compile_time_for<start + 1, end, OperatorType>(std::forward<Args>(args)...);
         }    
}

template <int I>
struct print_tuple_i {
  template <typename... U>
  void operator()(const std::tuple<U...>& x) { std::cout << std::get<I>(x) << " "; }
};

int main()
{
  std::tuple<int, int, std::string> x{1, 2, "hello"};

  compile_time_for<0, 3, print_tuple_i>(x);

  return 0;
}

