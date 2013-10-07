//
//   Copyright 2013 Daher Alfawares
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#ifndef __Solstice_Mobile__FullscreenBounceAnimator__
#define __Solstice_Mobile__FullscreenBounceAnimator__

#include "DA_Animator.hpp"

namespace DA
{
    class FullscreenBounceAnimator : public View
    {
        bool full;
    public:
        FullscreenBounceAnimator( UIView* view ): View(view)
        {
        }
        
        void activate()
        {
            CATransform3D pass   = CATransform3DMakeScale( 1.00f, 1.00f, 1.00f );
            CATransform3D repass = CATransform3DMakeScale( 0.92f, 0.92f, 0.92f );
            CATransform3D land   = CATransform3DMakeScale( 1.00f, 1.00f, 1.00f );
            
            this->animate(pass, repass, land);
        }
        
        void update_x( float x, float size )
        {            
            CGRect frame;
            frame.origin.x      = this->x;
            frame.origin.y      = this->y;
            frame.size.width    = this->w;
            frame.size.height   = this->h;
            
            [this->view setFrame:frame];
        }
    };
}


#endif
