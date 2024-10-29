#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_account_response.h"


char* get_account_response_method_of_payment_ToString(nabooapi_v1_get_account_response__e method_of_payment) {
    char* method_of_paymentArray[] =  { "NULL", "WAVE", "ORANGE_MONEY", "FREE_MONEY" };
    return method_of_paymentArray[method_of_payment];
}

nabooapi_v1_get_account_response__e get_account_response_method_of_payment_FromString(char* method_of_payment){
    int stringToReturn = 0;
    char *method_of_paymentArray[] =  { "NULL", "WAVE", "ORANGE_MONEY", "FREE_MONEY" };
    size_t sizeofArray = sizeof(method_of_paymentArray) / sizeof(method_of_paymentArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(method_of_payment, method_of_paymentArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

get_account_response_t *get_account_response_create(
    char *account_number,
    double balance,
    int account_is_activate,
    wallet_t *method_of_payment,
    int loyalty_credit
    ) {
    get_account_response_t *get_account_response_local_var = malloc(sizeof(get_account_response_t));
    if (!get_account_response_local_var) {
        return NULL;
    }
    get_account_response_local_var->account_number = account_number;
    get_account_response_local_var->balance = balance;
    get_account_response_local_var->account_is_activate = account_is_activate;
    get_account_response_local_var->method_of_payment = method_of_payment;
    get_account_response_local_var->loyalty_credit = loyalty_credit;

    return get_account_response_local_var;
}


void get_account_response_free(get_account_response_t *get_account_response) {
    if(NULL == get_account_response){
        return ;
    }
    listEntry_t *listEntry;
    if (get_account_response->account_number) {
        free(get_account_response->account_number);
        get_account_response->account_number = NULL;
    }
    if (get_account_response->method_of_payment) {
        wallet_free(get_account_response->method_of_payment);
        get_account_response->method_of_payment = NULL;
    }
    free(get_account_response);
}

cJSON *get_account_response_convertToJSON(get_account_response_t *get_account_response) {
    cJSON *item = cJSON_CreateObject();

    // get_account_response->account_number
    if (!get_account_response->account_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "account_number", get_account_response->account_number) == NULL) {
    goto fail; //String
    }


    // get_account_response->balance
    if (!get_account_response->balance) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "balance", get_account_response->balance) == NULL) {
    goto fail; //Numeric
    }


    // get_account_response->account_is_activate
    if (!get_account_response->account_is_activate) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "account_is_activate", get_account_response->account_is_activate) == NULL) {
    goto fail; //Bool
    }


    // get_account_response->method_of_payment
    if (nabooapi_v1_get_account_response__NULL == get_account_response->method_of_payment) {
        goto fail;
    }
    cJSON *method_of_payment_local_JSON = wallet_convertToJSON(get_account_response->method_of_payment);
    if(method_of_payment_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "method_of_payment", method_of_payment_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // get_account_response->loyalty_credit
    if (!get_account_response->loyalty_credit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "loyalty_credit", get_account_response->loyalty_credit) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_account_response_t *get_account_response_parseFromJSON(cJSON *get_account_responseJSON){

    get_account_response_t *get_account_response_local_var = NULL;

    // define the local variable for get_account_response->method_of_payment
    wallet_t *method_of_payment_local_nonprim = NULL;

    // get_account_response->account_number
    cJSON *account_number = cJSON_GetObjectItemCaseSensitive(get_account_responseJSON, "account_number");
    if (!account_number) {
        goto end;
    }

    
    if(!cJSON_IsString(account_number))
    {
    goto end; //String
    }

    // get_account_response->balance
    cJSON *balance = cJSON_GetObjectItemCaseSensitive(get_account_responseJSON, "balance");
    if (!balance) {
        goto end;
    }

    
    if(!cJSON_IsNumber(balance))
    {
    goto end; //Numeric
    }

    // get_account_response->account_is_activate
    cJSON *account_is_activate = cJSON_GetObjectItemCaseSensitive(get_account_responseJSON, "account_is_activate");
    if (!account_is_activate) {
        goto end;
    }

    
    if(!cJSON_IsBool(account_is_activate))
    {
    goto end; //Bool
    }

    // get_account_response->method_of_payment
    cJSON *method_of_payment = cJSON_GetObjectItemCaseSensitive(get_account_responseJSON, "method_of_payment");
    if (!method_of_payment) {
        goto end;
    }

    
    method_of_payment_local_nonprim = wallet_parseFromJSON(method_of_payment); //custom

    // get_account_response->loyalty_credit
    cJSON *loyalty_credit = cJSON_GetObjectItemCaseSensitive(get_account_responseJSON, "loyalty_credit");
    if (!loyalty_credit) {
        goto end;
    }

    
    if(!cJSON_IsNumber(loyalty_credit))
    {
    goto end; //Numeric
    }


    get_account_response_local_var = get_account_response_create (
        strdup(account_number->valuestring),
        balance->valuedouble,
        account_is_activate->valueint,
        method_of_payment_local_nonprim,
        loyalty_credit->valuedouble
        );

    return get_account_response_local_var;
end:
    if (method_of_payment_local_nonprim) {
        wallet_free(method_of_payment_local_nonprim);
        method_of_payment_local_nonprim = NULL;
    }
    return NULL;

}
