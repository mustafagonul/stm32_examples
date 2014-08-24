#include "rcc.hpp"
#include "types.hpp"
#include "utility.hpp"

#define RCC_BASE 0x40023800


namespace rcc {

static volatile register32ptr const clockControl                = reinterpret_cast<register32ptr>(RCC_BASE + 0x00);
static volatile register32ptr const pplConfiguration            = reinterpret_cast<register32ptr>(RCC_BASE + 0x04);
static volatile register32ptr const clockConfiguration          = reinterpret_cast<register32ptr>(RCC_BASE + 0x08);
static volatile register32ptr const clockInterrupt              = reinterpret_cast<register32ptr>(RCC_BASE + 0x0C);

static volatile register32ptr const ahb1_reset                  = reinterpret_cast<register32ptr>(RCC_BASE + 0x10);
static volatile register32ptr const ahb2_reset                  = reinterpret_cast<register32ptr>(RCC_BASE + 0x14);
static volatile register32ptr const ahb3_reset                  = reinterpret_cast<register32ptr>(RCC_BASE + 0x18);
static volatile register32ptr const apb1_reset                  = reinterpret_cast<register32ptr>(RCC_BASE + 0x20);
static volatile register32ptr const apb2_reset                  = reinterpret_cast<register32ptr>(RCC_BASE + 0x28);

static volatile register32ptr const ahb1_clockEnable            = reinterpret_cast<register32ptr>(RCC_BASE + 0x30);
static volatile register32ptr const ahb2_clockEnable            = reinterpret_cast<register32ptr>(RCC_BASE + 0x34);
static volatile register32ptr const ahb3_clockEnable            = reinterpret_cast<register32ptr>(RCC_BASE + 0x38);
static volatile register32ptr const apb1_clockEnable            = reinterpret_cast<register32ptr>(RCC_BASE + 0x40);
static volatile register32ptr const apb2_clockEnable            = reinterpret_cast<register32ptr>(RCC_BASE + 0x44);

//static volatile register32ptr const ahb1_lowPowerClockEnable
//static volatile register32ptr const ahb2_lowPowerClockEnable
//static volatile register32ptr const ahb3_lowPowerClockEnable
//static volatile register32ptr const apb1_lowPowerClockEnable
//static volatile register32ptr const apb2_lowPowerClockEnable


void enable(Port port)
{
  unsigned index = static_cast<unsigned>(port);

  utility::set(ahb1_clockEnable, index);
}

void disable(Port port)
{
  unsigned index = static_cast<unsigned>(port);

  utility::unset(ahb1_clockEnable, index);
}


} // rcc




