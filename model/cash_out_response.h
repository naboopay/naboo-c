/*
 * cash_out_response.h
 *
 * 
 */

#ifndef _cash_out_response_H_
#define _cash_out_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_out_response_t cash_out_response_t;

#include "transaction_status_enum.h"

// Enum  for cash_out_response

typedef enum  { nabooapi_v1_cash_out_response__NULL = 0, nabooapi_v1_cash_out_response__pending, nabooapi_v1_cash_out_response__paid, nabooapi_v1_cash_out_response__done, nabooapi_v1_cash_out_response__part_paid } nabooapi_v1_cash_out_response__e;

char* cash_out_response_status_ToString(nabooapi_v1_cash_out_response__e status);

nabooapi_v1_cash_out_response__e cash_out_response_status_FromString(char* status);



typedef struct cash_out_response_t {
    char *phone_number; // string
    int amount; //numeric
    char *full_name; // string
    transaction_status_enum_t *status; // custom

} cash_out_response_t;

cash_out_response_t *cash_out_response_create(
    char *phone_number,
    int amount,
    char *full_name,
    transaction_status_enum_t *status
);

void cash_out_response_free(cash_out_response_t *cash_out_response);

cash_out_response_t *cash_out_response_parseFromJSON(cJSON *cash_out_responseJSON);

cJSON *cash_out_response_convertToJSON(cash_out_response_t *cash_out_response);

#endif /* _cash_out_response_H_ */

