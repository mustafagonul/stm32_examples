#include "utility.hpp"


namespace utility {


void set(volatile register32ptr ptr, unsigned index)
{
  *ptr |= (1 << index);
}

void unset(volatile register32ptr ptr, unsigned index)
{
  *ptr &= ~(1 << index);
}

void set(volatile register16ptr ptr, unsigned index)
{
  *ptr |= (1 << index);
}

void unset(volatile register16ptr ptr, unsigned index)
{
  *ptr &= ~(1 << index);
}




} // utility
