# CashoutAPI

All URIs are relative to */api/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CashoutAPI_cashOutOrangeMoneyCashoutOrangeMoneyPost**](CashoutAPI.md#CashoutAPI_cashOutOrangeMoneyCashoutOrangeMoneyPost) | **POST** /cashout/orange-money | Cash Out Orange Money
[**CashoutAPI_cashOutWaveCashoutWavePost**](CashoutAPI.md#CashoutAPI_cashOutWaveCashoutWavePost) | **POST** /cashout/wave | Cash Out Wave


# **CashoutAPI_cashOutOrangeMoneyCashoutOrangeMoneyPost**
```c
// Cash Out Orange Money
//
// This endpoint enables a user to withdraw funds from their NabooPay account to their Orange Money account. Authentication is required, and users with the 'dev' role are not permitted to perform this operation. The amount to be withdrawn must be positive and within the user's available balance. The user's account must be active and registered in the system. After validation, the user's account balance is adjusted accordingly, and the transaction is logged for record-keeping.
//
cash_out_response_t* CashoutAPI_cashOutOrangeMoneyCashoutOrangeMoneyPost(apiClient_t *apiClient, cash_out_orange_request_t *cash_out_orange_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**cash_out_orange_request** | **[cash_out_orange_request_t](cash_out_orange_request.md) \*** |  | 

### Return type

[cash_out_response_t](cash_out_response.md) *


### Authorization

[HTTPBearer](../README.md#HTTPBearer)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CashoutAPI_cashOutWaveCashoutWavePost**
```c
// Cash Out Wave
//
// This endpoint allows a user to withdraw funds from their NabooPay account to their Wave account. The user must be authenticated and not possess the 'dev' role. The withdrawal amount must be greater than 10 and not exceed the user's account balance. The user's account must exist and be active. Upon successful validation, the system updates the user's account balance and records the transaction for tracking purposes.
//
cash_out_response_t* CashoutAPI_cashOutWaveCashoutWavePost(apiClient_t *apiClient, cash_out_wave_request_t *cash_out_wave_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**cash_out_wave_request** | **[cash_out_wave_request_t](cash_out_wave_request.md) \*** |  | 

### Return type

[cash_out_response_t](cash_out_response.md) *


### Authorization

[HTTPBearer](../README.md#HTTPBearer)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

