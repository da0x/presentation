//
//  PresentationView.m
//  Smart Presentation
//
//  Created by Daher Alfawares on 7/9/13.
//  Copyright (c) 2013 Daher Alfawares. All rights reserved.
//

#import "PresentationView.h"

#import "ViewController.h"
#import "ScrollView.h"

@interface PresentationView ()
@property (nonatomic,weak) IBOutlet ScrollView* scrollView;
@property (nonatomic,weak) IBOutlet UILabel* signatureLabel;
@property (nonatomic,weak) IBOutlet UILabel* titleLabel;
@end

@implementation PresentationView

-(void)addViewWithNibNamed:(NSString*)name
{
    UIView* view = [[[NSBundle mainBundle] loadNibNamed:name owner:self options:nil] objectAtIndex:0];
    [self.scrollView addView:view];
}

-(void)addViewWithImageNamed:(NSString*)name {
    UIImageView* imageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:name]];
    [imageView setUserInteractionEnabled:true];
    [self.scrollView addView:imageView];
}

-(void)setPresentationTitle:(NSString *)presentationTitle
{
    _presentationTitle = presentationTitle;
    
    self.titleLabel.text = presentationTitle;
}

-(void)setPresentationSignature:(NSString *)presentationSignature
{
    _presentationSignature = presentationSignature;
    
    self.presentationSignature = presentationSignature;
}


@end
