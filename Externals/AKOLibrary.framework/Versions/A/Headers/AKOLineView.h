//
//  AKOLineView.h
//  AKOLibrary
//
//  Created by Adrian on 5/16/11.
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
 @file AKOLineView.h
 Includes the definition of the AKOLineView class.
 */

#import <UIKit/UIKit.h>

typedef enum {
    AKOLineViewModeStroke = 0,
    AKOLineViewModeFill = 1
} AKOLineViewMode;

/**
 Subclass of UIView that draws a line going through all the points specified 
 in the "points" array. Users can specify the line color, the width and the 
 line mode.
 */
@interface AKOLineView : UIView 

/**
 The points through which the line goes through. This array contains CGPoints
 wrapped as NSValues.
 */
@property (nonatomic, copy) NSArray *points;

/**
 The color of the line.
 */
@property (nonatomic, retain) UIColor *color;

/**
 The width of the line.
 */
@property (nonatomic) CGFloat width;

/**
 The mode of the line. When set to "AKOLineViewModeFill", the line will
 be filled as a polygon.
 */
@property (nonatomic) AKOLineViewMode mode;

@end
