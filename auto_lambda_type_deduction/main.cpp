#include <iostream>
#include <optional>

template<typename F>
auto exec(F func){

  auto ret{func()};
  using LambdaRetType = decltype(ret);

  std::optional<LambdaRetType> opt_ret;
  if(!ret){
    opt_ret = std::nullopt;
  } else {
    opt_ret = std::make_optional<LambdaRetType>(ret);
  }
  return opt_ret;
}


int main(int argc, char* argv[]) {
    int i{42};
    std::optional<int> foo{exec([=](){
      return i;
    })};

    std::cout << foo.value_or(0) << std::endl;
  }

