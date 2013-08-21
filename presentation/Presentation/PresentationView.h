//
//  PresentationView.h
//  Smart Presentation
//
//  Created by Daher Alfawares on 7/9/13.
//  Copyright (c) 2013 Daher Alfawares. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PresentationView : UIView
@property (nonatomic,strong) NSString* presentationTitle;
@property (nonatomic,strong) NSString* presentationSignature;


-(void)addViewWithNibNamed:(NSString*)name;
-(void)addViewWithImageNamed:(NSString*)name;
@end
