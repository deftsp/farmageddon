//
//  EAGLView.h
//  gambit-iphone
//
//  Created by James on 4/22/09.
//  Copyright Coptix, Inc 2009. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

@interface TextFieldDoneDelegate : NSObject
- (bool)textFieldShouldReturn:(UITextField*)field;
@end

@interface EAGLView : UIView {
	
@private
	/* The pixel dimensions of the backbuffer */
	GLint backingWidth;
	GLint backingHeight;
	
	EAGLContext *context;
	
	/* OpenGL names for the renderbuffer and framebuffers used to render to this view */
	GLuint viewRenderbuffer, viewFramebuffer;
	
	/* OpenGL name for the depth buffer that is attached to viewFramebuffer, if it exists (0 if it does not exist) */
	GLuint depthRenderbuffer;
	
	NSTimer *animationTimer;
	NSTimeInterval animationInterval;

	IBOutlet UITextField *highScoreName;
        IBOutlet UIButton *infoButton;
        UIAlertView *infoAlert;
}

@property NSTimeInterval animationInterval;
                              
- (void)startAnimation;
- (void)stopAnimation;
- (void)drawView;
- (void)gotoFullVersion;
- (void)showInfoButton;
- (IBAction)showInfo;
- (BOOL)isHighRes;
- (void)hideInfoButton;
- (void)hideHighScoreField;
- (void)showHighScoreField:(int)x y:(int)y;
- (char*)highScoreFieldValue;

@end
