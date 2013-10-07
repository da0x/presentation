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

#include <UIKit/UIKit.h>

@interface DynamicScrollView : DAScrollView {
    DA::Animator    dynamicAnimator;
}

-(void)prepareIntro;
-(void)animateIntro;
-(void)addView:(UIView*)view;
-(void)addDynamicView:(UIView*)view;
-(void)addFastDynamicView:(UIView*)view;
-(void)addThumbnailView:(UIView*)view;

-(void)scrollToPage:(int)page;

@end
