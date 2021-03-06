//
//  JL_Handle.h
//  JL_BLEKit
//
//  Created by zhihui liang on 2018/11/10.
//  Copyright © 2018 www.zh-jieli.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JL_BLEApple.h"
#import "JL_RCSP.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  收到设备返回的XM_PKG的回调。
 */
extern NSString *kJL_CMD_RECEIVE;       //XM_RCSP【接收】

@protocol JL_HandleDelegate <NSObject>
@optional
-(void)onHandleOutputPKG:(JL_PKG*)pkg;
@end

@interface JL_Handle : NSObject
@property(nonatomic,weak)id<JL_HandleDelegate>delegate;

+(id)sharedMe;

/**
 向设备发送JL_PKG数据包。
 
 @param pkg JL_PKG数据模型
 */
+(void)handleSendPackage:(JL_PKG*)pkg;

/**
 整理JL_PKG

 @param pkg JL_PKG数据模型
 @return 数据
 */
+(NSData*)handlePackage:(JL_PKG*)pkg;

/**
输入BLE数据
@param data  设备过来的数据
*/
-(void)inputHandleData:(NSData*)data;

/**[实例]
向设备发送JL_PKG数据包。
@param pkg JL_PKG数据模型
@param name 设备名字
*/
-(NSData*)sendPackage:(JL_PKG*)pkg WithName:(NSString*)name;

@end

NS_ASSUME_NONNULL_END
