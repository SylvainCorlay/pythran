#ifndef PYTHONIC_INCLUDE_NUMPY_ASARRAYCHKFINITE_HPP
#define PYTHONIC_INCLUDE_NUMPY_ASARRAYCHKFINITE_HPP

#include "pythonic/__builtin__/ValueError.hpp"
#include "pythonic/types/ndarray.hpp"
#include "pythonic/types/numexpr_to_ndarray.hpp"
#include "pythonic/utils/numpy_traits.hpp"
#include "pythonic/numpy/isfinite.hpp"

namespace pythonic
{

  namespace numpy
  {

    namespace wrapper
    {
      template <class I>
      I asarray_chkfinite(I const &a);
    }

#define NUMPY_NARY_FUNC_NAME asarray_chkfinite
#define NUMPY_NARY_FUNC_SYM wrapper::asarray_chkfinite
#include "pythonic/include/types/numpy_nary_expr.hpp"
  }
}

#endif