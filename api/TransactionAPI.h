#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/delete_transaction_request.h"
#include "../model/delete_transaction_response.h"
#include "../model/get_all_transaction.h"
#include "../model/get_one_transaction.h"
#include "../model/http_validation_error.h"
#include "../model/transaction_request.h"
#include "../model/transaction_response.h"


// Create Transaction
//
// This endpoint allows authenticated users to create a transaction by submitting a request with the necessary details. The endpoint ensures that the user's access level permits transaction creation and enforces a rate limit of 30 requests. It checks that the number of products is within the allowed range (1-20) and calculates the total transaction amount, applying a 20% charge for escrow transactions. It also verifies that the total amount does not exceed a specific threshold (2,000,000). The user's IP address and browser information are logged, and the transaction details are saved with relevant metadata, including a unique order ID and the associated account state. If any conditions are not met, appropriate error messages are returned.
//
transaction_response_t*
TransactionAPI_createTransactionTransactionCreateTransactionPost(apiClient_t *apiClient, transaction_request_t *transaction_request);


// Delete Transaction
//
// This endpoint allows authenticated users to delete a transaction by submitting a request with the necessary details. The endpoint checks the user's access level to ensure they have permission to delete transactions and enforces a rate limit of 30 requests. It verifies that the transaction belongs to the user and has not already been deleted or withdrawn. If the transaction is paid and has a payment reference, it processes refunds and updates the user's account balance accordingly.
//
delete_transaction_response_t*
TransactionAPI_deleteTransactionTransactionDeleteTransactionDelete(apiClient_t *apiClient, delete_transaction_request_t *delete_transaction_request);


// Get One Transaction
//
// This endpoint allows authenticated users to retrieve the details of a specific transaction using the order ID. The endpoint ensures the user has read access and enforces a rate limit of 30 requests. It checks if the transaction exists in the database and if the user has the appropriate access rights,then provides a checkout URL for the transaction and others informations
//
get_one_transaction_t*
TransactionAPI_getOneTransactionTransactionGetOneTransactionGet(apiClient_t *apiClient, char *order_id);


// Get Transactions
//
// This endpoint allows authenticated users to retrieve a list of their visible transactions, up to a maximum of 50. The endpoint enforces a rate limit of 30 requests and ensures the user has read access.
//
get_all_transaction_t*
TransactionAPI_getTransactionsTransactionGetTransactionsGet(apiClient_t *apiClient);


