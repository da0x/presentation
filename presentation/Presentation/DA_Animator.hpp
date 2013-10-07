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

#ifndef __Solstice_Mobile__Animator__
#define __Solstice_Mobile__Animator__

#include "DA_View.hpp"

#include <memory>
#include <vector>

namespace DA
{
    class Animator
    {
    protected:
        std::vector<View::pointer_type> views;
        
    public:
        void add( View::pointer_type view )
        {
            this->views.push_back(view);
        }
        
        size_t size() const
        {
            return this->views.size();
        }

        virtual void activate()
        {
            for( size_t i=0; i< this->size(); i++ )
            {
                View::pointer_type& pointer = this->views[i];
                pointer->activate();
            }
        }
        
        virtual void update_x( float x, float size )
        {
            for( size_t i=0; i< this->size(); i++ )
            {
                View::pointer_type& pointer = this->views[i];
                pointer->update_x(x,size);
            }
        }
        
        virtual void update_y( float y, float size )
        {
            for( size_t i=0; i< this->size(); i++ )
            {
                View::pointer_type& pointer = this->views[i];
                pointer->update_y(y,size);
            }
        }

    protected:
    };
}

#endif
