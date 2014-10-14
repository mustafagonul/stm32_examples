#ifndef GPIO_HPP
#define GPIO_HPP

#include "types.hpp"


class GPIO {
private:
  explicit GPIO(register32ptr);

public:
  using Pin = unsigned;

  enum class Port : unsigned {
    A = 0, B = 1, C = 2, D = 3,
    E = 4, F = 5, G = 6, H = 7,
    I = 8, J = 9, K = 10,
  };

  enum class Mode : unsigned {
    Input,
    Output,
    Alternate,
    Analog,
  };

  enum class OutputType : unsigned {
    PushPull,
    OpenDrain,
  };

  enum class OutputSpeed : unsigned {
    Low,
    Medium,
    Fast,
    High,
  };

  enum class Pull : unsigned {
    None,
    Up,
    Down,
  };




public:
  void set(Pin, Mode) const;
  void set(Pin, OutputType) const;
  void set(Pin, OutputSpeed) const;
  void set(Pin, Pull) const;
  void set(Pin) const;
  void unset(Pin) const;

public:
  static GPIO port(Port);

private:
  volatile register32ptr const mode;
  volatile register32ptr const outputType;
  volatile register32ptr const outputSpeed;
  volatile register32ptr const pullUpPullDown;
  volatile register16ptr const inputData;
  volatile register16ptr const outputData;
  volatile register32ptr const bitSetReset;
  volatile register32ptr const locking;
  volatile register32ptr const afrl;
  volatile register32ptr const afrh;
};



#endif
