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
