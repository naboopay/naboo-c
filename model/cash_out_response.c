#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_out_response.h"


char* cash_out_response_status_ToString(nabooapi_v1_cash_out_response__e status) {
    char* statusArray[] =  { "NULL", "pending", "paid", "done", "part_paid" };
    return statusArray[status];
}

nabooapi_v1_cash_out_response__e cash_out_response_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "pending", "paid", "done", "part_paid" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cash_out_response_t *cash_out_response_create(
    char *phone_number,
    int amount,
    char *full_name,
    transaction_status_enum_t *status
    ) {
    cash_out_response_t *cash_out_response_local_var = malloc(sizeof(cash_out_response_t));
    if (!cash_out_response_local_var) {
        return NULL;
    }
    cash_out_response_local_var->phone_number = phone_number;
    cash_out_response_local_var->amount = amount;
    cash_out_response_local_var->full_name = full_name;
    cash_out_response_local_var->status = status;

    return cash_out_response_local_var;
}


void cash_out_response_free(cash_out_response_t *cash_out_response) {
    if(NULL == cash_out_response){
        return ;
    }
    listEntry_t *listEntry;
    if (cash_out_response->phone_number) {
        free(cash_out_response->phone_number);
        cash_out_response->phone_number = NULL;
    }
    if (cash_out_response->full_name) {
        free(cash_out_response->full_name);
        cash_out_response->full_name = NULL;
    }
    if (cash_out_response->status) {
        transaction_status_enum_free(cash_out_response->status);
        cash_out_response->status = NULL;
    }
    free(cash_out_response);
}

cJSON *cash_out_response_convertToJSON(cash_out_response_t *cash_out_response) {
    cJSON *item = cJSON_CreateObject();

    // cash_out_response->phone_number
    if (!cash_out_response->phone_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone_number", cash_out_response->phone_number) == NULL) {
    goto fail; //String
    }


    // cash_out_response->amount
    if (!cash_out_response->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", cash_out_response->amount) == NULL) {
    goto fail; //Numeric
    }


    // cash_out_response->full_name
    if (!cash_out_response->full_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "full_name", cash_out_response->full_name) == NULL) {
    goto fail; //String
    }


    // cash_out_response->status
    if (nabooapi_v1_cash_out_response__NULL == cash_out_response->status) {
        goto fail;
    }
    cJSON *status_local_JSON = transaction_status_enum_convertToJSON(cash_out_response->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cash_out_response_t *cash_out_response_parseFromJSON(cJSON *cash_out_responseJSON){

    cash_out_response_t *cash_out_response_local_var = NULL;

    // define the local variable for cash_out_response->status
    transaction_status_enum_t *status_local_nonprim = NULL;

    // cash_out_response->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(cash_out_responseJSON, "phone_number");
    if (!phone_number) {
        goto end;
    }

    
    if(!cJSON_IsString(phone_number))
    {
    goto end; //String
    }

    // cash_out_response->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(cash_out_responseJSON, "amount");
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }

    // cash_out_response->full_name
    cJSON *full_name = cJSON_GetObjectItemCaseSensitive(cash_out_responseJSON, "full_name");
    if (!full_name) {
        goto end;
    }

    
    if(!cJSON_IsString(full_name))
    {
    goto end; //String
    }

    // cash_out_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(cash_out_responseJSON, "status");
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = transaction_status_enum_parseFromJSON(status); //custom


    cash_out_response_local_var = cash_out_response_create (
        strdup(phone_number->valuestring),
        amount->valuedouble,
        strdup(full_name->valuestring),
        status_local_nonprim
        );

    return cash_out_response_local_var;
end:
    if (status_local_nonprim) {
        transaction_status_enum_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
