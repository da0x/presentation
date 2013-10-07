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

#ifndef __Solstice_Mobile__View__
#define __Solstice_Mobile__View__

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#include <memory>

namespace DA
{
    class View
    {
    protected:
        float x, y;
        float w, h;
        UIView* view;
        
    public:
        typedef std::shared_ptr<View> pointer_type;
        
        View();
        
        View( UIView* v ): view(v)
        {
            this->x = view.frame.origin.x;
            this->y = view.frame.origin.y;
            this->w = view.frame.size.width;
            this->h = view.frame.size.height;
        }
        
        View( const View& copy ):View(copy.view)
        {
            x = copy.x;
            y = copy.y;
            w = copy.w;
            h = copy.h;
        }
        
        virtual void activate(){}
        virtual void update_x( float x, float size ){}
        virtual void update_y( float y, float size ){}
        
        void animate( CATransform3D pass, CATransform3D land )
        {
            [UIView animateWithDuration:0.1f delay:0.0f options:0 animations:^{
                this->view.layer.transform = pass;
            } completion:^(BOOL finished) {
                [UIView animateWithDuration:0.05f animations:^{
                    this->view.layer.transform = land;
                }];
            }];
        }
        
        
        void animate( CATransform3D pass, CATransform3D repass, CATransform3D land )
        {
            [UIView animateWithDuration:0.3f delay:0.0f options:UIViewAnimationOptionCurveEaseIn animations:^{
                
                this->view.layer.transform = pass;
                
            } completion:^(BOOL finished) {
                
                [UIView animateWithDuration:0.1f delay:0.0f options:UIViewAnimationOptionCurveEaseOut animations:^{
                    
                    this->view.layer.transform = repass;
                    
                } completion:^(BOOL finished) {
                    
                    [UIView animateWithDuration:0.05f delay:0.0f options:UIViewAnimationOptionCurveEaseIn animations:^{
                        
                        this->view.layer.transform = land;
                        
                    } completion:nil];
                }];
            }];
        }
    };
}

#endif
