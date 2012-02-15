//
//  SMDatabase.h
//  CocoaSQLMapper
//
//  Copyright 2010-2012 Kenji Nishishiro. All rights reserved.
//  Written by Kenji Nishishiro <marvel@programmershigh.org>.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

NSString *const SMDatabaseErrorDomain;

@interface SMBindParameter : NSObject {
    int _index;
    NSString *_name;
    NSString *_type;
}

@property (nonatomic) int index;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *type;

@end

@interface SMColumn : NSObject {
    int _index;
    NSString *_name;
    NSString *_type;
}

@property (nonatomic) int index;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *type;

@end

@interface SMDatabase : NSObject {
	sqlite3 *_sqlite3;
}

- (id)initWithPath:(NSString *)path error:(NSError **)error;

- (id)selectObjectBySQL:(NSString *)SQL parameter:(id)parameter resultClass:(Class)resultClass error:(NSError **)error;
- (NSArray *)selectArrayBySQL:(NSString *)SQL parameter:(id)parameter resultClass:(Class)resultClass error:(NSError **)error;

- (BOOL)selectWithBlock:(BOOL (^)(id rst, NSError **err))block bySQL:(NSString *)SQL parameter:(id)parameter resultClass:(Class)resultClass error:(NSError **)error;

- (long long int)insertBySQL:(NSString *)SQL parameter:(id)parameter error:(NSError **)error;
- (int)updateBySQL:(NSString *)SQL parameter:(id)parameter error:(NSError **)error;
- (int)deleteBySQL:(NSString *)SQL parameter:(id)parameter error:(NSError **)error;

- (BOOL)executeBySQL:(NSString *)SQL parameter:(id)parameter error:(NSError **)error;

- (BOOL)transactionWithBlock:(BOOL (^)(NSError **err))block error:(NSError **)error;

@end
