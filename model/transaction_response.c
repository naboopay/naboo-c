#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_response.h"



transaction_response_t *transaction_response_create(
    char *order_id,
    list_t *method_of_payment,
    int amount,
    int amount_to_pay,
    char *currency,
    char *created_at,
    char *transaction_status,
    int is_escrow,
    int is_merchant,
    char *checkout_url
    ) {
    transaction_response_t *transaction_response_local_var = malloc(sizeof(transaction_response_t));
    if (!transaction_response_local_var) {
        return NULL;
    }
    transaction_response_local_var->order_id = order_id;
    transaction_response_local_var->method_of_payment = method_of_payment;
    transaction_response_local_var->amount = amount;
    transaction_response_local_var->amount_to_pay = amount_to_pay;
    transaction_response_local_var->currency = currency;
    transaction_response_local_var->created_at = created_at;
    transaction_response_local_var->transaction_status = transaction_status;
    transaction_response_local_var->is_escrow = is_escrow;
    transaction_response_local_var->is_merchant = is_merchant;
    transaction_response_local_var->checkout_url = checkout_url;

    return transaction_response_local_var;
}


void transaction_response_free(transaction_response_t *transaction_response) {
    if(NULL == transaction_response){
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_response->order_id) {
        free(transaction_response->order_id);
        transaction_response->order_id = NULL;
    }
    if (transaction_response->method_of_payment) {
        list_ForEach(listEntry, transaction_response->method_of_payment) {
            free(listEntry->data);
        }
        list_freeList(transaction_response->method_of_payment);
        transaction_response->method_of_payment = NULL;
    }
    if (transaction_response->currency) {
        free(transaction_response->currency);
        transaction_response->currency = NULL;
    }
    if (transaction_response->created_at) {
        free(transaction_response->created_at);
        transaction_response->created_at = NULL;
    }
    if (transaction_response->transaction_status) {
        free(transaction_response->transaction_status);
        transaction_response->transaction_status = NULL;
    }
    if (transaction_response->checkout_url) {
        free(transaction_response->checkout_url);
        transaction_response->checkout_url = NULL;
    }
    free(transaction_response);
}

cJSON *transaction_response_convertToJSON(transaction_response_t *transaction_response) {
    cJSON *item = cJSON_CreateObject();

    // transaction_response->order_id
    if (!transaction_response->order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_id", transaction_response->order_id) == NULL) {
    goto fail; //String
    }


    // transaction_response->method_of_payment
    if (!transaction_response->method_of_payment) {
        goto fail;
    }
    cJSON *method_of_payment = cJSON_AddArrayToObject(item, "method_of_payment");
    if(method_of_payment == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *method_of_paymentListEntry;
    list_ForEach(method_of_paymentListEntry, transaction_response->method_of_payment) {
    if(cJSON_AddStringToObject(method_of_payment, "", (char*)method_of_paymentListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // transaction_response->amount
    if(transaction_response->amount) {
    if(cJSON_AddNumberToObject(item, "amount", transaction_response->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // transaction_response->amount_to_pay
    if(transaction_response->amount_to_pay) {
    if(cJSON_AddNumberToObject(item, "amount_to_pay", transaction_response->amount_to_pay) == NULL) {
    goto fail; //Numeric
    }
    }


    // transaction_response->currency
    if (!transaction_response->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", transaction_response->currency) == NULL) {
    goto fail; //String
    }


    // transaction_response->created_at
    if (!transaction_response->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", transaction_response->created_at) == NULL) {
    goto fail; //String
    }


    // transaction_response->transaction_status
    if(transaction_response->transaction_status) {
    if(cJSON_AddStringToObject(item, "transaction_status", transaction_response->transaction_status) == NULL) {
    goto fail; //String
    }
    }


    // transaction_response->is_escrow
    if(transaction_response->is_escrow) {
    if(cJSON_AddBoolToObject(item, "is_escrow", transaction_response->is_escrow) == NULL) {
    goto fail; //Bool
    }
    }


    // transaction_response->is_merchant
    if(transaction_response->is_merchant) {
    if(cJSON_AddBoolToObject(item, "is_merchant", transaction_response->is_merchant) == NULL) {
    goto fail; //Bool
    }
    }


    // transaction_response->checkout_url
    if (!transaction_response->checkout_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "checkout_url", transaction_response->checkout_url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transaction_response_t *transaction_response_parseFromJSON(cJSON *transaction_responseJSON){

    transaction_response_t *transaction_response_local_var = NULL;

    // define the local list for transaction_response->method_of_payment
    list_t *method_of_paymentList = NULL;

    // transaction_response->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "order_id");
    if (!order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(order_id))
    {
    goto end; //String
    }

    // transaction_response->method_of_payment
    cJSON *method_of_payment = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "method_of_payment");
    if (!method_of_payment) {
        goto end;
    }

    
    cJSON *method_of_payment_local = NULL;
    if(!cJSON_IsArray(method_of_payment)) {
        goto end;//primitive container
    }
    method_of_paymentList = list_createList();

    cJSON_ArrayForEach(method_of_payment_local, method_of_payment)
    {
        if(!cJSON_IsString(method_of_payment_local))
        {
            goto end;
        }
        list_addElement(method_of_paymentList , strdup(method_of_payment_local->valuestring));
    }

    // transaction_response->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "amount");
    if (amount) { 
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }
    }

    // transaction_response->amount_to_pay
    cJSON *amount_to_pay = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "amount_to_pay");
    if (amount_to_pay) { 
    if(!cJSON_IsNumber(amount_to_pay))
    {
    goto end; //Numeric
    }
    }

    // transaction_response->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "currency");
    if (!currency) {
        goto end;
    }

    
    if(!cJSON_IsString(currency))
    {
    goto end; //String
    }

    // transaction_response->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "created_at");
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // transaction_response->transaction_status
    cJSON *transaction_status = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "transaction_status");
    if (transaction_status) { 
    if(!cJSON_IsString(transaction_status) && !cJSON_IsNull(transaction_status))
    {
    goto end; //String
    }
    }

    // transaction_response->is_escrow
    cJSON *is_escrow = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "is_escrow");
    if (is_escrow) { 
    if(!cJSON_IsBool(is_escrow))
    {
    goto end; //Bool
    }
    }

    // transaction_response->is_merchant
    cJSON *is_merchant = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "is_merchant");
    if (is_merchant) { 
    if(!cJSON_IsBool(is_merchant))
    {
    goto end; //Bool
    }
    }

    // transaction_response->checkout_url
    cJSON *checkout_url = cJSON_GetObjectItemCaseSensitive(transaction_responseJSON, "checkout_url");
    if (!checkout_url) {
        goto end;
    }

    
    if(!cJSON_IsString(checkout_url))
    {
    goto end; //String
    }


    transaction_response_local_var = transaction_response_create (
        strdup(order_id->valuestring),
        method_of_paymentList,
        amount ? amount->valuedouble : 0,
        amount_to_pay ? amount_to_pay->valuedouble : 0,
        strdup(currency->valuestring),
        strdup(created_at->valuestring),
        transaction_status && !cJSON_IsNull(transaction_status) ? strdup(transaction_status->valuestring) : NULL,
        is_escrow ? is_escrow->valueint : 0,
        is_merchant ? is_merchant->valueint : 0,
        strdup(checkout_url->valuestring)
        );

    return transaction_response_local_var;
end:
    if (method_of_paymentList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, method_of_paymentList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(method_of_paymentList);
        method_of_paymentList = NULL;
    }
    return NULL;

}
