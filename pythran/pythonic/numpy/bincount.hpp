#ifndef PYTHONIC_NUMPY_BINCOUNT_HPP
#define PYTHONIC_NUMPY_BINCOUNT_HPP

#include "pythonic/include/numpy/bincount.hpp"

#include "pythonic/numpy/max.hpp"
#include "pythonic/utils/numpy_conversion.hpp"

PYTHONIC_NS_BEGIN

namespace numpy
{
  template <class T>
  types::ndarray<long, 1> bincount(types::ndarray<T, 1> const &expr,
                                   types::none_type weights,
                                   types::none<long> minlength)
  {
    long length = 0;
    if (minlength)
      length = (long)minlength;
    length = std::max(length, 1 + max(expr));
    types::ndarray<long, 1> out(types::make_tuple(length), 0L);
    for (auto iter = expr.fbegin(), end = expr.fend(); iter != end; ++iter)
      ++out[*iter];
    return out;
  }

  template <class T, class E>
  types::ndarray<
      decltype(std::declval<long>() * std::declval<typename E::dtype>()), 1>
      bincount(types::ndarray<T, 1> const &expr, E const &weights,
               types::none<long> minlength)
  {
    long length = 0;
    if (minlength)
      length = (long)minlength;
    length = std::max(length, 1 + max(expr));
    types::ndarray<decltype(std::declval<long>() *
                            std::declval<typename E::dtype>()),
                   1> out(types::make_tuple(length), 0L);
    auto iweight = weights.fbegin();
    for (auto iter = expr.fbegin(), end = expr.fend(); iter != end;
         ++iter, ++iweight)
      out[*iter] += *iweight;
    return out;
  }

  NUMPY_EXPR_TO_NDARRAY0_IMPL(bincount);

  DEFINE_FUNCTOR(pythonic::numpy, bincount);
}
PYTHONIC_NS_END

#endif
