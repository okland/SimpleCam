//
//  SimpleCam.h
//  SimpleCam
//
//  Created by Logan Wright on 2/1/14.
//  Copyright (c) 2014 Logan Wright. All rights reserved.
//
//  Mozilla Public License v2.0
//
//  **
//
//  PLEASE FAMILIARIZE YOURSELF WITH THE ----- Mozilla Public License v2.0
//
//  **
//
//  Attribution is satisfied by acknowledging the use of SimpleCam,
//  or its creation by Logan Wright
//
//  **
//
//  You can use, modify and redistribute this code in your product,
//  but to satisfy the requirements of Mozilla Public License v2.0,
//  it is required to provide the source code for any fixes you make to it.
//
//  **
//
//  Covered Software is provided under this License on an “as is” basis, without warranty of any
//  kind, either expressed, implied, or statutory, including, without limitation, warranties that
//  the Covered Software is free of defects, merchantable, fit for a particular purpose or non-
//  infringing. The entire risk as to the quality and performance of the Covered Software is with
//  You. Should any Covered Software prove defective in any respect, You (not any Contributor)
//  assume the cost of any necessary servicing, repair, or correction. This disclaimer of
//  warranty constitutes an essential part of this License. No use of any Covered Software is
//  authorized under this License except under this disclaimer.
//
//  **
//

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class SimpleCam;

@protocol SimpleCamDelegate

@required

- (void) simpleCamNotAuthorizedForCameraUse:(SimpleCam *)simpleCam;

/*!
 Called when the user is done with SimpleCam.  If image is nil, user backed out w/o image.
 */
- (void) simpleCam:(SimpleCam *)simpleCam didFinishWithImage:(UIImage *)image;

- (void) simpleCamUserCanceled:(SimpleCam *)simpleCam;

@optional

/*!
 Called when the camera is successfully loaded into the view.
 */
- (void) simpleCamDidLoadCameraIntoView:(SimpleCam *)simpleCam;

@end

@interface SimpleCam : UIViewController

/*!
 Must adhere to SimpleCamDelegate protocol
 */
@property (retain, nonatomic) id <SimpleCamDelegate> delegate;

/*!
 Used if you'd like your pictures cropped to squareMode - defaults to NO (beta)
 */
@property BOOL isSquareMode;

/*!
 Allow to hide all controls (set to YES to show custom controls)
 */
@property (nonatomic) BOOL hideAllControls;
/*!
 Allow to hide the capture button. You can take programmaticaly photo using method 'capturePhoto'
 */
@property (nonatomic) BOOL hideCaptureButton;
/*!
 Allow to hide the back button. Used if you want to programmatically control the view flow
 */
@property (nonatomic) BOOL hideBackButton;
/*!
 Allow to hide the flash camera button Used if you don't want to allow flash
 */
@property (nonatomic) BOOL hideFlashButton;
/*!
 Allow to hide the flash camera button Used if you don't want to allow flash
 */
@property (nonatomic) BOOL showBluredBackground;

/*!
 Don't show the preview phase of the photo acquisition
 */
@property (nonatomic) BOOL disablePhotoPreview;
/*!
 allow using front camera
 */
@property (nonatomic) BOOL disableFrontCamera;
/*!
 allow using back camera
 */
@property (nonatomic) BOOL disableRearCamera;
/*!
 Control animation duration
 */
@property (nonatomic) float controlAnimateDuration;

@property (nonatomic) CGRect cropRect;

/*!
 Use this to close SimpleCam - Otherwise, the captureSession may not close properly and may result in memory leaks.
 */
- (void) closeWithCompletion:(void (^)(void))completion;

/*!
 Use this method for programmatically acquire a photo
 */
- (void) capturePhoto;

- (void) switchCameraBtnPressed:(id)sender;

- (void) backBtnPressed:(id)sender;

-(void) userReturnWithNoPicture;

- (void) photoCaptured;

@end
