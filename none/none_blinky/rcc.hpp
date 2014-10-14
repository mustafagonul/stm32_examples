#ifndef RCC_HPP
#define RCC_HPP


namespace rcc {
  enum class Port : unsigned {
    GPIO_A = 0,
    GPIO_B = 1,
    GPIO_C = 2,
    GPIO_D = 3,
    GPIO_E = 4,
    GPIO_F = 5,
    GPIO_G = 6,
    GPIO_H = 7,
    GPIO_I = 8,
    GPIO_J = 9,
    GPIO_K = 10,
  };

  void enable(Port);
  void disable(Port);
};


#endif // RCC
