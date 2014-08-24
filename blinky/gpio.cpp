#include "gpio.hpp"
#include "utility.hpp"

#define GPIO_BASE 0x40020000


GPIO::GPIO(register32ptr base)
  : mode(base + 0)
  , outputType(base + 1)
  , outputSpeed(base + 2)
  , pullUpPullDown(base + 3)
  , inputData(reinterpret_cast<register16ptr>(base + 4))
  , outputData(reinterpret_cast<register16ptr>(base + 5))
  , bitSetReset(base + 6)
  , locking(base + 7)
  , afrl(base + 8)
  , afrh(base + 9)
{
}

void GPIO::set(Pin pin, Mode m) const
{
  if (pin >= 16)
    return;

  unsigned index = pin * 2;

  switch (m) {
  case Mode::Input:
    utility::unset(mode, index);
    utility::unset(mode, index + 1);
    break;
  case Mode::Output:
    utility::set(mode, index);
    utility::unset(mode, index + 1);
    break;
  case Mode::Alternate:
    utility::unset(mode, index);
    utility::set(mode, index + 1);
    break;
  case Mode::Analog:
    utility::set(mode, index);
    utility::set(mode, index + 1);
    break;
  }
}

void GPIO::set(Pin pin, OutputType type) const
{
  if (pin >= 16)
    return;

  switch (type) {
  case OutputType::PushPull:
    utility::unset(outputType, pin);
    break;
  case OutputType::OpenDrain:
    utility::set(outputType, pin);
    break;
  }
}

void GPIO::set(Pin pin, OutputSpeed speed) const
{
  if (pin >= 16)
    return;

  unsigned index = pin * 2;

  switch (speed) {
  case OutputSpeed::Low:
    utility::unset(outputSpeed, index);
    utility::unset(outputSpeed, index + 1);
    break;
  case OutputSpeed::Medium:
    utility::set(outputSpeed, index);
    utility::unset(outputSpeed, index + 1);
    break;
  case OutputSpeed::Fast:
    utility::unset(outputSpeed, index);
    utility::set(outputSpeed, index + 1);
    break;
  case OutputSpeed::High:
    utility::set(outputSpeed, index);
    utility::set(outputSpeed, index + 1);
    break;
  }
}

void GPIO::set(Pin pin, Pull pull) const
{
  if (pin >= 16)
    return;

  unsigned index = pin * 2;

  switch (pull) {
  case Pull::None:
    utility::unset(pullUpPullDown, index);
    utility::unset(pullUpPullDown, index + 1);
    break;
  case Pull::Up:
    utility::set(pullUpPullDown, index);
    utility::unset(pullUpPullDown, index + 1);
    break;
  case Pull::Down:
    utility::unset(pullUpPullDown, index);
    utility::set(pullUpPullDown, index + 1);
    break;
  }
}

void GPIO::set(Pin pin) const
{
  if (pin >= 16)
    return;

  //utility::set(bitSetReset, pin);
  utility::set(outputData, pin);
}

void GPIO::unset(Pin pin) const
{
  if (pin >= 16)
    return;

  //utility::unset(bitSetReset, pin);
  utility::unset(outputData, pin);
}

GPIO GPIO::port(Port p)
{
  unsigned index = static_cast<unsigned>(p);
  register32ptr base = reinterpret_cast<register32ptr>(GPIO_BASE + 0x0400 * index);

  return GPIO(base);
}
