#include "rcc.hpp"
#include "gpio.hpp"


void delay(unsigned i)
{
  while(i--)
    ;
}

int main()
{
  rcc::enable(rcc::Port::GPIO_G);

  auto gpio_g = GPIO::port(GPIO::Port::G);

  gpio_g.set(13, GPIO::Mode::Output);
  gpio_g.set(13, GPIO::OutputType::PushPull);
  gpio_g.set(13, GPIO::Pull::None);
  gpio_g.set(13, GPIO::OutputSpeed::High);

  gpio_g.set(14, GPIO::Mode::Output);
  gpio_g.set(14, GPIO::OutputType::PushPull);
  gpio_g.set(14, GPIO::Pull::None);
  gpio_g.set(14, GPIO::OutputSpeed::High);


  while(true)
    for (unsigned i = 0; i < 2; ++i) {
      gpio_g.unset(13);
      gpio_g.unset(14);

      gpio_g.set(13 + i);

      delay(500000);
    }
}

/*
int main(void)
{
  rcc::enable(rcc::Port::GPIO_D);

  auto gpio_d = GPIO::port(GPIO::Port::D);

  gpio_d.set(12, GPIO::Mode::Output);
  gpio_d.set(13, GPIO::Mode::Output);
  gpio_d.set(14, GPIO::Mode::Output);
  gpio_d.set(15, GPIO::Mode::Output);

  gpio_d.set(12, GPIO::OutputType::PushPull);
  gpio_d.set(13, GPIO::OutputType::PushPull);
  gpio_d.set(14, GPIO::OutputType::PushPull);
  gpio_d.set(15, GPIO::OutputType::PushPull);

  gpio_d.set(12, GPIO::Pull::None);
  gpio_d.set(13, GPIO::Pull::None);
  gpio_d.set(14, GPIO::Pull::None);
  gpio_d.set(15, GPIO::Pull::None);

  gpio_d.set(12, GPIO::OutputSpeed::High);
  gpio_d.set(13, GPIO::OutputSpeed::High);
  gpio_d.set(14, GPIO::OutputSpeed::High);
  gpio_d.set(15, GPIO::OutputSpeed::High);


  while(true)
    for (unsigned i = 0; i < 4; ++i) {
      gpio_d.unset(12);
      gpio_d.unset(13);
      gpio_d.unset(14);
      gpio_d.unset(15);

      gpio_d.set(12 + i);

      delay(1000000);
    }




  return 0;
}
*/



extern "C" void _init()
{
}

extern "C" void SystemInit()
{
}
