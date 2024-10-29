/*
 * wallet.h
 *
 * 
 */

#ifndef _wallet_H_
#define _wallet_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct wallet_t wallet_t;


// Enum  for wallet

typedef enum { nabooapi_v1_wallet__NULL = 0, nabooapi_v1_wallet__WAVE, nabooapi_v1_wallet__ORANGE_MONEY, nabooapi_v1_wallet__FREE_MONEY } nabooapi_v1_wallet__e;

char* wallet_wallet_ToString(nabooapi_v1_wallet__e wallet);

nabooapi_v1_wallet__e wallet_wallet_FromString(char* wallet);

//cJSON *wallet_wallet_convertToJSON(nabooapi_v1_wallet__e wallet);

//nabooapi_v1_wallet__e wallet_wallet_parseFromJSON(cJSON *walletJSON);

#endif /* _wallet_H_ */

