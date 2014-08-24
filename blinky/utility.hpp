#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "types.hpp"


namespace utility {

  void set(volatile register32ptr, unsigned);
  void unset(volatile register32ptr, unsigned);
  void set(volatile register16ptr, unsigned);
  void unset(volatile register16ptr, unsigned);

}


#endif // UTILITY_HPP
