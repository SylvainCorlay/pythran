#ifndef PYTHONIC_INCLUDE_BUILTIN_FILE_READLINE_HPP
#define PYTHONIC_INCLUDE_BUILTIN_FILE_READLINE_HPP

#include "pythonic/include/types/file.hpp"
#include "pythonic/include/types/str.hpp"
#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  namespace file
  {

    types::str readline(types::file &f, long size = -1);
    types::str readline(types::file &&f, long size = -1);

    DECLARE_FUNCTOR(pythonic::__builtin__::file, readline);
  }
}
PYTHONIC_NS_END
#endif
