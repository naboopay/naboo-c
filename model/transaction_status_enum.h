/*
 * transaction_status_enum.h
 *
 * 
 */

#ifndef _transaction_status_enum_H_
#define _transaction_status_enum_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_status_enum_t transaction_status_enum_t;


// Enum  for transaction_status_enum

typedef enum { nabooapi_v1_transaction_status_enum__NULL = 0, nabooapi_v1_transaction_status_enum__pending, nabooapi_v1_transaction_status_enum__paid, nabooapi_v1_transaction_status_enum__done, nabooapi_v1_transaction_status_enum__part_paid } nabooapi_v1_transaction_status_enum__e;

char* transaction_status_enum_transaction_status_enum_ToString(nabooapi_v1_transaction_status_enum__e transaction_status_enum);

nabooapi_v1_transaction_status_enum__e transaction_status_enum_transaction_status_enum_FromString(char* transaction_status_enum);

//cJSON *transaction_status_enum_transaction_status_enum_convertToJSON(nabooapi_v1_transaction_status_enum__e transaction_status_enum);

//nabooapi_v1_transaction_status_enum__e transaction_status_enum_transaction_status_enum_parseFromJSON(cJSON *transaction_status_enumJSON);

#endif /* _transaction_status_enum_H_ */

