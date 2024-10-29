# TransactionAPI

All URIs are relative to */api/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TransactionAPI_createTransactionTransactionCreateTransactionPost**](TransactionAPI.md#TransactionAPI_createTransactionTransactionCreateTransactionPost) | **PUT** /transaction/create-transaction | Create Transaction
[**TransactionAPI_deleteTransactionTransactionDeleteTransactionDelete**](TransactionAPI.md#TransactionAPI_deleteTransactionTransactionDeleteTransactionDelete) | **DELETE** /transaction/delete-transaction | Delete Transaction
[**TransactionAPI_getOneTransactionTransactionGetOneTransactionGet**](TransactionAPI.md#TransactionAPI_getOneTransactionTransactionGetOneTransactionGet) | **GET** /transaction/get-one-transaction | Get One Transaction
[**TransactionAPI_getTransactionsTransactionGetTransactionsGet**](TransactionAPI.md#TransactionAPI_getTransactionsTransactionGetTransactionsGet) | **GET** /transaction/get-transactions | Get Transactions


# **TransactionAPI_createTransactionTransactionCreateTransactionPost**
```c
// Create Transaction
//
// This endpoint allows authenticated users to create a transaction by submitting a request with the necessary details. The endpoint ensures that the user's access level permits transaction creation and enforces a rate limit of 30 requests. It checks that the number of products is within the allowed range (1-20) and calculates the total transaction amount, applying a 20% charge for escrow transactions. It also verifies that the total amount does not exceed a specific threshold (2,000,000). The user's IP address and browser information are logged, and the transaction details are saved with relevant metadata, including a unique order ID and the associated account state. If any conditions are not met, appropriate error messages are returned.
//
transaction_response_t* TransactionAPI_createTransactionTransactionCreateTransactionPost(apiClient_t *apiClient, transaction_request_t *transaction_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**transaction_request** | **[transaction_request_t](transaction_request.md) \*** |  | 

### Return type

[transaction_response_t](transaction_response.md) *


### Authorization

[HTTPBearer](../README.md#HTTPBearer)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TransactionAPI_deleteTransactionTransactionDeleteTransactionDelete**
```c
// Delete Transaction
//
// This endpoint allows authenticated users to delete a transaction by submitting a request with the necessary details. The endpoint checks the user's access level to ensure they have permission to delete transactions and enforces a rate limit of 30 requests. It verifies that the transaction belongs to the user and has not already been deleted or withdrawn. If the transaction is paid and has a payment reference, it processes refunds and updates the user's account balance accordingly.
//
delete_transaction_response_t* TransactionAPI_deleteTransactionTransactionDeleteTransactionDelete(apiClient_t *apiClient, delete_transaction_request_t *delete_transaction_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**delete_transaction_request** | **[delete_transaction_request_t](delete_transaction_request.md) \*** |  | 

### Return type

[delete_transaction_response_t](delete_transaction_response.md) *


### Authorization

[HTTPBearer](../README.md#HTTPBearer)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TransactionAPI_getOneTransactionTransactionGetOneTransactionGet**
```c
// Get One Transaction
//
// This endpoint allows authenticated users to retrieve the details of a specific transaction using the order ID. The endpoint ensures the user has read access and enforces a rate limit of 30 requests. It checks if the transaction exists in the database and if the user has the appropriate access rights,then provides a checkout URL for the transaction and others informations
//
get_one_transaction_t* TransactionAPI_getOneTransactionTransactionGetOneTransactionGet(apiClient_t *apiClient, char *order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** |  | 

### Return type

[get_one_transaction_t](get_one_transaction.md) *


### Authorization

[HTTPBearer](../README.md#HTTPBearer)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TransactionAPI_getTransactionsTransactionGetTransactionsGet**
```c
// Get Transactions
//
// This endpoint allows authenticated users to retrieve a list of their visible transactions, up to a maximum of 50. The endpoint enforces a rate limit of 30 requests and ensures the user has read access.
//
get_all_transaction_t* TransactionAPI_getTransactionsTransactionGetTransactionsGet(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_all_transaction_t](get_all_transaction.md) *


### Authorization

[HTTPBearer](../README.md#HTTPBearer)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

