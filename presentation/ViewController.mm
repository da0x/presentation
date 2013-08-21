//
//  ViewController.m
//  Solstice-Mobile
//
//  Created by Daher Alfawares on 6/17/13.
//  Copyright (c) 2013 Daher Alfawares. All rights reserved.
//

#import "ViewController.h"
#import "PresentationView.h"

@interface ViewController()
@property (nonatomic,weak) IBOutlet PresentationView* view;
@end

@implementation ViewController
-(void)awakeFromNib
{
    [super awakeFromNib];
    
    [self.view addViewWithNibNamed:@"v1-iPhone"];
    [self.view addViewWithImageNamed:@"01_Breakfast"];
    [self.view addViewWithImageNamed:@"02_Lunch"];
    [self.view addViewWithImageNamed:@"03_Night"];
    [self.view addViewWithImageNamed:@"04_Menu"];
    [self.view addViewWithImageNamed:@"05_Locations"];
    [self.view addViewWithImageNamed:@"01_Breakfast"];
    [self.view addViewWithImageNamed:@"02_Lunch"];
    [self.view addViewWithImageNamed:@"03_Night"];
    [self.view addViewWithImageNamed:@"04_Menu"];
    [self.view addViewWithImageNamed:@"05_Locations"];
    [self.view addViewWithImageNamed:@"01_Breakfast"];
    [self.view addViewWithImageNamed:@"02_Lunch"];
    [self.view addViewWithImageNamed:@"03_Night"];
    [self.view addViewWithImageNamed:@"04_Menu"];
    [self.view addViewWithImageNamed:@"05_Locations"];
}
@end
