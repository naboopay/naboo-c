#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_out_orange_request.h"



cash_out_orange_request_t *cash_out_orange_request_create(
    char *full_name,
    int amount,
    char *phone_number
    ) {
    cash_out_orange_request_t *cash_out_orange_request_local_var = malloc(sizeof(cash_out_orange_request_t));
    if (!cash_out_orange_request_local_var) {
        return NULL;
    }
    cash_out_orange_request_local_var->full_name = full_name;
    cash_out_orange_request_local_var->amount = amount;
    cash_out_orange_request_local_var->phone_number = phone_number;

    return cash_out_orange_request_local_var;
}


void cash_out_orange_request_free(cash_out_orange_request_t *cash_out_orange_request) {
    if(NULL == cash_out_orange_request){
        return ;
    }
    listEntry_t *listEntry;
    if (cash_out_orange_request->full_name) {
        free(cash_out_orange_request->full_name);
        cash_out_orange_request->full_name = NULL;
    }
    if (cash_out_orange_request->phone_number) {
        free(cash_out_orange_request->phone_number);
        cash_out_orange_request->phone_number = NULL;
    }
    free(cash_out_orange_request);
}

cJSON *cash_out_orange_request_convertToJSON(cash_out_orange_request_t *cash_out_orange_request) {
    cJSON *item = cJSON_CreateObject();

    // cash_out_orange_request->full_name
    if (!cash_out_orange_request->full_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "full_name", cash_out_orange_request->full_name) == NULL) {
    goto fail; //String
    }


    // cash_out_orange_request->amount
    if (!cash_out_orange_request->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", cash_out_orange_request->amount) == NULL) {
    goto fail; //Numeric
    }


    // cash_out_orange_request->phone_number
    if (!cash_out_orange_request->phone_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone_number", cash_out_orange_request->phone_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cash_out_orange_request_t *cash_out_orange_request_parseFromJSON(cJSON *cash_out_orange_requestJSON){

    cash_out_orange_request_t *cash_out_orange_request_local_var = NULL;

    // cash_out_orange_request->full_name
    cJSON *full_name = cJSON_GetObjectItemCaseSensitive(cash_out_orange_requestJSON, "full_name");
    if (!full_name) {
        goto end;
    }

    
    if(!cJSON_IsString(full_name))
    {
    goto end; //String
    }

    // cash_out_orange_request->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(cash_out_orange_requestJSON, "amount");
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }

    // cash_out_orange_request->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(cash_out_orange_requestJSON, "phone_number");
    if (!phone_number) {
        goto end;
    }

    
    if(!cJSON_IsString(phone_number))
    {
    goto end; //String
    }


    cash_out_orange_request_local_var = cash_out_orange_request_create (
        strdup(full_name->valuestring),
        amount->valuedouble,
        strdup(phone_number->valuestring)
        );

    return cash_out_orange_request_local_var;
end:
    return NULL;

}
