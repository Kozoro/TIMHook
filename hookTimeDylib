#import "hook_iluoliDylib.h"
#import <CaptainHook/CaptainHook.h>
#import <UIKit/UIKit.h>
#import <Cycript/Cycript.h>
#import <MDCycriptManager.h>
#import <FLEX/FLEXManager.h>
#import <AFNetworking/AFNetworking.h>
#import <ReactiveObjC/ReactiveObjC.h>
#import "hex.h"

CHDeclareClass(OpenSSLECDHWrapper)
CHDeclareClass(WloginSdk_v2)

CHConstructor{
    NSLog(INSERT_SUCCESS_WELCOME);
    
    [[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationDidFinishLaunchingNotification object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * _Nonnull note) {
        [[FLEXManager sharedManager] showExplorer];
        
        CYListenServer(6666);
        
    }];
}


//Hook Tim QQ 方法
CHMethod5(int, OpenSSLECDHWrapper, geneECDHShareKey, char*, arg1, andSvrPubKey, char*, arg2, andSvrPubKeyLen, unsigned int, arg3, andCliPrivKey, char*, arg4, andCliPrivKeyLen, int, arg5 ){
    NSLog(@"iosqqhook:geneECDHShareKey pubkey=%@ pubkeyLen=%u prikey=%@ prikeyLen=%u out=%@",
          [NSString hexStringWithData:(unsigned char*)arg2 ofLength:(int)arg3],
          arg3,
          [NSString hexStringWithData:(unsigned char*)arg4 ofLength:arg5],
          arg5,
          [NSString hexStringWithData:(unsigned char*)arg1 ofLength:16]
          );
    CHSuper5(OpenSSLECDHWrapper, geneECDHShareKey, arg1, andSvrPubKey, arg2, andSvrPubKeyLen, arg3, andCliPrivKey, arg4, andCliPrivKeyLen, arg5);
}
CHMethod5(int, WloginSdk_v2, initECDHShareKey, char*, arg1, andCliPubKey, char*, arg2, andCliPubKeyLen, unsigned int *, arg3, andCliPrivKey, char*, arg4, andCliPrivKeyLen, unsigned int *, arg5){
    NSLog(@"iosqqhook:initECDHShareKey pubkey=%@ pubkeyLen=%u prikey=%@ prikeyLen=%u out=%@",
          [NSString hexStringWithData:(unsigned char*)arg2 ofLength:(int)(*arg3)],
          *arg3,
          [NSString hexStringWithData:(unsigned char*)arg4 ofLength:(int)(*arg5)],
          *arg5,
          [NSString hexStringWithData:(unsigned char*)arg1 ofLength:16]
          );
    CHSuper5(WloginSdk_v2, initECDHShareKey, arg1, andCliPubKey, arg2, andCliPubKeyLen, arg3, andCliPrivKey, arg4, andCliPrivKeyLen, arg5);
}

CHConstructor{
    CHLoadLateClass(OpenSSLECDHWrapper);
    CHLoadLateClass(WloginSdk_v2);
    //注册
    CHClassHook5(OpenSSLECDHWrapper, geneECDHShareKey, andSvrPubKey, andSvrPubKeyLen, andCliPrivKey, andCliPrivKeyLen);
    CHClassHook5(WloginSdk_v2, initECDHShareKey, andCliPubKey, andCliPubKeyLen, andCliPrivKey, andCliPrivKeyLen);
}
