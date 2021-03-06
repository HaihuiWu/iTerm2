//
//  iTermKeyMappingViewController.h
//  iTerm
//
//  Created by George Nachman on 4/7/14.
//
//

#import <Cocoa/Cocoa.h>

@class iTermKeyMappingViewController;
@class iTermPreferencesBaseViewController;

@protocol iTermKeyMappingViewControllerDelegate <NSObject>

- (NSDictionary *)keyMappingDictionary:(iTermKeyMappingViewController *)viewController;

- (NSArray *)keyMappingSortedKeys:(iTermKeyMappingViewController *)viewController;
- (NSArray *)keyMappingSortedTouchBarKeys:(iTermKeyMappingViewController *)viewController;

- (NSDictionary *)keyMappingTouchBarItems;

- (void)keyMapping:(iTermKeyMappingViewController *)viewController
      didChangeKey:(NSString *)keyCombo
    isTouchBarItem:(BOOL)isTouchBarItem
           atIndex:(NSInteger)index
          toAction:(int)action
         parameter:(NSString *)parameter
             label:(NSString *)label
        isAddition:(BOOL)addition;

- (void)keyMapping:(iTermKeyMappingViewController *)viewController
 removeKeyMappings:(NSSet<NSString *> *)keyCombos
     touchBarItems:(NSSet<NSString *> *)touchBarItems;

- (NSArray *)keyMappingPresetNames:(iTermKeyMappingViewController *)viewController;

- (void)keyMapping:(iTermKeyMappingViewController *)viewController
    loadPresetsNamed:(NSString *)presetName;

- (BOOL)keyMapping:(iTermKeyMappingViewController *)viewController shouldImportKeys:(NSSet<NSString *> *)keys;

@end

@interface iTermKeyMappingViewController : NSViewController <
    NSTableViewDelegate,
    NSTableViewDataSource>

@property(nonatomic, weak) IBOutlet id<iTermKeyMappingViewControllerDelegate> delegate;
@property(nonatomic, strong) IBOutlet NSView *placeholderView;
@property(nonatomic) BOOL hapticFeedbackForEscEnabled;
@property(nonatomic) BOOL soundForEscEnabled;
@property(nonatomic) BOOL visualIndicatorForEscEnabled;

- (void)hideAddTouchBarItem;
- (void)addViewsToSearchIndex:(iTermPreferencesBaseViewController *)vc;
- (NSNumber *)removeBeforeLoading:(NSString *)thing;

@end
