// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#include <string>

#include "igg_image/io_strategies/dummy_strategy.h"

namespace igg {

bool DummyIoStrategy::Write(const std::string&, const ImageData&) const {
  return true;
}
ImageData DummyIoStrategy::Read(const std::string&) const {
  return ImageData{0, 0, 0, {{}}};
}

}  // namespace igg
