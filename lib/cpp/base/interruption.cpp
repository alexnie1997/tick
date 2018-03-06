// License: BSD 3 clause

#include "tick/base/interruption.h"

#include <csignal>
#include <iostream>

const char *Interruption::what() const noexcept {
  return "Process was interrupted with signal SIGINT";
}

namespace {

void signal_handler(int signum) { Interruption::set(); }

}  // namespace

class InterruptionInit {
 public:
  InterruptionInit() { std::signal(SIGINT, signal_handler); }
};

InterruptionInit init;
