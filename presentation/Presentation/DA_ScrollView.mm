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

#include "DA_ScrollView.hpp"

@implementation DAScrollView

    // sets and activates the animator.
-(void)setAnimator:(DA::Animator*)animator
{
    _animator = animator;
    _animator->activate();
    
    [self setContentOffset:self.contentOffset];
}

    // updates the animator with offset changes.
-(void)setContentOffset:(CGPoint)offset
{
    [super setContentOffset:offset];
    
    if( _animator )
    {
        _animator->update_x( [self offset_x:offset], [self content_x] );
        _animator->update_y( [self offset_y:offset], [self content_y] );
    }
}

-(float)offset_x:(CGPoint)offset
{
    return offset.x;
}

-(float)offset_y:(CGPoint)offset
{
    return offset.y;
}

-(float)content_x
{
    return self.contentSize.width - self.frame.size.width;
}

-(float)content_y
{
    return self.contentSize.height - self.frame.size.height;
}

@end
