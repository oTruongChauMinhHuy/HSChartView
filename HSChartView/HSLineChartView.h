//
//  HSLineChartView.h
//  Account
//
//  Created by HuyTCM1 on 9/20/16.
//  Copyright © 2016 huytcm. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HSLineChartConstants.h"
#import "HSLineChartViewLine.h"

@protocol HSLineChartViewDataSource,HSLineChartViewDelegate;

@interface HSLineChartView : UIScrollView

    @property (nonatomic, weak, nullable) id <HSLineChartViewDataSource> dataSource;
    @property (nonatomic, weak, nullable) id <HSLineChartViewDelegate, UIScrollViewDelegate> delegate;
    @property (nonatomic, nullable) UIColor *axisColor;
    @property (nonatomic) CGFloat lineWidth; // default 1.0f

    @property (nonatomic, readonly) CGFloat maxVerticalValue;
    @property (strong, nonatomic, nullable) NSString *verticalLabel;
    @property (nonatomic, readonly) CGFloat maxHorizontalValue;
    @property (strong, nonatomic, nullable) NSString *horizontalLabel;
    @property (nonatomic) CGFloat horizontalUnitWidth;
    @property (nonatomic) CGFloat verticalUnitWidth;

    // label font
    @property (nonatomic) CGFloat fontSize;

@end

@protocol HSLineChartViewDataSource<NSObject>
    @required
- (nonnull HSLineChartViewLine *)chartView:(nonnull HSLineChartView *)chartView lineAtIndex:(NSInteger)index;

    @optional
    
@end

@protocol HSLineChartViewDelegate<UIScrollViewDelegate>
    @optional
- (NSInteger)numberOfLineInChartView:(nonnull HSLineChartView *)chartView;
- (nullable UIColor *)colorOfLine:(NSInteger)line;

@end
