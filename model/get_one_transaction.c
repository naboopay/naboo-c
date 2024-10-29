#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_one_transaction.h"


char* get_one_transaction_method_of_payment_ToString(nabooapi_v1_get_one_transaction__e method_of_payment) {
    char *method_of_paymentArray[] =  { "NULL", "WAVE", "ORANGE_MONEY", "FREE_MONEY" };
    return method_of_paymentArray[method_of_payment - 1];
}

nabooapi_v1_get_one_transaction__e get_one_transaction_method_of_payment_FromString(char* method_of_payment) {
    int stringToReturn = 0;
    char *method_of_paymentArray[] =  { "NULL", "WAVE", "ORANGE_MONEY", "FREE_MONEY" };
    size_t sizeofArray = sizeof(method_of_paymentArray) / sizeof(method_of_paymentArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(method_of_payment, method_of_paymentArray[stringToReturn]) == 0) {
            return stringToReturn + 1;
        }
        stringToReturn++;
    }
    return 0;
}
char* get_one_transaction_transaction_status_ToString(nabooapi_v1_get_one_transaction__e transaction_status) {
    char* transaction_statusArray[] =  { "NULL", "pending", "paid", "done", "part_paid" };
    return transaction_statusArray[transaction_status];
}

nabooapi_v1_get_one_transaction__e get_one_transaction_transaction_status_FromString(char* transaction_status){
    int stringToReturn = 0;
    char *transaction_statusArray[] =  { "NULL", "pending", "paid", "done", "part_paid" };
    size_t sizeofArray = sizeof(transaction_statusArray) / sizeof(transaction_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(transaction_status, transaction_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

get_one_transaction_t *get_one_transaction_create(
    char *order_id,
    list_t *method_of_payment,
    int amount,
    int amount_to_pay,
    char *currency,
    char *created_at,
    transaction_status_enum_t *transaction_status,
    list_t *products,
    int is_done,
    int is_escrow,
    int is_merchant,
    char *checkout_url
    ) {
    get_one_transaction_t *get_one_transaction_local_var = malloc(sizeof(get_one_transaction_t));
    if (!get_one_transaction_local_var) {
        return NULL;
    }
    get_one_transaction_local_var->order_id = order_id;
    get_one_transaction_local_var->method_of_payment = method_of_payment;
    get_one_transaction_local_var->amount = amount;
    get_one_transaction_local_var->amount_to_pay = amount_to_pay;
    get_one_transaction_local_var->currency = currency;
    get_one_transaction_local_var->created_at = created_at;
    get_one_transaction_local_var->transaction_status = transaction_status;
    get_one_transaction_local_var->products = products;
    get_one_transaction_local_var->is_done = is_done;
    get_one_transaction_local_var->is_escrow = is_escrow;
    get_one_transaction_local_var->is_merchant = is_merchant;
    get_one_transaction_local_var->checkout_url = checkout_url;

    return get_one_transaction_local_var;
}


void get_one_transaction_free(get_one_transaction_t *get_one_transaction) {
    if(NULL == get_one_transaction){
        return ;
    }
    listEntry_t *listEntry;
    if (get_one_transaction->order_id) {
        free(get_one_transaction->order_id);
        get_one_transaction->order_id = NULL;
    }
    if (get_one_transaction->method_of_payment) {
        list_ForEach(listEntry, get_one_transaction->method_of_payment) {
            wallet_free(listEntry->data);
        }
        list_freeList(get_one_transaction->method_of_payment);
        get_one_transaction->method_of_payment = NULL;
    }
    if (get_one_transaction->currency) {
        free(get_one_transaction->currency);
        get_one_transaction->currency = NULL;
    }
    if (get_one_transaction->created_at) {
        free(get_one_transaction->created_at);
        get_one_transaction->created_at = NULL;
    }
    if (get_one_transaction->transaction_status) {
        transaction_status_enum_free(get_one_transaction->transaction_status);
        get_one_transaction->transaction_status = NULL;
    }
    if (get_one_transaction->products) {
        list_ForEach(listEntry, get_one_transaction->products) {
            product_model_free(listEntry->data);
        }
        list_freeList(get_one_transaction->products);
        get_one_transaction->products = NULL;
    }
    if (get_one_transaction->checkout_url) {
        free(get_one_transaction->checkout_url);
        get_one_transaction->checkout_url = NULL;
    }
    free(get_one_transaction);
}

cJSON *get_one_transaction_convertToJSON(get_one_transaction_t *get_one_transaction) {
    cJSON *item = cJSON_CreateObject();

    // get_one_transaction->order_id
    if (!get_one_transaction->order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_id", get_one_transaction->order_id) == NULL) {
    goto fail; //String
    }


    // get_one_transaction->method_of_payment
    if (nabooapi_v1_get_one_transaction_METHODOFPAYMENT_NULL == get_one_transaction->method_of_payment) {
        goto fail;
    }
    cJSON *method_of_payment = cJSON_AddArrayToObject(item, "method_of_payment");
    if(method_of_payment == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *method_of_paymentListEntry;
    if (get_one_transaction->method_of_payment) {
    list_ForEach(method_of_paymentListEntry, get_one_transaction->method_of_payment) {
    cJSON *itemLocal = wallet_convertToJSON((nabooapi_v1_get_one_transaction__e)method_of_paymentListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(method_of_payment, itemLocal);
    }
    }


    // get_one_transaction->amount
    if (!get_one_transaction->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", get_one_transaction->amount) == NULL) {
    goto fail; //Numeric
    }


    // get_one_transaction->amount_to_pay
    if (!get_one_transaction->amount_to_pay) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount_to_pay", get_one_transaction->amount_to_pay) == NULL) {
    goto fail; //Numeric
    }


    // get_one_transaction->currency
    if (!get_one_transaction->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", get_one_transaction->currency) == NULL) {
    goto fail; //String
    }


    // get_one_transaction->created_at
    if (!get_one_transaction->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", get_one_transaction->created_at) == NULL) {
    goto fail; //String
    }


    // get_one_transaction->transaction_status
    if (nabooapi_v1_get_one_transaction__NULL == get_one_transaction->transaction_status) {
        goto fail;
    }
    cJSON *transaction_status_local_JSON = transaction_status_enum_convertToJSON(get_one_transaction->transaction_status);
    if(transaction_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "transaction_status", transaction_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // get_one_transaction->products
    if (!get_one_transaction->products) {
        goto fail;
    }
    cJSON *products = cJSON_AddArrayToObject(item, "products");
    if(products == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *productsListEntry;
    if (get_one_transaction->products) {
    list_ForEach(productsListEntry, get_one_transaction->products) {
    cJSON *itemLocal = product_model_convertToJSON(productsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(products, itemLocal);
    }
    }


    // get_one_transaction->is_done
    if (!get_one_transaction->is_done) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_done", get_one_transaction->is_done) == NULL) {
    goto fail; //Bool
    }


    // get_one_transaction->is_escrow
    if (!get_one_transaction->is_escrow) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_escrow", get_one_transaction->is_escrow) == NULL) {
    goto fail; //Bool
    }


    // get_one_transaction->is_merchant
    if (!get_one_transaction->is_merchant) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_merchant", get_one_transaction->is_merchant) == NULL) {
    goto fail; //Bool
    }


    // get_one_transaction->checkout_url
    if (!get_one_transaction->checkout_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "checkout_url", get_one_transaction->checkout_url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_one_transaction_t *get_one_transaction_parseFromJSON(cJSON *get_one_transactionJSON){

    get_one_transaction_t *get_one_transaction_local_var = NULL;

    // define the local list for get_one_transaction->method_of_payment
    list_t *method_of_paymentList = NULL;

    // define the local variable for get_one_transaction->transaction_status
    transaction_status_enum_t *transaction_status_local_nonprim = NULL;

    // define the local list for get_one_transaction->products
    list_t *productsList = NULL;

    // get_one_transaction->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "order_id");
    if (!order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(order_id))
    {
    goto end; //String
    }

    // get_one_transaction->method_of_payment
    cJSON *method_of_payment = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "method_of_payment");
    if (!method_of_payment) {
        goto end;
    }

    
    cJSON *method_of_payment_local_nonprimitive = NULL;
    if(!cJSON_IsArray(method_of_payment)){
        goto end; //nonprimitive container
    }

    method_of_paymentList = list_createList();

    cJSON_ArrayForEach(method_of_payment_local_nonprimitive,method_of_payment )
    {
        if(!cJSON_IsObject(method_of_payment_local_nonprimitive)){
            goto end;
        }
        get_one_transaction_wallet_e method_of_paymentItem = wallet_parseFromJSON(method_of_payment_local_nonprimitive);

        list_addElement(method_of_paymentList, (void *)method_of_paymentItem);
    }

    // get_one_transaction->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "amount");
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }

    // get_one_transaction->amount_to_pay
    cJSON *amount_to_pay = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "amount_to_pay");
    if (!amount_to_pay) {
        goto end;
    }

    
    if(!cJSON_IsNumber(amount_to_pay))
    {
    goto end; //Numeric
    }

    // get_one_transaction->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "currency");
    if (!currency) {
        goto end;
    }

    
    if(!cJSON_IsString(currency))
    {
    goto end; //String
    }

    // get_one_transaction->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "created_at");
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // get_one_transaction->transaction_status
    cJSON *transaction_status = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "transaction_status");
    if (!transaction_status) {
        goto end;
    }

    
    transaction_status_local_nonprim = transaction_status_enum_parseFromJSON(transaction_status); //custom

    // get_one_transaction->products
    cJSON *products = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "products");
    if (!products) {
        goto end;
    }

    
    cJSON *products_local_nonprimitive = NULL;
    if(!cJSON_IsArray(products)){
        goto end; //nonprimitive container
    }

    productsList = list_createList();

    cJSON_ArrayForEach(products_local_nonprimitive,products )
    {
        if(!cJSON_IsObject(products_local_nonprimitive)){
            goto end;
        }
        product_model_t *productsItem = product_model_parseFromJSON(products_local_nonprimitive);

        list_addElement(productsList, productsItem);
    }

    // get_one_transaction->is_done
    cJSON *is_done = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "is_done");
    if (!is_done) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_done))
    {
    goto end; //Bool
    }

    // get_one_transaction->is_escrow
    cJSON *is_escrow = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "is_escrow");
    if (!is_escrow) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_escrow))
    {
    goto end; //Bool
    }

    // get_one_transaction->is_merchant
    cJSON *is_merchant = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "is_merchant");
    if (!is_merchant) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_merchant))
    {
    goto end; //Bool
    }

    // get_one_transaction->checkout_url
    cJSON *checkout_url = cJSON_GetObjectItemCaseSensitive(get_one_transactionJSON, "checkout_url");
    if (!checkout_url) {
        goto end;
    }

    
    if(!cJSON_IsString(checkout_url))
    {
    goto end; //String
    }


    get_one_transaction_local_var = get_one_transaction_create (
        strdup(order_id->valuestring),
        method_of_paymentList,
        amount->valuedouble,
        amount_to_pay->valuedouble,
        strdup(currency->valuestring),
        strdup(created_at->valuestring),
        transaction_status_local_nonprim,
        productsList,
        is_done->valueint,
        is_escrow->valueint,
        is_merchant->valueint,
        strdup(checkout_url->valuestring)
        );

    return get_one_transaction_local_var;
end:
    if (method_of_paymentList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, method_of_paymentList) {
            wallet_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(method_of_paymentList);
        method_of_paymentList = NULL;
    }
    if (transaction_status_local_nonprim) {
        transaction_status_enum_free(transaction_status_local_nonprim);
        transaction_status_local_nonprim = NULL;
    }
    if (productsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, productsList) {
            product_model_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(productsList);
        productsList = NULL;
    }
    return NULL;

}
