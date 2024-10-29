# C API client for nabooapi_v1

- API version: 0.1.0
<!--  -->
## Installation
You'll need the `curl 7.58.0` package in order to build the API. To have code formatted nicely, you also need to have uncrustify version 0.67 or later.

# Prerequisites

## Install the `curl 7.58.0` package with the following command on Linux.
```bash
sudo apt remove curl
wget http://curl.haxx.se/download/curl-7.58.0.tar.gz
tar -xvf curl-7.58.0.tar.gz
cd curl-7.58.0/
./configure
make
sudo make install
```
## Install the `uncrustify 0.67` package with the following command on Linux.
```bash
git clone https://github.com/uncrustify/uncrustify.git
cd uncrustify
mkdir build
cd build
cmake ..
make
sudo make install
```

## Compile the sample:
This will compile the generated code and create a library in the build folder which has to be linked to the codes where API will be used.
```bash
mkdir build
cd build
// To install library to specific location, use following commands
cmake -DCMAKE_INSTALL_PREFIX=/pathtolocation ..
// for normal install use following command
cmake ..
make
sudo make install
```
## How to use compiled library
Considering the test/source code which uses the API is written in main.c(respective api include is written and all objects necessary are defined and created)

To compile main.c(considering the file is present in build folder) use following command
-L - location of the library(not required if cmake with normal installation is performed)
-l library name
```bash
gcc main.c -L. -lnabooapi_v1 -o main
```
Once compiled, you can run it with ``` ./main ```

Note: You don't need to specify includes for models and include folder separately as they are path linked. You just have to import the api.h file in your code, the include linking will work.

## Documentation for API Endpoints

All URIs are relative to */api/v1*

Category | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*AccountAPI* | [**AccountAPI_getAccountInformationAccountGet**](docs/AccountAPI.md#AccountAPI_getAccountInformationAccountGet) | **GET** /account/ | Get Account Information
*CashoutAPI* | [**CashoutAPI_cashOutOrangeMoneyCashoutOrangeMoneyPost**](docs/CashoutAPI.md#CashoutAPI_cashOutOrangeMoneyCashoutOrangeMoneyPost) | **POST** /cashout/orange-money | Cash Out Orange Money
*CashoutAPI* | [**CashoutAPI_cashOutWaveCashoutWavePost**](docs/CashoutAPI.md#CashoutAPI_cashOutWaveCashoutWavePost) | **POST** /cashout/wave | Cash Out Wave
*TransactionAPI* | [**TransactionAPI_createTransactionTransactionCreateTransactionPost**](docs/TransactionAPI.md#TransactionAPI_createTransactionTransactionCreateTransactionPost) | **PUT** /transaction/create-transaction | Create Transaction
*TransactionAPI* | [**TransactionAPI_deleteTransactionTransactionDeleteTransactionDelete**](docs/TransactionAPI.md#TransactionAPI_deleteTransactionTransactionDeleteTransactionDelete) | **DELETE** /transaction/delete-transaction | Delete Transaction
*TransactionAPI* | [**TransactionAPI_getOneTransactionTransactionGetOneTransactionGet**](docs/TransactionAPI.md#TransactionAPI_getOneTransactionTransactionGetOneTransactionGet) | **GET** /transaction/get-one-transaction | Get One Transaction
*TransactionAPI* | [**TransactionAPI_getTransactionsTransactionGetTransactionsGet**](docs/TransactionAPI.md#TransactionAPI_getTransactionsTransactionGetTransactionsGet) | **GET** /transaction/get-transactions | Get Transactions


## Documentation for Models

 - [cash_out_orange_request_t](docs/cash_out_orange_request.md)
 - [cash_out_response_t](docs/cash_out_response.md)
 - [cash_out_wave_request_t](docs/cash_out_wave_request.md)
 - [delete_transaction_request_t](docs/delete_transaction_request.md)
 - [delete_transaction_response_t](docs/delete_transaction_response.md)
 - [get_account_response_t](docs/get_account_response.md)
 - [get_all_transaction_t](docs/get_all_transaction.md)
 - [get_one_transaction_t](docs/get_one_transaction.md)
 - [http_validation_error_t](docs/http_validation_error.md)
 - [product_model_t](docs/product_model.md)
 - [transaction_request_t](docs/transaction_request.md)
 - [transaction_response_t](docs/transaction_response.md)
 - [transaction_status_enum_t](docs/transaction_status_enum.md)
 - [validation_error_t](docs/validation_error.md)
 - [validation_error_loc_inner_t](docs/validation_error_loc_inner.md)
 - [wallet_t](docs/wallet.md)


## Documentation for Authorization


Authentication schemes defined for the API:
### HTTPBearer


- **Type**: HTTP Bearer Token authentication


## Author



