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
