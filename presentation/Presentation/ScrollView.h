//
//  ScrollView.h
//  Solstice-Mobile
//
//  Created by Daher Alfawares on 6/17/13.
//  Copyright (c) 2013 Daher Alfawares. All rights reserved.
//

#include "DA_ScrollView.hpp"
#include "FullscreenBounceAnimator.hpp"
#include "ThumbnailAnimator.hpp"

#include <UIKit/UIKit.h>

@interface ScrollView : DAScrollView {
    DA::Animator    fullscreenAnimator;
    DA::Animator    thumbnailAnimator;
}

-(void)addView:(UIView*)view;

@end
