#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "product_model.h"



product_model_t *product_model_create(
    char *name,
    char *category,
    int amount,
    int quantity,
    char *description
    ) {
    product_model_t *product_model_local_var = malloc(sizeof(product_model_t));
    if (!product_model_local_var) {
        return NULL;
    }
    product_model_local_var->name = name;
    product_model_local_var->category = category;
    product_model_local_var->amount = amount;
    product_model_local_var->quantity = quantity;
    product_model_local_var->description = description;

    return product_model_local_var;
}


void product_model_free(product_model_t *product_model) {
    if(NULL == product_model){
        return ;
    }
    listEntry_t *listEntry;
    if (product_model->name) {
        free(product_model->name);
        product_model->name = NULL;
    }
    if (product_model->category) {
        free(product_model->category);
        product_model->category = NULL;
    }
    if (product_model->description) {
        free(product_model->description);
        product_model->description = NULL;
    }
    free(product_model);
}

cJSON *product_model_convertToJSON(product_model_t *product_model) {
    cJSON *item = cJSON_CreateObject();

    // product_model->name
    if (!product_model->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", product_model->name) == NULL) {
    goto fail; //String
    }


    // product_model->category
    if (!product_model->category) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category", product_model->category) == NULL) {
    goto fail; //String
    }


    // product_model->amount
    if (!product_model->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", product_model->amount) == NULL) {
    goto fail; //Numeric
    }


    // product_model->quantity
    if (!product_model->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", product_model->quantity) == NULL) {
    goto fail; //Numeric
    }


    // product_model->description
    if (!product_model->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", product_model->description) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

product_model_t *product_model_parseFromJSON(cJSON *product_modelJSON){

    product_model_t *product_model_local_var = NULL;

    // product_model->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(product_modelJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // product_model->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(product_modelJSON, "category");
    if (!category) {
        goto end;
    }

    
    if(!cJSON_IsString(category))
    {
    goto end; //String
    }

    // product_model->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(product_modelJSON, "amount");
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }

    // product_model->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(product_modelJSON, "quantity");
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }

    // product_model->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(product_modelJSON, "description");
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }


    product_model_local_var = product_model_create (
        strdup(name->valuestring),
        strdup(category->valuestring),
        amount->valuedouble,
        quantity->valuedouble,
        strdup(description->valuestring)
        );

    return product_model_local_var;
end:
    return NULL;

}
