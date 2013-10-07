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

#ifndef __Solstice_Mobile__ThumbnailAnimator__
#define __Solstice_Mobile__ThumbnailAnimator__

#include "DA_Animator.hpp"

namespace DA
{
    class ThumbnailAnimator : public View
    {
        bool focus;
    public:
        ThumbnailAnimator( UIView* view ): View(view)
        {
        }
        
        void activate()
        {
            focus = true;
            this->exitFocus();
        }
        
        // f(a,p,s,s') returns a'' ( position of a around axis p in domain 1 with scaled domain s'
        // domain 1 is full view
        // domain 2 is scaled view
        // domain 3 is domain 2 around reference point p
        // a position in domain 1
        // p reference point in domain 1
        // s is size of domain 1
        // s' is size in domain 2
        // returns a in domain 3 per reference p
        // ----------------------------------
        // a'  = a * s' / s
        // p'  = p * s' / s
        // ----------------------------------
        // a'' = p + a' - p'
        //     = p + a * s' / s - p * s' / s
        //     = p + ( s / s' ) * ( a - p )
        // ----------------------------------
        float f( float a, float p, float s, float s_ )
        {
            return p + ( s_ / s ) * ( a - p );
        }
        
        void update_x( float x, float size )
        {
            if ( size == 0 )
                return;
            
                // move the view get params.
            float a = this->x;       // position in domain 1
            float p = x;             // offset in domain 1
            float s = size;          // size for domain 1
            float s_ = s * 0.32f;    // one third the size.
            
            float a__ = f( a, p, s, s_ );
            
            CGRect frame;
            frame.origin.x      = a__;
            frame.origin.y      = 0.0f;
            frame.size.width    = this->w;
            frame.size.height   = this->h;
            
            [this->view setFrame:frame];
            
                // apply transformations.
            float offset   = x;
            float distance = ( offset - this->x );
            bool  inView   = fabs(distance) < 200;
            if( inView )
                this->enterFocus();
            else
                this->exitFocus();
            
            if( inView )
            {
                [this->view.superview bringSubviewToFront:this->view];
            }
        }
    
        void enterFocus()
        {
            if( this->focus )
                return;
            
            this->focus = true;
            
            // going in.
            CATransform3D pass = CATransform3DMakeScale( 0.32f, 0.32f, 0.32f );
            CATransform3D land = CATransform3DMakeScale( 0.30f, 0.30f, 0.30f );
            
            this->animate(pass,land);
        }
        
        void exitFocus()
        {
            if( !this->focus )
                return;
            
            this->focus = false;
            
            // going out.
            CATransform3D pass = CATransform3DMakeScale( 0.18f, 0.18f, 0.18f );
            CATransform3D land = CATransform3DMakeScale( 0.20f, 0.20f, 0.20f );
            
            this->animate(pass, land);
        }

    };
}

#endif
