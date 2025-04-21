/**
 * File: point_impl.h - MODIFIED
 *
 * Make these key changes:
 */

 #ifndef _ANKICORETECH_COMMON_POINT_IMPL_H_
 #define _ANKICORETECH_COMMON_POINT_IMPL_H_
 
 #include "util/math/math.h"
 // IMPORTANT: Remove this include to avoid circular inclusion
 // #include "coretech/common/engine/math/point.h"
 
 #include "coretech/common/shared/radians.h"
 #include "coretech/common/engine/exceptions.h"
 
 #include <cmath>
 
 namespace Anki {
   
   // Keep all your implementations as they are
   template<PointDimType N, typename T>
   Point<N,T>::Point( void )
   {
     for(PointDimType i=0; i<N; ++i) {
       this->data[i] = T(0);
     }
   }
   
   // All other implementations...
   
 } // namespace Anki
 
 #endif // _ANKICORETECH_COMMON_POINT_IMPL_H_