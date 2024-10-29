#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_request.h"


char* transaction_request_method_of_payment_ToString(nabooapi_v1_transaction_request__e method_of_payment) {
    char *method_of_paymentArray[] =  { "NULL", "WAVE", "ORANGE_MONEY", "FREE_MONEY" };
    return method_of_paymentArray[method_of_payment - 1];
}

nabooapi_v1_transaction_request__e transaction_request_method_of_payment_FromString(char* method_of_payment) {
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

transaction_request_t *transaction_request_create(
    list_t *method_of_payment,
    list_t *products,
    char *success_url,
    char *error_url,
    int is_escrow,
    int is_merchant
    ) {
    transaction_request_t *transaction_request_local_var = malloc(sizeof(transaction_request_t));
    if (!transaction_request_local_var) {
        return NULL;
    }
    transaction_request_local_var->method_of_payment = method_of_payment;
    transaction_request_local_var->products = products;
    transaction_request_local_var->success_url = success_url;
    transaction_request_local_var->error_url = error_url;
    transaction_request_local_var->is_escrow = is_escrow;
    transaction_request_local_var->is_merchant = is_merchant;

    return transaction_request_local_var;
}


void transaction_request_free(transaction_request_t *transaction_request) {
    if(NULL == transaction_request){
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_request->method_of_payment) {
        list_ForEach(listEntry, transaction_request->method_of_payment) {
            wallet_free(listEntry->data);
        }
        list_freeList(transaction_request->method_of_payment);
        transaction_request->method_of_payment = NULL;
    }
    if (transaction_request->products) {
        list_ForEach(listEntry, transaction_request->products) {
            product_model_free(listEntry->data);
        }
        list_freeList(transaction_request->products);
        transaction_request->products = NULL;
    }
    if (transaction_request->success_url) {
        free(transaction_request->success_url);
        transaction_request->success_url = NULL;
    }
    if (transaction_request->error_url) {
        free(transaction_request->error_url);
        transaction_request->error_url = NULL;
    }
    free(transaction_request);
}

cJSON *transaction_request_convertToJSON(transaction_request_t *transaction_request) {
    cJSON *item = cJSON_CreateObject();

    // transaction_request->method_of_payment
    if (nabooapi_v1_transaction_request_METHODOFPAYMENT_NULL == transaction_request->method_of_payment) {
        goto fail;
    }
    cJSON *method_of_payment = cJSON_AddArrayToObject(item, "method_of_payment");
    if(method_of_payment == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *method_of_paymentListEntry;
    if (transaction_request->method_of_payment) {
    list_ForEach(method_of_paymentListEntry, transaction_request->method_of_payment) {
    cJSON *itemLocal = wallet_convertToJSON((nabooapi_v1_transaction_request__e)method_of_paymentListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(method_of_payment, itemLocal);
    }
    }


    // transaction_request->products
    if (!transaction_request->products) {
        goto fail;
    }
    cJSON *products = cJSON_AddArrayToObject(item, "products");
    if(products == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *productsListEntry;
    if (transaction_request->products) {
    list_ForEach(productsListEntry, transaction_request->products) {
    cJSON *itemLocal = product_model_convertToJSON(productsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(products, itemLocal);
    }
    }


    // transaction_request->success_url
    if(transaction_request->success_url) {
    if(cJSON_AddStringToObject(item, "success_url", transaction_request->success_url) == NULL) {
    goto fail; //String
    }
    }


    // transaction_request->error_url
    if(transaction_request->error_url) {
    if(cJSON_AddStringToObject(item, "error_url", transaction_request->error_url) == NULL) {
    goto fail; //String
    }
    }


    // transaction_request->is_escrow
    if(transaction_request->is_escrow) {
    if(cJSON_AddBoolToObject(item, "is_escrow", transaction_request->is_escrow) == NULL) {
    goto fail; //Bool
    }
    }


    // transaction_request->is_merchant
    if(transaction_request->is_merchant) {
    if(cJSON_AddBoolToObject(item, "is_merchant", transaction_request->is_merchant) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transaction_request_t *transaction_request_parseFromJSON(cJSON *transaction_requestJSON){

    transaction_request_t *transaction_request_local_var = NULL;

    // define the local list for transaction_request->method_of_payment
    list_t *method_of_paymentList = NULL;

    // define the local list for transaction_request->products
    list_t *productsList = NULL;

    // transaction_request->method_of_payment
    cJSON *method_of_payment = cJSON_GetObjectItemCaseSensitive(transaction_requestJSON, "method_of_payment");
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
        transaction_request_wallet_e method_of_paymentItem = wallet_parseFromJSON(method_of_payment_local_nonprimitive);

        list_addElement(method_of_paymentList, (void *)method_of_paymentItem);
    }

    // transaction_request->products
    cJSON *products = cJSON_GetObjectItemCaseSensitive(transaction_requestJSON, "products");
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

    // transaction_request->success_url
    cJSON *success_url = cJSON_GetObjectItemCaseSensitive(transaction_requestJSON, "success_url");
    if (success_url) { 
    if(!cJSON_IsString(success_url) && !cJSON_IsNull(success_url))
    {
    goto end; //String
    }
    }

    // transaction_request->error_url
    cJSON *error_url = cJSON_GetObjectItemCaseSensitive(transaction_requestJSON, "error_url");
    if (error_url) { 
    if(!cJSON_IsString(error_url) && !cJSON_IsNull(error_url))
    {
    goto end; //String
    }
    }

    // transaction_request->is_escrow
    cJSON *is_escrow = cJSON_GetObjectItemCaseSensitive(transaction_requestJSON, "is_escrow");
    if (is_escrow) { 
    if(!cJSON_IsBool(is_escrow))
    {
    goto end; //Bool
    }
    }

    // transaction_request->is_merchant
    cJSON *is_merchant = cJSON_GetObjectItemCaseSensitive(transaction_requestJSON, "is_merchant");
    if (is_merchant) { 
    if(!cJSON_IsBool(is_merchant))
    {
    goto end; //Bool
    }
    }


    transaction_request_local_var = transaction_request_create (
        method_of_paymentList,
        productsList,
        success_url && !cJSON_IsNull(success_url) ? strdup(success_url->valuestring) : NULL,
        error_url && !cJSON_IsNull(error_url) ? strdup(error_url->valuestring) : NULL,
        is_escrow ? is_escrow->valueint : 0,
        is_merchant ? is_merchant->valueint : 0
        );

    return transaction_request_local_var;
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
