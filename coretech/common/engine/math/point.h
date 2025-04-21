
/**
 * File: point.h - MODIFIED
 *
 * Keep all your existing declarations and documentation, but make these key changes:
 */

#ifndef _ANKICORETECH_COMMON_POINT_H_
#define _ANKICORETECH_COMMON_POINT_H_

#include "coretech/common/shared/types.h"

#if ANKICORETECH_USE_OPENCV
#include "opencv2/core.hpp"
#endif

#include <array>

namespace Anki {
  
  // Forward declaration
  class Radians;
  template<MatDimType,MatDimType,typename> class SmallMatrix;
  
  using PointDimType = size_t;
  
  // Generic N-dimensional Point class
  template<PointDimType N, typename T>
  class Point //: public std::array<T,N>
  {
    static_assert(N>0, "Cannot create an empty Point.");
    
  public:
    
    // Keep all declarations as they are, removing any implementations that might exist here
    Point( void );
    Point(const T scalar);
    Point(const Point<N+1,T>& pt);
    explicit Point(const SmallMatrix<N,1,T>& M);

    // Keep all your other declarations...
    
  protected:
    std::array<T,N> data;
    
  }; // class Point
  
  // Type aliases remain the same
  template <typename T>
  using Point2 = Point<2, T>;
  
  template <typename T>
  using Point3 = Point<3, T>;
  
  using Point2f = Point2<f32>;
  using Point3f = Point3<f32>;
  
  using Point2i = Point2<s32>;
  using Point3i = Point3<s32>;
  
  using Vec2f = Point2f;
  using Vec3f = Point3f;
  
  const Vec2f& X_AXIS_2D();
  const Vec2f& Y_AXIS_2D();
  
  const Vec3f& X_AXIS_3D();
  const Vec3f& Y_AXIS_3D();
  const Vec3f& Z_AXIS_3D();

  // All other declarations...

} // namespace Anki

// CRITICAL: Include the implementation file OUTSIDE the namespace
// and AFTER the class is fully declared
#include "coretech/common/engine/math/point_impl.h"

#endif // _ANKICORETECH_COMMON_POINT_H_