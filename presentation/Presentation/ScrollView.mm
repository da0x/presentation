//
//  ScrollView.m
//  Solstice-Mobile
//
//  Created by Daher Alfawares on 6/17/13.
//  Copyright (c) 2013 Daher Alfawares. All rights reserved.
//

#import "ScrollView.h"
#import <QuartzCore/QuartzCore.h>


@interface ScrollView()
@property (nonatomic) bool pinched;
@end

@implementation ScrollView

- (id)initWithCoder:(NSCoder *)aDecoder
{
    self = [super initWithCoder:aDecoder];
    if (self) {
        self.pagingEnabled = 1;        
        
        UIPinchGestureRecognizer* pinch = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(viewPinched:)];
        [self addGestureRecognizer:pinch];
    }
    return self;
}

-(void)addView:(UIView*)view
{
    float width  = self.frame.size.width;
    float height = self.frame.size.height;

    int   index         = fullscreenAnimator.size();
    float offset        = index  * width;

        // update frame.
    CGRect viewFrame   = { offset, 0, width, height };
    view.frame = viewFrame;
    
        // update content size.
    CGSize contentSize = { offset + width,   height };
    self.contentSize = contentSize;
    
        // ready, add it to super.
    fullscreenAnimator.add( DA::View::pointer_type( new DA::FullscreenBounceAnimator( view ) ) );
    thumbnailAnimator.add( DA::View::pointer_type( new DA::ThumbnailAnimator( view ) ) );
    
        // add view
    [self addSubview:view];
    
        // setup touch
    UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(viewTapped:)];
    [view addGestureRecognizer:tap];
}

-(void)setPinched:(bool)pinched
{
    if( _pinched != pinched )
    {
        _pinched = pinched;
        if( pinched )
        {
            self.animator = &thumbnailAnimator;
            self.pagingEnabled = false;
        }
        else
        {
            self.animator = &fullscreenAnimator;
            self.pagingEnabled = true;
        }
    }
}

-(void)viewPinched:(id)sender
{
    self.pinched = true;
}

-(void)viewTapped:(UITapGestureRecognizer*)gesture
{
    self.pinched = false;
    [self setContentOffset:gesture.view.frame.origin];
}

@end


