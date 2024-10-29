#ifndef transaction_request_TEST
#define transaction_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_request.h"
transaction_request_t* instantiate_transaction_request(int include_optional);



transaction_request_t* instantiate_transaction_request(int include_optional) {
  transaction_request_t* transaction_request = NULL;
  if (include_optional) {
    transaction_request = transaction_request_create(
      list_createList(),
      list_createList(),
      "a",
      "a",
      1,
      1
    );
  } else {
    transaction_request = transaction_request_create(
      list_createList(),
      list_createList(),
      "a",
      "a",
      1,
      1
    );
  }

  return transaction_request;
}


#ifdef transaction_request_MAIN

void test_transaction_request(int include_optional) {
    transaction_request_t* transaction_request_1 = instantiate_transaction_request(include_optional);

	cJSON* jsontransaction_request_1 = transaction_request_convertToJSON(transaction_request_1);
	printf("transaction_request :\n%s\n", cJSON_Print(jsontransaction_request_1));
	transaction_request_t* transaction_request_2 = transaction_request_parseFromJSON(jsontransaction_request_1);
	cJSON* jsontransaction_request_2 = transaction_request_convertToJSON(transaction_request_2);
	printf("repeating transaction_request:\n%s\n", cJSON_Print(jsontransaction_request_2));
}

int main() {
  test_transaction_request(1);
  test_transaction_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_request_MAIN
#endif // transaction_request_TEST
