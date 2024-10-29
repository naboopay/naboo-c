#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "CashoutAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Cash Out Orange Money
//
// This endpoint enables a user to withdraw funds from their NabooPay account to their Orange Money account. Authentication is required, and users with the 'dev' role are not permitted to perform this operation. The amount to be withdrawn must be positive and within the user's available balance. The user's account must be active and registered in the system. After validation, the user's account balance is adjusted accordingly, and the transaction is logged for record-keeping.
//
cash_out_response_t*
CashoutAPI_cashOutOrangeMoneyCashoutOrangeMoneyPost(apiClient_t *apiClient, cash_out_orange_request_t *cash_out_orange_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/cashout/orange-money")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/cashout/orange-money");




    // Body Param
    cJSON *localVarSingleItemJSON_cash_out_orange_request = NULL;
    if (cash_out_orange_request != NULL)
    {
        //string
        localVarSingleItemJSON_cash_out_orange_request = cash_out_orange_request_convertToJSON(cash_out_orange_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_cash_out_orange_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","The request was successful.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid or malformed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","The user is not authorized to make this request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","The user does not have permission to access this resource.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","The requested resource could not be found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","An unexpected internal server error occurred.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Validation Error");
    //}
    //nonprimitive not container
    cJSON *CashoutAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    cash_out_response_t *elementToReturn = cash_out_response_parseFromJSON(CashoutAPIlocalVarJSON);
    cJSON_Delete(CashoutAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_cash_out_orange_request) {
        cJSON_Delete(localVarSingleItemJSON_cash_out_orange_request);
        localVarSingleItemJSON_cash_out_orange_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Cash Out Wave
//
// This endpoint allows a user to withdraw funds from their NabooPay account to their Wave account. The user must be authenticated and not possess the 'dev' role. The withdrawal amount must be greater than 10 and not exceed the user's account balance. The user's account must exist and be active. Upon successful validation, the system updates the user's account balance and records the transaction for tracking purposes.
//
cash_out_response_t*
CashoutAPI_cashOutWaveCashoutWavePost(apiClient_t *apiClient, cash_out_wave_request_t *cash_out_wave_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/cashout/wave")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/cashout/wave");




    // Body Param
    cJSON *localVarSingleItemJSON_cash_out_wave_request = NULL;
    if (cash_out_wave_request != NULL)
    {
        //string
        localVarSingleItemJSON_cash_out_wave_request = cash_out_wave_request_convertToJSON(cash_out_wave_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_cash_out_wave_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","The request was successful.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid or malformed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","The user is not authorized to make this request.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","The user does not have permission to access this resource.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","The requested resource could not be found.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","An unexpected internal server error occurred.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Validation Error");
    //}
    //nonprimitive not container
    cJSON *CashoutAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    cash_out_response_t *elementToReturn = cash_out_response_parseFromJSON(CashoutAPIlocalVarJSON);
    cJSON_Delete(CashoutAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_cash_out_wave_request) {
        cJSON_Delete(localVarSingleItemJSON_cash_out_wave_request);
        localVarSingleItemJSON_cash_out_wave_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

