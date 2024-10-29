#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wallet.h"


char* wallet_wallet_ToString(nabooapi_v1_wallet__e wallet) {
    char *walletArray[] =  { "NULL", "WAVE", "ORANGE_MONEY", "FREE_MONEY" };
    return walletArray[wallet];
}

nabooapi_v1_wallet__e wallet_wallet_FromString(char* wallet) {
    int stringToReturn = 0;
    char *walletArray[] =  { "NULL", "WAVE", "ORANGE_MONEY", "FREE_MONEY" };
    size_t sizeofArray = sizeof(walletArray) / sizeof(walletArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(wallet, walletArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *wallet_wallet_convertToJSON(nabooapi_v1_wallet__e wallet) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "wallet", wallet_wallet_ToString(wallet)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

nabooapi_v1_wallet__e wallet_wallet_parseFromJSON(cJSON *walletJSON) {
    nabooapi_v1_wallet__e *wallet = NULL;
    nabooapi_v1_wallet__e walletVariable;
    cJSON *walletVar = cJSON_GetObjectItemCaseSensitive(walletJSON, "wallet");
    if(!cJSON_IsString(walletVar) || (walletVar->valuestring == NULL)){
        goto end;
    }
    walletVariable = wallet_wallet_FromString(walletVar->valuestring);
    return walletVariable;
end:
    return 0;
}
