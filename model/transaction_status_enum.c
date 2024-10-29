#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_status_enum.h"


char* transaction_status_enum_transaction_status_enum_ToString(nabooapi_v1_transaction_status_enum__e transaction_status_enum) {
    char *transaction_status_enumArray[] =  { "NULL", "pending", "paid", "done", "part_paid" };
    return transaction_status_enumArray[transaction_status_enum];
}

nabooapi_v1_transaction_status_enum__e transaction_status_enum_transaction_status_enum_FromString(char* transaction_status_enum) {
    int stringToReturn = 0;
    char *transaction_status_enumArray[] =  { "NULL", "pending", "paid", "done", "part_paid" };
    size_t sizeofArray = sizeof(transaction_status_enumArray) / sizeof(transaction_status_enumArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(transaction_status_enum, transaction_status_enumArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *transaction_status_enum_transaction_status_enum_convertToJSON(nabooapi_v1_transaction_status_enum__e transaction_status_enum) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "transaction_status_enum", transaction_status_enum_transaction_status_enum_ToString(transaction_status_enum)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

nabooapi_v1_transaction_status_enum__e transaction_status_enum_transaction_status_enum_parseFromJSON(cJSON *transaction_status_enumJSON) {
    nabooapi_v1_transaction_status_enum__e *transaction_status_enum = NULL;
    nabooapi_v1_transaction_status_enum__e transaction_status_enumVariable;
    cJSON *transaction_status_enumVar = cJSON_GetObjectItemCaseSensitive(transaction_status_enumJSON, "transaction_status_enum");
    if(!cJSON_IsString(transaction_status_enumVar) || (transaction_status_enumVar->valuestring == NULL)){
        goto end;
    }
    transaction_status_enumVariable = transaction_status_enum_transaction_status_enum_FromString(transaction_status_enumVar->valuestring);
    return transaction_status_enumVariable;
end:
    return 0;
}
