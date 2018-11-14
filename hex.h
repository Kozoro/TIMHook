//
//  hex.h
//  hook.iluoli
//
//  Created by lishuai on 2018/11/14.
//  Copyright © 2018年 lishuai. All rights reserved.
//

#ifndef hex_h
#define hex_h
@implementation NSString (Hex)
+ (NSString*) hexStringWithData: (unsigned char*) data ofLength: (int) len
{
    NSMutableString *tmp = [NSMutableString string];
    for (int i=0; i<len; i++)
        [tmp appendFormat:@"%02X", data[i]];
    return [NSString stringWithString:tmp];
}
@end
#endif /* hex_h */
