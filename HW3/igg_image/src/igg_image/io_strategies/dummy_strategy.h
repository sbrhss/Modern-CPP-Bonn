// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <string>

#include "igg_image/io_strategies/strategy.h"

namespace igg {

class DummyIoStrategy : public IoStrategy {
  bool Write(const std::string&, const ImageData&) const override;
  ImageData Read(const std::string&) const override;
};

}  // namespace igg
