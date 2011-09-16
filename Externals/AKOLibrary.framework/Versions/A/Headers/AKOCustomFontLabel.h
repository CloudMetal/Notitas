//
//  AKOCustomFontView.h
//  AKOLibrary
//
//  Created by Adrian on 6/19/10.
//  Copyright (c) 2009, 2010, 2011, Adrian Kosmaczewski & akosma software
//  All rights reserved.
//  
//  Use in source and/or binary forms without modification is permitted following the
//  instructions in the LICENSE file.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
//  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
//  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
//  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
//  OF THE POSSIBILITY OF SUCH DAMAGE.
//

/**
 @file AKOCustomFontLabel.h
 Definition of the AKOCustomFontLabel class.
 */

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

/**
 Label which can use any CTFontRef loaded from the current bundle.
 This class represents a label that can load any CTFontRef object
 loaded from the current bundle. It shows automatically an ellipsis
 at the end of the text if the text to be shown is too long to fit.
 This class has an interface purposedly similar to that of UILabel.
 */
@interface AKOCustomFontLabel : UIView 
{
@private
    CTFontRef _font;
    NSString *_text;
    UIColor *_textColor;
    UIColor *_shadowColor;
    CGSize _shadowOffset;
    AKOCustomFontLabel *_shadowSubview;
    BOOL _multiline;
    CGFloat _margin;
    CGFloat _maximumLineHeight;
}

/**
 The text to be shown in the label.
 */
@property (nonatomic, copy) NSString *text;

/**
 The color of the text in the label.
 */
@property (nonatomic, retain) UIColor *textColor;

/**
 The color of the shadow of the text in the label.
 */
@property (nonatomic, retain) UIColor *shadowColor;

/**
 The offset of the shadow of the text in the label.
 */
@property (nonatomic, assign) CGSize shadowOffset;

/**
 Specifies whether the current instance displays text in several lines or not.
 */
@property (nonatomic, getter = isMultiline) BOOL multiline;

/**
 Margin used to draw multiline strings.
 The default value is 0.0.
 */
@property (nonatomic) CGFloat margin;

/**
 The maximum line height of the text to be rendered.
 */
@property (nonatomic) CGFloat maximumLineHeight;

/**
 Returns the CTFontRef object used to format the text in the label.
 The CTFontRef object is retained and owned by the current instance.
 @return A CTFontRef object.
 */
- (CTFontRef)font;

/**
 Sets the CTFontRef object used to format the text in the label.
 The CTFontRef object is retained and owned by the current instance.
 @param customFont A CTFontRef object.
 */
- (void)setFont:(CTFontRef)customFont;

@end